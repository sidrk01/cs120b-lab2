/*	Author: sramk002
 *  Partner(s) Name: none 
 *	Lab Section: 022
 *	Assignment: Lab #2  Exercise #0
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRC = 0xFF; PORTC = 0x00; //Configure port C's 8 pins as outputs, intializie to 0s
unsigned char shiftBit = 0x00;
unsigned char i = 0x00;
unsigned char cntavail = 0x00; //Temporary variable to assign the value to C 
unsigned char tmpA = 0x00; //Temporary variable to hold A
    /* Insert your solution below */
    while (1) {
    tmpA = PINA & 0x0F;

    while (i < 4){
	shiftBit = tmpA >> i;
	shiftBit = shiftBit & 0x01;

	if (shiftBit == 0x01){
	cntavail = cntavail + 1;
}
i = i + 1;
}
PORTC = cntavail;

    }
    return 0;
}
