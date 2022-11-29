/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       File:  Mcu.h
 *       Module:  Mcu
 *
 *  Description:  Header file for Mcu Module     
 *  
 *********************************************************************************************************************/
#ifndef MCU_H_
#define MCU_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "platform_types.h"
#include "Mcu_Cfg.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define CLOCK_0 0
#define CLOCK_1 1


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
extern uint8 Mcu_ActivatedClockGates[];

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint8 Mcu_ClockType;


typedef uint32 Mcu_FreqType;

typedef uint8 Mcu_StatusType;

#define MCU_NOT_INITIALIZED          0
#define MCU_INITIALIZED              1



typedef uint32 Mcu_RawResetType;

#define MCU_MOSC_FAILURE_RESET            0x10000uL
#define MCU_WDT_1_RESET                   32u
#define MCU_SOFTWARE_RESET                16u
#define MCU_WDT_0_RESET                   8u
#define MCU_BROWN_OUT_RESET               4u
#define MCU_POWER_ON_RESET                2u
#define MCU_EXTERNAL_RESET                1u

typedef enum
{
	  MCU_PLL_UNPOWERED_UNLOCKED,
    MCU_PLL_POWERED_LOCKED,             
    MCU_PLL_STATUS_UNDEFINED
	
}Mcu_PllStatusType;
typedef enum
{
	MCU_CLOCK_SOURCE_MOSC,    // main 
	MCU_CLOCK_SOURCE_PIOSC,
	MCU_CLOCK_SOURCE_PIOSC_Div4,
	MCU_CLOCK_SOURCE_LFIOSC,
	MCU_CLOCK_SOURCE_HibOSC	
	
}McuClockSourceType;


typedef struct
{
   Mcu_ClockType ClockSource;
   boolean PllUse;
   Mcu_FreqType Freq_KHz;
	
}Mcu_ConfigType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 

/******************************************************************************
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     : This service initializes the MCU driver.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr       Pointer to MCU driver configuration set.                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_Init ( const Mcu_ConfigType* ConfigPtr );

/******************************************************************************
* \Syntax          : Mcu_RawResetType Mcu_GetResetRawValue( void )        
* \Description     : The service reads the reset type from the hardware, if supported.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                            
* \Parameters (out): None                                                      
* \Return value:   : Mcu_RawResetType   Reset raw value
*******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue( void );

/******************************************************************************
* \Syntax          : void Mcu_PerformReset( void )        
* \Description     : The service performs a microcontroller reset.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_PerformReset( void );
/******************************************************************************
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     : This service initializes the PLL and other MCU specific clock options.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ClockSetting       ClockSetting.                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 
*******************************************************************************/
uint8 Mcu_InitClock( Mcu_ClockType ClockSetting );

/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_DistributePllClock( void )        
* \Description     : This service activates the PLL clock to the MCU clock distribution.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                            
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 
*                    E_OK: Command has been accepted
*                    E_NOT_OK: Command has not been accepted
*******************************************************************************/
uint8 Mcu_DistributePllClock( void );

/******************************************************************************
* \Syntax          : Mcu_PllStatusType Mcu_GetPllStatus        
* \Description     : This service provides the lock status of the PLL.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : Mcu_PllStatusType  PLL Status
*******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus( void );

 
#endif  /* MCU_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/