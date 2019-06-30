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
unsigned char button;
unsigned char tempb;
void button_tick(){
        button = PINA & 0x01;
        switch(state){
                case start:
                        state = offrelease;
                        break;
                case offrelease:
                        if(button == 0x01){
                                state = onpress;
                        }
                        else{
                                state = offrelease;
                        }
			break;
		case onpress:
			if(button == 0x01){
				state = onpress;
			}
			else{
				state = onrelease;
			}
			break;
		case onrelease:
			if(button == 0x01){
				state = offpress;
			}
			else{
				state = onrelease;
			}
			break;
		case offpress:
			if(button == 0x01){
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
			tempb = 0x01;
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
	PORTB = tempb;
}
int main() {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTC = 0x00;
	state = start;
	
    while (1) {
	button_tick();

    }
    return 1;
}
