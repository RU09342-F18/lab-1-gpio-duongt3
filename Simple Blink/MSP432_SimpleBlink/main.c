#include "msp.h"


/**
 * File: main.c
 * Author: Timothy Duong
 * Date Created: 9/18/18
 *
 * Used on MSP432 to blink LED P1.0.
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	P1DIR |= 0x01;          //Sets P1.0 as output

	while(1)
	{
	    volatile unsigned int i;

	    P1OUT ^= 0x01;                          // Toggle P1.0 using exclusive-OR

	    i = 50000;                              // Delay
	    do (i--);
	    while (i != 0);
	}
}
