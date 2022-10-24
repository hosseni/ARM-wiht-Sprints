 
/**
 * @file LinkerScript_STM32F103.ld
 * @author Elhosseni Galam 
 * @brief LinkerScript for STM32F103C8 
 * @version 0.1
 * @date 2022-10-24
 */


/* Highest address of the user mode stack */
_estack = ORIGIN(RAMEXEC) + LENGTH(RAMEXEC);	/* end of "RAMEXEC" Ram type memory */


_Min_Heap_Size = 0x200 ;  /* Required amount of heap */
_Min_Stack_Size = 0x400 ; /* Required amount of stack */
/*
0x20000000
0x8000000*/
/* Memories definition -> Label_Name(AttributeList) : ORIGIN = StartMemoryAddress,   LENGTH = MemoryLength */
MEMORY
{
  RAMEXEC    (xrw)    : ORIGIN = 0x20000000,   LENGTH  = 0x00008000
  FLASH      (rx)     : ORIGIN = 0x00000000,    LENGTH = 0x00040000
}

/* Sections */
SECTIONS
{
.isr_vector :
{
    . = ALIGN(4);
    *(.isr_vector)
    . = ALIGN(4);

} > FLASH

.Sprints_Section (0x1000) : AT (0x1000) 
{
  . = ALIGN(4);
  *(.Sprints_Section)
  *(.Sprints_Section*)
  . = ALIGN(4);
} >FLASH
  
/* .text section, The program code and other data into "FLASH" Rom type memory */
.text :
 {
    . = ALIGN(4);
    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */
    . = ALIGN(4);
    _etext = .;        /* Define a global symbols at end of code */
 } >FLASH

  /* .rodata section, Constant data into "FLASH" Rom type memory */
.rodata :
{
    . = ALIGN(4);
    *(.rodata)         /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
    . = ALIGN(4);
} >FLASH

/*used by start up code to init .data*/
_sidata = LOADADDR(.data);

  /* .data section, Initialized data sections into "RAM" Ram type memory */
.data :
{
    . = ALIGN(4);
    _sdata = .;        /* Create a global symbol at data start */
    *(.data)           /* .data sections */
    *(.data*)          /* .data* sections */
    . = ALIGN(4);
    _edata = .;        /* Define a global symbol at data end */
} >RAMEXEC AT> FLASH

  /* .bss section, Uninitialized data section into "RAM" Ram type memory */
.bss :
{
    _sbss = .;         /* Define a global symbol at bss start */
    *(.bss)            /* .bss sections */
    *(.bss*)           /* .bss* sections */
    . = ALIGN(4);
    _ebss = .;         /* Define a global symbol at bss end */
} >RAMEXEC

  /* .User_heap_stack section, used to check that there is enough "RAM" Ram  type memory left */
._user_heap_stack :
{
    . = ALIGN(8);
    . = . + _Min_Heap_Size;
    . = . + _Min_Stack_Size;
    . = ALIGN(8);
} >RAMEXEC

} /*SECTIONS*/
