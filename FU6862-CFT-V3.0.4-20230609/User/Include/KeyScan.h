/**************************** (C) COPYRIGHT 2015 Fortiortech shenzhen *****************************
* File Name          : KeyScan.h
* Author             : Billy Long Fortiortech  Market Dept
* Version            : V1.0
* Date               : 01/07/2015
* Description        : This file contains all the common data types used for Motor Control.
***************************************************************************************************
* All Rights Reserved
**************************************************************************************************/ 

/* Define to prevent recursive inclusion --------------------------------------------------------*/
#ifndef __KEYSCAN_H_
#define __KEYSCAN_H_

#define SW3				GP34   //冷风按键 冷风

#define SW1       GP02   //按键SW1  控制温度

#define SW2       GP04   //按键SW2  控制转速

#define     KEY_H_ON      1           //按键高电平有效
#define     KEY_L_ON      0           //按键低电平有效

#define     SPD_LV_MAX    3           //转速最大档位数
#define     HEAT_LV_MAX   4           //温度最大档位数

#define     SPD_LV_ON     3           //上电转速档
#define     HEAT_LV_ON    0           //上电温度档

//#define     LED_SPEED_1    Led_D3_Lv
//#define     LED_SPEED_2    Led_D2_Lv
//#define     LED_SPEED_3    Led_D1_Lv

//#define     LED_HEAT_1     Led_D4_Lv
//#define     LED_HEAT_2     Led_D5_Lv
//#define     LED_HEAT_3     Led_D6_Lv

#define     LED_ALL_OFF   ClrBit(P1, P15 | P16 | P17)      //LED全关断

//#define     SPEED_LV1     75000       //RPM
//#define     SPEED_LV2     91000       //RPM
//#define     SPEED_LV3     100200      //RPM

//#define     Motor_SPEED_LV1     S_Value(SPEED_LV1)
//#define     Motor_SPEED_LV2     S_Value(SPEED_LV2)
//#define     Motor_SPEED_LV3     S_Value(SPEED_LV3)

#define STARTPAGEROMADDRESS 0X3E00

/* Exported types -------------------------------------------------------------------------------*/
typedef struct
{
	uint8 Key1Value;
	uint8 Key2Value;
	uint8 Key3Value;
	
	uint16 Key1PressCnt;
	uint16 Key2PressCnt;
	uint16 Key3PressCnt;
	uint16 Key3releaseCnt;
	
	uint16 KeyADCValue;                     //按键ADC值
	
	uint8 KeyValuetotal;
	uint8 OldKeyValuetotal;
	uint8 ChangeKeyFlg;
	
} KeyScanParam_TypeDef;


/* Exported variables ---------------------------------------------------------------------------*/
extern KeyScanParam_TypeDef xdata KS;

/* 变量全局声明 */
extern uint8  Speed_Lv;
extern uint8  heat_Lv, heat_Lv_Init;
extern int8   Heat_duty;
extern int16  Heat_duty_act;
extern uint8  Heat_duty_yu;
extern int8   Heat_duty_cycle;
extern uint16 Heat_on_delay;
extern uint8  WindTemperCmd;
extern uint16 Heatonoffcnt;
extern uint8  Secoff_flag;
extern uint8  Secoffcnt;
extern uint16 Tmpregularcnt;
extern int8   TmpPwmdelta;
extern uint8  Heat_on_flag;
extern uint8  Keysavevalue;
extern uint16 RuntimeCntX1ms;
extern uint8  RuntimeCntX1min;
extern uint16 RuntimeCntXn;
extern uint8  Cool_Lv;
extern uint8  HeatTmp_real;
extern uint16 HeatTmp_ADvalue_avg;
extern uint8  HeatTmp_old, HeatTmp_new;
extern uint8  xdata Heatduty[6];
extern uint8  Heat_on_cnt;
extern uint8  Heatdutycnt;
extern uint8  Overtmpcnt, Overtmp_flag;
extern uint16 Overtmp_recovercnt;
extern uint8  Led_play_mode;
extern uint16 Ledflashcnt;
extern uint8  HeatTmp_updowmLv;
extern uint8  Ledselfcheckflag;
extern uint16 Ledselfcheckcnt;
extern uint8  xdata BlockFlashNum;

/* Exported functions ---------------------------------------------------------------------------*/
extern void KeyInit(void);
extern int  KeyValue(void);
extern void KeyScan(void);
extern void Key_Led_Ctrl(void);
extern int16 CalTemperOffset(uint16 base,uint16 val, uint16 warm, uint16 cool);
extern void UARTDataSend(void);
#endif

