 /************************************************************************/
 /************************************************************************/
 /***********************  Author :Mahmoud Hamed   ***********************/
 /***********************       Layer :MCAl        ***********************/
 /**********************         SWC :EXTI         ***********************/
 /***********************       Version :1.00      ***********************/
 /************************************************************************/
 /************************************************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*control sense options*/
#define LOW_LEVEL      1
#define ON_CHANGE      2
#define FALLING_EDGE   3
#define RISING_EDGE    4

/*interrupts*/
#define INT0  0 
#define INT1  1 
#define INT2  2


/*description : A function to initiate INT0 using prebuild configuration
* INPUT : void						
* OUTPUT :void */
void EXTI_vidInt0Init(void);


/*description : A function to initiate INT1 using prebuild configuration
* INPUT : void
* OUTPUT :void */
void EXTI_vidInt1Init(void); 

/*description : A function to initiate INT2 using prebuild configuration
* INPUT : void
* OUTPUT :void */
void EXTI_vidInt2Init(void);
/*description : A function to set the required sense control of INT0 using post build configuration 
* INPUT : copy_u8sense , options are:
*									1-LOW_LEVEL   
*									2-ON_CHANGE   
*									3-FALLING_EDGE
*									4-RISING_EDGE 
* OUTPUT : Error status with type u8 */
u8 EXTI_u8Int0SetSenseControl(u8 copy_u8Int0Sense);



/*description : A function to set the required sense control of INT1 using post build configuration
* INPUT : copy_u8sense , options are:
*									1-LOW_LEVEL
*									2-ON_CHANGE
*									3-FALLING_EDGE
*									4-RISING_EDGE
* OUTPUT : Error status with type u8 */
u8 EXTI_u8Int1SetSenseControl(u8 copy_u8Int1Sense);


/*description : A function to set the required sense control of INT0 using post build configuration
* INPUT : copy_u8sense , options are:
*									1-FALLING_EDGE
*									2-RISING_EDGE
* OUTPUT : Error status with type u8 */
u8 EXTI_u8Int2SetSenseControl(u8 copy_u8Inte2Sense);


/*description : A function to peripheral interrupt enable using post build configuration
* INPUT : copy_u8Int                options are:
*									1-INT0
*                                   2-INT1
*									3-INT2
* OUTPUT : Error status with type u8 */
u8 EXTI_u8IntEnable(u8 copy_u8INT );

/*description : A function to peripheral interrupt disable using post build configuration
* INPUT : copy_u8Int                options are:
*									1-INT0
*                                   2-INT1
*									3-INT2
* OUTPUT : Error status with type u8 */
u8 EXTI_u8IntDisable(u8 copy_u8INT );



u8 EXTI_u8Int0SetCallBack(void(*copy_pvINT0Func)(void));

u8 EXTI_u8Int1SetCallBack(void(*copy_pvINT1Func)(void));

u8 EXTI_u8Int2SetCallBack(void(*copy_pvINT2Func)(void));
#endif