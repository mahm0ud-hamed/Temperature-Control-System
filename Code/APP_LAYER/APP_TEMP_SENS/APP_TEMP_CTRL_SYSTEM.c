 /*************************************************************************/
 /*************************************************************************/
 /***********************  Author :Mahmoud Hamed    ***********************/
 /***********************       Layer :APP          ***********************/
 /**********************   SWC :TEMP_CTRL_SYSTE     ***********************/
 /***********************       Version :1.00       ***********************/
 /*************************************************************************/
 /*************************************************************************/



#include "../../SERVICE/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "../../MCAL/PORT/PORT_interface.h"		 // MCAL_LAYER
#include "../../MCAL/ADC/ADC_interface.h"		 // MCAL_LAYER
#include "../../MCAL/EXTI/EXTI_interface.h"		 // MCAL_LAYER
#include "../../MCAL/GIE/GIE_interface.h"		 // MCAL_LAYER
#include "../../MCAL/TIMER/TIMER_interface.h"	 // MCAL_LAYER
#include "../../MCAL/UART/UART_int.h"

#include "../../HAL/CLCD/CLCD_interface.h"      //HAL_LAYER
#include "../../HAL/KPD/KPD_interface.h"       //HAL_LAYER
#include "../../HAL/LEDs/LEDs_interface.h" 
#include "../../HAL/BUZZER/BUZZER.h"

#include "../APP_EEPROM/EEPROM_STORE.h"
#include "APP_TEMP_CTRL_SYSTEM.h"

#define F_CPU 8000000UL          // MICRO_CONFIG 
#include "util/delay.h"			 // MICRO_CONFIG 



#define TEMP_STORED_HIGH        EEPROM_READ(HIGH_TEMP_u8LOCATION,HIGH_TEMP_u8ADRESS) /*read value of high and low temp from EEPROm*/
#define TEMP_STORED_LOW			EEPROM_READ(BY_PASS_TEMP,LOW_TEMP_u8ADRESS)			 /*read value of high and low temp from EEPROm*/


#define HIG_MODE      1   /*macros for operating modes */
#define NORMAL_MODE   2   /*macros for operating modes */
#define LOW_MODE      3	  /*macros for operating modes */

 

 u8 GLOBAL_u8SELECTOR='0'; // global variable to store choose from main menu
 u8 Local_Uart_state = 0 ;  // global variable to store current operating mode
 u8 Local_Uart_check = 0 ;  // global variable to store last operating mode

// volatile u8 TEMP_STORED_HIGH = EEPROM_READ(HIGH_TEMP_u8LOCATION,HIGH_TEMP_u8ADRESS);/*read value of high and low temp from EEPROm*/
// volatile u8 TEMP_STORED_LOW  = EEPROM_READ(BY_PASS_TEMP,LOW_TEMP_u8ADRESS);		 /*read value of high and low temp from EEPROm*/

void TEMP_CTRL_SYSTEM_INIT(void)
{
	PORT_vidInit();     //ALL MC PORT INITIALIZE 
	
	CLCD_vidInit();     // initialize LCD
	
	GIE_vidEnable();    // ENABLE GENERAL INTERRUPT 
	 
	TIMER0_vidInit();   // INITIALIZE TIMER0
	
	EXTI_vidInt0Init(); // INITIALIZE EXTI0
	
	UART_voidInit();    // INITIALIZE UART 
	
	ADC_vidInit();      // INITIALIZE ANALOG TO DIGITAL CONVERTER
	
	EXTI_u8Int0SetCallBack(MAIN_MENU_ISR);   // call back function of EXTI0 
	
	
	
	SET_MOTOR_SPEED(MOTOR_STOP);             // start first time with motor stop
	LED_u8SetLedOff(LED_PORT,LED_HIGH);      // start first time with status led off 
	LED_u8SetLedOff(LED_PORT,LED_NORMAL);	 // start first time with status led off 
	LED_u8SetLedOff(LED_PORT,LED_LOW);		 // start first time with status led off 
	BUZZER_OFF();							 // start first time BUZZER stop
}

void START_MASSAGE(void)
{
	
	/*send start massage with UART*/
	UART_voidSendString("NTI_AVR_PROJECTI");
	UART_voidWriteNewLine(); 
	UART_voidSendString("TEMPERATURE CONTROL SYSTEM ");
	UART_voidWriteNewLine();
	UART_voidSendString("un_sp ENG/Mohamed taha"); 
	UART_voidWriteNewLine();
	CLCD_vidClearLcd(); 
	CLCD_vidGoToXY(0,2); 
	CLCD_vidSednString("NTI_AVR_PROJECT");
	CLCD_vidGoToXY(1,2);  
	CLCD_vidSednString("ENG:Mhmoud_Hamed"); 
	_delay_ms(300); 
	CLCD_vidClearLcd();
	CLCD_vidGoToXY(0,2); 
	CLCD_vidSednString("TEMP_CTRL_SYSTEM");
	CLCD_vidGoToXY(LCD_ROW2,LCD_COL1); 
	CLCD_vidSednString("sp_ENG/Mohamed_Taha");
	_delay_ms(300); 
	CLCD_vidClearLcd(); 
}

void MAIN_MENUE(void)
{
	u8 Local_u8Up_Down=0 ; /*local variable to select screen up and down moving*/
	CLCD_vidClearLcd();

		do
		{
			do
			{
				/*wait untill get key from usre */
				CLCD_vidGoToXY(0,0);
				CLCD_vidSednString("1- START");
				CLCD_vidGoToXY(1,0);
				CLCD_vidSednString("2- ENTER_NEW_H&L_TEMP");
				Local_u8Up_Down=KPD_u8GetPressedKey();
			} while (Local_u8Up_Down==0xff);
			
			/*check if key = '+'*/
			if ('+'== Local_u8Up_Down )
			{
				/*screen will scroll down */
				CLCD_vidClearLcd();
				CLCD_vidSednString("3- SHOW CUREENT TEMP");
				_delay_ms(100);
				Local_u8Up_Down=KPD_u8GetPressedKey();
				
			}
			/*check if key = '-'*/
			else if ('-'== Local_u8Up_Down)
			{
				/*screen will scroll up */
				CLCD_vidClearLcd();
				CLCD_vidGoToXY(0,0);
				CLCD_vidSednString("1- START");
				CLCD_vidGoToXY(1,0);
				CLCD_vidSednString("2-ENTER_NEW_H&L_TEMP");
				Local_u8Up_Down = KPD_u8GetPressedKey();
			}
			/*check if key = '1' go start the sensor comparing and take action  */
			else if ('1'== Local_u8Up_Down)
			{
				GLOBAL_u8SELECTOR = '1'; 
				return; 
			}
			/*check if key = '2' go enter new high& low temperature */
			else if ('2'== Local_u8Up_Down)
			{
				GLOBAL_u8SELECTOR = '2';
				return;
			}
			/*check if key = '2' go show  high& low temperature */
			else if ('3'== Local_u8Up_Down)
			{
				GLOBAL_u8SELECTOR = '3';
				return;
			}
			
			do 
			{
				Local_u8Up_Down = 0 ; 
				Local_u8Up_Down = KPD_u8GetPressedKey();
				
			} while (Local_u8Up_Down == 0xff);
			
		} while (Local_u8Up_Down!='c');		

}

/*set motor speed by writing on OCR0 REGISTER*/
void SET_MOTOR_SPEED(u8 Copy_u8MotorSpeed)
{
	TIMER0_vidSetCompMatchValue(Copy_u8MotorSpeed); 
}


void TEMP_VALUE(void)
{
	/*ADC start conversion and calculate the temperature  */
	u16 Local_u32ADCReading = 0 ;
	u8 TempC=0 ;
	u16 Local_u16MilliVolt = 0 ;
	ADC_u8StartConversionSynch(ADC_CH_0,&Local_u32ADCReading);
	Local_u16MilliVolt=(u16)(((u32)Local_u32ADCReading*5000Ul)/256UL); // using 8bit resolution
	TempC = Local_u16MilliVolt/10 ;
	
	/*check if temperature is bigger than high temperature */
	if (TempC>TEMP_STORED_HIGH)
	{
		LED_u8SetLedOff(LED_PORT,LED_LOW);     /*set other mode led off */
		LED_u8SetLedOff(LED_PORT,LED_NORMAL);  /*set other mode led off */
		SET_MOTOR_SPEED(MOTOR_FULL_SPEED);/*set motor speed to full speed */
		LED_u8SetLedOn(LED_PORT,LED_HIGH);/* set the red led high */
		/*BUZZER_ON();*/ 
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN1,DIO_u8PIN_HIGH);
		_delay_ms(50);
		CLCD_vidClearLcd(); 
		CLCD_vidGoToXY(LCD_ROW1,LCD_COL1); 
		CLCD_vidSednString("T_*c= ");
		CLCD_vidSendLargeNmber(TempC);      /*display current temperature on screen */
		CLCD_vidGoToXY(LCD_ROW2,LCD_COL1); 
		CLCD_vidSednString("ALARM");        /*display ALARM on screen */
		CLCD_vidGoToXY(LCD_ROW2,LCD_COL7); 
		CLCD_vidSednString("FanSpeed 100%");/*display motor speed  on screen */
		_delay_ms(500); 
		Local_Uart_state = HIG_MODE ;  
		 
	}
	
	/*check if temperature is on the mid range */
	else if (TempC>TEMP_STORED_LOW && TempC<=TEMP_STORED_HIGH)
	{
		LED_u8SetLedOff(LED_PORT,LED_LOW);     /*set other mode led off */
		LED_u8SetLedOff(LED_PORT,LED_HIGH);	  /*set other mode led off */
		BUZZER_OFF();                         /*Disable buzzer*/
		
		SET_MOTOR_SPEED(MOTOR_HALF_SPEED);    /*set motor speed to full speed */
		LED_u8SetLedOn(LED_PORT,LED_NORMAL);  /* set the red led mid */
		
		CLCD_vidClearLcd();
		CLCD_vidGoToXY(LCD_ROW1,LCD_COL1);
		CLCD_vidSednString("T_*c= ");
		CLCD_vidSendLargeNmber(TempC);        /*display current temperature on screen */
		CLCD_vidGoToXY(LCD_ROW2,LCD_COL1);
		CLCD_vidSednString("NORM");			  /*display ALARM on screen */
		CLCD_vidGoToXY(LCD_ROW2,LCD_COL7);
		CLCD_vidSednString("FanSpeed 50%");	  /*display motor speed  on screen */
		_delay_ms(500);
		Local_Uart_state = NORMAL_MODE ; 
	}
	/*check if temperature is on the mid range */
	else if (TempC<=TEMP_STORED_LOW)
	{
		LED_u8SetLedOff(LED_PORT,LED_HIGH);     /*set other mode led off */
		LED_u8SetLedOff(LED_PORT,LED_NORMAL);  /*set other mode led off */
		BUZZER_OFF();                         /*Disable buzzer*/
		
		SET_MOTOR_SPEED(MOTOR_STOP);          /*set motor speed to full speed */
		LED_u8SetLedOn(LED_PORT,LED_LOW);     /* set the red led low */
		
		CLCD_vidClearLcd();
		CLCD_vidGoToXY(LCD_ROW1,LCD_COL1);
		CLCD_vidSednString("T_*c= ");
		CLCD_vidSendLargeNmber(TempC);        /*display current temperature on screen */
		CLCD_vidGoToXY(LCD_ROW2,LCD_COL1);
		CLCD_vidSednString("LOW");			  /*display ALARM on screen */
		CLCD_vidGoToXY(LCD_ROW2,LCD_COL5);
		CLCD_vidSednString("FanSpeed 0%");	  /*display motor speed  on screen */
		_delay_ms(500);
		Local_Uart_state = LOW_MODE ; 
	}
	
	/*check if operating mode is not changed */
	 if (Local_Uart_check != Local_Uart_state ) 
	 {
		switch(Local_Uart_state)
			{
				case HIG_MODE : 
				UART_voidWriteNewLine(); 
				UART_voidSendString("FIRE_ALARM"); 
				break;
				case NORMAL_MODE : 
				UART_voidWriteNewLine(); 
				UART_voidSendString("NORAML_MODE") ; 
				break; 
				case LOW_MODE :
				UART_voidWriteNewLine();
				UART_voidSendString("LOW_TEMPRATURE") ;
				break; 
				default:
				break;
				
				}
	 }
	 
	 Local_Uart_check = Local_Uart_state ; 
	
	
	
}


// interrupt service routine function to retun to main menu 
void MAIN_MENU_ISR(void)
{
	GLOBAL_u8SELECTOR='0'; 
}