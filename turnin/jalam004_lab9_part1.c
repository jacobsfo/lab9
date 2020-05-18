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
enum States{ Start, Off, Press } state;
void Ex1(){
unsigned char tmpA = 0x00;
//enum States{ Off, Press } state;
tmpA = ~PINA & 0x01;
switch(state)
{
case Start:
state = Off;
case Off:
if((tmpA == 0x00) || (tmpA == 0x03) || (tmpA == 0x05) || (tmpA == 0x06) )
state = Off;
else {state = Press;}
break;
case Press:
if((tmpA == 0x01) ||( tmpA == 0x02) || (tmpA = 0x04) )
state = Press;
else {state = Off;}
break;
}

switch(state)
{
case Start:
break;
case Off:
set_PWM(0);
break;
case Press:
if(tmpA == 0x01)
set_PWM(261.63);
if(tmpA == 0x02)
set_PWM(293.66);
if(tmpA == 0x04)
set_PWM(329.63);
break;
}


}
int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00; PORTA = 0xFF;
DDRB = 0x40; PORTB = 0x00;
 state = Start;
   /* Insert your solution below */
//unsigned char tmpA = 0x00;
//tmpA = ~PINA & 0x01;
    while (1) {
PWM_on();
//state = Start;
Ex1();

    }
    return 1;
}
