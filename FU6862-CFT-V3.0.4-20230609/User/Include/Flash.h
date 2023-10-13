
/************************ (C) COPYRIGHT 2015 FT *******************************
* File Name          : 
* Author             : Application Team  Tom.wang 
* Version            : V2.0.0
* Date               : 06/15/2015
* Description        : 
********************************************************************************
/*******************************************************************************
* All Rights Reserved
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FLASH_H
#define __FLASH_H
#define     __I     volatile const    /*!< defines 'read only' permissions      */
#define     __O     volatile          /*!< defines 'write only' permissions     */
#define     __IO    volatile          /*!< defines 'read / write' permissions   */

typedef struct
  {
	uint16 WriteAddress;     //写入地址 
    uint8  WriteValue;       //ROM 写入值
    uint8  ReadValue;        //ROM 读出值
	uint8  FlagFlashWrite;   //写标志位
  }ROM_TypeDef;

extern ROM_TypeDef xdata  Rom;  
extern uint8 ReadFlashValue(uint16 ReadAddress);
extern void Flash_KeyWriteValue(uint16 WriteAddress, uint8 value);
extern void  Save_KeyValue(void);
#endif