#include <hidef.h>      /* common defines and macros */   
#include "derivative.h"      /* derivative-specific definitions */   
#include  "sci.h"   
#include "sci_buffered.h"

void main(void)
{
	/* put your own code here */
	unsigned char C, err;
	long l = 0x1234L;
	int i = 0x5678;
	CRGInit ();
	SCIInit (SCI0);
	SCIInit (SCI1);
	SCIBufferInit();
	SCISetIEBit (SCI0, SCI_RIE);
	SCISetIEBit (SCI1, SCI_RIE);
	
	EnableInterrupts;
	SCIPutShortBigEndian (SCI1, i); 
    SCIPutShortLittleEndian (SCI1, i);
	SCIPutLongBigEndian (SCI1, l);
	SCIPutLongLittleEndian (SCI1, l);
	for(;;)
	{
		_FEED_COP(); /* feeds the dog */
		C = SCIGetCharB(SCI1, &err);
		if(err == SCI_NO_ERR)
		{
			SCIPutCharB(SCI1, C);
		}
	} /* loop forever */
	/* please make sure that you never leave main */
}