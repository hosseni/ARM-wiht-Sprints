
#include "Std_Types.h"
#include "PlatForm_Types.h"
#include "Cpu_Driver.h"
#include "IntrCtrl.h"

#include "Mcu.h"
extern const Mcu_ConfigType McuConfig[];

int main (void)
{
	
	Mcu_Init(McuConfig);
	Mcu_InitClock(0);
	Mcu_DistributePllClock();
	while (Mcu_GetPllStatus () == MCU_PLL_POWERED_LOCKED);
	Mcu_PerformReset();
	while(1)
	{
	
	}
	
}
