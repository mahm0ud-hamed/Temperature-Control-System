 /************************************************************************/
 /************************************************************************/
 /***********************  Author :Mahmoud Hamed   ***********************/
 /***********************       Layer :MCAl        ***********************/
 /**********************         SWC :ADC         ***********************/
 /***********************       Version :1.00      ***********************/
 /************************************************************************/
 /************************************************************************/
#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_
 
#define ADMUX              *((volatile u8*)0x27)  /*ADC multiplier selection register*/
#define ADMUX_REFS1        7                      // reference selection bit 1 
#define ADMUX_REFS0        6					  // reference selection bit  0 
#define ADMUX_ADLAR        5					  //  ADC left adgust result 
 
#define ADCSRA            *((volatile u8*)0x26)  /*ADC control and status register*/
#define ADCSRA_ADEN        7			          // ADC enable 
#define ADCSRA_ADSC		   6			          // start conversion 
#define ADCSRA_ADATE	   5			          // auto trigger enable
#define ADCSRA_ADIF		   4			          // interrupt flag
#define ADCSRA_ADIE		   3			          // interrupt enable 
#define ADCSRA_ADPS2	   2					  // prescaler bit2 
#define ADCSRA_ADPS1	   1					  //prescaler bit1
#define ADCSRA_ADPS0	   0                      //prescaler bit0
  			                
#define ADCH               *((volatile u8*)0x25)  // ADC high register

#define ADCL               *((volatile u8*)0x24)  // ADC low register

#define ADC                *((volatile u16*)0x24)  // ADC register

#endif