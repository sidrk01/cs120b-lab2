
/*	Author: Sidharth Ramkumar (sramk002@ucr.edu)
 *	 *  Partner(s) Name: none 
 *	  *	Lab Section: 022
 *	   *	Assignment: Lab #2  Exercise #2
 *	    *	Exercise Description: [optional - include for your own benefit]
 *	     *
 *	      *	I acknowledge all content contained herein, excluding template or example
 *	       *	code, is my own original work.
 *	        */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRC = 0xFF; PORTC = 0x00; //Configure port C's 8 pins as outputs, intializie to 0s
unsigned char taken = 0x00;
unsigned char cntavail = 0x00; //Temporary variable to assign the value to C 
unsigned char tmpA = 0x00; //Temporary variable to hold A
    /* Insert your solution below */
    while (1) {
tmpA = PINA;
   taken = 0x00;

unsigned char i = 0x01;
while (i <= 0x08){
    if (tmpA & i){
    taken = taken + 1;
        }
i = i * 0x02;
}
        cntavail = 0x04 - taken;

PORTC = cntavail;
    }
    return 1;
}
