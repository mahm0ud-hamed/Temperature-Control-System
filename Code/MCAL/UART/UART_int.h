/*****************************************************************/
/*                      Author : Moamen Mamdouh Thabet           */
/*                      Date   : 16/11/2022                      */
/*                      Module : UART_init                       */
/*                      Layer  : MCAL                            */
/*                      Version:  1.0                            */
/*****************************************************************/


#ifndef UART_INT_H_
#define UART_INT_H_


void UART_voidInit(void);

void UART_voidSendByte(u8 Byte);

void UART_voidSendString(char Copy_u8Str[]);

u8 UART_u8ReceiveByte(void);

void UART_voidReceiveString(u8 Copy_u8Str[],u8 Copy_u8Size);
void UART_voidWriteNewLine(void);
u8 UART_u8_ReturnUDRValue(void);

void UART_void_SetCBReceive( void (*ptr) (void) );
void UART_void_SetCBSend( void (*ptr) (void) );



#endif /* UART_INT_H_ */
