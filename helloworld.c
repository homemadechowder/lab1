//simple program
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void delay(int v) {
	int c, d;
	int max;
	max = 1000 * v;
	for(c = 1; c <= max; c++)
		for(d = 1; d <= 327; d++)
		{}
	return 0;
}

int main(void) {
	volatile int * led            = (int * )0xFF200040;		// LEDR
	volatile int * switchptr      = (int * )0xFF200030;		// SW
	volatile int * h3_h0	      = (int * )0xFF200020;		// HEX3_HEX0
	volatile int * h5_h4		  = (int * )0xFF200010;		// HEX5_HEX4
	volatile int * pushbutton     = (int * )0xFF200000;		// KEY
	
	
	
	int del = 5;
	int ret = 0;
	int FSM = 0;
	int pattern = 0; // choose between LED patterns; pattern=0 is HELLO WORLD, pattern=1 is II
	
	while(1)
	{	
		if(*(switchptr) == 0) // Hello world
		{
			*(led)= 0x0;
			
			
			switch(*(pushbutton)) {
				case(1):	// Toggle between HELLO WOLRD and LED pattern
					FSM = 0;
					if (pattern==0)
						pattern=1;
					else
						pattern=0;
					break;
				case(2):	// del++
					if (del <= 10)
						del++;
					break;
				case(4):	// del--
					if (del >= 2)
						del--;
					break;
				case(8):	// pause - un-pause
					if (FSM == 32) // unpause
						FSM = 0;
					else			// pause
						ret = FSM;
						FSM = 32;
					break;
				
			} // end switch()
			
			
			
			// Scrolling HELLO UUORLD FSM
			if(pattern==0){
				switch(FSM) {
				case(0):
				*(h3_h0) = 0x00000076;
				*(h5_h4) = 0x0000;
				FSM++;
				break;
				case(1):
				*(h3_h0) = 0x00007679;
				*(h5_h4) = 0x0000;
				FSM++;
				break;
				case(2):
				*(h3_h0) = 0x00767938;
				*(h5_h4) = 0x0000;
				FSM++;
				break;
				case(3):
				*(h3_h0) = 0x76793838;
				*(h5_h4) = 0x0000;
				FSM++;  
				break;
				case(4):
				*(h3_h0) = 0x7938383F;
				*(h5_h4) = 0x0076;
				FSM++;  
				break;
				case(5):
				*(h3_h0) = 0x38383F00;
				*(h5_h4) = 0x7679;
				FSM++;  
				break;
				case(6):
				*(h3_h0) = 0x383F003E;
				*(h5_h4) = 0x7938;
				FSM++;  
				break;
				case(7):
				*(h3_h0) = 0x3F003E3E;
				*(h5_h4) = 0x3838;
				FSM++;  
				break;
				case(8):
				*(h3_h0) = 0x003E3E3F;
				*(h5_h4) = 0x383F;
				FSM++;  
				break;
				case(9):
				*(h3_h0) = 0x3E3E3F50;
				*(h5_h4) = 0x3F00;
				FSM++;  
				break;
				case(10):
				*(h3_h0) = 0x3E3F5038;
				*(h5_h4) = 0x003E;
				FSM++;  
				break;
				case(11):
				*(h3_h0) = 0x3F50385E;
				*(h5_h4) = 0x3E3E;
				FSM++;  
				break;
				case(12):
				*(h3_h0) = 0x50385E00;
				*(h5_h4) = 0x3E3F;
				FSM++;  
				break;
				case(13):
				*(h3_h0) = 0x385E0000;
				*(h5_h4) = 0x3F50;
				FSM++;  
				break;
				case(14):
				*(h3_h0) = 0x5E000000;
				*(h5_h4) = 0x5038;
				FSM++;  
				break;
				case(15):
				*(h3_h0) = 0x00000000;
				*(h5_h4) = 0x385E;
				FSM++;  
				break;
				case(16):
				*(h3_h0) = 0x00000000;
				*(h5_h4) = 0x5E00;
				FSM++;  
				break;
				case(17):
				*(h3_h0) = 0x00000000;
				*(h5_h4) = 0x0000;
				FSM = 0;  
				break;

				case(32):
				delay(2);
				if (*(pushbutton) == 8)
					FSM = ret;
				break;

				default:
				FSM = 0;
				break;
			}
			}
			
			// Scrolling LED pattern 2
			if(pattern==1){
				switch(FSM) {
				case(0):
				*(h3_h0) = 0x00000470;
				*(h5_h4) = 0x0000;
				FSM++;
				break;
				case(1):
				*(h3_h0) = 0x00047000;
				*(h5_h4) = 0x0000;
				FSM++;
				break;
				case(2):
				*(h3_h0) = 0x04700000;
				*(h5_h4) = 0x0000;
				FSM++;
				break;
				case(3):
				*(h3_h0) = 0x70000000;
				*(h5_h4) = 0x0004;
				FSM++;  
				break;
				case(4):
				*(h3_h0) = 0x00000000;
				*(h5_h4) = 0x0470;
				FSM++;  
				break;
				case(5):
				*(h3_h0) = 0x00000004;
				*(h5_h4) = 0x7000;
				FSM=0;  
				break;
				case(32):
				delay(2);
				if (*(pushbutton) == 8)
					FSM = ret;
				break;

				default:
				FSM = 0;
				break;
				}
			
			}
			delay(del);
			
		} else {	// Part 2
			// Reset HELLO WORLD vars
			FSM = 0;
			pattern = 0;
			del = 5;
		
			*(h3_h0) = 0x0; 		// Turns off H3-H0
			*(h5_h4) = 0x0; 		// Turns off H5_H4
			*(led)=*(switchptr);	
			
		}
	}
}	
