 /*************************************************************************/
 /*************************************************************************/
 /***********************  Author :Mahmoud Hamed    ***********************/
 /***********************       Layer :APP          ***********************/
 /**********************   SWC :TEMP_CTRL_SYSTE     ***********************/
 /***********************       Version :1.00       ***********************/
 /*************************************************************************/
 /*************************************************************************/



#ifndef APP_TEMP_CTRL_SYSTEM_H_
#define APP_TEMP_CTRL_SYSTEM_H_


   
  
#define MOTOR_HALF_SPEED  128  /*macro for HALF motor speed */
#define MOTOR_FULL_SPEED  255  /*macro for FULL motor speed */
#define MOTOR_STOP         0   /*macro for STOP motor  */

 
 /*description : A function to initiate all system component
 * INPUT :void
 * OUTPUT:void    */
void TEMP_CTRL_SYSTEM_INIT(void);  


/*description : A function display start massage
 * INPUT :void
 * OUTPUT:void    */
void START_MASSAGE(void); 

         
/*description : function main menu to choose options
 * INPUT :void
 * OUTPUT:void    */
void MAIN_MENUE(void);              

/*description : A function to start the program to compare sensor read with high and low temp
 * INPUT :void
 * OUTPUT:void    */
void PROGRAM_START();            


/*description : A function set the motor speed 
 * INPUT :u8 copy_u8MotorSpeed
 * OUTPUT:void    */
void SET_MOTOR_SPEED(u8 copy_u8MotorSpeed); 

/*description : A function display start massage
 * INPUT :void
 * OUTPUT:void    */
void TEMP_VALUE(void); 


/*description : INTERRUT SERVICE ROUTINE FUNCTION
 * INPUT :void
 * OUTPUT:void    */
void MAIN_MENU_ISR(void); 

#endif /* APP_TEMP_CTRL_SYSTEM_H_ */