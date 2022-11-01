#include "Cpu_Driver.h"


void CpuDriver_EnableGlobalInterrupt (void)
{
    __asm("CPSIE i"); /*clear PRIMASK
                        Enable all interrupts*/ 
    
    /*
    __asm("MOV R0, 0x0\n");
    __asm("MSR PRIMASK, R0\n");
    */
}
void CpuDriver_DisableGlobalInterrupt(void)
{
    __asm("CPSID i"); /*set PRIMASK
                        Disable all interrupts except non maskable and HardFault*/
    /*
    __asm("MOV R0, 0x0\n");
    __asm("MSR PRIMASK, R0\n");
    */
}
void CpuDriver_StartCriticalSection  (void)
{
    CpuDriver_DisableGlobalInterrupt();
}
void CpuDriver_StopCriticalSection   (void)
{
    CpuDriver_EnableGlobalInterrupt();
}