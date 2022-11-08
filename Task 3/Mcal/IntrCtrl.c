/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntrCtr.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *       \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable and Disable Navic Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "platform_types.h"
#include "IntrCtrl_Cfg.h"
#include "IntrCtrl.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Nvic_Init(void)                                      
* \Description     : initialize Nvic Module by parsing the Configuration 
*                    into Nvic registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Nvic_Init(void)
{
	
	Nvic_IntType intNum;
	uint8 intGroup, intSubGroup, intStatus, groupAndSubGroup, i;
	uint32 regEnableOffset, bitEnableOffset, regPriorityOffset,bitPriorityOffset;
	volatile uint32  *regEnableAdd, *regPriorityAdd ;
	
	/*TODO COnfigure Grouping\SubGrouping System in APINT register in SCB*/
		*APINT = (APINT_KEY << APINT_KEY_START_BIT)| (NVIC_GROUPING_SYSTEM << NVIC_GROUPING_SYSTEM_START_BIT);
	
		for(i=0;i< NVIC_ACTIVATED_INT_SIZE;i++)
		{
		intNum       =  Nvic_Cfg[i].interruptNumber;
		intGroup     =  Nvic_Cfg[i].groupPriority;
		intSubGroup  =  Nvic_Cfg[i].subgroupPriority;	
			
	/*TODO : Enable\Disable based on user configurations in ENx Nvic Registers */
		
		/*Calc register offset and bit offset to get Enable regester address*/
		regEnableOffset = (intNum/WORD_LENGTH_BITS)*WORD_LENGTH_BYTES;
		bitEnableOffset = (intNum % WORD_LENGTH_BITS);
		

		regEnableAdd = (uint32 *)(NVIC_ENABLE_BASE_ADDRESS +  regEnableOffset );
		/*Enable Interrupt*/
	 *regEnableAdd |= ( 1 << bitEnableOffset );

		/* Create Grouping Field */
#if (NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXX)
	      groupAndSubGroup = intGroup;
#elif (NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXY) 
        groupAndSubGroup = ((intGroup<<1)&0x6) | (intSubGroup&0x1);
#elif (NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XYY) 
        groupAndSubGroup = ((intGroup<<2)&0x4) | (intSubGroup&0x3);
#elif (NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_YYY) 
        groupAndSubGroup = intSubGroup;
#else
     #error Invalid grouping system 
#endif 	/*NVIC_GROUPING_SYSTEM*/

/*TODO : Assign Group\Subgroup priority in PRIx Nvic Registers*/

		/*Calc register offset and bit offset to get Priority regester address*/
		regPriorityOffset = (intNum / 4) ;
		bitPriorityOffset = ((intNum % 4) *8) +5;

	/*set priority grouping value*/
		regPriorityAdd  = (uint32 *) (NVIC_PRIORITY_BASE_ADDRESS + regPriorityOffset);
	 *regPriorityAdd |= (groupAndSubGroup << bitPriorityOffset);


	}
}

void 

/**********************************************************************************************************************
 *  END OF FILE: IntrCtrl.c
 *********************************************************************************************************************/