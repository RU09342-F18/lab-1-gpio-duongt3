#include <msp430.h> 


/**
 * File: main.c
 * Author: Timothy Duong
 * Date Created: 9/18/18
 *
 * Used on MSP430F5529 to blink LED P1.0 and LED P1.4 at two different rates
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1SEL = 0;              //Set P1.0 = 0
	P4SEL = 0;              //Set P1.4 = 0

	P1DIR |= 0x01;                            // Set P1.0 to output direction
	P4DIR |= 0x80;                            // Set P1.0 to output direction

	for (;;)
	{

    volatile unsigned int i;
    for(i = 0; i <= 50000; i++)
    {
        if((i % 3000) == 0) //Counts to 3000
        {
            P1OUT ^= 0x01;  // Toggle P1.0 using exclusive-OR
        }

        if((i % 4000) == 0) //Counts to 4000
        {
            P4OUT ^= 0x80;  //Toggle P1.4 using exclusive-OR
        }
    }

	}
}
