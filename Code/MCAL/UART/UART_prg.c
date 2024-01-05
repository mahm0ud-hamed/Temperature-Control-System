/*****************************************************************/
/*                      Author : Moamen Mamdouh Thabet           */
/*                      Date   : 16/11/2022                      */
/*                      Module : UART_prog                       */
/*                      Layer  : MCAL                            */
/*                      Version:  1.0                            */
/*****************************************************************/



#include "../../SERVICE/STD_TYPES.h"
#include "../../SERVICE/BIT_MATH.h"

#include "UART_int.h"
#include "UART_private.h"
#include "UART_config.h"

void (*CallBackReceive) (void) ;
void (*CallBackSend) (void) ;


void UART_void_SetCBReceive( void (*ptr) (void) )
{
	CallBackReceive = ptr ;
}

void UART_void_SetCBSend( void (*ptr) (void) )
{
	CallBackSend = ptr ;
}

u8 UART_u8_ReturnUDRValue(void)
{
	return UDR ;
}


void UART_voidInit(void)
{
	u8 Local_u8uCSRCVal=0;
	/*set bit 7 for UCsRC register select*/
	SET_BIT(Local_u8uCSRCVal,UCSRC_URSEL);
	/*Select 8-bit data frame*/
	CLR_BIT(UCSRB , UCSRB_UCSZ2) ;
	SET_BIT(Local_u8uCSRCVal ,UCSRC_UCSZ1) ;
	SET_BIT(Local_u8uCSRCVal ,UCSRC_UCSZ0) ;
	/*Select asynchronous mode*/
	CLR_BIT(Local_u8uCSRCVal , UCSRC_UMSEL);
	/*disable parity bit*/
	CLR_BIT(Local_u8uCSRCVal,UCSRC_UPM1);
	CLR_BIT(Local_u8uCSRCVal,UCSRC_UPM0);
	/*Choose one stop bit */
	CLR_BIT(Local_u8uCSRCVal , UCSRC_USBS);
	/*CLR clock polarity */
	CLR_BIT(Local_u8uCSRCVal , UCSRC_UCPOL);
	UCSRC=Local_u8uCSRCVal;
	/* select 9600 baud rate 16 Mhz*/
	UBRRH = 0 ; // write zero on the last bit to choose UBRRH
	UBRRL = B_9600 ;
	
	/*Enable rx and tx*/
	SET_BIT(UCSRB , UCSRB_RXEN) ;
	SET_BIT(UCSRB , UCSRB_TXEN) ;
	/*disable interrupt*/
	CLR_BIT(UCSRB , UCSRB_RXCIE);
	CLR_BIT(UCSRB , UCSRB_UDRIE);

}

void UART_voidSendByte(u8 Byte)
{
	while(GET_BIT(UCSRA , UCSRA_UDRE) == 0); // stuck here to check if flag is one to sure the UDR is empty
	UDR = Byte ;

}
void UART_voidWriteNewLine(void)
{
	UART_voidSendByte(NEW_LINE);
}
void UART_voidSendString(char Copy_u8Str[])
{
	u8 Local_u8Iteration = 0;
	while (Copy_u8Str[Local_u8Iteration] != '\0')
	{
		UART_voidSendByte(Copy_u8Str[Local_u8Iteration]);
		
		Local_u8Iteration++;
	}
}

u8 UART_u8ReceiveByte(void)
{

	while(GET_BIT(UCSRA , UCSRA_RXC) == 0);
	return UDR ;

}
void UART_voidReceiveString(u8 Copy_u8Str[],u8 Copy_u8Size)
{
	u8 Local_u8Iteration = 0;
    for (Local_u8Iteration=0;Local_u8Iteration<Copy_u8Size-1;Local_u8Iteration++)
    {
		while(GET_BIT(UCSRA , UCSRA_RXC) == 0);
		Copy_u8Str[Local_u8Iteration] = UDR ;
    }
	
}

void __vector_13(void) __attribute__((signal , used));
void __vector_13(void)
{
	CallBackReceive();
}

void __vector_14(void) __attribute__((signal , used));
void __vector_14(void)
{
	CallBackSend();
}
