/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#include "freq.h"
#endif
enum States{ Start, Press } state;
unsigned char tmpA = 0x00;
//PWM_on();

void Ex1()
{
//unsigned char tmpA = 0x00;
//enum States{ Off, Press } state;
	tmpA = ~PINA & 0x01;
	switch(state)
	{
//tmpA = ~PINA & 0x01;

	case Start:
	state = Press;
	case Press:
	state = Press;	
	break;
	}

	switch(state)
	{
	case Start:
	
	break;
	
	break;
	case Press:
	if(tmpA == 0x01)
	set_PWM(261.63);
//PWM_on();
	
	if(tmpA == 0x02)
	set_PWM(293.66);
//PWM_on();
	if(tmpA == 0x04)
	set_PWM(329.63);
	
	else{set_PWM(0);}
//PWM_on();
	break;
	}


}
int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00; PORTA = 0xFF;
DDRB = 0xFF; PORTB = 0x00;
PWM_on(); 
state = Start;
// PWM_off();
// PWM_on();
 /* Insert your solution below */
//unsigned char tmpA = 0x00;
//tmpA = ~PINA & 0x01;
    while (1) {
//PWM_on();
//state = Start;
Ex1();
//PWM_on();
    }
    return 1;
}
