# Off Board Blink

![demo](MultipleBlink.gif)

Off Board Blink uses the MSP430G2553 processor and simulates the multiple blink lab on a breadboard. One LED blinks after a counter reaches 3000 and the second LED blinks after a counter reaches 4000.

Port1.0 and Port1.6 are connected to LEDs and resistors. VCC is connected to 3.3V and voltage sink is connected to ground. In addition, an RC circuit was placed on the reset pin. A 1 nF capacitor was placed between the reset pin and ground, and a 47k resistor placed between the reset pin and high voltage. This is to reduce the effect of noise on the circuit that would cause the reset pin to trigger.
