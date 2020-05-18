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
#include "timer.h"
#endif
enum States{start,init,power,wait,up,down} state;
unsigned char tmpA = 0x00;
unsigned char cnt = 0;
//unsigned char size = 8;
double arr[] ={261.63, 293.66,329.63,349.23,392.00,440.00,493.88,523.25}//PWM_on()i;
//volatile unsigned char TimerFlag = 0;
;
void Begin()
{
//unsigned char tmpA = 0x00;
//enum States{ Off, Press } state;
	unsigned char cnt1 = 0;
tmpA = ~PINA & 0x01;
	switch(state)
	{
//tmpA = ~PINA & 0x01;

	case start:
	state = init;
	break;
	case init:
	if(tmpA == 0x01)
	
	{ 
	cnt1++; state = power;
	}
	if(tmpA == 0x02)
	{state = up;}
	if(tmpA == 0x04)
	{state = down;
	}
	break;
	case power:
	state = init;
	break;
	case up:
	state = wait;
	break;
	case down:
	state = wait;
	break;

	case wait:
	if(tmpA == 0x02)
	state = up;
	if(tmpA == 0x04)
	state = down;
	else{state = init;}
	break;
	}
	switch(state)
	{
	case start:	
	break;
	case wait:	
	break;

	break;
	case init:
	break;
	case power:
	//tmpA = 0x00;
	if(cnt1 == 2)
	{PWM_off();}
	else{PWM_on();}
	break;

	break;
	case up:
	if((tmpA == 0x02) && (cnt<9))
	{
		
		set_PWM(arr[cnt]);
		cnt++;	
	}
	break;
	case down:
	if((tmpA == 0x04) && (cnt > 0))
	{
		
		set_PWM(arr[cnt]);
		cnt--;	
	}
	break;

}

int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00; PORTA = 0xFF;
DDRB = 0xFF; PORTB = 0x00;
state = start;
// PWM_off();
// PWM_on();
 /* Insert your solution below */
//unsigned char tmpA = 0x00;
//tmpA = ~PINA & 0x01;
TimerSet(1000);
TimerOn();  
  while (1) {
//PWM_on();
//state = Start;
Begin();
//PWM_on();
while(!TimerFlag) {}
	TimerFlag = 0;
//	tmpB = PORTB;
	//Begin();
	//PORTB = tmpB;
	}
    
//    return 1;
}
}
