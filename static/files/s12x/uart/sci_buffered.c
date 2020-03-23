/**  
 * SCI(Serial Communication Interface)  Buffered Serial I/O     
 * @file sci_buffered.c  
 * @author Li Yuan  
 * @platform mc9s12XX  
 * @date 2012-7-22  
 * @version 1.0.1  
 */

#include "derivative.h"      /* derivative-specific definitions */ 
#include <stddef.h> 
#include "sci.h" 
#include "sci_buffered.h"

//#define OS_ENTER_CRITICAL()    _asm ("pshc; sei") 
//#define OS_EXIT_CRITICAL()     _asm ("pulc")

#define OS_ENTER_CRITICAL()       _asm ("tpa; sei; staa cpu_sr") 
#define OS_EXIT_CRITICAL()        _asm ("ldaa cpu_sr; tap")

/**  
 *        DATA TYPES  
 */ 
 typedef struct {     short  RingBufRxCtr;     	 /* Number of characters in the Rx ring buffer           */     
 unsigned char  *RingBufRxInPtr;                 /* Pointer to where next character will be inserted     */
 unsigned char  *RingBufRxOutPtr;			     /* Pointer from where next character will be extracted  */
 unsigned char   RingBufRx[SCI_RX_BUF_SIZE];     /* Ring buffer character storage (Rx)                   */ 
 short  RingBufTxCtr;                            /* Number of characters in the Tx ring buffer           */
 unsigned char  *RingBufTxInPtr;                 /* Pointer to where next character will be inserted     */
 unsigned char  *RingBufTxOutPtr;                /* Pointer from where next character will be extracted  */
 unsigned char   RingBufTx[SCI_TX_BUF_SIZE];     /* Ring buffer character storage (Tx)                   */
 } SCI_RING_BUF;

/**  *       GLOBAL VARIABLES  */

SCI_RING_BUF  SCI0Buf;
SCI_RING_BUF  SCI1Buf;

/**  
 * To obtain a character from the communications channel.  
 * @param port, port can be SCI0 / SCI1  
 * @param err,  is a pointer to where an error code will be placed:  
 *                   
 *err is set to SCI_NO_ERR   if a character is available  
 *                   
 *err is set to SCI_RX_EMPTY if the Rx buffer is empty  
 *                   
 *err is set to SCI_BAD_CH   if you have specified an invalid channel   
 * @return The received char if err == SCI_NO_ERR            
 */ 
unsigned char  SCIGetCharB (unsigned char port, unsigned char *err) {
	unsigned char cpu_sr;
	unsigned char c;
	SCI_RING_BUF *pbuf;         /* Obtain pointer to communications channel */
	switch (port)     {
		case SCI0:
		pbuf = &SCI0Buf;
		break;

        case SCI1:
		pbuf = &SCI1Buf;
		break;

        default:
		*err = SCI_BAD_CH;
		return (0);
	}
	OS_ENTER_CRITICAL();
	if (pbuf->RingBufRxCtr > 0)   /* See if buffer is empty */
	{
		pbuf->RingBufRxCtr--;                              /* No, decrement character count */
		c = *pbuf->RingBufRxOutPtr++;                      /* Get character from buffer */
		if (pbuf->RingBufRxOutPtr == &pbuf->RingBufRx[SCI_RX_BUF_SIZE])
			{
				pbuf->RingBufRxOutPtr = &pbuf->RingBufRx[0];   /* Wrap OUT pointer */
			}
		OS_EXIT_CRITICAL();
		*err = SCI_NO_ERR;
		return (c);
	}
	else
	{
		OS_EXIT_CRITICAL();
		*err = SCI_RX_EMPTY;
		c    = 0;  /* Buffer is empty, return 0 */
		return (c);
	}
}

  /**  
   * To send a character on the communications channel.   
   * The character to send is first inserted into the Tx buffer and will be sent by  
   * the Tx ISR.  If this is the first character placed into the buffer, the Tx ISR will be  
   * enabled.  If the Tx buffer is full, the character will not be sent (i.e. it will be lost)  
   *  
   * @param port, port can be SCI0 / SCI1  
   * @return   COMM_NO_ERR   if the function was successful (the buffer was not full)  
   *           COMM_TX_FULL  if the buffer was full  
   *           COMM_BAD_CH   if you have specified an incorrect channel  
   */
unsigned char SCIPutCharB (unsigned char port, unsigned char c)
{
	unsigned char cpu_sr;
	SCI_RING_BUF *pbuf;
	/* Obtain pointer to communications channel */
	switch (port)
	{
		case SCI0:
		pbuf = &SCI0Buf;
		break;

        case SCI1:
		pbuf = &SCI1Buf;
		break;

        default:
		return (SCI_BAD_CH);
	}

    OS_ENTER_CRITICAL();
	if (pbuf->RingBufTxCtr < SCI_TX_BUF_SIZE)/* See if buffer is full */
	{
		pbuf->RingBufTxCtr++;          /* No, increment character count */
		*pbuf->RingBufTxInPtr++ = c;   /* Put character into buffer */
		if (pbuf->RingBufTxInPtr == &pbuf->RingBufTx[SCI_TX_BUF_SIZE])
		{
			pbuf->RingBufTxInPtr = &pbuf->RingBufTx[0];  /* Wrap IN pointer */
		}
		if (pbuf->RingBufTxCtr == 1)
		{
			/* See if this is the first character */
			SCIEnableTxInt(port);   /* Yes, Enable Tx interrupts */
			OS_EXIT_CRITICAL();
		}
		else
		{
			OS_EXIT_CRITICAL();
		} 
        return (SCI_NO_ERR);
	}
	else
	{
		OS_EXIT_CRITICAL();
		return (SCI_TX_FULL);
	}
}

/**
  * To initialize the communications module.
  * You must call this function before calling any other functions.
  */
  void  SCIBufferInit (void) {
	  SCI_RING_BUF *pbuf;
	  /* Initialize the ring buffer for SCI0     */
	  pbuf                  = &SCI0Buf;
	  pbuf->RingBufRxCtr    = 0;
	  pbuf->RingBufRxInPtr  = &pbuf->RingBufRx[0];
	  pbuf->RingBufRxOutPtr = &pbuf->RingBufRx[0];
	  pbuf->RingBufTxCtr    = 0;
	  pbuf->RingBufTxInPtr  = &pbuf->RingBufTx[0];
	  pbuf->RingBufTxOutPtr = &pbuf->RingBufTx[0];
	  /* Initialize the ring buffer for SCI1     */
	  pbuf                  = &SCI1Buf;
	  pbuf->RingBufRxCtr    = 0;
	  pbuf->RingBufRxInPtr  = &pbuf->RingBufRx[0];
	  pbuf->RingBufRxOutPtr = &pbuf->RingBufRx[0];
	  pbuf->RingBufTxCtr    = 0;
	  pbuf->RingBufTxInPtr  = &pbuf->RingBufTx[0];
	  pbuf->RingBufTxOutPtr = &pbuf->RingBufTx[0];
  }

/**
  * To see if any character is available from the communications channel.  
  *
  * @param port, port can be SCI0 / SCI1
  * @return   If at least one character is available, the function returns
  *            FALSE(0) otherwise, the function returns TRUE(1).
  */
  unsigned char  SCIBufferIsEmpty (unsigned char port)
  {
	  unsigned char cpu_sr;
	  unsigned char empty;
	  SCI_RING_BUF *pbuf;
	  /* Obtain pointer to communications channel */
	  switch (port)
	  {
		case SCI0:
		  pbuf = &SCI0Buf; 
		  break;

        case SCI1:
		pbuf = &SCI1Buf;
		break;

        default:
		return (1);
	}
	OS_ENTER_CRITICAL();
	if (pbuf->RingBufRxCtr > 0)  /* See if buffer is empty */
	{
		empty = 0; /* Buffer is NOT empty */
	}
	else
	{
		empty = 1; /* Buffer is empty     */
	}
	OS_EXIT_CRITICAL();
	return (empty);
}

/**
  * To see if any more characters can be placed in the Tx buffer.
  * In other words, this function check to see if the Tx buffer is full.
  *
  * @param port, port can be SCI0 / SCI1
  * @return   If the buffer is full, the function returns TRUE
  *           otherwise, the function returns FALSE.
  */
  unsigned char SCIBufferIsFull (unsigned char port)
  {
	  unsigned char cpu_sr;
	  char full;
	  SCI_RING_BUF *pbuf;
	  /* Obtain pointer to communications channel */
	  switch (port)
	  {
		  case SCI0:
		  pbuf = &SCI0Buf;
		  break;

        case SCI1:
		pbuf = &SCI1Buf;
		break;

        default:
		return (1);
	}
	OS_ENTER_CRITICAL();
	if (pbuf->RingBufTxCtr < SCI_TX_BUF_SIZE)
	{
        /* See if buffer is full */
		full = 0;
		/* Buffer is NOT full    */
	}
	else
	{
		full = 1;
		/* Buffer is full        */
	}
	OS_EXIT_CRITICAL();
	return (full);
}

// This function is called by the Rx ISR to insert a character into the receive ring buffer.
static void  SCIPutRxChar (unsigned char port, unsigned char c) {
	SCI_RING_BUF *pbuf;
	/* Obtain pointer to communications channel */
	switch (port)
	{
		case SCI0:
		pbuf = &SCI0Buf;
		break;

        case SCI1:
		pbuf = &SCI1Buf;
		break;

        default:
		return;
	}
	if (pbuf->RingBufRxCtr < SCI_RX_BUF_SIZE) /* See if buffer is full */
	{
		pbuf->RingBufRxCtr++;         /* No, increment character count */
		*pbuf->RingBufRxInPtr++ = c;  /* Put character into buffer */
		if (pbuf->RingBufRxInPtr == &pbuf->RingBufRx[SCI_RX_BUF_SIZE])
		{
			/* Wrap IN pointer */
			pbuf->RingBufRxInPtr = &pbuf->RingBufRx[0];
		}
	}
}

// This function is called by the Tx ISR to extract the next character from the Tx buffer. 
//    The function returns FALSE if the buffer is empty after the character is extracted from 
//    the buffer.  This is done to signal the Tx ISR to disable interrupts because this is the 
//    last character to send. 
static unsigned char SCIGetTxChar (unsigned char port, unsigned char *err)
{
	unsigned char c;
	SCI_RING_BUF *pbuf;

    switch (port)
	{
		case SCI0:
		pbuf = &SCI0Buf;
		break;

        case SCI1:
		pbuf = &SCI1Buf;
		break;

        default:
		*err = SCI_BAD_CH;
		return (0);
	}
	/* See if buffer is empty */
	if (pbuf->RingBufTxCtr > 0)
	{
		pbuf->RingBufTxCtr--;    /* No, decrement character count */
		c = *pbuf->RingBufTxOutPtr++;   /* Get character from buffer */
		if (pbuf->RingBufTxOutPtr == &pbuf->RingBufTx[SCI_TX_BUF_SIZE])
		{
			pbuf->RingBufTxOutPtr = &pbuf->RingBufTx[0];   /* Wrap OUT pointer */
		}
		*err = SCI_NO_ERR;
		return (c);   /* Characters are still available */
	}
	else
	{
		*err = SCI_TX_EMPTY;
		return (0);   /* Buffer is empty */
	}
}

interrupt VectorNumber_Vsci0  void SCI0_ISR(void) 
{
	char status;
	unsigned char data;
	unsigned char err;
	status = SCI0SR1;
	if(status & 0x0F) // 0x1F = 0001 1111, if status is not Receive Data Reg Full Flag
	{         
		// See if we have some kind of error           
		// Clear interrupt (do nothing about it!)
		data = SCI0DRL;
	}
	else if(status & 0x20) //Receive Data Reg Full Flag
	{
		data = SCI0DRL;
		SCIPutRxChar(SCI0, data);                    // Insert received character into buffer
	}
	else if(status & 0x80)
	{
		data = SCIGetTxChar(SCI0, &err);             // Get next character to send.
		if (err == SCI_TX_EMPTY)
		{                                            
			// Do we have anymore characters to send ?
			// No,  Disable Tx interrupts
			SCI0CR2_SCTIE = 0;
			SCI0CR2_TCIE = 0;
		}
		else
		{
			SCI0DRL = data;
			// Yes, Send character
		}
	}
}   

interrupt VectorNumber_Vsci1 void SCI1_ISR(void)
{
	char status;
	unsigned char data;
	unsigned char err;
	status = SCI1SR1;
	if(status & 0x0F) // 0x1F = 0001 1111, if status is not Receive Data Reg Full Flag
	{
		// See if we have some kind of error
		// Clear interrupt (do nothing about it!)
		data = SCI1DRL;
	}
	else if(status & 0x20) //Receive Data Reg Full Flag
	{
		data = SCI1DRL;
		SCIPutRxChar(SCI1, data);
		// Insert received character into buffer
	}
	else if(status & 0x80)
	{
		data = SCIGetTxChar(SCI1, &err);
		// Get next character to send.
		if (err == SCI_TX_EMPTY)
		{
			// Do we have anymore characters to send ?
			// No,  Disable Tx interrupts
			SCI1CR2_SCTIE = 0;
			SCI1CR2_TCIE = 0;
		}
		else
		{
			SCI1DRL = data;        // Yes, Send character
		}
	}
}  
