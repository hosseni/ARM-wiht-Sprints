#include "IntrCtrl.h"




const Nvic_CfgType Nvic_Cfg[NVIC_ACTIVATED_INT_SIZE] ={
/* Interrupt_Number	    Group_Priority          SubGroup_Priority */
 { NVIC_GPIO_PORT_B,    2,                       1                  },
 { NVIC_GPIO_PORT_A,    2,                       2                  }
};