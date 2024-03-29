/*  -------------------------- (C) COPYRIGHT 2022 Fortiortech ShenZhen ---------------------------*/
/**
 * @copyright (C) COPYRIGHT 2022 Fortiortech Shenzhen
 * @file      xxx.c
 * @author    Fortiortech  Appliction Team
 * @since     Create:2022-07-14
 * @date      Last modify:2022-07-14
 * @note      Last modify author is Leo.li
 * @brief      
 */


/* Includes -------------------------------------------------------------------------------------*/
// #include <FOCTailDect.h>
#include <FU68xx_2.h>
#include <Myproject.h>

#if ((FRDetectMethod == FOCMethod) && (TailWind_Mode == TailWind))
MotorTailWindTypeDef xdata  TailWindDetect;

/** 
 * @brief      顺逆风参数初始化
 * @date       2022-07-14
 */	
void TailWindDetectInit(void)
{
    TailWindDetect.MotorTailWindState     = NormalTailWind;                     //  初始状态为正常的顺逆风状态
    TailWindDetect.TempThailWindSpeedBase = ThailWindSpeedBase;                 //  顺逆风计算的speedbase
    FOC_Init();                                                                 // FOC的初始化
    FOC_DQKP    = DQKP_TailWind;                                                // 顺逆风的电流环KP
    FOC_DQKI    = DQKI_TailWind;                                                // 顺逆风的电流环KI
    FOC_EKP     = OBSW_KP_GAIN_WIND;                                            // 顺逆风速度估算的KP
    FOC_EKI     = OBSW_KI_GAIN_WIND;                                            // 顺逆风速度估算的KI
    FOC_OMEKLPF = SPEED_KLPF_WIND;                                              // 顺逆风下的速度滤波系数
    SetBit(FOC_CR1, ANGM);                                                      // 估算模式                                                 // Driver 输出计数器使能，0-禁止，1-使能
    DRV_CMR    |= 0x3F;                                                          // U、V、W相输出
    MOE         = 1;                                                              // 打开MOE
    FOC_IDREF   = 0;                                                              // D轴给定电流
    FOC_IQREF   = 0;
}

/** 
 * @brief      顺逆风速度检测，根据角度的变化趋势来判断方向
 * @date       2022-07-14
 */
void TailWindSpeedDetect(void)
{
    static int16 LatestTheta;
    
    if (mcState == mcTailWind)
    {
        //顺风检测过程由于FOC内部根据电流估算角度，故直接对FOC_ETHETA进行处理
        if (TailWindDetect.MotorTailWindState == NormalTailWind)
        {
            LatestTheta = FOC__ETHETA;
            
            //旋转方向判断在 <-170度   <10 >-10  >170度三个状态切换的时间
            if (LatestTheta < -30946)
            {
                //计数器未清零或从状态3跳到状态1时清零
                if ((TailWindDetect.SpeedTimerClearStatus == 0) || (TailWindDetect.AngleState == 3))
                {
                    TailWindDetect.SpeedCountTimer       = 0;
                    TailWindDetect.SpeedTimerClearStatus = 1;
                    
                    if (TailWindDetect.AngleState == 3)
                    {
                        TailWindDetect.ShakeTimes++;    //来回1和3之间抖动，抖动次数加1
                    }
                }
                
                //<-170度  时设置状态为1，并清零SpeedCountTimer在TIM5中计时
                TailWindDetect.AngleState = 1;
            }
            else if ((LatestTheta > -1820) && (LatestTheta < 1820)) //<10 >-10
            {
                //状态1或状态3切换到状态2时保存当前转速时间至TailWindDetect.SpeedCount[SpeedStoreNum]
                if ((TailWindDetect.AngleState == 1) || (TailWindDetect.AngleState == 3))
                {
                    //计算当前转速，RPM
                    TailWindDetect.SpeedCountTimer += 1;//防止为0
                    TailWindDetect.TailWindSpeed   = DivQ_L_MDU(TailWindDetect.TempThailWindSpeedBase >>16, TailWindDetect.TempThailWindSpeedBase, TailWindDetect.SpeedCountTimer);//测出速度
                    TailWindDetect.SpeedStoreNum++;
                    
                    //用于SpeedCountTimer清零
                    if (TailWindDetect.SpeedTimerClearStatus == 1)
                    {
                        TailWindDetect.SpeedTimerClearStatus = 0;
                    }
                    
                    //有1状态切换到2状态说明角度递增旋转方向为CW，3->2则为CCW
                    if (TailWindDetect.AngleState == 1)
                    {
                        TailWindDetect.MotorDir = CW;
                    }
                    else if (TailWindDetect.AngleState == 3)
                    {
                        TailWindDetect.MotorDir = CCW;
                    }
                    
                    TailWindDetect.ShakeTimes = 0;//清除来回抖动的计数
                }
                
                TailWindDetect.AngleState = 2;
            }
            //>170度时
            else if (LatestTheta > 30946)
            {
                //计数器未清零或从状态1跳到状态3时清零
                if ((TailWindDetect.SpeedTimerClearStatus == 0) || (TailWindDetect.AngleState == 1))
                {
                    TailWindDetect.SpeedCountTimer       = 0;
                    TailWindDetect.SpeedTimerClearStatus = 1;
                    
                    if (TailWindDetect.AngleState == 1)
                    {
                        TailWindDetect.ShakeTimes++;    //来回1和3之间抖动
                    }
                }
                
                TailWindDetect.AngleState = 3;
            }
        }
    }
}

/** 
 * @brief      顺风启动
 * @date       2022-07-14
 */
void FOCCloseLoopStart(void)
{
    //配置启动的参数，Omega模式
    FOC_EFREQACC    = Motor_Omega_Ramp_ACC;
    FOC_EFREQMIN    = Motor_Omega_Ramp_Min;
    FOC_EFREQHOLD = Motor_Omega_Ramp_End;
    SetBit(FOC_CR1, EFAE);                                                      // 估算器强制输出
    ClrBit(FOC_CR1, RFAE);                                                      // 禁止强拉
    SetBit(FOC_CR1, ANGM);                                                      // 估算模式
    //电流环的PI和输出限赋值
    FOC_DQKP = DQKP;
    FOC_DQKI = DQKI;
    FOC_DMAX = DOUTMAX;
    FOC_DMIN = DOUTMIN;
    FOC_QMAX = QOUTMAX;
    FOC_QMIN = QOUTMIN;
	
    /*********PLL或SMO/AO**********/
    //根据不同转速确启动的ATO_BW值   
    #if (EstimateAlgorithm == PLL)
    mcFocCtrl.mcIqref = IQ_RUN_CURRENT;
	#else
    //根据不同转速确启动的ATO_BW值
    if (TailWindDetect.TailWindSpeed > 16383)
    {
        FOC_EKP               = OBSW_KP_GAIN_RUN1;
        FOC_EKI               = OBSW_KI_GAIN_RUN1;
        mcFocCtrl.mcIqref     = IQ_RUN_CURRENT;
        mcFocCtrl.State_Count = 10;
    }
    else if (TailWindDetect.TailWindSpeed > 5000)
    {
        FOC_EKP               = OBSW_KP_GAIN_RUN2;
        FOC_EKI               = OBSW_KI_GAIN_RUN2;
        mcFocCtrl.mcIqref     = IQ_RUN_CURRENT;
        mcFocCtrl.State_Count = 60;
    }
    else
    {
        FOC_EKP               = OBSW_KP_GAIN_RUN;
        FOC_EKI               = OBSW_KI_GAIN_RUN;
        mcFocCtrl.mcIqref     = IQ_RUN_CURRENT;
        mcFocCtrl.State_Count = 120;
    }	
    #endif 
    /*estimate parameter set*/
    FOC_OMEKLPF = SPEED_KLPF;
    FOC_IDREF   = ID_RUN_CURRENT;             // D轴启动电流
    FOC_IQREF   = mcFocCtrl.mcIqref ;         // Q轴启动电流
    PI_UK       =   mcFocCtrl.mcIqref;
    mcState            = mcRun;
    mcFocCtrl.CtrlMode = 0;
}


/** 
 * @brief      FOC顺逆风检测的时间处理
 * @date       2022-07-14
 */
void FOCTailWindTimeLimit(void)
{
    if (mcState == mcTailWind)
    {
        //1Hz Min
        if (TailWindDetect.SpeedCountTimer < TailWind_Time)                     // SpeedCountTimer-计算时间间隔
        {
            TailWindDetect.SpeedCountTimer++;
        }
        else
        {
            TailWindDetect.TailWindSpeed       = 0;                             //速度为0
            TailWindDetect.SpeedCountTimer     = 0;
            TailWindDetect.SpeedOverFlowStatus = 1;                             // 转速计数溢出标志
        }
    }
}


/** 
 * @brief      顺风逆风参数配置函数
 * @date       2022-07-14
 */
void FOCTailWindDealwith(void)
{
    /*********SMO/AO**********/
    #if ((EstimateAlgorithm == SMO)||(EstimateAlgorithm == AO))
    SMO_TailWindDealwith();
    #endif //end    EstimateAlgorithm
}

void SMO_TailWindDealwith(void)
{
    //电机状态为正转且转速计数溢出时；或1-3状态抖动次数大于2次时，认为静止
    if (((TailWindDetect.MotorDir == CW) && (TailWindDetect.SpeedOverFlowStatus)) || (TailWindDetect.ShakeTimes > 2))
    {
        MOE = 0;
        SetBit(DRV_CR, FOCEN);   //关闭FOC
        mcState                           = mcPosiCheck;
        McStaSet.SetFlag.PosiCheckSetFlag = 0;
        mcFocCtrl.mcPosCheckAngle         = 0xffff;         // 角度赋初值
    }
    else if ((TailWindDetect.MotorDir == CCW) && (TailWindDetect.SpeedStoreNum > 2)) //||((TailWindDetect.MotorDir == CW)&&(TailWindDetect.TailWindSpeed>TailWindStartMinSpeed)))
    {
        if (TailWindDetect.TailWindSpeed < 13000)
        {
            mcFocCtrl.mcIqref       = IQ_Start_CURRENT + I_Value(0.2);       // Q轴启动电流
            TailWindDetect.AntiFlag = 1;
        }
        else if (TailWindDetect.TailWindSpeed < 8000)
        {
            mcFocCtrl.mcIqref       = IQ_Start_CURRENT + I_Value(0.3);       // Q轴启动电流
            TailWindDetect.AntiFlag = 2;
        }
        else if (TailWindDetect.TailWindSpeed < 3000)
        {
            mcFocCtrl.mcIqref       = IQ_Start_CURRENT + I_Value(0.4);       // Q轴启动电流
            TailWindDetect.AntiFlag = 3;
        }
        else
        {
            mcFocCtrl.mcIqref       = IQ_Start_CURRENT + I_Value(0.5);       // Q轴启动电流
            TailWindDetect.AntiFlag = 4;
        }
        
        FOC_DQKP              = DQKP;
        FOC_DQKI              = DQKI;
        FOC_DMAX              = DOUTMAX;
        FOC_DMIN              = DOUTMIN;
        FOC_QMAX              = QOUTMAX;
        FOC_QMIN              = QOUTMIN;
        FOC_EK2               = OBS_K2T;
        FOC_IQREF             = mcFocCtrl.mcIqref;
        mcFocCtrl.State_Count = 120;
        FOC_EKP               = OBSW_KP_GAIN;
        FOC_EKI               = OBSW_KI_GAIN;
        FOC_IDREF             = 0;
        mcState               = mcRun;
        mcFocCtrl.CtrlMode    = 0;
    }
    else if (TailWindDetect.MotorDir == CW)
    {
        //超过检测次数TailWindDetect.SpeedStoreNum切转速TailWindStartMinSpeed以上时直接顺风启动
        if ((TailWindDetect.TailWindSpeed > TailWindStartMinSpeed) && (TailWindDetect.SpeedStoreNum >= 2))
        {
            FOCCloseLoopStart();
        }
    }
}

#endif
