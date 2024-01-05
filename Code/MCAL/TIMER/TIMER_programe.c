

/************************************************************************/
/************************************************************************/
/***********************  Author :Mahmoud Hamed   ***********************/
/***********************       Layer :MCAl        ***********************/
/**********************         SWC :TIMER         ***********************/
/***********************       Version :1.00      ***********************/
/************************************************************************/
/************************************************************************/

#include "../../SERVICE/STD_TYPES.h"
#include "../../SERVICE/BIT_MATH.h"


#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

/*static pointer to function */
static void (*TIMER0_pvCallBackFunc)(void)=NULL ; 

void TIMER0_vidInit(void)
{
// 	/*choose CTC mode*/
// 	CLR_BIT(TCCR0,TCCR0_WGM00);
// 	SET_BIT(TCCR0,TCCR0_WGM01);
    
	/*choose fast PWM mode*/
	 SET_BIT(TCCR0,TCCR0_WGM00);
	 SET_BIT(TCCR0,TCCR0_WGM01);
	
// 	/*output compare match interrupt enable*/	
// 	SET_BIT(TIMSK,TIMSK_OCIE0); 
	
    /*set compare match value 64*/
 	/*OCR0 =64 ;*/ 
	
	
	
	/*choose non inverted mode oc0 mode to
	                      set on top
						  clear on compare*/                 
	SET_BIT(TCCR0,TCCR0_COM01); 
	CLR_BIT(TCCR0,TCCR0_COM00);
	
	
	/*select prescaler division by 8 for duty cycle 25%*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
}

void TIMER0_vidSetCompMatchValue(u8 copy_u8Value)
{
	OCR0=copy_u8Value ;
}

u8 TIMER_u8SetCallBack(void (*copy_CallBackFunc)(void))
{
	u8 Local_u8ErrorStaus= 0 ;
	if (copy_CallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc= copy_CallBackFunc ; 
	}
	else
	{
		Local_u8ErrorStaus = 1 ; 
	}
	return Local_u8ErrorStaus ;
}


/*TIMER1 INITIALIZE*/
void TIMER1_vidInit(void)
{
	
	
   /*select normal mode,prescaler timer1 divide by 8 */
    CLR_BIT(TCCR1B,TCCR1B_CS10);
   	SET_BIT(TCCR1B,TCCR1B_CS11);
    CLR_BIT(TCCR1B,TCCR1B_CS12);
	
// 	select FAST PWM non inverting mode 	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
// 	SET_BIT(TCCR1A,TCCR1A_COM1A1);
// 	
// 	select WAVE GENERATION MODE with determination of 
// 	1- comp match value 
// 	2- top  timer value  	CLR_BIT(TCCR1A,TCCR1A_WGM10);
// 	SET_BIT(TCCR1A,TCCR1A_WGM11);
// 	SET_BIT(TCCR1B,TCCR1B_WGM12);
// 	SET_BIT(TCCR1B,TCCR1B_WGM13); 
// 	
// 	select prescaler divided by 8	CLR_BIT(TCCR1B,TCCR1B_CS10);
// 	SET_BIT(TCCR1B,TCCR1B_CS11);
// 	CLR_BIT(TCCR1B,TCCR1B_CS12); 
	

}

/*TIMER1 set COMPARE MAtCH REGISTER*/
void TIMER1_vidSetChannel_A_CompMatchValue(u16 Copy_u16ComValue)
{
	OCR1A=(u16)Copy_u16ComValue ; 
}

/*TIMER1 SET ICR1 INPUTCAPTURE REGISTER */
void TIMER1_vidSetInputCaptureValue(u16 copy_u16TopValue)
{
	ICR1 = (u16)copy_u16TopValue ; 
}

void TIMER1_vidSetTimerValue(u16 copy_TimerValue)
{
	TCNT1= copy_TimerValue; 
}

u16 TIMER1_u16ReadTimerValue(void)
{
	return TCNT1 ;
}


void __vector_10(void) __attribute__((signal)); 
void __vector_10(void) 
{
	if (TIMER0_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc(); 
	}
}






