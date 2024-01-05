/************************************************************************/
/************************************************************************/
/***********************  Author :Mahmoud Hamed   ***********************/
/***********************       Layer :MCAl        ***********************/
/*********************         SWC :TIMER         ***********************/
/***********************       Version :1.00      ***********************/
/************************************************************************/
/************************************************************************/


#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

/***************TIMER0 REGISTERS*********************/
/*timer0/counter0 register*/
#define TCNT0          *((volatile u8*)0x52)

/*TIMER0 control register */
#define TCCR0         *((volatile u8*)0x53)

#define TCCR0_COM00   4                     /*compare output mode FAST PWM*/
#define TCCR0_COM01   5                     /*compare output mode FAST PWM*/
#define TCCR0_WGM00   6						/*wave form generation mode bit0*/
#define TCCR0_WGM01   3						/*wave form generation mode bit1 */
#define TCCR0_CS02    2						/* prescaler bit2*/
#define TCCR0_CS01    1						/* prescaler bit1*/
#define TCCR0_CS00    0						/* prescaler bit0*/


/*output compare register 0 */
#define OCR0          *((volatile u8*)0x5c) 


/*timer mask interrupt mask register*/
#define TIMSK         *((volatile u8*)0x59)  

#define TIMSK_OCIE0   1						  /*output compare 0 interrupt enable */
#define TIMSK_TOIE0   0						  /*timer over flow interrupt enable*/


/*counter interrupt flag register*/
#define TIFR          *((volatile u8*)0x58);

#define TIFR_TOV0    0                       /* TIMER0 overflow flag*/
#define TIFR_OCF0    1                       /*output compare flag*/
/**********************************************************************/
/************** TIMER1 REGISTERS *****************/
/*TIMER1/COUNTER1 CONTROL REGISTER A*/
#define  TCCR1A		    *((volatile u8*)0x4f)
 
#define   TCCR1A_WGM10   0                    /*wave form generation mode bit*/
#define   TCCR1A_WGM11   1					 /*wave form generation mode bit*/
 
#define   TCCR1A_COM1A0 6                    /*compare output mode for compare unit*/
#define   TCCR1A_COM1A1 7					 /*compare output mode for compare unit*/


 
#define   TCCR1A_FOC1B 2
#define   TCCR1A_FOC1A 3

/*TIMER1/COUNTER1 CONTROL REGISTER B*/
#define  TCCR1B		    *((volatile u8*)0x4e)
#define  TCCR1B_CS10   0                    /*the three clock select bit used by timer 1 */
#define  TCCR1B_CS11   1					/*the three clock select bit used by timer 1 */
#define  TCCR1B_CS12   2					/*the three clock select bit used by timer 1 */

#define  TCCR1B_WGM12  3	                /*wave form generation mode bit*/
#define  TCCR1B_WGM13  4	 				/*wave form generation mode bit*/


/*INPUT CAPTURE REGISTER*/
#define ICR1       *((volatile u16 *)0x46)

/*TIMER1 COMPARE MATCH REGISTER */
#define OCR1A      *((volatile u16 *)0x4A) 

/*timer/counter1 register */
#define TCNT1      *((volatile u16 *)0x4C)
#endif