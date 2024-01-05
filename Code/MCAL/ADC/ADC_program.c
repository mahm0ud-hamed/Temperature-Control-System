 /************************************************************************/
 /************************************************************************/
 /***********************  Author :Mahmoud Hamed   ***********************/
 /***********************       Layer :MCAl        ***********************/
 /**********************         SWC :ADC         ***********************/
 /***********************       Version :1.00      ***********************/
 /************************************************************************/
 /************************************************************************/

#include "../../SERVICE/STD_TYPES.h"
#include "../../SERVICE/BIT_MATH.h"


#include "ADC_interface.h"
#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_config.h"


static u16 *ADC_pu16Reading=NULL ;
static void(*ADC_pvCallBackNotficationFunc)(void)= NULL;  

void ADC_vidInit(void)
{
	/*AVCC as reference voltage */
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	/*choose left adjust result */
	SET_BIT(ADMUX,ADMUX_ADLAR); 
	
	/*set prescaler to divide by 128*/
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS0);

	/*enable ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN); 
	
}

u8 ADC_u8StartConversionSynch(u8 copy_u8Channel, u16 *copy_pu168Reading)
{
	u32 Local_u32Counter=0; 
	u8 Local_u8ErrorState=0 ;
	/*u8  Local_u8ErrorState= Ok ; */
	
	/*Clear the MUX bits in ADMUX register*/
	ADMUX&=0b11100000; 
	/*set the required channel at ADMUX */
	ADMUX|=copy_u8Channel;
	/*start conversion*/
    SET_BIT(ADCSRA,ADCSRA_ADSC); 
	/*busy wait until the conversion complete flag is set  or reaching timeout*/
    while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0 && (Local_u32Counter!=ADC_u32TIME_OUT))  
	{
		Local_u32Counter++;
	}
	/*check the reason of while loop broken */
	if (Local_u32Counter == ADC_u32TIME_OUT)
	{
	  // loop is broken because timeout is reached 
	  Local_u8ErrorState = NOT_OK ; 
	}
	else
 	{
		/*loop is broken because flag is raised */
		
		/*clear the conversion complete flag*/
		SET_BIT(ADCSRA,ADCSRA_ADIF);
		/*return the reading value*/
		*copy_pu168Reading= ADCH ; 
    }
		return Local_u8ErrorState; 
	  
}

u8 ADC_u8SartConversionAsynch(u8 copy_u8Channel, u16 *copy_pu16Reading , void(*copy_pvNotficationFunc)(void))
{
	u8 Local_u8ErrorState =0 ; 
	if ((Local_u8ErrorState == NULL) || (copy_pvNotficationFunc==NULL))
	{
		return Local_u8ErrorState = NULL_POINTER ;
	}
	else
	{
		/*Initiate the reading variable globally*/
		ADC_pu16Reading = copy_pu16Reading ; 
		/*Initiate the Callback notification function globally */
		ADC_pvCallBackNotficationFunc=copy_pvNotficationFunc; 
		/*Clear the MUX bits in ADMUX register*/
		ADMUX&=0b11100000;
		/*set the required channel at ADMUX */
		ADMUX|=copy_u8Channel;
		/*start conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);
		/*ADC interrupt enable*/
		SET_BIT(ADCSRA,ADCSRA_ADIE);
		
	}
	return Local_u8ErrorState ; 
	
}
void __vector_16(void)__attribute__((signal));
void __vector_16(void)
{
	/*read ADC result*/
	*ADC_pu16Reading = ADCH; 
	/*Invoke Call back notification*/
	ADC_pvCallBackNotficationFunc();
	/*disable ADC conversion complete interrupt*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);  
}