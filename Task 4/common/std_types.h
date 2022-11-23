#ifndef STD_Types_H_
#define STD_Types_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "platform_types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define WORD_LENGTH_BITS      32u
#define WORD_LENGTH_BYTES     4u
#define MSB_FIRST             0u    /* big endian bit ordering */
#define LSB_FIRST        1u    /* little endian bit ordering */

#define HIGH_BYTE_FIRST  0u    /* big endian byte ordering */
#define LOW_BYTE_FIRST   1u    /* little endian byte ordering */

#ifndef TRUE
   #define TRUE   1u
#endif

#ifndef FALSE
   #define FALSE  0u
#endif

#define ENABLE    1u
#define DISABLE   0u

#define CPU_BIT_ORDER    LSB_FIRST        /*little endian bit ordering*/
#define CPU_BYTE_ORDER   LOW_BYTE_FIRST   /*little endian byte ordering*/



typedef uint8 Std_ReturnType;
#define OK          0u
#define NOT_OK      1u

/* NULL_PTR define with a void pointer to zero definition*/
#define NULL_PTR       ((void *)0)



#endif /*STD_Types_H_*/