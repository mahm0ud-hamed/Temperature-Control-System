/*
 * testing every thing.c
 *
 * Created: 1/6/2023 8:51:40 PM
 * Author : Mahmoud Hamed
 */ 

#include "SERVICE/STD_TYPES.h"           // LIBRARY


#include "HAL/CLCD/CLCD_interface.h"      //HAL_LAYER

#include "APP_LAYER/APP_EEPROM/EEPROM_STORE.h"

#include "APP_LAYER/APP_TEMP_SENS/APP_TEMP_CTRL_SYSTEM.h" // APP_LAYER

#define F_CPU 8000000UL          // MICRO_CONFIG
#include "util/delay.h"			 // MICRO_CONFIG

extern u8 GLOBAL_u8SELECTOR ; 
int main(void)
{
	
	
	TEMP_CTRL_SYSTEM_INIT(); /*initialize all system component */
	
	
	START_MASSAGE();         /*send the welcome massage */
  
    while (1) 
    {
		/*choose which operation selected by user */
		
		switch(GLOBAL_u8SELECTOR)
		{
			case '0':
			
				 MAIN_MENUE();  /*display to the user the whole option that  program  perform */
			  break;
			
			case '1': while('1' == GLOBAL_u8SELECTOR)
					  {
					  	   TEMP_VALUE();  /*start the programe */  
					  }
			break;
			
			case '2': while('2' == GLOBAL_u8SELECTOR)
						{
							 STORE_voidTEMPRATURE(); /*store high an low temp on EXT EEPROM  */
							 GLOBAL_u8SELECTOR='0'; 
						}
			break;
			 
			
			case '3': while('3' == GLOBAL_u8SELECTOR)/*function to display EEPROM values*/
					  {
					  	READ_STOR_voidTEMPARTURE();  /*read the value stored on EEPROM*/
						  _delay_ms(100);
						GLOBAL_u8SELECTOR='0'; 
					  }
		       break;
			
		}
    }
}



