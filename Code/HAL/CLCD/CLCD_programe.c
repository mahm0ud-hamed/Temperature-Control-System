 /*************************************************************************/
 /*************************************************************************/
 /***********************  Author :Mahmoud Hamed    ***********************/
 /***********************       Layer :HAL          ***********************/
 /**********************         SWC :CLCD          ***********************/
 /***********************       Version :1.00       ***********************/
 /*************************************************************************/
 /*************************************************************************/

#include "../../SERVICE/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"




#define F_CPU 8000000UL
#include "util/delay.h"

/*function that send command to LCD */
void CLCD_vidSendCommand(u8 copy_u8Command)
{
	/*set rs pin to low for command */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	/*set R/W pin to 0 to active write */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	
	/*send upper half of command*/
	/*set command to data pins  */
	DIO_u8SetPortValue(CLCD_DATA_PORT,(copy_u8Command & 0xf0));//& 0xf0)
	/*send enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(1);
	/*set enable again to zero*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(1);
// 	/*send lower half of command*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,((copy_u8Command&0x0f)<<4));//& 0x0f)<<4
	/*send enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(1);
	/*set enable again to zero*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(1);
}

/*function that send data to display on LCD*/
void CLCD_vidSendData(u8 copy_u8Data)
{
	/*set rs pin to high  for data  */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	/*set R/W pin to 0 to active write */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	
	/*send upper half of data */
	/*set data to data pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT,(copy_u8Data&0xf0));//&0xf0)
	/*send enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(1);
	/*set enable again to zero*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(1);
 	/*send lower half of data */
	DIO_u8SetPortValue(CLCD_DATA_PORT,((copy_u8Data&0x0f)<<4));//&0xf0)<<4
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(1);
	/*set enable again to zero*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(1);
}

/*function that initialize LDC to work*/
void CLCD_vidInit(void)
{
	/*wait for more than 30 ms */
	_delay_ms(40);
	CLCD_vidSendCommand(FOUR_BITS_DATA_MODE);
	/*function set command 2 lines , 5*8 for font */
	 CLCD_vidSendCommand(TWO_LINE_LCD_Four_BIT_MODE);
	 
	 /*display on of control : display enable , disable cursor , to blink cursor */
	 CLCD_vidSendCommand(CURSOR_OFF);
	 
	 /*clear display */
	 CLCD_vidSendCommand(0X01); 
	 
}

void CLCD_vidSednString(const char* copy_pcString)
{
	u8 Local_u8StringCounter= 0 ;
	
	while(copy_pcString[Local_u8StringCounter]!='\0')
	{
		CLCD_vidSendData(copy_pcString[Local_u8StringCounter]);
		
		Local_u8StringCounter++;
	}
	
}

void CLCD_vidGoToXY(u8 copy_u8Xpos , u8 copy_u8Ypos)
{
	u8 Local_u8Adress =0;
	/*if location is on the first line */
	if (copy_u8Xpos== 0 )
	{
		Local_u8Adress = copy_u8Ypos ;
	}
	/*if location is on the second line */
	else if (copy_u8Xpos == 1)
	{
		Local_u8Adress = copy_u8Ypos+0x40 ;
	}
	/*add 128 to set the bit #8 by one because it must in data sheet */
	 CLCD_vidSendCommand(Local_u8Adress+128);
	
}

void CLCD_vidWriteSpecialCaracter(u8* copy_pu8Pattern , u8 copy_u8PatternNumber, u8 copy_u8Xpos , u8 copy_u8Ypos )
{
	// variable to carry CGRAM address
	u8 Local_u8CGRAM_Address = 0 ;
	u8 Local_u8Counter ;
	
	/*calculate the CGRAM address whose each block is 8 bytes*/
	Local_u8CGRAM_Address = copy_u8PatternNumber * 8 ;
	
	/*+64 to make bit number 6 by one to active accessing CGRAM*/
	CLCD_vidSendCommand(Local_u8CGRAM_Address+64);
	
	/*storing the needed pattern in CGRAM*/
	for(Local_u8Counter =0 ; Local_u8Counter < 8 ; Local_u8Counter++)
	{
		CLCD_vidSendData(copy_pu8Pattern[Local_u8Counter]);
	}
	
	/*back to DDRAM to display the pattern data on the screen */
	CLCD_vidGoToXY(copy_u8Xpos,copy_u8Ypos);
	
	/*display the pattern written in CGRAM */
	CLCD_vidSendData(copy_u8PatternNumber);
	
}

/*function to write  large number on LCD*/
// void CLCD_vidSendLargeNmber(u32 copy_u32Data)
// {
// 	u32 Local_u32Reserved=1;
// 	
// 	while(copy_u32Data!=0)
// 	{
// 		Local_u32Reserved=Local_u32Reserved*10 + copy_u32Data%10 ; 
// 		copy_u32Data/=10 ; 
// 	}
// 	do 
// 	{
// 		CLCD_vidSendData((Local_u32Reserved%10)+'0');
// 		Local_u32Reserved/=10;
// 	} while (Local_u32Reserved!=1);
// }

void CLCD_vidSendLargeNmber(u32 Copy_u32Num)
{
	u32 Revers_num = 0;
	u8 displayed_num = 0;
	u32 multiplier = 1, i = 0;
	if(Copy_u32Num == 0)
	{
		CLCD_vidSendData('0');
	}
	else if(Copy_u32Num < 0)
	{
		CLCD_vidSendData('-');
		Copy_u32Num *= -1;
	}
	
	while (Copy_u32Num != 0)
	{
		Revers_num = (Revers_num * 10) + Copy_u32Num % 10;
		if (Revers_num == 0)
		multiplier *= 10;
		Copy_u32Num /= 10;
	}
	while (Revers_num != i)
	{
		displayed_num = Revers_num % 10;
		CLCD_vidSendData(displayed_num + 48);   //48 -> '0'
		Revers_num/=10;
		if (Revers_num == 0 && multiplier >= 10)
		{
			i = 1;
			Revers_num = multiplier;
		}
	}
}

void CLCD_vidClearLcd(void)
{
	CLCD_vidSendCommand(CLEAR_SCREEN);
}