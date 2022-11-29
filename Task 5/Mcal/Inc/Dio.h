/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       File:  Dio.h
 *       Module:  Dio
 *
 *  Description:  Header file for Dio Module     
 *  
 *********************************************************************************************************************/
#ifndef DIO_H_
#define DIO_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "platform_types.h"
#include "Dio_Config.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


typedef enum 
{
	 Dio_Channel_A0, /*portA*/
	 Dio_Channel_A1,
	 Dio_Channel_A2,
	 Dio_Channel_A3,
	 Dio_Channel_A4,
	 Dio_Channel_A5,
	 Dio_Channel_A6,
	 Dio_Channel_A7,
	
	Dio_Channel_B0, /*portB*/
	 Dio_Channel_B1,
	 Dio_Channel_B2,
	 Dio_Channel_B3,
	 Dio_Channel_B4,
	 Dio_Channel_B5,
	 Dio_Channel_B6,
	 Dio_Channel_B7,
	 
	Dio_Channel_C0, /*portC*/
	 Dio_Channel_C1,
	 Dio_Channel_C2,
	 Dio_Channel_C3,
	 Dio_Channel_C4,
	 Dio_Channel_C5,
	 Dio_Channel_C6,
	 Dio_Channel_C7,
	 
	 Dio_Channel_D0,	/*portD*/
	 Dio_Channel_D1,
	 Dio_Channel_D2,
	 Dio_Channel_D3,
	 Dio_Channel_D4,
	 Dio_Channel_D5,
	 Dio_Channel_D6,
	 Dio_Channel_D7,
	 
	 Dio_Channel_E0,  /*portE*/
	 Dio_Channel_E1,
	 Dio_Channel_E2,
	 Dio_Channel_E3,
	 Dio_Channel_E4,
	 Dio_Channel_E5,
	 
	 Dio_Channel_F0 = 41,  /*portF*/
	 Dio_Channel_F1,
	 Dio_Channel_F2,
	 Dio_Channel_F3,
	 Dio_Channel_F4
	 
}Dio_ChannelType;

typedef enum 
{
	Dio_Input, 
	Dio_Output
	
}Dio_ChannelDirectionType;
typedef enum 
{
	 Dio_PortA,
	 Dio_PortB,
	 Dio_PortC,
	 Dio_PortD,
	 Dio_PortE,
	 Dio_PortF
	
}Dio_PortType;

typedef enum 
{
	Dio_Low,
	Dio_High
	
}Dio_LevelType;

typedef uint8 Dio_PortLevelType;
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void 				Dio_SetChannelDirection ( Dio_ChannelType ChannelId, Dio_ChannelDirectionType ChannelDirection);
Dio_LevelType 		Dio_ReadChannel  (Dio_ChannelType ChannelId);
void 				Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_PortLevelType   Dio_ReadPort 	 (Dio_PortType PortId);
void 				Dio_WritePort	 (Dio_PortType PortId, Dio_PortLevelType Level);
Dio_LevelType		Dio_FlipChannel  (Dio_ChannelType ChannelId);



/******************************************************************************/

 
#endif  /* DIO_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/