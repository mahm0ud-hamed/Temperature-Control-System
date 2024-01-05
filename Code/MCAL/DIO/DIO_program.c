/************************************************************************/
/************************************************************************/
/***********************  Author :Mahmoud Hamed   ***********************/
/***********************       Layer :MCAl        ***********************/
/***********************         SWC :DIO         ***********************/
/***********************       Version :1.00      ***********************/
/************************************************************************/
/************************************************************************/

#include "../../SERVICE/STD_TYPES.h"
#include "../../SERVICE/BIT_MATH.h"

#include "DIO_config.h"
#include "DIO_registers.h"
#include "DIO_interface.h"
#include "DIO_private.h"




/* function to set pin value high or low */
u8 DIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	u8 Local_u8ErroState = 0 ;//return with value zero no error
	if(Copy_u8Pin<=DIO_u8PIN7)
	{
		if(Copy_u8Value == DIO_u8PIN_LOW )
		{
			switch (Copy_u8Port)
			{
				case DIO_u8PORTA:CLR_BIT(PORTA,Copy_u8Pin);break; 
				case DIO_u8PORTB:CLR_BIT(PORTB,Copy_u8Pin);break;
				case DIO_u8PORTC:CLR_BIT(PORTC,Copy_u8Pin);break;
				case DIO_u8PORTD:CLR_BIT(PORTD,Copy_u8Pin);break;
				default:Local_u8ErroState = 1 ; break;
				
			}
		}
			
		else if(Copy_u8Value == DIO_u8PIN_HIGH )
		{
			switch (Copy_u8Port)
			{
					case DIO_u8PORTA:SET_BIT(PORTA,Copy_u8Pin);break;
					case DIO_u8PORTB:SET_BIT(PORTB,Copy_u8Pin);break;
					case DIO_u8PORTC:SET_BIT(PORTC,Copy_u8Pin);break;
					case DIO_u8PORTD:SET_BIT(PORTD,Copy_u8Pin);break;
					default:Local_u8ErroState = 1 ; break;
					
			}
		}
		else 
		{
			Local_u8ErroState = 1 ; 
			
		}
		
	}
	return Local_u8ErroState ;
	
}// end of set pin value function 


/*function to set port value high or low */
u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value)
{
	u8 Local_u8ErroState = 0 ;
	 switch(Copy_u8Port)
	 {
		 case DIO_u8PORTA : PORTA = Copy_u8Value ; break; 
		 case DIO_u8PORTB : PORTB = Copy_u8Value ; break; 
		 case DIO_u8PORTC : PORTC = Copy_u8Value ; break; 
		 case DIO_u8PORTD : PORTD = Copy_u8Value ; break;
		 default: Local_u8ErroState = 1 ; break;
	 } 
	return Local_u8ErroState ; 
}// end of set port value function 


/*function to read pin value high or low */
u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_Pu8Value)
{
	u8 Local_u8ErroState = 0 ; 
	
	if((Copy_Pu8Value!= NULL) && (Copy_u8Pin <= DIO_u8PIN7))
	{
		switch (Copy_u8Port)
		{
			case DIO_u8PORTA :*Copy_Pu8Value = GET_BIT(PINA,Copy_u8Pin); break; 
			case DIO_u8PORTB :*Copy_Pu8Value = GET_BIT(PINB,Copy_u8Pin); break;
			case DIO_u8PORTC :*Copy_Pu8Value = GET_BIT(PINC,Copy_u8Pin); break;
			case DIO_u8PORTD :*Copy_Pu8Value = GET_BIT(PIND,Copy_u8Pin); break;
			default:Local_u8ErroState =1 ; 
		}
		
	}
	else 
	{
		Local_u8ErroState = 1; 
	}
	return Local_u8ErroState ; 
	

}// end of get pin value function 


/*function to toggle a pin */
u8 DIO_u8TogglePinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 Local_u8ErroState =0 ; 
	if(Copy_u8Pin<= DIO_u8PIN7)
	{
		switch(Copy_u8Port)
		{
				case DIO_u8PORTA : TOGGLE_BIT(PORTA,Copy_u8Pin); break;
				case DIO_u8PORTB : TOGGLE_BIT(PORTB,Copy_u8Pin); break;
				case DIO_u8PORTC : TOGGLE_BIT(PORTC,Copy_u8Pin); break;
				case DIO_u8PORTD : TOGGLE_BIT(PORTD,Copy_u8Pin); break;
				default: Local_u8ErroState =1 ;break;
		}
	
	}
	return Local_u8ErroState ; 
	
}// end of toggle pin value function 

