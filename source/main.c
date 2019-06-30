/*	Author: zzhan171
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
#endif
enum States{start, offrelease, offpress, onrelease, onpress  } state;
unsigned char button0;
void botton_tick(){
        button0 = PINA & 0x01;
        switch(state){
                case start:
                        state = offrelease;
                        break;
                case offrelease:
                        if(botton == 0x01){
                                state = onpress;
                        }
                        else{
                                state = offrelease;
                        }
			break;
		case onpress:
			if(botton == 0x01;){
				state = onpress;
			}
			else{
				state = onrelease;
			}
			break;
		case onrelease:
			if(botton = 0x01){
				state = offpress;
			}
			else{
				state = onrelease;
			}
			break;
		case offpress:
			if(botton == 0x01){
				state = offpress;
			}
			else{
				state = offrelease;
			}
			break;
	}
	switch(state){
		case start:
			break;
		case offrelease:
			tempB = 0x01;
			break;
		case onpress:
			tempb = 0x02;
			break;
		case onrelease:
			tempb = 0x02;
			break;
		case offpress:
			tempb = 0x01;
			break;
	}
}
int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTC = 0x00;
	state = start;
	tempb = 0x01;
    while (1) {
	button_tick();
	PORTC = tempc;
    }
    return 1;
}
