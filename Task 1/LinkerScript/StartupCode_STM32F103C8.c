
/**
 * @file StartupCode_STM32F103C8.c
 * @author Elhosseni Galam 
 * @brief StartUp code for STM32F103C8 
 * @version 0.1
 * @date 2022-10-24
 */



#include "STD_TYPES.h"

/*********************************************************************/
extern int main (void);
extern u32 _estack, _etext, _sdata, _edata, _sbss, _ebss, _sidata;
/*********************************************************************/

u32 * const MSP_Value = (u32 *)&_estack;
/****************************************************************************************/

void Reset_Handler                     (void);
/******************************************************************************************/



u32 *Vector_Table []   __attribute__ ((section (".isr_vector"))) =
{
    (u32 *)MSP_Value,                          /* Main Stack Pointer */
    (u32 *)Reset_Handler,                     /* Reset */
};


void Reset_Handler (void)
{
    u32 Section_Size = 0;
 
    u32 *MemSourceAddr = NULL;
    u32 *MemDesAddr = NULL;

/*copy the data segment initialization from flash to SRAM*/
  Section_Size = &_edata - &_sdata;
  MemSourceAddr = (u32 *) &_sidata;/*this address is the start address of .data on FLAS (LMA) */
  MemDesAddr    = (u32 *) &_sdata;  /*this address is the start address of .data on RAM (VMA) */
  
  for (u32 MemCounter = 0 ; MemCounter < Section_Size ; MemCounter++)
  {
        *MemDesAddr++ = *MemSourceAddr++;
  }

/*initialize the .bss segment with zero*/
Section_Size = &_ebss - &_sbss;
MemDesAddr    = (u32 *) &_sbss;  /*this address is the start address of .bss on RAM */
  for (u32 MemCounter = 0 ; MemCounter < Section_Size ; MemCounter++)
  {
        *MemDesAddr++ = 0;
  }

/*call the system initalization function*/

/*call the main function*/
main();
}
