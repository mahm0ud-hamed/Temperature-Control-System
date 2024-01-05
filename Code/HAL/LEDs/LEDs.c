 /************************************************************************/
 /************************************************************************/
 /***********************  Author :Mahmoud Hamed   ***********************/
 /***********************       Layer :HAL        ***********************/
 /**********************         SWC :LED         ***********************/
 /***********************       Version :1.00      ***********************/
 /************************************************************************/
 /************************************************************************/

#include "../../SERVICE/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LEDs_interface.h"



/*function to set led pin high  turn led on */
u8 LED_u8SetLedOn(u8 copy_u8LedPort , u8 copy_u8LedPin)
{
	u8 Local_u8ErroState = 0 ;
	if(copy_u8LedPin <= DIO_u8PIN7 && copy_u8LedPort <= DIO_u8PORTD)
	{
		DIO_u8SetPinValue(copy_u8LedPort,copy_u8LedPin,LED_u8PIN_HIGH);
	}// end of if
	else
	{
		Local_u8ErroState = 1 ;
	} // end of else
	
	return Local_u8ErroState ;
}// end of led set led on function


/*function to set led pin low turn led off */
u8 LED_u8SetLedOff(u8 copy_u8LedPort , u8 copy_u8LedPin)
{
	u8 Local_u8ErroState = 0 ;
	if(copy_u8LedPin <= DIO_u8PIN7 && copy_u8LedPort <= DIO_u8PORTD)
	{
		DIO_u8SetPinValue(copy_u8LedPort,copy_u8LedPin,DIO_u8PIN_LOW);
	}// end of if
	else
	{
		Local_u8ErroState = 1 ;
	} // end of else
	
	return Local_u8ErroState ;
}// end of set led of function 

/*function to toggle led pin */

u8 LED_u8ToggleLed(u8 copy_u8LedPort , u8 copy_u8LedPin)
{
	u8 Local_u8ErroState = 0 ;
	if(copy_u8LedPin <= DIO_u8PIN7 && copy_u8LedPort <= DIO_u8PORTD)
	{
		DIO_u8TogglePinValue(copy_u8LedPort , copy_u8LedPin ); 
	}// end of if
	else
	{
		Local_u8ErroState = 1 ;
	} // end of else
	
	return Local_u8ErroState ;
}//end of led state toggle function 


