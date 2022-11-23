#include "Std_Types.h"
#include "Mcu.h"

/* Configuartion file */
#define MCU_CLOCK_GATE_GPIOA     20u
#define MCU_CLOCK_GATE_GPIOB     21u
#define MCU_CLOCK_GATE_GPIOE     24u


#define MCU_CLOCK_GATE_WD0       00u
#define MCU_CLOCK_GATE_WD1       01u

#define Mcu_Clock_0        0
#define Mcu_Clock_1        1


uint8 Mcu_ActivatedClockGates[MCU_ACTIVATED_CLOCK_GATES_SIZE]=
{
	MCU_CLOCK_GATE_GPIOA,
	MCU_CLOCK_GATE_GPIOB,
	MCU_CLOCK_GATE_WD0

};

const Mcu_ConfigType McuConfig[MCU_CLOCK_SETTINGS_SIZE]=
{
	/*ClockSettingID*/ /* ClockSource                        PllUse     Freq_KHz  */
	/* 0            */ {  MCU_CLOCK_SOURCE_MOSC             ,ENABLE     ,16000},
	/* 1            */ {  MCU_CLOCK_SOURCE_PIOSC            ,ENABLE     ,16000},
};