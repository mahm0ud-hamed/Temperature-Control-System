 /*************************************************************************/
 /*************************************************************************/
 /***********************  Author :Mahmoud Hamed    ***********************/
 /***********************       Layer :HAL          ***********************/
 /**********************         SWC :BUZZER          *********************/
 /***********************       Version :1.00       ***********************/
 /*************************************************************************/
 /*************************************************************************/


#include "../../SERVICE/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "BUZZER.h"

void BUZZER_ON(void)
{
	DIO_u8SetPinValue(BUZEER_PORT,BUZEER_PIN,DIO_u8PIN_HIGH);
}
void BUZZER_OFF(void)
{
	DIO_u8SetPinValue(BUZEER_PORT,BUZEER_PIN,DIO_u8PIN_LOW);
}
void BUZZER_TOGGLE(void)
{
	DIO_u8TogglePinValue(BUZEER_PORT,BUZEER_PIN);
}