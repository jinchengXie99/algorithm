/**************************** (C) COPYRIGHT 2017 Fortiortech shenzhen *****************************
* File Name          : Parameter.h
* Author             : Fortiortech  Appliction Team
* Version            : V1.0
* Date               : 2017-12-20
* Description        : This file contains all FOC debug parameter.
***************************************************************************************************
* All Rights Reserved
**************************************************************************************************/

/* Define to prevent recursive inclusion --------------------------------------------------------*/

#ifndef __Parameter_H_
#define __Parameter_H_

#include <Develop.h>

/* Define to prevent recursive inclusion -------------------------------------*/
/* Q format define ---------------------------------------------------------------------------------*/
#define _Q7(A)                          (int8) ((A) * 0x7f)         ///< Q7 format
#define _Q8(A)                          (int16)((A) * 0xff)         ///< Q8 format
#define _Q9(A)                          (int16)((A) * 0x1ff)        ///< Q9 format
#define _Q10(A)                         (int16)((A) * 0x3ff)        ///< Q10 format
#define _Q11(A)                         (int16)((A) * 0x07ff)       ///< Q11 format
#define _Q12(A)                         (int16)((A) * 0x0fff)       ///< Q12 format
#define _Q13(A)                         (int16)((A) * 0x1fff)       ///< Q13 format
#define _Q14(A)                         (int16)((A) * 0x3fff)       ///< Q14 format
#define _Q15(A)                         (int16)((A) * 0x7fff)       ///< Q15 format
#define _Q16                            (65535.0)                   ///< Q16 format value
#define _2PI                            (3.1415926 * 2)             ///< 2 PI value

/* Private define ------------------------------------------------------------*/
#define SystemPowerUpTime               (10000)                                           // 上电等待时间，cpu计数时钟

#if (HW_ADC_VREF==VREF5_0)
 #define HW_ADC_REF                     (5.0)                                    ///< (V)  ADC参考电压
#elif (HW_ADC_VREF==VREF4_5)
 #define HW_ADC_REF                     (4.5)                                    ///< (V)  ADC参考电压
#elif (HW_ADC_VREF==VREF4_0)
 #define HW_ADC_REF                     (4.0)                                    ///< (V)  ADC参考电压
#elif (HW_ADC_VREF==VREF3_0)
 #define HW_ADC_REF                     (3.0)                                    ///< (V)  ADC参考电压
#endif

/*芯片参数值------------------------------------------------------------------*/
/*CPU and PWM Parameter*/
#define PWM_CYCLE                       (1000.0 / PWM_FREQUENCY)                          // 周期us
#define SAMP_FREQ                       (PWM_FREQUENCY * 1000)                            // 采样频率(HZ)
#define TPWM_VALUE                      (1.0 / SAMP_FREQ)                                 // 载波周期(S)
#define PWM_VALUE_LOAD                  (uint16)(MCU_CLOCK * 500 / PWM_FREQUENCY)         // PWM 定时器重载值

/*deadtime Parameter*/
#define PWM_LOAD_DEADTIME               (PWM_DEADTIME * MCU_CLOCK)                        // 死区设置值
#define PWM_OVERMODULE_TIME             (OVERMOD_TIME * MCU_CLOCK / 2)                    // 过调制时间
#define PWM_DLOWL_TIME                  (DLL_TIME * MCU_CLOCK / 2)                        //下桥臂最小时间
/*single resistor sample Parameter*/
#define PWM_TS_LOAD                     (uint16)(_Q16 / PWM_CYCLE * MIN_WIND_TIME / 16)                 // 单电阻采样设置值
#define PWM_DT_LOAD                     (uint16)(_Q16 / PWM_CYCLE * DT_TIME / 16)                       // 死区补偿值
#define PWM_TGLI_LOAD                   0//(uint16)(_Q16 / PWM_CYCLE * (GLI_TIME + PWM_DEADTIME) / 16)     // 最小脉冲

/*硬件板子参数设置值------------------------------------------------------------------*/
/*hardware current sample Parameter*/
/*电流基准的电路参数*/
#define HW_BOARD_CURR_MAX               (HW_ADC_REF / 2 / HW_AMPGAIN / HW_RSHUNT)         // 最大采样电流,2.702A
#define HW_BOARD_CURR_MIN               (-HW_BOARD_CURR_MAX)                              // 最小采样电流,-2.702A
#define HW_BOARD_CURR_BASE              (HW_BOARD_CURR_MAX * 2)                           // 电流基准//5.4A

/*hardware voltage sample Parameter*/
/*母线电压采样分压电路参数*/
#define HW_BOARD_VOLTAGE_BASE           (HW_BOARD_VOLT_MAX / 1.732)                       // 电压基准
#define HW_BOARD_VOLTAGE_VC             ((RV1 + RV2 + RV3 * VC1) / (RV3 * VC1))
#define HW_BOARD_VOLTAGE_BASE_Start     (HW_ADC_REF * HW_BOARD_VOLTAGE_VC / 1.732)        // 电压基准


/*硬件过流保护DAC值*/
#define DAC_OvercurrentValue            _Q7(I_ValueX(OverHardcurrentValue))+0x7F		  // HALF到VCC需加7F 

#define Align_Theta                     _Q15((float)Align_Angle / 180.0)

#define BASE_FREQ                       ((MOTOR_SPEED_BASE / 60) * Pole_Pairs)            // 基准频率

/*保护参数值------------------------------------------------------------------*/
/* protect value */
#define OVER_PROTECT_VALUE              _Q15(Over_Protect_Voltage  / HW_BOARD_VOLT_MAX)
#define UNDER_PROTECT_VALUE             _Q15(Under_Protect_Voltage / HW_BOARD_VOLT_MAX)
#define OVER_RECOVER_VALUE              _Q15(Over_Recover_Vlotage  / HW_BOARD_VOLT_MAX)
#define UNDER_RECOVER_VALUE             _Q15(Under_Recover_Vlotage / HW_BOARD_VOLT_MAX)


/* motor speed set value */
#define Motor_Open_Ramp_ACC             _Q15(MOTOR_OPEN_ACC     / MOTOR_SPEED_BASE)
#define Motor_Open_Ramp_Min             _Q15(MOTOR_OPEN_ACC_MIN / MOTOR_SPEED_BASE)

#define Motor_Omega_Ramp_Min            _Q15(MOTOR_OMEGA_ACC_MIN / MOTOR_SPEED_BASE)
#define Motor_Omega_Ramp_End            _Q15(MOTOR_OMEGA_ACC_END / MOTOR_SPEED_BASE)

#define Motor_Loop_Speed                _Q15(MOTOR_LOOP_RPM / MOTOR_SPEED_BASE)

#define Motor_Max_Speed                 _Q15(MOTOR_SPEED_MAX_RPM   / MOTOR_SPEED_BASE)
#define Motor_Min_Speed                 _Q15(MOTOR_SPEED_MIN_RPM   / MOTOR_SPEED_BASE)
#define Motor_Stop_Speed                _Q15(MOTOR_SPEED_STOP_RPM  / MOTOR_SPEED_BASE)

#define Motor_Stall_Min_Speed           _Q15(MOTOR_SPEED_STAL_MIN_RPM / MOTOR_SPEED_BASE)
#define Motor_Stall_Max_Speed           _Q15(MOTOR_SPEED_STAL_MAX_RPM / MOTOR_SPEED_BASE)

#define Motor_RD_Speed                  _Q15(MOTOR_SPEED_RD_RPM    / MOTOR_SPEED_BASE)
#define Motor_RDPT_Speed                _Q15(MOTOR_SPEED_RDPT_RPM  / MOTOR_SPEED_BASE)
#define Motor_RDRCV_Speed               _Q15(MOTOR_SPEED_RDRCV_RPM / MOTOR_SPEED_BASE)



/*外环增量*/
#define SPEEDRAMPINC                		(S_Value(SpeedRampInc)) 					// 运行加速度 
#define SPEEDRAMPDEC                		(S_Value(SpeedRampDec))						// 运行减速度 

#define SPEEDRAMPSTARTINC           		(S_Value(SpeedRampStartInc)) 				// 启动加速度
#define SPEEDRAMPSTARTDEC           		(S_Value(SpeedRampStartDec)) 				// 启动减速度 

/* obsever parameter set value */
#define MAX_BEMF_VOLTAGE                ((MOTOR_SPEED_BASE*Ke)/(1000.0))
#define MAX_OMEG_RAD_SEC                ((float)(_2PI*BASE_FREQ))


//自适应估算器模式使能
#if (EstimateAlgorithm == AO) 
    #define OBS_K1T                     _Q11((1.0*3.0/(125.0*1.0))*(LQ/TPWM_VALUE)*(HW_BOARD_CURR_BASE/HW_BOARD_VOLTAGE_BASE))
    #define OBS_K2T                     _Q11(0.6*RS*HW_BOARD_CURR_BASE/HW_BOARD_VOLTAGE_BASE)
	#define OBS_K3T1                    _Q8(2.5)
    #define OBS_K3T                     _Q8(2.5)
    #define OBS_K4T                     _Q15(0)
#else
    #define OBS_K1T                     _Q15(LD/(LD+RS*TPWM_VALUE))
    #define OBS_K2T                     _Q13(1.4*(TPWM_VALUE/(LD+RS*TPWM_VALUE))*(HW_BOARD_VOLTAGE_BASE/HW_BOARD_CURR_BASE))
    #define OBS_K3T                     _Q15((TPWM_VALUE/(LD+RS*TPWM_VALUE))*(MAX_BEMF_VOLTAGE/HW_BOARD_CURR_BASE))
	#define OBS_K3T1                     _Q15((TPWM_VALUE/(LD+RS*TPWM_VALUE))*(MAX_BEMF_VOLTAGE/HW_BOARD_CURR_BASE))
    #define OBS_K4T                     _Q15(((LD-LQ)*TPWM_VALUE*MAX_OMEG_RAD_SEC)/(LD+RS*TPWM_VALUE))
#endif

#define OBSW_KP_GAIN                    _Q12(2*_2PI*ATT_COEF*ATO_BW/BASE_FREQ)
#define OBSW_KI_GAIN                    _Q15(_2PI*ATO_BW*ATO_BW*TPWM_VALUE/BASE_FREQ)

#define OBSW_KP_GAIN_RUN                _Q12(2*_2PI*ATT_COEF*ATO_BW_RUN/BASE_FREQ)
#define OBSW_KI_GAIN_RUN                _Q15(_2PI*ATO_BW_RUN*ATO_BW_RUN*TPWM_VALUE/BASE_FREQ)

#define OBSW_KP_GAIN_RUN1               _Q12(2*_2PI*ATT_COEF*ATO_BW_RUN1/BASE_FREQ)
#define OBSW_KI_GAIN_RUN1               _Q15(_2PI*ATO_BW_RUN1*ATO_BW_RUN1*TPWM_VALUE/BASE_FREQ)

#define OBSW_KP_GAIN_RUN2               _Q12(2*_2PI*ATT_COEF*ATO_BW_RUN2/BASE_FREQ)
#define OBSW_KI_GAIN_RUN2               _Q15(_2PI*ATO_BW_RUN2*ATO_BW_RUN2*TPWM_VALUE/BASE_FREQ)

#define OBSW_KP_GAIN_RUN3               _Q12(2*_2PI*ATT_COEF*ATO_BW_RUN3/BASE_FREQ)
#define OBSW_KI_GAIN_RUN3               _Q15(_2PI*ATO_BW_RUN3*ATO_BW_RUN3*TPWM_VALUE/BASE_FREQ)


#define OBS_FBASE                       BASE_FREQ*TPWM_VALUE*32768                          // Fbase*Tpwm*32768
#define OBS_KLPF                        _Q15(_2PI*BASE_FREQ*TPWM_VALUE * 0.75)                 // 2PI*Fbase*Tpwm
#define SPEED_KLPF                      _Q15(_2PI*SPD_BW*TPWM_VALUE)    // 转速的滤波深度 *0.75                    // 2PI*SPD_BW*Tpwm
#define OBS_EA_KS                       _Q15((2*MOTOR_SPEED_SMOMIN_RPM*_2PI*BASE_FREQ*TPWM_VALUE)/MOTOR_SPEED_BASE)     // SMO的最小速度

#define OBSE_PLLKP_GAIN                 _Q11(((2*ATT_COEF*_2PI*E_BW*LD - RS)*HW_BOARD_CURR_BASE)/HW_BOARD_VOLTAGE_BASE)
#define OBSE_PLLKI_GAIN                 _Q11((_2PI*E_BW*_2PI*E_BW*LD*TPWM_VALUE*HW_BOARD_CURR_BASE)/HW_BOARD_VOLTAGE_BASE)

/*逆风判断时的估算算法设置值------------------------------------------------------------*/
#define SPEED_KLPF_WIND                 _Q15(_2PI*SPD_BW_Wind*TPWM_VALUE)           // 2PI*SPD_BW_Wind*Tpwm
#define OBSW_KP_GAIN_WIND               _Q12(2*_2PI*ATT_COEF*ATO_BW_Wind/BASE_FREQ)
#define OBSW_KI_GAIN_WIND               _Q15(_2PI*ATO_BW_Wind*ATO_BW_Wind*TPWM_VALUE/BASE_FREQ)//---PLL

#endif