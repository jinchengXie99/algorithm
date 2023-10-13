/*  -------------------------- (C) COPYRIGHT 2022 Fortiortech ShenZhen ---------------------------*/
/**
 * @copyright (C) COPYRIGHT 2022 Fortiortech Shenzhen
 * @file      xxx
 * @author    Fortiortech  Appliction Team
 * @since     Create:2022-07-14
 * @date      Last modify:2022-07-14
 * @note      Last modify author is Leo.li
 * @brief      
 */

/*  Define to prevent recursive inclusion --------------------------------------------------------*/
#ifndef __DEVELOP_H_
#define __DEVELOP_H_

#include <Customer.h>

#define I_ValueX(Curr_Value)            ((Curr_Value) * (HW_RSHUNT) * (HW_AMPGAIN) / ((HW_ADC_REF)/2))
#define I_Value(Curr_Value)             _Q15(((Curr_Value) * (HW_RSHUNT) * (HW_AMPGAIN)) / (HW_ADC_REF))
#define S_Value(SpeedValue)            _Q15((SpeedValue) / (MOTOR_SPEED_BASE * 0.994))

/*CPU and PWM Parameter*/
#define MCU_CLOCK                      (24.0)                                  // (MHz) 主频

/*double resistor sample Parameter*/
#define DLL_TIME                        (0.0)                                  // 双电阻最小脉宽设置(us),建议值为死区时间值+0.2us以上
/*three resistor overmodule Parameter*/
#define OVERMOD_TIME                    (2.0)                                  // 三电阻过调制时间(us)，建议值2.0
/*deadtime compensation*/
#define DT_TIME                         (0.0)                                  // 死区补偿时间(us)，适用于双电阻和三电阻，建议值是1/2死区时间
/*min pulse*/
#define GLI_TIME                        (0.0)                                  // 桥臂窄脉宽消除(us),建议值0.5


/*Current Calib:enable or disable*/ 
#define CalibENDIS                      (Enable)            // 一定会开  62  VREF  VHALF = 1/2 * VREF

/*SVPWM mode*/
#define SVPWM_5_Segment                 (0)                                                            // 五段式SVPWM
#define SVPWM_7_Segment                 (1)                                                            // 七段式SVPWM
#define SVPMW_Mode                      (SVPWM_7_Segment)

/*double resistor sample mode*/
#define DouRes_1_Cycle                  (0)                                                            // 1 周期采样完 ia, ib
#define DouRes_2_Cycle                  (1)                                                            // 交替采用ia, ib, 2周期采样完成
#define DouRes_Sample_Mode              (DouRes_1_Cycle)


/*根据驱动芯片的类型选择，大部分芯片为High_Level*/
#define High_Level                     (0)                                     // 驱动高电平有效
#define Low_Level                      (1)                                     // 驱动低电平有效
#define UP_H_DOWN_L                    (2)                                     // 上桥臂高电平有效，下桥臂低电平有效
#define UP_L_DOWN_H                    (3)                                     // 上桥臂低电平有效，下桥臂高电平有效

/* 内部PGA放大倍数选择 */
#define AMP2x                           (2)
#define AMP4x                           (4)
#define AMP8x                           (8)
#define AMP16x                          (16)

/* ADC参考电压配置 */
#define VREF3_0                         (0xA0)          ///< 0XA0 远离实际值  减少直接填写数值导致错误，其他同理
#define VREF4_0                         (0xB0)
#define VREF4_5                         (0xC0)
#define VREF5_0                         (0xD0)

/* 运放模式选择 */
#define AMP_NOMAL                       (0xA0)          ///< 外部放大
#define AMP_PGA_DUAL                    (0xB0)          ///< 内部PGA 双端差分输入

#define RV                             ((RV1 + RV2 + RV3) / RV3)               // 分压比
#define HW_BOARD_VOLT_MAX              (HW_ADC_REF * RV)                       // (V)  ADC可测得的最大母线电压

#define Calib_Time                     (1000)                                  // 校正次数，固定1000次，单位:次

/*正常运行时估算算法的参数设置值-------------------------------------------------*/
#define OBS_KSLIDE                     _Q15(0.85)                               // SMO算法里的滑膜增益值
#define E_BW                           (1.5*BASE_FREQ)                          // PLL算法里的反电动势滤波值
/*脉冲注入时间长于2ms 或 低于2ms*/
#define Long_Inject                    (0)                                     // 脉冲注入时间长于2ms,若时间长于4ms，则要修改定时器分频
#define Short_Inject                   (1)                                     // 脉冲注入时间低于2ms
#define InjectTime                     (Short_Inject)

//open 算法启动参数
#define MOTOR_OPEN_ACC                 (16000.0)                                 // 强拖启动的增量(每载波周期加一次)
#define MOTOR_OPEN_ACC_MIN             (50.0)                                  // 强拖启动的初始速度
#define MOTOR_OPEN_ACC_CNT             (3.0)                                 // 强拖启动的执行次数(MOTOR_OPEN_ACC_CNT*256)
#define MOTOR_OPEN_ACC_CYCLE           (0)                                     // 强拖启动循环拖动的次数

#define ATT_COEF                       (0.85)                                  // 无需改动
//调速模式
#define PWMMODE                        (0)                                     // PWM调速
#define ONOFFTEST                      (1)                                     // 测试模式
#define NONEMODE                       (2)                                     // 直接给定值，不调速
#define KEYSCANMODE                    (3) 
#define TOUCHMODE                      (4)                                     // 开关启停

/*估算器模式选择*/
#define SMO                            (0)                                     // SMO ,滑膜估算
#define AO                             (1)                                      // AO , 自适应
#define PLL                            (2)                                     // PLL ,锁相环

/*顺逆风判断设置*/
#define NoTailWind                     (0)                                     // 无逆风顺风判断
#define TailWind                       (1)                                     // 逆风顺风判断

/*顺逆风判断方法*/
#define BEMFMethod                     (1)                                     // BEMF方法
#define FOCMethod                      (2)                                     // FOC计算方法

/*开环启动模式选择*/
#define Observer_Start                 (0)                                     // 新低速估算启动
#define Omega_Start                    (1)                                     // Omega启动
#define Open_Omega_Start               (2)                                     // 先开环启，后Omega启动

/*电流采样模式*/
#define Single_Resistor                (0)                                     // 单电阻电流采样模式
#define Double_Resistor                (1)                                     // 双电阻电流采样模式
#define Three_Resistor                 (2)                                     // 三电阻电流采样模式

/* -----过调制使能----- */
#define OverModulation                 (0)                                     // 0-禁止过调制，1-使能过调制

/*Key Scan Parameter*/
#define KeyFilterTime				   (100)	

#endif

