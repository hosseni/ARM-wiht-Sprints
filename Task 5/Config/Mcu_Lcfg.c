#include "Std_Types.h"
#include "Mcu.h"

/* Configuartion file */

/*Activation Gate */
#define MCU_CLOCK_GATE_GPIOA     20u
#define MCU_CLOCK_GATE_GPIOB     21u
#define MCU_CLOCK_GATE_GPIOC     22u
#define MCU_CLOCK_GATE_GPIOD     23u
#define MCU_CLOCK_GATE_GPIOE     24u
#define MCU_CLOCK_GATE_GPIOF     25u

#define MCU_CLOCK_GATE_WD0       00u
#define MCU_CLOCK_GATE_WD1       01u


#define Mcu_Clock_0        0
#define Mcu_Clock_1        1


uint8 Mcu_ActivatedClockGates[MCU_ACTIVATED_CLOCK_GATES_SIZE]=
{
	MCU_CLOCK_GATE_GPIOA,
	/*
	MCU_CLOCK_GATE_GPIOB,
	MCU_CLOCK_GATE_GPIOC,
	MCU_CLOCK_GATE_GPIOD,
	MCU_CLOCK_GATE_GPIOE,
	MCU_CLOCK_GATE_GPIOF,
	MCU_CLOCK_GATE_WD1
	*/
};

const Mcu_ConfigType McuConfig[MCU_CLOCK_SETTINGS_SIZE]=
{
	/*ClockSettingID*/ /* ClockSource                        PllUse     Freq_KHz  */
	/* 0            */ {  MCU_CLOCK_SOURCE_MOSC             ,DISABLE     ,16000},
	/* 1            */ {  MCU_CLOCK_SOURCE_PIOSC            ,DISABLE     ,16000},
};