/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**       \file  Mcu.c
 *        \brief  Microcontroller Unit Driver
 *      	\details Clock Control and reset
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Mcu.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define MCU_PLL_OUTPUT_DIV2          200
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static const Mcu_ConfigType* Mcu_ConfigPtr = NULL_PTR;
static Mcu_StatusType Mcu_Status = MCU_NOT_INITIALIZED;
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
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     : This service initializes the MCU driver.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr       Pointer to MCU driver configuration set.                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )
{
	Mcu_Status = MCU_INITIALIZED;
	Mcu_ConfigPtr = ConfigPtr;
}


/******************************************************************************
* \Syntax          : Mcu_RawResetType Mcu_GetResetRawValue( void )        
* \Description     : The service reads the reset type from the hardware, if supported.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                            
* \Parameters (out): None                                                      
* \Return value:   : Mcu_RawResetType   Reset raw value
*******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue( void )
{
	/*load the reset cause type*/
	Mcu_RawResetType resetCause = RESC;
	/*clear the reset cause type*/
	RESC = 0x0;
	return resetCause;
}

/******************************************************************************
* \Syntax          : void Mcu_PerformReset( void )        
* \Description     : The service performs a microcontroller reset.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_PerformReset( void )
{
	/*Clear Reset Cause Register */
	RESC = 0x0;
	
	/*Perform Reset */
	APINT = (APINT_KEY<<APINT_KEY_START_BIT) | (1<<APINT_SYSRESREQ);
	
}

/******************************************************************************
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     : This service initializes the PLL and other MCU specific clock options.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ClockSetting       ClockSetting.                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 

*******************************************************************************/
Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockType )
{
	Std_ReturnType ret_status = NOT_OK;
	uint8 i, locGateRegOffset,locGateBitOffset;


	if(Mcu_Status == MCU_INITIALIZED)
	{
	    /*Enable Configured Pripherals Gates */
	    for(i=0; i<MCU_ACTIVATED_CLOCK_GATES_SIZE; i++)
	    {
	    	locGateRegOffset = (Mcu_ActivatedClockGates[i] / 10) * WORD_LENGTH_BYTES ;
	    	locGateBitOffset = Mcu_ActivatedClockGates[i] % 10 ;
				
	    	GET_REG(SYSCTR_RCG_BASE_ADDR,locGateRegOffset ) |= (1<<locGateBitOffset);	
	    }
			
			/* Set Clock Source in RCC -> OSCSRC*/
	    RCC.B.OSCSRC = Mcu_ConfigPtr[ClockType].ClockSource;
	    
	    /* Calculate System Division Value */
	    if(Mcu_ConfigPtr[ClockType].PllUse == ENABLE)
	    {
	    	/*Enable PLL*/
	    	RCC.B.PWRDN = 0x0; /*PLL Operation Normally*/
	    	RCC.B.SYSDIV = (MCU_PLL_OUTPUT_DIV2 / (Mcu_ConfigPtr[ClockType].Freq_KHz/1000))-1;	
	    }
	    else
	    {
	    	if (Mcu_ConfigPtr[ClockType].ClockSource == MCU_CLOCK_SOURCE_LFIOSC)
	    	{
	    		RCC.B.SYSDIV = 0x0;
	    	}
	    	else
	    	{
	    		if(Mcu_ConfigPtr[ClockType].ClockSource == MCU_CLOCK_SOURCE_MOSC)
	            {
	            	RCC.B.MOSCDIS = 0x0;  /*enable main oscillator.*/
	            	RCC.B.XTAL = MCU_XTAL_CLOCK_FREQ_MHZ ; /* The value need to be mapped */

								RCC.B.SYSDIV = ((MCU_XTAL_CLOCK_FREQ_MHZ / (Mcu_ConfigPtr[ClockType].Freq_KHz/1000))-1);	

	            }
	    	    else if (Mcu_ConfigPtr[ClockType].ClockSource == MCU_CLOCK_SOURCE_PIOSC)
	    	    {
	    	    	
	    	    }
	    	    else if (Mcu_ConfigPtr[ClockType].ClockSource == MCU_CLOCK_SOURCE_PIOSC_Div4)
	    	    {
	    	    	
	    	    }
	    	}	
	    }
        ret_status = OK;
    }
	return ret_status;
}

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
Std_ReturnType Mcu_DistributePllClock( void ){
	Std_ReturnType ret = NOT_OK;
	/*Check if PLL is Enabled */
	if(RCC.B.PWRDN == 0)
	{
		/*Check if PLL locked */
	    if(Mcu_GetPllStatus() == MCU_PLL_POWERED_LOCKED)
	    {
	    	/* Distrubute PLL */
	        RCC.B.BYPASS = 1;
					ret = OK;
      }
	}
	return ret;
}

/******************************************************************************
* \Syntax          : Mcu_PllStatusType Mcu_GetPllStatus        
* \Description     : This service provides the lock status of the PLL.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : Mcu_PllStatusType  PLL Status
*******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus( void )
{
	/*1 : PLL is powered and locked
	  0 : PLL is unpowered or is not yet locked
	*/
	return PLLSTAT;
}



/**********************************************************************************************************************
 *  END OF FILE: Mcu.c
 *********************************************************************************************************************/
