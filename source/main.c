
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
    DDRB = 0x00; PORTB = 0xFF; // B's 8 pins as inputs
    DDRC = 0x00; PORTC = 0xFF; // C's 8 pins as inputs
    DDRD = 0xFF; PORTD = 0x00; //Configure port D's 8 pins as outputs, intializie to 0s
unsigned char tmpA = 0x00; //Temp val to hold A-C
unsigned char tmpB = 0x00; 
unsigned char tmpC = 0x00; 

unsigned char cartwght = 0x00; //Temporary variable to assign the value to D
unsigned char sumwght = 0x00;

    /* Insert your solution below */
    while (1) {
   tmpA = PINA;
   tmpB = PINB;
   tmpC = PINC;

sumwght = 0x00;
cartwght = 0x00;

//Exceeds 140kg and balanced
sumwght = tmpA + tmpB + tmpC;
 
if (sumwght > 0x8C){
   if ((tmpA ^ tmpB) == 0){
	if((tmpB ^ tmpC) == 0){
	cartwght = 0x01;
	}	
    }	 
}   

//Diff A and C exceeds 80kg
if ((tmpA - tmpC) > 0x50){
   cartwght = 0x02;
}

PORTD = cartwght; 
}
    return 1;
}
