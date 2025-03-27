/*
 * laboratorio6.c
 *
 * Created: 3/20/2025 8:52:20 PM
 * Author : njfg0
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include <string.h>
#include <stdint.h>
#include "com_uart/com_uart.h"



int main(void)
{
	cli();
	DDRB=0b00000000;
	PORTB=0b00000001;
	DDRD=0b00000000;
	PORTD=0b10000000;
	DDRC=0b00000000;
	PORTC=0b00001111;
	
	PCICR |=(1<<PCIE1)|(1 << PCIE2)|(1 << PCIE0);
	PCMSK1|=(1<<PCINT8)|(1<<PCINT9)|(1<<PCINT10)|(1<<PCINT11);
	PCMSK0 |= (1 << PCINT0);//D8
	PCMSK2 |= (1 << PCINT23);//D7
	initUART9600();
	sei();
    /* Replace with your application code */
    while (1) 
    {
    }
}

ISR(PCINT1_vect)
{
	if (!(PINC & (1 << PC0))) {  
			writetxtUART("Control Izquierda\n"); 
		} else if (!(PINC & (1 << PC1))) {  
			writetxtUART("Control Arriba\n");  
		} else if (!(PINC & (1 << PC2))) {  
			writetxtUART("Control Abajo\n"); 
		} else if (!(PINC & (1 << PC3))) {  
			writetxtUART("Control Derecha\n"); 
		}
}
ISR(PCINT2_vect)
{
	if (!(PIND & (1 << PD7))) {  
		writetxtUART("Control A\n"); 
	}
}
ISR(PCINT0_vect)
{
	if (!(PINB & (1 << PB0))) {  
		writetxtUART("Control B\n");  
	}
}