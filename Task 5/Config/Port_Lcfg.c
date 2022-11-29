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
#include  "Port_Cfg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

const Port_ConfigType Port_Config[PORT_ACTIVATED_CHANNELS_SIZE]=
{
	/* pinId         			  pinDir         	 pinMode                     currentStrength        internalAttach          externalInt*/
	{  Port_Channel_A0     ,PORT_PIN_OUT   ,Port_PinMode_X_DIO		      ,PORT_PIN_CURRENT_NA   ,PORT_ATTACH_PULLUP     ,PORT_EXT_INT_DISABLE},

	{  Port_Channel_A1     ,PORT_PIN_OUT   ,Port_PinMode_X_DIO          ,PORT_PIN_CURRENT_NA   ,PORT_ATTACH_PULLDOWN   ,PORT_EXT_INT_DISABLE},
	{  Port_Channel_A2     ,PORT_PIN_OUT   ,Port_PinMode_X_DIO          ,PORT_PIN_CURRENT_8m   ,PORT_ATTACH_OPENDRAIN  ,PORT_EXT_INT_DISABLE},
	{  Port_Channel_A3     ,PORT_PIN_OUT   ,Port_PinMode_X_DIO		      ,PORT_PIN_CURRENT_NA   ,PORT_ATTACH_PULLUP     ,PORT_EXT_INT_DISABLE},
	{  Port_Channel_A4     ,PORT_PIN_OUT   ,Port_PinMode_X_DIO          ,PORT_PIN_CURRENT_NA   ,PORT_ATTACH_PULLDOWN   ,PORT_EXT_INT_DISABLE},
	{  Port_Channel_A5     ,PORT_PIN_OUT   ,Port_PinMode_X_DIO          ,PORT_PIN_CURRENT_8m   ,PORT_ATTACH_OPENDRAIN  ,PORT_EXT_INT_DISABLE},
	{  Port_Channel_A5     ,PORT_PIN_OUT   ,Port_PinMode_X_DIO          ,PORT_PIN_CURRENT_8m   ,PORT_ATTACH_OPENDRAIN  ,PORT_EXT_INT_DISABLE},
	{  Port_Channel_A5     ,PORT_PIN_OUT   ,Port_PinMode_X_DIO          ,PORT_PIN_CURRENT_8m   ,PORT_ATTACH_OPENDRAIN  ,PORT_EXT_INT_DISABLE}

	
};


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

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
