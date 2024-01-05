/************************************************************************/
/************************************************************************/
/***********************  Author :Mahmoud Hamed   ***********************/
/***********************       Layer :MCAl        ***********************/
/**********************         SWC :PORT         ***********************/
/***********************       Version :1.00      ***********************/
/************************************************************************/
/************************************************************************/

#include "../../SERVICE/STD_TYPES.h"
#include "../../SERVICE/BIT_MATH.h"


#include "PORT_interface.h"
#include "PORT_register.h"
#include "PORT_config.h"
#include "PORT_private.h"

void PORT_vidInit(void)
{
	/*set direction of all ports INPUT or OUTPUT*/
	 DDRA=PORTA_DIR;
	 
	 DDRB=PORTB_DIR;
	 
	 DDRC=PORTC_DIR;
	 
	 DDRD=PORTD_DIR;
	 
	 /*set value of all ports HIGH or LOW*/
	 PORTA=PORTA_INITIAL_VALUE;
	 
	 PORTB=PORTB_INITIAL_VALUE;
	 
	 PORTC=PORTC_INITIAL_VALUE;
	 
	 PORTD=PORTD_INITIAL_VALUE;
	
}