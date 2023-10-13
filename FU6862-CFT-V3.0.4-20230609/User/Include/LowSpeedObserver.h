#ifndef __LowSpeedObserver_H_
#define __LowSpeedObserver_H_

#define LowSpeedObserver_K1              _Q12(2.8)
#define LowSpeedObserver_K2              _Q15(0.02)
#define LowSpeedObserver_K3              _Q8(40.0/16.0)
#define LowSpeedObserverDeltaTheta_K     _Q15(2*TPWM_VALUE * MAX_OMEG_RAD_SEC / 3.1415926)
#define BEMFFliter_Count                 (550)
#define Init_gain                        (0)
#define Angle_Com                        (0)
#define ForcedSpeedCount_Value           (1000.0/2.0)                                 //载波周期个数
#define Forced_Speed                     (400)                                        //强制速度1
#define ForcedSpeed_1                    (50)                                         //强制速度1
#define ForcedSpeed_2                    (80)                                         //强制速度2
#define ForcedSpeedLoop_Period           (1)                                          //强制速度2
#define ForcedSpeed_NegativeValue1       (-1800)                                      //强制速度1
#define ForcedSpeed_NegativeValue2       (-1800)                                      //强制速度1
typedef union
{
    int32 s32;
    int16 s16[2];
}s32tos16;
typedef struct
{

    int16 EMF;
    int16 EMF_OMEGA;
    int16 EMF_OMEGA_LPF;
    int16 EMF_OMEGA_LPF1;
    int16 Observer_Count;
    int16 EALP;
    int16 EBET;    
    int16 AO_THTEA;
    uint8 state;
    int16 LowSpeedObserverOmega;
    s32tos16 LowSpeedObserverOmega_32;
    int16 omega;
    int16 ABSOMEGA;
    int16 ABSOMEGA1;
    int16 AO_DELTAOMEGA;
    uint8 Smoothswith_Count;    
    int16 LowSpeedObserverOmegaErr;

    s32tos16 LowSpeedObserverOmegaDelta_32;

    s32tos16 LowSpeedObserverDeltaTheta_32;

    s32tos16 LowSpeedObserverTheta_32;
    int16 Lowspeed_adjust;
    int16 count1;
    int16 count2;
    int16 ThetaDelta;
    int16 OMEGALPF;
    uint8 windstate;
    int16 Switch_Count;
}MCLowSpeedObserver;


typedef struct
{
    int16 LowSpeedObserverK1;
    int16 LowSpeedObserverK2;
    int16 LowSpeedObserverK3;
    int16 LowSpeedObserverDeltaThetaK;
    int16 AngleCom;
    int16 Initgain;
    uint16 ForcedSpeedCount;
    uint16 ForcedSpeedCountValue;
    int16 ForcedSpeed;
    int16 ForcedSpeed1;
    int16 ForcedSpeed2;
    int16 ForcedSpeedLoopPeriod;
    int16 ForcedSpeedNegativeValue1;
    int16 ForcedSpeedNegativeValue2;
    int16 BEMFLPFK;
    int16 BEMFFliterCount;
    
}StartupVar;

extern StartupVar xdata Startup;
extern MCLowSpeedObserver data LowSpeedObserver;
extern void LowSpeedObserverInit(void);
extern void StartupState(void);
extern void MCLowSpeedObserverFunction(void);


#endif