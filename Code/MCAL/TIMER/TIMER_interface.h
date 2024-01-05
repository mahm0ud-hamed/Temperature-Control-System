/************************************************************************/
/************************************************************************/
/***********************  Author :Mahmoud Hamed   ***********************/
/***********************       Layer :MCAl        ***********************/
/**********************         SWC :TIMER         ***********************/
/***********************       Version :1.00      ***********************/
/************************************************************************/
/************************************************************************/


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/************TIMER0***********/

/*TIMER0 INITIALIZE*/
void TIMER0_vidInit(void);

/*TIMER0 set COMPARE MATCH REGISTRE VALUE */
void TIMER0_vidSetCompMatchValue(u8 copy_u8Value);

/*****************************/

/************TIMER1***********/

/*TIMER1 INITIALIZE*/
void TIMER1_vidInit(void);

/*TIMER1 set COMPARE MARCH REGISTER*/
void TIMER1_vidSetChannel_A_CompMatchValue(u16 Copy_u16ComValue);

/*TIMER1 INPUTCAPTURE REGISTER */
void TIMER1_vidSetInputCaptureValue(u16 copy_u16TopValue);

/*TIMER1 GET TIMER REGISTER VALUE*/
u16 TIMER1_u16ReadTimerValue(void);

/*TIMER1 SET TIMER REGISTER VALUE*/
void TIMER1_vidSetTimerValue(u16 copy_TimerValue);
/***********************************/

/*call back function to call ISR */
u8 TIMER_u8SetCallBack(void (*copy_CallBackFunc)(void));
#endif