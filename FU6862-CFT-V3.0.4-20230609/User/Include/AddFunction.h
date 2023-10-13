/*  -------------------------- (C) COPYRIGHT 2022 Fortiortech ShenZhen ---------------------------*/
/**
 * @copyright (C) COPYRIGHT 2022 Fortiortech Shenzhen
 * @file      LED.c
 * @author    Fortiortech  Appliction Team
 * @since     Create:2022-07-14
 * @date      Last modify:2022-07-14
 * @note      Last modify author is Leo.li
 * @brief      
 */

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __AddFuntion_H_
#define __AddFuntion_H_


/* Exported types -------------------------------------------------------------------------------*/
typedef struct
{
    uint16      ON_Count;           // 运行时间计数
    uint16      OFF_Count;          // 停止时间计数
    uint16      ONOFF_Times;        // 启停计数
    uint8       ONOFF_Flag;         // 启停测试中启动标志位
} ONVarible;


typedef struct
{
    uint16 mcDcbusFlt;              // 母线电压
	uint16 mcIbusFlt;              // 母线电流
    uint8  CtrlMode;                // 控制模式
    uint16 CurrentPower;            // 当前功率
    uint16 Powerlpf;                // 功率滤波后的值
    uint16 mcIqref;                 // Q轴给定电流
    uint16 mcPosCheckAngle;         // 位置检测的角度
    int16  SpeedFlt;                // 当前速度滤波后的值
    
    uint16 EsValue;                 // 当前FOC_ESQU滤波后的值
    int16  UqFlt;                   // UQ滤波后的值
    int16  UdFlt;                   // UD滤波后的值
    uint16 SpeedLoopTime;           // 速度环时间
    uint8  ChargeStep;              // 预充电的步骤
    uint16 State_Count;             // 电机各个状态的时间计数

} FOCCTRL;

typedef struct
{
	uint8  FlagONOFF;	
	uint8  FlagFR;                 // 电机方向改变标志位
	uint8  FR_Status;              // 电机运行方向
    uint16 TargetValue;
    uint16 ActualValue;
    uint16 PowerLimitValue;        // 功率限制的值	
}MC_CONTROL;


typedef struct
{
    uint32 SleepDelayCout;
    uint8  SleepFlag;
    uint8  SleepEn;
} SLEEPMODE;


typedef struct
{
    int16  RefValue;
    float  OutValue_float;
    float  IncValue;
    float  DecValue;
   
}MCRAMP;

typedef struct
{
    uint16   ExtKP;            // KP
    uint16   ExtKI;            // KI
    //uint16   ExtErr;           // PI Err value
    int16   ExtOut;           // output value
	int16   ExtEK;           // output value
	//int16   ExtEK1;           // output value
	//int16   ExtEK2;           // output value
	//int16   ExtD_Value;
    int16   ExtOutMax;        // output max value
    int16   ExtOutMin;        // output min value
} OUTLOOP;

/* Exported variables ---------------------------------------------------------------------------*/
extern ONVarible        xdata     ONOFFTest;
extern FOCCTRL          xdata     mcFocCtrl;
extern SLEEPMODE        xdata     SleepSet;
extern OUTLOOP          xdata     SpeedPICtrl;
extern MCRAMP           xdata     mcRefRamp;
extern MC_CONTROL       xdata     MCCtrl;

extern int8   PWMadapt;

extern uint16 Ubusmaxavg;
extern uint16 Ubusmax;
extern uint32 Ubusmaxsum;
extern uint8  Ubusmaxcnt;
extern uint8  Ubusmaxsumcnt;

extern uint8  OverVoltageflag;
extern uint8  Getzero_flag;
extern uint16 Key_ADvalue_avg;
extern uint32 HeatTmp_ADvalue_sum;
extern uint8  HeatTmp_sum_cnt;
extern uint8  VoltDetecExternCnt;

/* Exported functions ---------------------------------------------------------------------------*/
extern void VariablesPreInit(void);
extern void Speed_response(void);
extern int16 Motor_Ramp(int16 ref);
extern void VSPSample(void);

extern void Sleepmode(void);

extern uint32 Abs_F32(int32 value);
extern uint16 Abs_F16(int16 value);
extern void StarRampDealwith(void);
extern void TargetSpeed_Colletion(void);
extern void ONOFF_Starttest(void);
extern void Touch_Control(void);

extern void TailWindSpeedDetect(void);

extern void OutLoopParameterSet(void);
extern void FRControl(void);

extern void  TickCycle_1ms(void);
extern void  LED_Display(void);
extern void  HEATER_CONTROL(void);

#endif