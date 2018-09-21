#include <msp430.h> 


/**
 * File: main.c
 * Author: Timothy Duong
 * Date Created: 9/18/18
 *
 * Used on MSP430FR2311 using the button P1.1. When button is pressed, LED P1.0 will blink and will remain off if button is not pressed.
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

	P1SEL0 = 0;         //Set P1.0 to 0
	P1SEL1 = 0;         //Set P1.1 to 0
	P1OUT &= ~BIT0;     //
    P1DIR |= 0x01;      //Set P1.0 as an output
    P1DIR &= ~BIT1;     //Set P1.1 as an input
    P1REN |= BIT1;      //Set the pullup resistor on P1.1
    P1OUT |= BIT1;      //Set the output for P1.1

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    int j;

    while(1){
        j = P1IN&BIT1;
        if(j != 2)
        {
            P1OUT ^= 0x01;
        }
        else
        {
            P1OUT &= ~BIT0;
        }
    }
}

