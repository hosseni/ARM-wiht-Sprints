/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_H_
#define PORT_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port_Cfg.h"

#include "Mcu_Hw.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CHANNEL_SIZE_IN_PORT               8
#define NUMBER_OF_GPIO_PORTS    		   6

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



typedef enum 
{
	 Port_Channel_A0 = 0, /*portA*/
	 Port_Channel_A1,
	 Port_Channel_A2,
	 Port_Channel_A3,
	 Port_Channel_A4,
	 Port_Channel_A5,
	 Port_Channel_A6,
	 Port_Channel_A7,
	  
	 Port_Channel_B0, /*portB*/
	 Port_Channel_B1,
	 Port_Channel_B2,
	 Port_Channel_B3,
	 Port_Channel_B4,
	 Port_Channel_B5,
	 Port_Channel_B6,
	 Port_Channel_B7,
	  
	 Port_Channel_C0, /*portC*/
	 Port_Channel_C1,
	 Port_Channel_C2,
	 Port_Channel_C3,
	 Port_Channel_C4,
	 Port_Channel_C5,
	 Port_Channel_C6,
	 Port_Channel_C7,

   Port_Channel_D0,	/*portD*/
	 Port_Channel_D1,
	 Port_Channel_D2,
	 Port_Channel_D3,
	 Port_Channel_D4,
	 Port_Channel_D5,
	 Port_Channel_D6,
	 Port_Channel_D7,
	  
	 Port_Channel_E0,  /*portE*/
	 Port_Channel_E1,
	 Port_Channel_E2,
	 Port_Channel_E3,
	 Port_Channel_E4,
	 Port_Channel_E5,
	  
	 Port_Channel_F0 = 43,  /*portF*/
	 Port_Channel_F1,
	 Port_Channel_F2,
	 Port_Channel_F3,
	 Port_Channel_F4
	 
}Port_ChannelType;

typedef enum
{
	PORT_PIN_IN = 0,
	PORT_PIN_OUT
	
}Port_PinDirectionType;


typedef uint8 Port_PinModeType;
#define Port_PinMode_X_DIO           0
#define Port_PinMode_PA0_U0RX        1
#define Port_PinMode_PA1_U0TX        1
#define Port_PinMode_PA2_SSI0Clk     2

typedef enum
{
	PORT_ATTACH_DEFAULT,
	PORT_ATTACH_PULLUP,
	PORT_ATTACH_PULLDOWN,
	PORT_ATTACH_OPENDRAIN	
}Port_PinInternalAttachType;

typedef enum 
{
	PORT_PIN_CURRENT_NA,
	PORT_PIN_CURRENT_2m,
	PORT_PIN_CURRENT_4m,
	PORT_PIN_CURRENT_8m
}Port_PinOutputCurrentType;

typedef enum
{
	PORT_EXT_INT_DISABLE,
	PORT_EXT_INT_RISING,
	PORT_EXT_INT_FALLING,
	PORT_EXT_INT_BOTH
}Port_PinExternalIntType;
typedef struct
{
  Port_ChannelType            pinId;
	Port_PinDirectionType       pinDir;
	Port_PinModeType            pinMode;
	Port_PinOutputCurrentType   currentStrength;
	Port_PinInternalAttachType  internalAttach;
	Port_PinExternalIntType     externalInt;
	
}Port_ConfigType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Port_Init (const Port_ConfigType* ConfigPtr);
 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Port.h
 *********************************************************************************************************************/
