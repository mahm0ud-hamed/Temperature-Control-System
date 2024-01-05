 /************************************************************************/
 /************************************************************************/
 /***********************  Author :Mahmoud Hamed   ***********************/
 /***********************       Layer :MCAl        ***********************/
 /**********************         SWC :EXTI         ***********************/
 /***********************       Version :1.00      ***********************/
 /************************************************************************/
 /************************************************************************/


#include "../../SERVICE/STD_TYPES.h"
#include "../../SERVICE/BIT_MATH.h"


#include "EXTI_interface.h"
#include "EXTI_registers.h"
#include "EXTI_config.h"
#include "EXTI_private.h"


void(*EXTI_pvINT0func)(void)= NULL ;/*global pointer to function to hold INT0 ISR address*/
void(*EXTI_pvINT1func)(void)= NULL ;/*global pointer to function to hold INT1 ISR address*/
void(*EXTI_pvINT2func)(void)= NULL ;/*global pointer to function to hold INT2 ISR address*/


/*function to initiate interrupt INT0  */
void EXTI_vidInt0Init(void)
{
	/*1- check INT0 sense control*/
	
	#if INT0_SENSE == LOW_LEVEL
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
	
	#elif INT0_SENSE == ON_CHANGE
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		
	#elif INT0_SENSE == FALLING_EDGE
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		
	#elif INT0_SENSE == RISING_EDGE
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
	#else
		#error "Wrong INT0_SENSE configuration option"
	
	#endif
	/*2-check peripheral interrupt enable initial state */	
	#if INT0_INITIAL_STATE == ENABLED
		SET_BIT(GICR,GICR_INT0);
	#elif INT0_INITIAL_STATE== DISABLED
		CLR_BIT(GICR,GICR_INT0);
	#else
		#error "Wrong INT0_INITIAL_STATE configuration"
	#endif
		
}



/*function to initiate interrupt INT1 */
void EXTI_vidInt1Init(void)
{
	/*1- check INT1 sense control*/
	#if INT1_SENSE == LOW_LEVEL 
		CLR_BIT(MCUCR,MCUCR_ISC10); 
		CLR_BIT(MCUCR,MCUCR_ISC11);
		
	#elif INT1_SENSE == ON_CHANGE
		  SET_BIT(MCUCR,MCUCR_ISC10);
		  CLR_BIT(MCUCR,MCUCR_ISC11);
		  
	#elif INT1_SENSE == FALLING_EDGE
		  CLR_BIT(MCUCR,MCUCR_ISC10);
		  SET_BIT(MCUCR,MCUCR_ISC11);
	
	#elif INT1_SENSE == RISING_EDGE
		  SET_BIT(MCUCR,MCUCR_ISC10);
		  SET_BIT(MCUCR,MCUCR_ISC11);
	#else
		 #error "wrong INT1_sense control configuration"
	#endif 
	
	/*2-check peripheral interrupt enable initial state */	
	#if INT1_INITIAL_STATE == ENABLED 
		SET_BIT(GICR,GICR_INT1); 
	#elif INT1_INITIAL_STATE == DISABLED
		CLR_BIT(GICR,GICR_INT1);
	#else 
		#error "wrong INT1_INITIAL_STATE configuration"
	#endif
}



/*function to initiate interrupt INT2 */
void EXTI_vidInt2Init(void)
{
	/*1- check INT2 sense control*/
	#if INT2_SENSE == RISING_EDGE 
		SET_BIT(MCUCSR,MCUCSR_ISC2);
	#elif INT2_SENSE == FALLING_EDGE
        CLR_BIT(MCUCSR,MCUCSR_ISC2);
	#else
		#error "wrong INT2_SENSE  sense control configuration"	
	#endif
	
	/*2-check peripheral interrupt enable initial state */
	#if INT2_INITIAL_STATE == ENABLED
		SET_BIT(GICR,GICR_INT2);
	#elif INT2_INITIAL_STATE == DISABLED 
		CLR_BIT(GICR,GICR_INT2);
	#else 
		#error "worng INT2_INITIAL_STATE configuration "
	#endif
}


u8 EXTI_u8Int0SetSenseControl(u8 copy_u8Int0Sense)
{
	u8 Local_u8ErrorState = Ok ;
	 switch(copy_u8Int0Sense)
	 {
		 case  LOW_LEVEL: CLR_BIT(MCUCR,MCUCR_ISC00);CLR_BIT(MCUCR,MCUCR_ISC01);break; 
		 case  ON_CHANGE: SET_BIT(MCUCR,MCUCR_ISC00);CLR_BIT(MCUCR,MCUCR_ISC01);break;
		 case  FALLING_EDGE:CLR_BIT(MCUCR,MCUCR_ISC00);SET_BIT(MCUCR,MCUCR_ISC01);break;
		 case  RISING_EDGE: SET_BIT(MCUCR,MCUCR_ISC00);SET_BIT(MCUCR,MCUCR_ISC01);break;
		 default:Local_u8ErrorState = NOT_OK ; 	 
	 }
	 
	 return Local_u8ErrorState ; 
}

u8 EXTI_u8Int1SetSenseControl(u8 copy_u8Int1Sense)
{
	u8 Local_u8ErrorState = Ok ; 
	switch(copy_u8Int1Sense)
	{
		case  LOW_LEVEL: CLR_BIT(MCUCR,MCUCR_ISC10);CLR_BIT(MCUCR,MCUCR_ISC11); break; 
		case  ON_CHANGE: SET_BIT(MCUCR,MCUCR_ISC10);CLR_BIT(MCUCR,MCUCR_ISC11); break;
		case  FALLING_EDGE:CLR_BIT(MCUCR,MCUCR_ISC10);SET_BIT(MCUCR,MCUCR_ISC11);break;
		case  RISING_EDGE:SET_BIT(MCUCR,MCUCR_ISC10);SET_BIT(MCUCR,MCUCR_ISC11); break;
		default: Local_u8ErrorState = NOT_OK ;
	}
	return Local_u8ErrorState; 
}

u8 EXTI_u8Int2SetSenseControl(u8 copy_u8Inte2Sense)
{
	u8 Local_u8ErrorState = Ok ;
	switch(copy_u8Inte2Sense)
	{
		case  FALLING_EDGE:CLR_BIT(MCUCSR,MCUCSR_ISC2);break ;
		case  RISING_EDGE:SET_BIT(MCUCSR,MCUCSR_ISC2);break ; 
		default: Local_u8ErrorState = NOT_OK;
	}
	
	return Local_u8ErrorState ; 
}

u8 EXTI_u8IntEnable(u8 copy_u8INT )
{
	u8 Local_u8ErrorState = Ok ; 
	switch(copy_u8INT)
	{
		case INT0:SET_BIT(GICR,GICR_INT0);break; 
		case INT1:SET_BIT(GICR,GICR_INT1);break; 
		case INT2:SET_BIT(GICR,GICR_INT2);break; 
		default:Local_u8ErrorState = NOT_OK ;  	 
	}
	return Local_u8ErrorState ; 
}
u8 EXTI_u8IntDisable(u8 copy_u8INT )
{
	u8 Local_u8ErrorState = Ok ;
	switch(copy_u8INT)
	{
		case INT0:CLR_BIT(GICR,GICR_INT0);break;
		case INT1:CLR_BIT(GICR,GICR_INT1);break;
		case INT2:CLR_BIT(GICR,GICR_INT2);break;
		default:Local_u8ErrorState = NOT_OK ;
		
	}
	return Local_u8ErrorState ;
}


u8 EXTI_u8Int0SetCallBack(void(*copy_pvINT0Func)(void))
{
	u8 Local_u8ErrorState = Ok ; 
	if(copy_pvINT0Func!=NULL)
	{
		EXTI_pvINT0func=copy_pvINT0Func ;
	}
	else
	{
		return Local_u8ErrorState=NULL_POINTER; 
	}
	
	return Local_u8ErrorState ; 
}

u8 EXTI_u8Int1SetCallBack(void(*copy_pvINT1Func)(void))
{
	u8 Local_u8ErrorState = Ok ;
	if(copy_pvINT1Func!=NULL)
	{
		EXTI_pvINT1func=copy_pvINT1Func ;
	}
	else
	{
		return Local_u8ErrorState=NULL_POINTER;
	}
	
	return Local_u8ErrorState ;
}

u8 EXTI_u8Int2SetCallBack(void(*copy_pvINT2Func)(void))
{
	u8 Local_u8ErrorState = Ok ;
	if(copy_pvINT2Func!=NULL)
	{
		EXTI_pvINT2func=copy_pvINT2Func ;
	}
	else
	{
		return Local_u8ErrorState=NULL_POINTER;
	}
	
	return Local_u8ErrorState ;
}


/*ISR of INT0*/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if (EXTI_pvINT0func!=NULL)
	{
		EXTI_pvINT0func();
	}
	else
	{
		/*do nothing*/
	}
	
}


/*ISR of INT1*/
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if (EXTI_pvINT1func!=NULL)
	{
		EXTI_pvINT1func();
	}
	else
	{
		/*do nothing*/
	}
	
}

/*ISR of INT2*/
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if (EXTI_pvINT2func!=NULL)
	{
		EXTI_pvINT2func();
	}
	else
	{
		/*do nothing*/
	}
	
}