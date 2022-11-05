#include "Std_Types.h"
#include "PlatForm_Types.h"
#include "Cpu_Driver.h"

int main(void)
{
	
	while(1)
	{
		/*Set PRIMASK  : Diable all maskable interrupts */
			Cpu_StartCriticalSection ();
		
		/*Clear PRIMASK  : Enable all maskable interrupts */
		  Cpu_StopCriticalSection();
		
		/*Clear CONTROL reg*/
			CPU_SwitchToUnprivaleged();
		
		/*fire interrupt signal for SVC "To be in privalged mode to be able  access CONTROL reg and clear it" */
		  CPU_SwitchToPrivaleged();
	}
	
	return 0;
}
