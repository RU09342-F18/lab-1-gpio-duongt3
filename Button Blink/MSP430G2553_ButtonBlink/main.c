#include <msp430.h> 


/**
 * File: main.c
 * Author: Timothy Duong
 * Date Created: 9/18/18
 *
 * Used on MSP430G2553 using the button P1.6. When button is pressed, LED P1.0 will turn on and will remain off if button is not pressed.
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1SEL = 0;
	P1DIR |= 0x01;
	P1DIR &= ~BIT3;
	P1REN |= BIT3;

	int j;

	while(1){
	    j = P1IN&BIT3;
	    if(j != 8)
	    {
	        P1OUT ^= 0x01;
	    }
	    else
	    {
	        P1OUT &= ~BIT0;
	    }
	}

}
