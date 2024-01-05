 /*************************************************************************/
 /*************************************************************************/
 /***********************  Author :Mahmoud Hamed    ***********************/
 /***********************     Layer :APP            ***********************/
 /******************** SWC :TEMP_CTRL_SYSTE_EEPROM_STORE ******************/
 /***********************       Version :1.00       ***********************/
 /*************************************************************************/
 /*************************************************************************/


#include "../../SERVICE/STD_TYPES.h"
#include "../../MCAL/I2C/i2c_MT.h"
#include "../../HAL/EEPROM/EEPROM_MT.h"
#include "../../HAL/CLCD/CLCD_interface.h"
#include "../../HAL/KPD/KPD_interface.h"

#include "EEPROM_STORE.h"

#define F_CPU 8000000UL 
#include <util/delay.h>
extern u8 GLOBAL_u8SELECTOR ; 


void STORE_voidTEMPRATURE(void)
{
     static volatile u8 copy_TempHigh=0, copy_TempLow=0,tempr;

	do
	{
		CLCD_vidClearLcd();
		
		CLCD_vidSednString("ENTER HIGH TEMP");  // LCD display string
		copy_TempHigh= KEYPAD_u8GetValue();     // key pad get value from user
		CLCD_vidGoToXY(LCD_ROW2,LCD_COL1);
		CLCD_vidSednString("ENTER LOW TEMP");
		copy_TempLow= KEYPAD_u8GetValue();
	    CLCD_vidSendLargeNmber(copy_TempLow); 
		EEPROM_write(BY_PASS_TEMP,EEPROM_ADRESS,copy_TempLow);
		
		if (GLOBAL_u8SELECTOR=='0')             /*check if interrupt has done */
		{
			GLOBAL_u8SELECTOR='1';              /*return to the main_menu*/
			break;
		}
		
       /*display the given high,low temp on  screen */
		CLCD_vidClearLcd();
		CLCD_vidSednString("HIGH_TEMP= ");
		CLCD_vidSendLargeNmber(copy_TempHigh);
		CLCD_vidGoToXY(LCD_ROW2,LCD_COL1);
		CLCD_vidSednString("LOW_TEMP= ");
		CLCD_vidSendLargeNmber(copy_TempLow);
		_delay_ms(500); 
		
     	/*check if low > high that will not accept the opertaion */
		if (copy_TempHigh<=copy_TempLow)
		{
			CLCD_vidClearLcd(); 
			CLCD_vidGoToXY(LCD_ROW1,LCD_COL8);
			CLCD_vidSednString(" WRONG! ");
			CLCD_vidGoToXY(LCD_ROW2,LCD_COL1);
			CLCD_vidSednString("ENTER T_H > T_L");
			_delay_ms(500);
		}
	   /*check if low <high that will  accept the opertaion */
		else
		{
			
			EEPROM_write( HIGH_TEMP_u8LOCATION,HIGH_TEMP_u8ADRESS,copy_TempHigh);
			_delay_ms(100);
			EEPROM_write( LOW_TEMP_u8LOCATION, LOW_TEMP_u8ADRESS,copy_TempLow);
			CLCD_vidClearLcd();
			CLCD_vidSednString("STORE SUCCSSES");
			_delay_ms(500);
			CLCD_vidClearLcd();
		}
		
	} while (copy_TempHigh<=copy_TempLow);
	
	 
	
}

void READ_STOR_voidTEMPARTURE(void)
{
	/*local variables to store value from EEPROM */
	 u8 Local_High , Local_LOW , tempr ; 
	
	/*GET the value stored on EEPORM AND SAVE it ON variable*/
	Local_High = EEPROM_READ(HIGH_TEMP_u8LOCATION,HIGH_TEMP_u8ADRESS);
	Local_LOW = EEPROM_READ(BY_PASS_TEMP,LOW_TEMP_u8ADRESS);
	
	/*Display the stored VALUES on screen */
	CLCD_vidClearLcd();
	CLCD_vidSednString("TEMP_HIGH= "); 
	CLCD_vidSendLargeNmber(Local_High);
	_delay_ms(50);
	CLCD_vidGoToXY(LCD_ROW2,LCD_COL1); 
	CLCD_vidSednString("TEMP_LOW= "); 
	CLCD_vidSendLargeNmber(Local_LOW);
	_delay_ms(1000);
	CLCD_vidClearLcd();
}
