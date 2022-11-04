/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *      File:  <BitOperations.h>
 *      Module:  -
 *
 *      Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef BitOperator_H_
#define	BitOperator_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include "STD_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define BITBAND_SRAM_BASE 0x20000000 // Define base address of bit-band
#define ALIAS_SRAM_BASE   0x22000000 // Define base address of alias band
#define BITBAND_PERI_BASE 0x40000000 // Define base address of peripheral bit-band
#define ALIAS_PERI_BASE   0x42000000 // Define base address of peripheral alias band

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

volatile uint32 * ALIAS_PERI_ADD = NULL;
volatile uint32 * ALIAS_SRAM_ADD = NULL;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
// Convert SRAM address to alias region

#define BITBAND_SRAM(REG_ADD,BIT_NUM) ((ALIAS_SRAM_ADD = ( ALIAS_SRAM_BASE + (REG_ADD - BITBAND_SRAM_BASE)*32 + (BIT_NUM*4))))
 
// Convert PERI address to alias region
#define BITBAND_PERI(REG_ADD,BIT_NUM) ((ALIAS_PERI_ADD = ( ALIAS_PERI_BASE + (REG_ADD - BITBAND_PERI_BASE)*32 + (BIT_NUM*4))))

#define SET_BIT (REG_ADD, BIT_NUM) {\
                                    BITBAND_PERI (REG_ADD, BIT_NUM)\
                                    if (ALIAS_PERI_ADD != NULL)\
                                    (ALIAS_PERI_ADD*) |= 1;\
                                    }\


#define CLEAR_BIT (REG_ADD, BIT_NUM) {\
                                      BITBAND_PERI (REG_ADD, BIT_NUM)\
                                      if (ALIAS_PERI_ADD != NULL)\
                                      (ALIAS_PERI_ADD*) &= 0;\
                                     }\

#define TOGGLE_BIT (REG_ADD, BIT_NUM) {\
                                       BITBAND_PERI (REG_ADD, BIT_NUM)\
                                       if (ALIAS_PERI_ADD != NULL)\
                                       (ALIAS_PERI_ADD*) ^= 0;\
                                       }\

 
#endif  /*BitOperator_H_ */

/**********************************************************************************************************************
 *  END OF FILE: BitOperations.h
 *********************************************************************************************************************/
