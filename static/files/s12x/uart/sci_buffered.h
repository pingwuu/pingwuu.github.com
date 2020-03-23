/* sci_buffered.h */
#ifndef _SCI_BUFFERED_H_ #define _SCI_BUFFERED_H_

#define  SCI_RX_BUF_SIZE        64                /* Number of characters in Rx ring buffer             */ 
#define  SCI_TX_BUF_SIZE        64                /* Number of characters in Tx ring buffer             */

#define  SCI_NO_ERR             0                /* Function call was successful                       */ 
#define  SCI_BAD_CH             1                /* Invalid communications port channel                */ 
#define  SCI_RX_EMPTY           2                /* Rx buffer is empty, no character available         */ 
#define  SCI_TX_FULL            3                /* Tx buffer is full, could not deposit character     */ 
#define  SCI_TX_EMPTY           4                /* If the Tx buffer is empty.                         */

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
 unsigned char  SCIGetCharB (unsigned char port, unsigned char *err);

/**  
 * To send a character on the communications channel.   
 * The character to send is first inserted into the Tx buffer and will be sent by  
 * the Tx ISR.  If this is the first character placed into the buffer, the Tx ISR will be  
 * enabled.  If the Tx buffer is full, the character will not be sent (i.e. it will be lost)  *
 * @param port, port can be SCI0 / SCI1  
 * @return   COMM_NO_ERR   if the function was successful (the buffer was not full)  
 *           COMM_TX_FULL  if the buffer was full  
 *           COMM_BAD_CH   if you have specified an incorrect channel  
 */ 
 unsigned char SCIPutCharB (unsigned char port, unsigned char c);

/**  
 * To initialize the communications module.  
 * You must call this function before calling any other functions.  
 */ 
 void  SCIBufferInit (void);

/**  
 * To see if any character is available from the communications channel.  
 *  
 * @param port, port can be SCI0 / SCI1  
 * @return   If at least one character is available, the function returns  
 *            FALSE(0) otherwise, the function returns TRUE(1).  
 */ 
 unsigned char  SCIBufferIsEmpty (unsigned char port);

/**  
  * To see if any more characters can be placed in the Tx buffer.  
  * In other words, this function check to see if the Tx buffer is full.  
  *  
  * @param port, port can be SCI0 / SCI1  
  * @return   If the buffer is full, the function returns TRUE  
  *           otherwise, the function returns FALSE.  
  */ 
  unsigned char SCIBufferIsFull (unsigned char port);

#endif