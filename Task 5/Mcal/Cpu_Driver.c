


/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**       \file  Cpu_Driver.c
 *        \brief  
 *        \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Cpu_Driver.h"

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
* \Syntax          : void CpuDriver_StopCriticalSection   (void)
        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : none                         
* \Parameters (out): None                                                      
* \Return value:   : none                                   
*******************************************************************************/

void CpuDriver_StopCriticalSection   (void)
{
    CpuDriver_EnableGlobalInterrupt();
}

/******************************************************************************
* \Syntax          : void CpuDriver_StartCriticalSection  (void)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : none                         
* \Parameters (out): None                                                      
* \Return value:   : none                                   
*******************************************************************************/

void CpuDriver_StartCriticalSection  (void)
{
    CpuDriver_DisableGlobalInterrupt();
}
/******************************************************************************
* \Syntax          : void CpuDriver_DisableGlobalInterrupt(void)        
* \Description     : Disable all interrupts except non maskable and HardFault                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : none                         
* \Parameters (out): None                                                      
* \Return value:   : none                                   
*******************************************************************************/
void CpuDriver_DisableGlobalInterrupt(void)
{
    __asm("CPSID i"); /*set PRIMASK
                        Disable all interrupts except non maskable and HardFault*/
    /*
    __asm("MOV R0, 0x0\n");
    __asm("MSR PRIMASK, R0\n");
    */
}
/******************************************************************************
* \Syntax          : void CpuDriver_EnableGlobalInterrupt (void)        
* \Description     : Enable all interrupts                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : none                         
* \Parameters (out): None                                                      
* \Return value:   : none                                   
*******************************************************************************/
void CpuDriver_EnableGlobalInterrupt (void)
{
    __asm("CPSIE i"); /*clear PRIMASK
                        Enable all interrupts*/ 
    
    /*
    __asm("MOV R0, 0x0\n");
    __asm("MSR PRIMASK, R0\n");
    */
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
