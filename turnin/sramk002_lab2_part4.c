/*      Author: Sidharth Ramkumar (sramk002@ucr.edu)
 *       *       *  Partner(s) Name: none 
 *        *       *     Lab Section: 022
 *         *       *    Assignment: Lab #2  Exercise #4
 *          *       *   Exercise Description: [optional - include for your own benefit]
 *           *       *
 *            *       * I acknowledge all content contained herein, excluding template or example
 *             *               *        code, is my own original work.
 *              *               */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0x00; PORTB = 0xFF; // B's 8 pins as inputs
    DDRC = 0x00; PORTC = 0xFF; // C's 8 pins as inputs
    DDRD = 0xFF; PORTD = 0x00; //Configure port D's 8 pins as outputs, intializie to 0s
unsigned char tmpA = 0x00; //Temp val to hold A-C
unsigned char tmpB = 0x00;
unsigned char tmpC = 0x00;

unsigned char cartwght = 0x00; //Temporary variable to assign the value to D
unsigned short sumwght = 0x00;

    /* Insert your solution below */
    while (1) {
   tmpA = PINA;
   tmpB = PINB;
   tmpC = PINC;
   cartwght = 0x00;

sumwght = tmpA + tmpB + tmpC;
sumwght = sumwght / 4;


cartwght = sumwght;
cartwght = cartwght & 0xFC;

sumwght = tmpA + tmpB + tmpC;
if (sumwght > 0x8C){
   cartwght = cartwght |  0x01;
}

if ((tmpA - tmpC > 0x50) || (tmpC - tmpA > 0x50)){
   cartwght = cartwght | 0x02;
}

PORTD = cartwght;
}
    return 1;
}
