/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
static const uint32 Port_BaseAddr[NUMBER_OF_GPIO_PORTS] = {	    GPIO_PORT_A_BASE,
	                                                            GPIO_PORT_B_BASE,
	                                                    	    GPIO_PORT_C_BASE,
																GPIO_PORT_D_BASE,														  GPIO_PORT_D_BASE,
	                                                            GPIO_PORT_E_BASE,
	                                                            GPIO_PORT_F_BASE};

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
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Port_Init (const Port_ConfigType* ConfigPtr)
{
	
	Port_ChannelType             pinId = 0;
	Port_PinDirectionType       pinDir = 0;
	Port_PinModeType            pinMode = 0;
	Port_PinOutputCurrentType   currentStrength = 0;
	Port_PinInternalAttachType  internalAttach = 0;
	Port_PinExternalIntType     externalInt = 0;
	uint8 PortIndex = 0,PinIndex = 0,i = 0;
	uint32 PortBaseAddr;
	
	for(i=0; i<PORT_ACTIVATED_CHANNELS_SIZE; i++)
	{
		pinId             = ConfigPtr[i].pinId;
		pinDir            = ConfigPtr[i].pinDir;
		pinMode           = ConfigPtr[i].pinMode;
		currentStrength   = ConfigPtr[i].currentStrength;
		internalAttach    = ConfigPtr[i].internalAttach;
		externalInt       = ConfigPtr[i].externalInt;
	
		
		PortIndex    = pinId / 8 ;
		PinIndex     = pinId % 8 ;
    PortBaseAddr = Port_BaseAddr[PortIndex] ;
		
	//	uint32 add = GPIODIR_REG(PortBaseAddr);
		GPIODIR_REG(PortBaseAddr) |= (pinDir<< PinIndex) ; 
		
		
		
	}
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
