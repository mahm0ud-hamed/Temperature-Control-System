 /************************************************************************/
 /************************************************************************/
 /***********************  Author :Mahmoud Hamed   ***********************/
 /***********************       Layer :MCAl        ***********************/
 /**********************         SWC :ADC         ***********************/
 /***********************       Version :1.00      ***********************/
 /************************************************************************/
 /************************************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_CH_0               0
#define ADC_CH_1			   1
#define ADC_CH_2			   2
#define ADC_CH_3			   3
#define ADC_CH_4			   4
#define ADC_CH_5			   5
#define ADC_CH_6			   6
#define ADC_CH_7			   7

void ADC_vidInit(void); 

u8 ADC_u8StartConversionSynch(u8 copy_u8Channel,u16 *copy_pu168Reading);
/*you must enable global interrupt before using function */
u8 ADC_u8SartConversionAsynch(u8 copy_u8Channel, u16 *copy_pu16Reading , void(*copy_pvNotficationFunc)(void));

#endif