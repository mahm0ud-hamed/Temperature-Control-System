/************************************************************************/
/************************************************************************/
/***********************  Author :Mahmoud Hamed   ***********************/
/***********************       Layer :MCAl        ***********************/
/**********************         SWC :PORT         ***********************/
/***********************       Version :1.00      ***********************/
/************************************************************************/
/************************************************************************/


#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

/*choose : 0 for input
           1 for output 
		    */

/*PORTA PIN DIRECTION*/
#define PORTA_PIN0_DIR			     0    //INPUT FOR TEMP_SENSOR  
#define PORTA_PIN1_DIR				 1    //OUTPUT FOR  BUZZER  
#define PORTA_PIN2_DIR				 0
#define PORTA_PIN3_DIR				 0
#define PORTA_PIN4_DIR				 1   // LCD_DATA_PINS
#define PORTA_PIN5_DIR				 1	 // LCD_DATA_PINS
#define PORTA_PIN6_DIR				 1	 // LCD_DATA_PINS
#define PORTA_PIN7_DIR				 1	 // LCD_DATA_PINS

/*PORTB PIN DIRECTION*/
#define PORTB_PIN0_DIR				 1   // LCD_E_PIN
#define PORTB_PIN1_DIR				 1	 // LCD_RS_PINS
#define PORTB_PIN2_DIR				 1	 // LCD_RW_PINS
#define PORTB_PIN3_DIR			 	 1   // OC0_MOTOR_PIN
#define PORTB_PIN4_DIR				 1   //BLINK_LED
#define PORTB_PIN5_DIR			 	 1	 // LOW_LED
#define PORTB_PIN6_DIR				 1	 // MID_LED
#define PORTB_PIN7_DIR				 1	 // HIGH_LED

/*PORTC PIN DIRECTION*/
#define PORTC_PIN0_DIR				 1   // EEPROM_PIN
#define PORTC_PIN1_DIR				 1	 // EEPROM_PIN
#define PORTC_PIN2_DIR				 0
#define PORTC_PIN3_DIR				 1
#define PORTC_PIN4_DIR				 1  // KPD COLUMNS
#define PORTC_PIN5_DIR				 1	// KPD COLUMNS
#define PORTC_PIN6_DIR				 1	// KPD COLUMNS
#define PORTC_PIN7_DIR				 1	// KPD COLUMNS

/*PORTD PIN DIRECTION*/
#define PORTD_PIN0_DIR				 0 // UART PINS
#define PORTD_PIN1_DIR				 1 // UART PINS
#define PORTD_PIN2_DIR				 0
#define PORTD_PIN3_DIR				 0
#define PORTD_PIN4_DIR				 0  // KPD ROWS
#define PORTD_PIN5_DIR				 0	// KPD ROWS
#define PORTD_PIN6_DIR				 0	// KPD ROWS
#define PORTD_PIN7_DIR				 0	// KPD ROWS


/*CHOOSE : 0 FOR floating if input , LOW if OUTPUT
		   1 FOR pulled up if INPUT, HIGH if OUTPUT 
		   */
/*PORTA PIN VALUES */
#define PORTA_PIN0_INITIAL_VALUE     0
#define PORTA_PIN1_INITIAL_VALUE	 1
#define PORTA_PIN2_INITIAL_VALUE	 0
#define PORTA_PIN3_INITIAL_VALUE	 0
#define PORTA_PIN4_INITIAL_VALUE	 0
#define PORTA_PIN5_INITIAL_VALUE	 0
#define PORTA_PIN6_INITIAL_VALUE	 0
#define PORTA_PIN7_INITIAL_VALUE	 0

/*PORTB PIN VALUES*/
#define PORTB_PIN0_INITIAL_VALUE     0
#define PORTB_PIN1_INITIAL_VALUE	 0
#define PORTB_PIN2_INITIAL_VALUE	 0
#define PORTB_PIN3_INITIAL_VALUE	 0
#define PORTB_PIN4_INITIAL_VALUE	 0
#define PORTB_PIN5_INITIAL_VALUE	 0
#define PORTB_PIN6_INITIAL_VALUE	 0
#define PORTB_PIN7_INITIAL_VALUE	 0

/*PORTC PIN VALUES*/
#define PORTC_PIN0_INITIAL_VALUE     0
#define PORTC_PIN1_INITIAL_VALUE	 0
#define PORTC_PIN2_INITIAL_VALUE	 0
#define PORTC_PIN3_INITIAL_VALUE	 0
#define PORTC_PIN4_INITIAL_VALUE	 0
#define PORTC_PIN5_INITIAL_VALUE	 0
#define PORTC_PIN6_INITIAL_VALUE	 0
#define PORTC_PIN7_INITIAL_VALUE	 0

/*PORTD PIN VALUES*/
#define PORTD_PIN0_INITIAL_VALUE	 0
#define PORTD_PIN1_INITIAL_VALUE	 0
#define PORTD_PIN2_INITIAL_VALUE 	 1          // INT0 PULL UP RESISTOR 
#define PORTD_PIN3_INITIAL_VALUE	 0			 
#define PORTD_PIN4_INITIAL_VALUE	 1			// KPD ROWS PULL UP RESISTOR
#define PORTD_PIN5_INITIAL_VALUE  	 1			// KPD ROWS	PULL UP RESISTOR
#define PORTD_PIN6_INITIAL_VALUE	 1			// KPD ROWS PULL UP RESISTOR
#define PORTD_PIN7_INITIAL_VALUE	 1			// KPD ROWS	PULL UP RESISTOR




#endif