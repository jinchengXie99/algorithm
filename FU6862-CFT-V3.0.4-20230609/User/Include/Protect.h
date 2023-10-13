/*  -------------------------- (C) COPYRIGHT 2022 Fortiortech ShenZhen ---------------------------*/
/**
 * @copyright (C) COPYRIGHT 2022 Fortiortech Shenzhen
 * @file      xxx
 * @author    Fortiortech  Appliction Team
 * @since     Create:2022-07-14
 * @date      Last modify:2022-08-04
 * @note      Last modify author is Leo.li
 * @brief      
 */

/*  Define to prevent recursive inclusion --------------------------------------------------------*/
#ifndef __PROTECT_H_
#define __PROTECT_H_

#define Tempera_Value(NTC_Value)       _Q15((5.0*NTC_Value/(10.0+NTC_Value))/HW_ADC_REF)
/*保护参数值-------------------------------------------------------------------*/
 /*硬件过流保护*/

 /*硬件过流保护比较值来源*/
 #define Compare_DAC                    (0)                                    // DAC设置硬件过流值
 #define Compare_Hardware               (1)                                    // 硬件设置硬件过流值
 #define Compare_Mode                   (Compare_DAC)                          // 硬件过流值的来源
 #define OverHardcurrentValue           (5.0)                                  // (A) DAC模式下的硬件过流值

 /*软件过流保护参数设置*/
 #define OverSoftCurrent_DectTime       (5)                                    ///< (ms)软件过流检测时间
 #define OverSoftCurrentValue           I_Value(2.5)                           // (A) 软件过流值   相电流

 /*过欠压保护参数设置*/
 #define Over_Protect_Voltage           (356)     // DC                             // (V) 直流电压过压保护值
 #define Over_Recover_Vlotage           (364)                                  // (V) 直流电压过压保护恢复值
 #define Under_Protect_Voltage          (220)                                  // (V) 直流电压欠压保护值
 #define Under_Recover_Vlotage          (260)                                  // (V) 直流电压欠压保护恢复值
 #define Under_Brake_Vlotage            _Q15(180 / HW_BOARD_VOLT_MAX)
  
 /*缺相保护参数设置*/
 #define PhaseLoss_DectTIME             (50)                                    ///< (ms) 峰值检测周期时间,需满足覆盖至少一个完整电周期
 #define PhaseLossCurrentValue          I_Value(0.10)                          // (A)  缺相电流值
 #define PhaseLossLeftNum               (1)                                    // 三相电流差值判断右移位数,寄存器采集电流值较大可适当给大，反之给小

 /*堵转保护参数设置*/
// #define StallCurrentValue              I_Value(4.0)                           // (A)  堵转过流值
 #define MOTOR_SPEED_STAL_MAX_RPM       (150000.0)                             // (RPM) 堵转失速保护转速
 #define MOTOR_SPEED_STAL_MIN_RPM       (7000)                                 // (RPM) 堵转保护转速 
 
 /*功率保护参数设置*/
 #define PowerLimit                     (23500)    // 寄存器的估算值                            // 功率上限值 6500:300W

 /*mos过温保护参数设置*/
 #define OverTemperProtectValue         Tempera_Value(3.679)                     // mos过温保护温度阈值
 
 /*发热丝过温保护参数设置*/
 #define HeatOverTempValue              CELSIUS_P160_ADC_B // HEAT_CELSIUS_ADC(0.5)
 
 /*  保护重启参数设置  */
 #define CurrentRecoverEnable           (1)                                    // 过流恢复, 0，不使能；1，使能
 #define CurrentRecoverTimes            (2)                                    // 重启次数,设定值<255 达到重启次数后不再重启，设定值>=255，一直重启
 #define OverCurrentRecoverTime         (2000)                                 // (5ms) 过流保护恢复时间
 
 #define VoltageRecoverEnable           (1)                                    // 过流恢复, 0，不使能；1，使能
 #define VoltageRecoverTimes            (255)                                    // 重启次数,设定值<255 达到重启次数后不再重启，设定值>=255，一直重启
 #define VoltageRecoverTime             (150)                                  // (5ms) 过流保护恢复时间
 
 #define PowerRecoverEnable             (0)                                    //功率保护恢复使能  0，不使能；1，使能
 #define PowerRecoverTimes              (2)                                    // 重启次数,设定值<255 达到重启次数后不再重启，设定值>=255，一直重启
 #define OverPowerRecoverTime           (2000)                                 // (5ms) 功率保护恢复时间 

 #define StallRecoverEnable             (1)                                    // 堵转保护恢复使能  0，不使能；1，使能
 #define StallRecoverTimes              (2)                                    // 重启次数,设定值<255 达到重启次数后不再重启，设定值>=255，一直重启
 #define StallRecoverTime               (1000)                                  // (5ms) 堵转保护恢复时间

 #define StartRecoverEnable             (1)                                    // 启动保护恢复使能  0，不使能；1，使能
 #define StartRecoverTimes              (5)                                    // 重启次数,设定值<255 达到重启次数后不再重启，设定值>=255，一直重启
 #define StartRecoverTime               (200)                                 // (5ms) 启动保护恢复时间 

 #define PhaseLossRecoverEnable         (1)                                    // 缺相保护恢复使能  0，不使能；1，使能
 #define PhaseLossRecoverTimes          (2)                                    // 重启次数,设定值<255 达到重启次数后不再重启，设定值>=255，一直重启
 #define PhaseLossRecoverTime           (2000)                                 // (5ms) 缺相保护恢复时间
 
 #define Mos_TemperatureRecoverEnable   (1)                                    // mos过温保护恢复使能
 #define MosTemperRecoverTimes          (2)                                    // mos过温保护恢复次数
 #define MosTemperRecoverTime           (2000)                                 // mos过温保护恢复检测时间
 #define OverTemperRecoverValue         Tempera_Value(5.004)                     // mos过温保护恢复温度阈值
 
 /*保护使能*/
 #define OverSoftCurrentProtectEnable   (1)                                    // 软件过流保护，0,不使能；1，使能
 #define VoltageProtectEnable           (1)                                    // 电压保护，0,不使能；1，使能
 #define StartProtectEnable             (1)                                    // 启动保护，0,不使能；1，使能
 #define StallProtectEnable             (1)                                    // 堵转失速保护，0,不使能；1，使能
 #define PhaseLossProtectEnable         (1)                                    // 缺相保护，0,不使能；1，使能
 #define OverPowerProtectEnable         (0)                                    // 功率保护，0,不使能；1，使能
 #define HEATEROTProtectEnable          (1)                                    // 发热丝过温保护
 #define Mos_TemperatureProtectEnable   (1)                                    // mos过温保护
 


/* Exported types -------------------------------------------------------------------------------*/
typedef struct
{
    //Current protect
    uint8       OverCurCnt;               // 软件过流计数   
	int16       Is; 	
    uint16      Max_ia;                   // IA的最大值
    uint16      Max_ib;                   // IB的最大值
    uint16      Max_ic;                   // IC的最大值
} CurrentVarible;

typedef struct
{
    uint8      SecondStartTimes;   // 二次启动保护的次数
    uint8      StartFlag;          // 启动保护的标志位，用于判断哪个方法起作用
    uint8      StallTimes;         // 堵转保护次数
    uint8      StallFlag;          // 堵转保护的标志位，用于判断哪个方法起作用
    uint8      LossPHTimes;        // 缺相保护次数
    uint8      CurrentPretectTimes;// 过流保护次数
    uint8      PowerPretectTimes;  // 功率保护次数
	uint8      VoltagePretectTimes;  // 电压保护次数
    uint8      MosTemperPretectTimes;
} ProtectVarible;

typedef struct
{
    //voltage protect
    uint16      OverVoltDetecCnt; // 过压检测计数
    uint16      UnderVoltDetecCnt;// 欠压检测计数
    uint16      VoltRecoverCnt;   // 过压恢复计数
    uint16      VoltDetecBraketCount;
	uint8       FlagBrakeInit;
	uint16      VoltDetecBraketDuty;
    uint8       UnderVotBrakeFlag;
    
    //Power Protect
    uint16      OverPowerDetecCnt;   //过功率检测次数
    //OVER Current protect recover
    uint16      CurrentRecoverCnt;  // 过流保护恢复计数
      
    //stall protect
    uint16      StallDelayCnt;        // 堵转延迟判断计时
    uint16      StallDectEs;          // method 1，与ES相关
    uint16      StallDectSpeed;       // method 2，与速度相关
    uint16      mcStallDeCurrent;     //堵转电流检测次数
    uint16      StallReCount;         // 堵转保护恢复计数
           
    //Loss Phase protect    
    uint16      Lphasecnt;            // 缺相保护计时
    uint16      AOpencnt ;            // A缺相计数
    uint16      BOpencnt ;            // B缺相计数
    uint16      COpencnt ;            // C缺相计数
    uint16      mcLossPHRecCount;     // 缺相恢复计数
    
    //start protect    
    uint16       StartESCount;         // 启动保护判断ES的计数
    uint16       StartEsCnt;           // 启动保护判断ES的计时
    uint16       StartDelay;           // 启动保护判断ES的延迟
    uint16       StartFocmode;         // 启动保护判断FOCMODE状态的计时
    uint16       StartSpeedCnt;        // 启动保护判断速度和ES的计时
    uint16       StartRecoverDelayCnt; //启动保护恢复延时计数   
    
    uint16       MosTemperCnt;         // mos过温检测计数
    uint16       MosTemperRecover;      // mos过温保护恢复延时计数
} FaultVarible;

typedef enum
{
    FaultNoSource         = 0,         // 无故障
    FaultHardOVCurrent    = 1,         // 硬件过流
    FaultSoftOVCurrent    = 2,         // 软件过流
    FaultUnderVoltage     = 3,         // 欠压保护
    FaultOverVoltage      = 4,         // 过压保护
    FaultLossPhase        = 5,         // 缺相保护
    FaultStall            = 6,         // 堵转保护
    FaultStart            = 7,         // 启动保护
    FaultOverwind         = 8,         // 顺逆风失败保护
    FaultOverPower        = 9,         //功率保护
    FaultStallenter       = 10,        //堵进风口保护
    FaultMosOverTemperature = 11,      // mos过温保护
} FaultStateType;

extern CurrentVarible   xdata     mcCurVarible;
extern ProtectVarible   xdata     mcProtectTime;
extern FaultStateType   xdata     mcFaultSource;
extern FaultVarible     xdata     mcFaultDect;

/* Exported functions ---------------------------------------------------------------------------*/
extern void Fault_OverUnderVoltage(void);
extern void Fault_Power(void);
extern void Fault_Overcurrent(void);
extern void Fault_OverCurrentRecover(void);
extern void Fault_OverPowerRecover(void);
extern void Fault_Stall(void);
extern void Fault_Start(void);
extern void Fault_phaseloss(void);
extern void Fault_Detection(void);
extern void FaultProcess(void);
extern void UnderProcess(void);
extern void Fault_MosTemperature(void);
extern void Fault_HeaterOverTemp(void);
//extern void Fault_RecoverDetection(void);

#endif

