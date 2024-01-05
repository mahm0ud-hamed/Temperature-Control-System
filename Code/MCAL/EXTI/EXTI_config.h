 /************************************************************************/
 /************************************************************************/
 /***********************  Author :Mahmoud Hamed   ***********************/
 /***********************       Layer :MCAl        ***********************/
 /**********************         SWC :EXTI         ***********************/
 /***********************       Version :1.00      ***********************/
 /************************************************************************/
 /************************************************************************/
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*options :
************* valid only for INT0 ,INT1  
             1- LOW_LEVEL
			 2- ON_CHANGE
			 3- FALLING_EDGE
			 4- RISING_EDGE
************ valid only for INT2
			 1- FALLING_EDGE
			 2- RISING_EDGE
*/

#define  INT0_SENSE   FALLING_EDGE  /* INT0 sense control */

#define  INT1_SENSE   FALLING_EDGE   /* INT1 sense control */

#define  INT2_SENSE   FALLING_EDGE   /* INT2 sense control */

/*options:
1- ENABLED
2- DISABLED */
#define  INT0_INITIAL_STATE  ENABLED  /*INT0 initial state*/
#define  INT1_INITIAL_STATE  DISABLED /*INT1 initial state*/
#define  INT2_INITIAL_STATE  DISABLED /*INT2 initial state*/


#endif
