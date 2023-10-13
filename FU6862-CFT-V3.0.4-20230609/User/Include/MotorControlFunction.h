/*  -------------------------- (C) COPYRIGHT 2020 Fortiortech ShenZhen ---------------------------*/
/*  File Name      : MotorControlFunction.h
/*  Author         : Fortiortech  Appliction Team
/*  Version        : V1.0
/*  Date           : 2020-09-06
/*  Description    : This file contains MotorControl parameter used for Motor Control.
/*  ----------------------------------------------------------------------------------------------*/
/*                                     All Rights Reserved
/*  ----------------------------------------------------------------------------------------------*/

/*  Define to prevent recursive inclusion --------------------------------------------------------*/
#ifndef __MOTOR_CONTROL_FUNCTION_H_
#define __MOTOR_CONTROL_FUNCTION_H_

/* Define to prevent recursive inclusion -------------------------------------*/
typedef struct
{
  int16   IuOffset;       //Iu的偏置电压
  int32   IuOffsetSum;    //Iu的偏置电压总和
  int16   IvOffset;       //Iv的偏置电压
  int32   IvOffsetSum;    //Iv的偏置电压总和
  int16   Iw_busOffset;   //Iw或Ibus的偏置电压
  int32   Iw_busOffsetSum;//Iw或Ibus的偏置电压总和
  int16   OffsetCount;    //偏置电压采集计数
  int8    OffsetFlag;      //偏置电压结束标志位
}CurrentOffset;

extern CurrentOffset xdata mcCurOffset;
extern void GetCurrentOffset(void);
extern void Motor_Ready (void);
extern void Motor_Init (void);

extern void FOC_Init(void);
extern void Motor_Charge(void);
extern void MC_Stop(void);
extern void Motor_TailWind(void);
extern void TailWindDealwith(void);
extern void Motor_Open(void);
extern void Motor_Align(void);
extern void McTailWindDealwith(void);
extern void MotorcontrolInit(void);
extern void BEMFTailWindDealwith(void);
extern void FOCCloseLoopStart(void);
#endif