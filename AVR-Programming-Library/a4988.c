
#include <avr/io.h>
#include <util/delay.h>
#include "a4988.h"

void initStepper(void){
	DDRD |= (1<<Enable) | (1<<dirPin) | (1<<stepPin);
	PORTD &= ~(1<<Enable);
}

void pulseC(int steps){
	int y;
	int uDelay = 475;
	PORTD |= (1<<dirPin);                //Make PORTD6 high to rotate motor in clockwise direction
	for(y=0; y<steps; y++){
		PORTD |=(1<<stepPin);
		_delay_us(uDelay);
		PORTD &=~(1<<stepPin);
		_delay_us(uDelay);
	}
}

void pulseCC(int steps){
	int y;	
	int uDelay = 475;	
	PORTD &= ~(1<<dirPin);              //Make PORTD6 high to rotate motor in anti-clockwise direction
	for(y=0; y<steps; y++){
		PORTD |=(1<<stepPin);
		_delay_us(uDelay);
		PORTD &=~(1<<stepPin);
		_delay_us(uDelay);
	}	
}

void stopPulse(void){
	PORTD |= _BV(Enable);
}
