/************************************************************************/
/************************************************************************/
/***********************   Author :Mahmoud Mohamed Hame  ***********************/
/***********************       Layer :MCAl        ***********************/
/***********************         SWC :DIO         ***********************/
/***********************       Version :1.00      ***********************/
/************************************************************************/
/************************************************************************/

#ifndef DIO_REGISTERS_H_	
#define DIO_REGISTERS_H_
/* using volatile to tell processorr rvery time i need value get it from memory not from CPU register , don't make copy in CPU Register
   because it is a memory and every time processor will read it so its may make a copy of register in CPU registers */ 
/* MACROS of Register Address */
#define PORTA      *((volatile u8 *)0x3b) 
#define DDRA       *((volatile u8 *)0x3a) 
#define PINA       *((volatile u8 *)0x39)
								
#define PORTB	   *((volatile u8 *)0x38)
#define DDRB	   *((volatile u8 *)0x37)
#define PINB	   *((volatile u8 *)0x36)
										
#define PORTC	   *((volatile u8 *)0x35)
#define DDRC       *((volatile u8 *)0x34)
#define PINC       *((volatile u8 *)0x33)
										
#define PORTD      *((volatile u8 *)0x32)
#define DDRD       *((volatile u8 *)0x31)
#define PIND       *((volatile u8 *)0x30)



#endif 
