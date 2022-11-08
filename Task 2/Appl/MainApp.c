#include "Std_Types.h"
#include "PlatForm_Types.h"
#include "Cpu_Driver.h"
#include "IntrCtrl.h"


int main(void)
{
	
	while (1)
	{
			Cpu_StartCriticalSection();
			Cpu_StopCriticalSection();
		
		  CPU_SwitchToUnprivaleged();
		  CPU_SwitchToPrivaleged();
	}	
	return 0;
}
