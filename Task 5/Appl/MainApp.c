
#include "Std_Types.h"
#include "PlatForm_Types.h"
#include "Mcu_Hw.h"
#include "Dio.h"
#include "Mcu.h"
#include "Port.h"
//   0x40000000, 0xDFFFFFFF

extern Mcu_ConfigType  McuConfig[];
extern Port_ConfigType Port_Config [];
Dio_LevelType Channel_Value;

int main (void)
{
	
	Mcu_Init(McuConfig);
	Mcu_InitClock (CLOCK_1);
	
	Port_Init (Port_Config);
	
	Dio_WriteClannel (Dio_Channel_A0, Dio_High);
	Dio_WritePort (Dio_PortA, 255);
	/*
	Dio_WriteClannel (Dio_Channel_B0, Dio_High);
	Dio_WriteClannel (Dio_Channel_C0, Dio_High);
	Dio_WriteClannel (Dio_Channel_D0, Dio_High);
	Dio_WriteClannel (Dio_Channel_E0, Dio_High);
	Dio_WriteClannel (Dio_Channel_F0, Dio_High);
	*/
	
	Channel_Value = Dio_ReadPort (Dio_PortA);
	/*
	Channel_Value[1] = Dio_ReadClannel (Dio_Channel_B0);
	Channel_Value[2] = Dio_ReadClannel (Dio_Channel_C0);
	Channel_Value[3] = Dio_ReadClannel (Dio_Channel_D0);
	Channel_Value[4] = Dio_ReadClannel (Dio_Channel_E0);
	Channel_Value[5] = Dio_ReadClannel (Dio_Channel_F0);
	*/
	

	while(1)
	{
	
	}
	
}
