#ifndef Cpu_Driver_H_
#define Cpu_Driver_H_


void CpuDriver_EnableGlobalInterrupt (void);
void CpuDriver_DisableGlobalInterrupt(void);
void CpuDriver_StartCriticalSection  (void);
void CpuDriver_StopCriticalSection   (void);

#endif /*Cpu_Driver_H_*/