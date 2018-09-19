#include <msp430.h> 


/**
 * File: main.c
 * Author: Timothy Duong
 * Date Created: 9/18/18
 *
 * Used on MSP430G2553 will blink LED P1.6 and LED 1.0 at two different rates.
 */
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1DIR |= 0x41;                            // Set P1.0 to output direction

  for (;;)
  {

  volatile unsigned int i;
  for(i = 0; i <= 50000; i++)
  {
      if((i % 3000) == 0) // Counts to 3000
      {
          P1OUT ^= 0x01;  // Toggle P1.0 using exclusive-OR
      }

      if((i % 4000) == 0) // Counts to 4000
      {
          P1OUT ^= 0x40; // Toggle P1.6 using exclusive-OR
      }
  }

  }
}
