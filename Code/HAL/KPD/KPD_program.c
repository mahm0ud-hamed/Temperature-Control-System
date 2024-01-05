 /************************************************************************/
 /************************************************************************/
 /***********************  Author :Mahmoud Hamed   ***********************/
 /***********************       Layer :HAL        ***********************/
 /**********************         SWC :KEY_PAD         ********************/
 /***********************       Version :1.00      ***********************/
 /************************************************************************/
 /************************************************************************/

#include "../../SERVICE/STD_TYPES.h"
#include "../CLCD/CLCD_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"


#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"

#define F_CPU 8000000UL
#include "util/delay.h"

extern u8 GLOBAL_u8SELECTOR ; 
u8 KPD_u8GetPressedKey(void)
{
	/*variable to return the pressed key */
	u8 Local_u8PressedKey= KPD_NO_PRESSED_KEY; 
	
	/*variable for iteration on columns of array*/
	u8 Local_u8ColumnIndx;
	
	/*variable for iteration on ROW OF array  */
	u8 Local_u8RowIndx;
	
	/*variable to store the row value if HIGH or LOW */
	u8 Local_u8RowState; 
	
	/*TWO dimensional array that stored the value of the key pad keys*/
	static u8 Local_u8KPDArr[ROW_NUM][COLUMN_NUM]=KPD_ARR_VAL ;
	
	/*one dimensional array to store number of columns*/
	static u8 Local_u8KPDColumnArr[COLUMN_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	
	/*one dimensional array to store number of rows */
	static u8 Local_u8KPDROWArr[ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
		
	/*TWO nested for loops the outer for loop iterate on columns and set the current column by zero 
	  and second loop to iterate on the row and check which one value is zero 
	  to determine the pressed KEY  */
	
	for (Local_u8ColumnIndx=0 ; Local_u8ColumnIndx<COLUMN_NUM ; Local_u8ColumnIndx++)
	{
		/*activate current column*/
		DIO_u8SetPinValue(KPD_COL_PORT,Local_u8KPDColumnArr[Local_u8ColumnIndx],DIO_u8PIN_LOW);
		/*go to check which row is equal to zero */
		for (Local_u8RowIndx=0 ; Local_u8RowIndx<ROW_NUM ; Local_u8RowIndx++)
		{
			/*read current Row*/
			DIO_u8GetPinValue(KPD_ROW_PORT,Local_u8KPDROWArr[Local_u8RowIndx],&Local_u8RowState);
		
			/*check switch is pressed or not */
			if (DIO_u8PIN_LOW==Local_u8RowState)
			{
				/*polling (busy waiting)until the pressed key is released */
				while(DIO_u8PIN_LOW==Local_u8RowState)
				{
					DIO_u8GetPinValue(KPD_ROW_PORT,Local_u8KPDROWArr[Local_u8RowIndx],&Local_u8RowState);
				}
				Local_u8PressedKey=Local_u8KPDArr[Local_u8RowIndx][Local_u8ColumnIndx];
				return Local_u8PressedKey ;
			}
		}
		
		/*deactivate the current columns*/
		DIO_u8SetPinValue(KPD_COL_PORT,Local_u8KPDColumnArr[Local_u8ColumnIndx],DIO_u8PIN_HIGH);
	}
	
	
	return Local_u8PressedKey ;
}

u8 KEYPAD_u8GetValue(void)
{
	u8 Local_u8Var=0,Sum=0;
	
	do
	{
		
		CLCD_vidSendLargeNmber(Sum);
		do
		{
			if (GLOBAL_u8SELECTOR=='0')
			{
				return 0; 
			}
			Local_u8Var = KPD_u8GetPressedKey();
		} while (Local_u8Var==0xff);
		if (Local_u8Var =='=')
		{
			return Sum;
		}
		else
		{
			Sum=(Sum*10+(Local_u8Var-'0'));
	
			CLCD_vidClearLcd();
		}
		
	}while(Local_u8Var!= '=');
	/*return Sum;*/
}