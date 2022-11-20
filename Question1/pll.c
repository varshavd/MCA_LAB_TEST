#include "pll.h"
#include <LPC214x.h>

void init_pll() 
	{
		PLL0CON = 0x01;
		PLL0CFG = 0x24;
		PLL0FEED =0xaa;
		PLL0FEED =0x55;
		while(!(PLL0STAT & (1<<10)));
		PLL0CON =0X03;
		PLL0FEED =0xaa;
		PLL0FEED =0x55;
		VPBDIV =0x01;
		
	}
		
	