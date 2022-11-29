/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_COnfig.h
 *       	 Module:  Dio
 *
 *    			Description:
 *  
 *********************************************************************************************************************/
#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_


#define  AHB_BUS  0
#define  APB_BUS  1

#define READ_MODIFY_WRITE_ACCESSING  1
#define BIT_BANDING_ACCESSING				 2
#define BIT_MASKING_ACCESSING				 3

/*
	AHP_BUS
  APB_BUS
*/
#define DIO_USED_BUS  APB_BUS

/*READ_MODIFY_WRITE_ACCESSING
	BIT_BANDING_ACCESSING
	BIT_MASKING_ACCESSING*/
#define DIO_REG_ACCESSING_TYPE  BIT_BANDING_ACCESSING
 
#endif  /* DIO_CONFIG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
