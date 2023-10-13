/**************************** (C) COPYRIGHT 2017 Fortiortech shenzhen *****************************
* File Name          : FU68xx_2_System.c
* Author             : Fortiortech  Appliction Team
* Version            : V1.0
* Date               : 10-Apr-2017
* Description        : This file contains the system function used for Motor Control.
***************************************************************************************************
* All Rights Reserved
**************************************************************************************************/
/* Includes -------------------------------------------------------------------------------------*/
#include <FU68xx_2.h>


/* WatchDog Config-------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
    Function Name ：WatchDogConfig(Value ,Status)
    Description   ：看门狗定时函数初始化，看门狗使能和复位使能，定时配置
    Input         ：Value--定时时间，单位ms，最小定时时间8ms，最大定时1800ms
                  Statue--使能控制，Disable或Enable
  Output                ：None
-------------------------------------------------------------------------------------------------*/
void WatchDogConfig(uint16 Value, bool Status)
{
    SetReg(CCFG1, WDTEN, (Status ? WDTEN : 0x00));
    WDT_REL = ((uint16)(65532 - (uint32)Value * 32768 / 1000) >> 8);
    ClrBit(WDT_CR, WDTF);
    SetBit(WDT_CR, WDTRF);
}


/*-------------------------------------------------------------------------------------------------
    Function Name ：WatchDogRefresh(Value ,Status)
    Description   ：刷新看门狗计数器
    Input         ：None
  Output                ：None
-------------------------------------------------------------------------------------------------*/
void WatchDogRefresh(void)
{
    SetBit(WDT_CR, WDTRF);
}
