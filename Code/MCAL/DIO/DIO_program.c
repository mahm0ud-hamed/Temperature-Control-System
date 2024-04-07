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
	if(Copy_u8Pin<=DIO_u8PIN7 && Copy_u8Pin>=DIO_u8PIN )  // if pin number between 0 and 7 , its valid value 
	{
		if(Copy_u8Value == DIO_u8PIN_LOW ) // check if pin is low 
		{
			switch (Copy_u8Port) // check port 
			{
				case DIO_u8PORTA:CLR_BIT(PORTA,Copy_u8Pin);break; 
				case DIO_u8PORTB:CLR_BIT(PORTB,Copy_u8Pin);break;
				case DIO_u8PORTC:CLR_BIT(PORTC,Copy_u8Pin);break;
				case DIO_u8PORTD:CLR_BIT(PORTD,Copy_u8Pin);break;
				default:Local_u8ErroState = 1 ; 
				
			}
		}
			
		else if(Copy_u8Value == DIO_u8PIN_HIGH ) // check pin high 
		{
			switch (Copy_u8Port) // check port 
			{
					case DIO_u8PORTA:SET_BIT(PORTA,Copy_u8Pin);break;
					case DIO_u8PORTB:SET_BIT(PORTB,Copy_u8Pin);break;
					case DIO_u8PORTC:SET_BIT(PORTC,Copy_u8Pin);break;
					case DIO_u8PORTD:SET_BIT(PORTD,Copy_u8Pin);break;
					default:Local_u8ErroState = 1 ; 
					
			}
		}
		else  // if the selction is differ from high and low , function will return error 
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
	 switch(Copy_u8Port) // check port 
	 {
		 case DIO_u8PORTA : PORTA = Copy_u8Value ; break;  // asign value to port 
		 case DIO_u8PORTB : PORTB = Copy_u8Value ; break; 
		 case DIO_u8PORTC : PORTC = Copy_u8Value ; break; 
		 case DIO_u8PORTD : PORTD = Copy_u8Value ; break;
		 default: Local_u8ErroState = 1 ; break; // if port not exsist , return 1 as error status 
	 } 
	return Local_u8ErroState ; 
}// end of set port value function 


/*function to read pin value high or low */
u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_Pu8Value)
{
	u8 Local_u8ErroState = 0 ;  // error state variable to return function state 
	
	if((Copy_Pu8Value!= NULL) && (Copy_u8Pin <= DIO_u8PIN7)) // check that the passed adress not NULL , and pin in range 0f 0 -> 7
	{
		switch (Copy_u8Port)
		{
			case DIO_u8PORTA :*Copy_Pu8Value = GET_BIT(PINA,Copy_u8Pin); break; // return pin state on the address of varaiable 
			case DIO_u8PORTB :*Copy_Pu8Value = GET_BIT(PINB,Copy_u8Pin); break;
			case DIO_u8PORTC :*Copy_Pu8Value = GET_BIT(PINC,Copy_u8Pin); break;
			case DIO_u8PORTD :*Copy_Pu8Value = GET_BIT(PIND,Copy_u8Pin); break;
			default:Local_u8ErroState =1 ; 
		}
		
	}
	else 
	{
		Local_u8ErroState = 1; // return error if pin is not in range of 0->7 or adress passed to function is equal to NULL 
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

