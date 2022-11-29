/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  
 *
 *      	\details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Dio.h"
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

Dio_LevelType 		Dio_ReadClannel  (Dio_ChannelType ChannelId)
{
	uint8 port_offset    = ChannelId /8;
	uint8 channel_offset = ChannelId %8;
	
	Dio_LevelType  ReadChannel_Value = 0;
	switch (port_offset)
	{
		case (Dio_PortA):
		#if (DIO_REG_ACCESSING_TYPE == READ_MODIFY_WRITE_ACCESSING)
		ReadChannel_Value = GET_BIT(GET_REG(GPIO_PORT_A_BASE, GPIODATA_OFFSET), channel_offset);
		
		#elif (DIO_REG_ACCESSING_TYPE == BIT_BANDING_ACCESSING)
		ReadChannel_Value = GET_BBAlIAS_PRE_REG ((GPIO_PORT_A_BASE + GPIODATA_OFFSET), channel_offset) ;
				
		#elif (DIO_REG_ACCESSING_TYPE == BIT_MASKING_ACCESSING)
		
		#endif
		
		break;
		
		case (Dio_PortB):
		#if (DIO_REG_ACCESSING_TYPE == READ_MODIFY_WRITE_ACCESSING)
		ReadChannel_Value = GET_BIT(GET_REG(GPIO_PORT_B_BASE, GPIODATA_OFFSET), channel_offset);
		
		#elif (DIO_REG_ACCESSING_TYPE == BIT_BANDING_ACCESSING)
		ReadChannel_Value = GET_BBAlIAS_PRE_REG ((GPIO_PORT_B_BASE + GPIODATA_OFFSET), channel_offset) ;
				
		#elif (DIO_REG_ACCESSING_TYPE == BIT_MASKING_ACCESSING)
		
		#endif
		
		break;
		case (Dio_PortC):
		#if (DIO_REG_ACCESSING_TYPE == READ_MODIFY_WRITE_ACCESSING)
		ReadChannel_Value = GET_BIT(GET_REG(GPIO_PORT_C_BASE, GPIODATA_OFFSET), channel_offset);
		
		#elif (DIO_REG_ACCESSING_TYPE == BIT_BANDING_ACCESSING)
		ReadChannel_Value = GET_BBAlIAS_PRE_REG ((GPIO_PORT_C_BASE + GPIODATA_OFFSET), channel_offset) ;
				
		#elif (DIO_REG_ACCESSING_TYPE == BIT_MASKING_ACCESSING)
		
		#endif
		
		break;
		case (Dio_PortD):
		#if (DIO_REG_ACCESSING_TYPE == READ_MODIFY_WRITE_ACCESSING)
		ReadChannel_Value = GET_BIT(GET_REG(GPIO_PORT_D_BASE, GPIODATA_OFFSET), channel_offset);
		
		#elif (DIO_REG_ACCESSING_TYPE == BIT_BANDING_ACCESSING)
		ReadChannel_Value = GET_BBAlIAS_PRE_REG ((GPIO_PORT_D_BASE + GPIODATA_OFFSET), channel_offset) ;
				
		#elif (DIO_REG_ACCESSING_TYPE == BIT_MASKING_ACCESSING)
		
		#endif
		break;
		case (Dio_PortE):
		#if (DIO_REG_ACCESSING_TYPE == READ_MODIFY_WRITE_ACCESSING)
		ReadChannel_Value = GET_BIT(GET_REG(GPIO_PORT_E_BASE, GPIODATA_OFFSET), channel_offset);
		
		#elif (DIO_REG_ACCESSING_TYPE == BIT_BANDING_ACCESSING)
		ReadChannel_Value = GET_BBAlIAS_PRE_REG ((GPIO_PORT_E_BASE + GPIODATA_OFFSET), channel_offset) ;
				
		#elif (DIO_REG_ACCESSING_TYPE == BIT_MASKING_ACCESSING)
		
		#endif
		break;
		case (Dio_PortF):
		#if (DIO_REG_ACCESSING_TYPE == READ_MODIFY_WRITE_ACCESSING)
		ReadChannel_Value = GET_BIT(GET_REG(GPIO_PORT_F_BASE, GPIODATA_OFFSET), channel_offset);
		
		#elif (DIO_REG_ACCESSING_TYPE == BIT_BANDING_ACCESSING)
		ReadChannel_Value = GET_BBAlIAS_PRE_REG ((GPIO_PORT_F_BASE + GPIODATA_OFFSET), channel_offset) ;
				
		#elif (DIO_REG_ACCESSING_TYPE == BIT_MASKING_ACCESSING)
		
		#endif
		break;
	}
	return ReadChannel_Value;
}
void 	Dio_WriteClannel (Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	uint8 port_offset    = ChannelId /8;
	uint8 channel_offset = ChannelId %8;
	
	switch (port_offset)
	{
		case (Dio_PortA):
		
		#if (DIO_REG_ACCESSING_TYPE == READ_MODIFY_WRITE_ACCESSING)
		SET_BIT((GET_REG(GPIO_PORT_A_BASE, GPIODATA_OFFSET)), channel_offset);
		
		#elif (DIO_REG_ACCESSING_TYPE == BIT_BANDING_ACCESSING)
		GET_BBAlIAS_PRE_REG ((GPIO_PORT_A_BASE + GPIODATA_OFFSET), channel_offset) = 1;
				
		#elif (DIO_REG_ACCESSING_TYPE == BIT_MASKING_ACCESSING)
		
		#endif
		
		break;
	
		
		case (Dio_PortB):
		#if (DIO_REG_ACCESSING_TYPE == READ_MODIFY_WRITE_ACCESSING)
		SET_BIT((GET_REG(GPIO_PORT_B_BASE, GPIODATA_OFFSET)), channel_offset);

		#elif (DIO_REG_ACCESSING_TYPE == BIT_BANDING_ACCESSING)
		GET_BBAlIAS_PRE_REG ((GPIO_PORT_B_BASE + GPIODATA_OFFSET), channel_offset) = 1;

		#elif (DIO_REG_ACCESSING_TYPE == BIT_MASKING_ACCESSING)
		#endif
		
		break;
		case (Dio_PortC):
		#if (DIO_REG_ACCESSING_TYPE == READ_MODIFY_WRITE_ACCESSING)
		SET_BIT((GET_REG(GPIO_PORT_C_BASE, GPIODATA_OFFSET)), channel_offset);
		
		#elif (DIO_REG_ACCESSING_TYPE == BIT_BANDING_ACCESSING)
		GET_BBAlIAS_PRE_REG ((GPIO_PORT_C_BASE + GPIODATA_OFFSET), channel_offset) = 1;
		
		#elif (DIO_REG_ACCESSING_TYPE == BIT_MASKING_ACCESSING)
		#endif
		break;
		
		case (Dio_PortD):
		#if (DIO_REG_ACCESSING_TYPE == READ_MODIFY_WRITE_ACCESSING)
		SET_BIT((GET_REG(GPIO_PORT_D_BASE, GPIODATA_OFFSET)), channel_offset);
		
		#elif (DIO_REG_ACCESSING_TYPE == BIT_BANDING_ACCESSING)
		GET_BBAlIAS_PRE_REG ((GPIO_PORT_D_BASE + GPIODATA_OFFSET), channel_offset) = 1;
		
		#elif (DIO_REG_ACCESSING_TYPE == BIT_MASKING_ACCESSING)
		#endif
		break;
		
		case (Dio_PortE):
		#if (DIO_REG_ACCESSING_TYPE == READ_MODIFY_WRITE_ACCESSING)
		SET_BIT((GET_REG(GPIO_PORT_E_BASE, GPIODATA_OFFSET)), channel_offset);
		
		#elif (DIO_REG_ACCESSING_TYPE == BIT_BANDING_ACCESSING)
		GET_BBAlIAS_PRE_REG ((GPIO_PORT_E_BASE + GPIODATA_OFFSET), channel_offset) = 1;
		
		#elif (DIO_REG_ACCESSING_TYPE == BIT_MASKING_ACCESSING)
		#endif
		break;
		
		case (Dio_PortF):
		#if (DIO_REG_ACCESSING_TYPE == READ_MODIFY_WRITE_ACCESSING)
		SET_BIT((GET_REG(GPIO_PORT_F_BASE, GPIODATA_OFFSET)), channel_offset);
		
		#elif (DIO_REG_ACCESSING_TYPE == BIT_BANDING_ACCESSING)
		GET_BBAlIAS_PRE_REG ((GPIO_PORT_F_BASE + GPIODATA_OFFSET), channel_offset) = 1;
		
		#elif (DIO_REG_ACCESSING_TYPE == BIT_MASKING_ACCESSING)
		#endif
		break;
	}
}	
Dio_PortLevelType  Dio_ReadPort 		 (Dio_PortType PortId)
{
	Dio_PortLevelType PortValue = 0;
	switch (PortId)
	{
		case (Dio_PortF): PortValue = *(uint8 *)GPIO_PORT_F_BASE ;	
		break;
		case (Dio_PortA): PortValue = *(uint8 *)GPIO_PORT_A_BASE ;
		break;
		case (Dio_PortB): PortValue = *(uint8 *)GPIO_PORT_B_BASE ;
		break;
		case (Dio_PortC): PortValue = *(uint8 *)GPIO_PORT_C_BASE ;
		break;
		case (Dio_PortD): PortValue = *(uint8 *)GPIO_PORT_D_BASE ;
		break;
		case (Dio_PortE): PortValue = *(uint8 *)GPIO_PORT_E_BASE ;
		break;
	}	
}
void Dio_WritePort		 (Dio_PortType PortId, Dio_PortLevelType Level)
{
	switch (PortId)
	{
		case (Dio_PortF): *(uint8 *)GPIO_PORT_F_BASE =  Level;	
		break;
		case (Dio_PortA): *(uint8 *)GPIO_PORT_A_BASE =  Level;
		break;
		case (Dio_PortB): *(uint8 *)GPIO_PORT_B_BASE =  Level;
		break;
		case (Dio_PortC): *(uint8 *)GPIO_PORT_C_BASE =  Level;
		break;
		case (Dio_PortD): *(uint8 *)GPIO_PORT_D_BASE =  Level;
		break;
		case (Dio_PortE): *(uint8 *)GPIO_PORT_E_BASE =  Level;
		break;
	}
}
Dio_LevelType	Dio_FlipChannel  (Dio_ChannelType ChannelId)
{
	Dio_LevelType Channel_Satae = Dio_Low;
	
	Channel_Satae = Dio_ReadClannel (ChannelId);
	if (Channel_Satae == Dio_Low)
	{
		Dio_WriteClannel (ChannelId, Dio_High);
	}
	else 
	{
		Dio_WriteClannel (ChannelId, Dio_Low);
	}
}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
