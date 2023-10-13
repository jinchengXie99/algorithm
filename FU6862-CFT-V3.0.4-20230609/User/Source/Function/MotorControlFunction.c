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
#include <FU68xx_2.h>
#include <Myproject.h>
#include <FU68xx_2_DMA.h>
CurrentOffset xdata mcCurOffset;

/** 
 * @brief      对FOC的相关寄存器进行配置,先清理寄存器，后配置，最后使能
 * @exception  初始化FOC，需要先关闭DRVIVER，对FOC寄存器配置完成后，使能FOC再打开DRVIVER,否则可能导致第一拍电流采样错误
 * @date       2022-07-14
 */
void FOC_Init(void)
{
    /*DRV计数器使能，0-禁止，1-使能*/
    ClrBit(DRV_CR, DRVEN);
    /*使能FOC*/
    ClrBit(DRV_CR, FOCEN);
    SetBit(DRV_CR, FOCEN);
    SetBit(FOC_CR3, ESCMS);
    /*配置FOC寄存器*/
    FOC_CR1             = 0;                                                                            // 清零 FOC_CR1
    FOC_CR2             = 0;                                                                            // 清零 FOC_CR2
    FOC_IDREF       = 0;                                                                            // 清零 Id
    FOC_IQREF       = 0;                                                                            // 清零 Iq
    FOC__THETA      = 0;                                                                            // 清零 角度
    FOC_RTHEACC     = 0;                                                                            // 清零 爬坡函数的初始加速度
    FOC__RTHESTEP   = 0;                                                                        //
    FOC__RTHECNT    = 0;                                                                            //
    FOC_THECOMP    = _Q15(10.0 / 180.0);                                            // SMO 估算补偿角
    FOC_THECOR         = 0x02;                                                                 // 误差角度补偿
    /*电流环参数配置*/
    FOC_DMAX            = DOUTMAX;
    FOC_DMIN            = DOUTMIN;
    FOC_QMAX            = QOUTMAX;
    FOC_QMIN            = QOUTMIN;
    /*位置估算参数配置*/
    FOC_EK1             = OBS_K1T;
    FOC_EK2             = OBS_K2T;
    FOC_EK3             = OBS_K3T;
    FOC_EK4             = OBS_K4T;
    FOC_FBASE           = OBS_FBASE;
    FOC_OMEKLPF         = SPEED_KLPF;
    FOC_EBMFK           = OBS_KLPF;
    FOC_TGLI            = PWM_TGLI_LOAD;
	
	#if(EstimateAlgorithm == AO)
    SetBit(FOC_CR3, MFP_EN);
	#else
	ClrBit(FOC_CR3, MFP_EN);
	#endif
	
     /*********PLL或SMO/AO**********/
    #if (EstimateAlgorithm == PLL)
    {
        SetBit(FOC_CR2, ESEL);
        FOC_KSLIDE      = OBSE_PLLKP_GAIN;
        FOC_EKLPFMIN    = OBSE_PLLKI_GAIN;		
    }
    #else
    {
        ClrBit(FOC_CR2, ESEL);
        FOC_KSLIDE    = OBS_KSLIDE;
        FOC_EKLPFMIN    = OBS_EA_KS;
    }
    #endif //end SVPMW_Mode
    SetBit(FOC_CR1, SVPWMEN);                                                           // SVPWM模式
    
    //  /*正反转*/
    if (MCCtrl.FR_Status == 1)
    {
        SetBit(DRV_CR, DDIR);                              // 反转标志位
    }
    else
    {
        ClrBit(DRV_CR, DDIR);
    }
    
    /**过调制**/
    #if (OverModulation)
    {
        SetBit(FOC_CR1, OVMDL);                                                 // 过调制
    }
    #endif //end OverModulation
    /*单电阻采样；需要最小采样窗,FOC_TRGDLY为0，七段式SVPWM方式*/
    #if (Shunt_Resistor_Mode == Single_Resistor)
    {
        SetReg(FOC_CR1, CSM0 | CSM1, 0x00);
        FOC_TSMIN = PWM_TS_LOAD;                                                          // 最小采样窗口
        FOC_TRGDLY = 0x0F;                                                                // 采样时刻在中点，一般考虑开关噪声影响，会设置延迟；
        // 0x0c表示延迟12个clock，提前用反码形式，如0x84表示提前12个clock。
        ClrBit(FOC_CR2, F5SEG);                                                           // 7段式
        SetReg(CMP_CR1, CMP3MOD0 | CMP3MOD1, 0x00);
    }
    /*双电阻采样，可设置死区补偿值，在下降沿结束前开始采样Ia，配置81*/
    #elif (Shunt_Resistor_Mode == Double_Resistor)                  // double resistor sample
    {
        SetReg(FOC_CR1, CSM0 | CSM1, CSM0);
        FOC_TSMIN = PWM_DT_LOAD;                                                            // 死区补偿值
        FOC_TRGDLY = 0x06;                                                                    // ADC采样的时刻，采样时刻在计数器零点附近，83为下降沿结束前3个clock采样Ia，与单电阻不同
        // 01为上升沿开始后第一个clock开始采样。根据实际情况调整。
        FOC_TBLO = PWM_DLOWL_TIME;                            //下桥臂最小脉冲，保证采样
        SetReg(CMP_CR1, CMP3MOD0 | CMP3MOD1, 0x00);
        /*五段式或七段式选择*/
        #if (SVPMW_Mode == SVPWM_7_Segment)
        {
            ClrBit(FOC_CR2, F5SEG);                                                         // 7段式
        }
        #elif (SVPMW_Mode == SVPWM_5_Segment)
        {
            SetBit(FOC_CR2, F5SEG);                                                         // 7段式
        }
        #endif
        #if (DouRes_Sample_Mode == DouRes_1_Cycle)
        {
            ClrBit(FOC_CR2, DSS);                                                             // 7段式
        }
        #elif (DouRes_Sample_Mode == DouRes_2_Cycle)
        {
            SetBit(FOC_CR2, FOC_DSS);                                                       // 7段式
        }
        #endif //end DouRes_Sample_Mode
    }
    /*三电阻采样*/
    #elif (Shunt_Resistor_Mode == Three_Resistor)                     // signel resistor sample
    {
        SetReg(FOC_CR1, CSM0 | CSM1, CSM0 | CSM1);// 三电阻
        FOC_TSMIN  = PWM_DT_LOAD;                                                           // 死区补偿值
        FOC_TRGDLY = 0x06;                                                                         // ADC采样的时刻，采样时刻在计数器零点附近，83为下降沿结束前3个clock采样Ia，与单电阻不同。
        // 01为上升沿开始后第一个clock开始采样。根据实际情况调整。
        SetReg(CMP_CR1, CMP3MOD0 | CMP3MOD1, CMP3MOD0 | CMP3MOD1);
        FOC_TBLO = PWM_OVERMODULE_TIME;                       // 过调制电流采样处理的TB脉宽
        /*五段式或七段式选择*/
        #if (SVPMW_Mode == SVPWM_7_Segment)
        {
            ClrBit(FOC_CR2, F5SEG);                                                         // 7段式
        }
        #elif (SVPMW_Mode == SVPWM_5_Segment)
        {
            SetBit(FOC_CR2, F5SEG);                                                         // 7段式
        }
        #endif //end SVPMW_Mode
        #if (DouRes_Sample_Mode == DouRes_1_Cycle)
        {
            ClrBit(FOC_CR2, DSS);                                                           // 7段式
        }
        #elif (DouRes_Sample_Mode == DouRes_2_Cycle)
        {
            SetBit(FOC_CR2, DSS);                                                           // 7段式
        }
        #endif //end DouRes_Sample_Mode
    }
    #endif  //end Shunt_Resistor_Mode
    /* 使能电流基准校正 */
    #if (CalibENDIS == Enable)
    {
        if (mcCurOffset.OffsetFlag == 1)
        {
            #if (Shunt_Resistor_Mode == Single_Resistor)          // 单电阻校正
            {
                /*set ibus current sample offset*/
                SetReg(FOC_CR2, CSOC0 | CSOC1, 0x00);
                FOC_CSO = mcCurOffset.Iw_busOffset;               // 写入Ibus的偏置
                
            }
            #elif (Shunt_Resistor_Mode == Double_Resistor)        // 双电阻校正
            {
                /*set ia, ib current sample offset*/
                SetReg(FOC_CR2, CSOC0 | CSOC1, CSOC0);
                FOC_CSO  = mcCurOffset.IuOffset;                  // 写入IA的偏置
            
                SetReg(FOC_CR2, CSOC0 | CSOC1, CSOC1);
                FOC_CSO  = mcCurOffset.IvOffset;                 // 写入IB的偏置
            
            }
            #elif (Shunt_Resistor_Mode == Three_Resistor)         // 三电阻校正
            {
                /*set ibus current sample offset*/
                SetReg(FOC_CR2, CSOC0 | CSOC1, CSOC0);
                FOC_CSO = mcCurOffset.IuOffset;                  // 写入IA的偏置
            
                SetReg(FOC_CR2, CSOC0 | CSOC1, CSOC1);
                FOC_CSO = mcCurOffset.IvOffset;                   // 写入IB的偏置
            
                SetReg(FOC_CR2, CSOC0 | CSOC1, 0x00);
                FOC_CSO = mcCurOffset.Iw_busOffset;               // 写入IC的偏置
            }
            #endif  //end Shunt_Resistor_Mode
        }
    }
    #endif  //end CalibENDIS
    /*  -------------------------------------------------------------------------------------------------
        DRV_CTL：PWM来源选择
        OCS = 0, DRV_COMR
        OCS = 1, FOC/SVPWM/SPWM
        -------------------------------------------------------------------------------------------------*/
    /*计数器比较值来源FOC*/
    SetBit(DRV_CR, OCS);
    /*DRV计数器使能，0-禁止，1-使能*/
    SetBit(DRV_CR, DRVEN);    
    
//    ClrBit(DRV_CR, DRVEN);
//    
//    /*使能FOC*/
//    ClrBit(DRV_CR, FOCEN);
//    SetBit(DRV_CR, FOCEN);
//    SetBit(FOC_CR3, ESCMS);
//    /*配置FOC寄存器*/
//    FOC_CR1             = 0;                                                                            // 清零 FOC_CR1
//    FOC_CR2             = 0;                                                                            // 清零 FOC_CR2
//    FOC_IDREF       = 0;                                                                            // 清零 Id
//    FOC_IQREF       = 0;                                                                            // 清零 Iq
//    FOC__THETA      = 0;                                                                            // 清零 角度
//    FOC_RTHEACC     = 0;                                                                            // 清零 爬坡函数的初始加速度
//    FOC__RTHESTEP   = 0;                                                                        //
//    FOC__RTHECNT    = 0;                                                                            //
//    FOC_THECOMP     = _Q15(10.0 / 180.0);                                            // SMO 估算补偿角
//    FOC_THECOR         = 0x04;                                                                 // 误差角度补偿
//    /*电流环参数配置*/
//    FOC_DMAX            = DOUTMAX;
//    FOC_DMIN            = DOUTMIN;
//    FOC_QMAX            = QOUTMAX;
//    FOC_QMIN            = QOUTMIN;
//    /*位置估算参数配置*/
//    FOC_EK1             = OBS_K1T;
//    FOC_EK2             = OBS_K2T;
//    FOC_EK3             = OBS_K3T;
//    FOC_EK4             = OBS_K4T;
//    FOC_FBASE           = OBS_FBASE;
//    FOC_OMEKLPF         = SPEED_KLPF;
//    FOC_EBMFK           = OBS_KLPF;
//    FOC_TGLI            = PWM_TGLI_LOAD;
//	
//	#if (EstimateAlgorithm == AO)
//    SetBit(FOC_CR3, MFP_EN);
//	#else
//	ClrBit(FOC_CR3, MFP_EN);
//	#endif
//	
//     /*********PLL或SMO/AO**********/
//    #if (EstimateAlgorithm == PLL)
//    {
//        SetBit(FOC_CR2, ESEL);
//        FOC_KSLIDE      = OBSE_PLLKP_GAIN;
//        FOC_EKLPFMIN    = OBSE_PLLKI_GAIN;		
//    }
//    #else
//    {
//        ClrBit(FOC_CR2, ESEL);
//        FOC_KSLIDE    = OBS_KSLIDE;
//        FOC_EKLPFMIN    = OBS_EA_KS;
//    }
//    #endif //end SVPMW_Mode
//    SetBit(FOC_CR1, SVPWMEN);                                                           // SVPWM模式
//    
//    //  /*正反转*/
//    if (MCCtrl.FR_Status == 1)
//    {
//        SetBit(DRV_CR, DDIR);                              // 反转标志位
//    }
//    else
//    {
//        ClrBit(DRV_CR, DDIR);
//    }
//    
//    /**过调制**/
//    #if (OverModulation)
//    {
//        SetBit(FOC_CR1, OVMDL);                                                 // 过调制
//    }
//    #endif //end OverModulation
//    /*单电阻采样；需要最小采样窗,FOC_TRGDLY为0，七段式SVPWM方式*/
//    #if (Shunt_Resistor_Mode == Single_Resistor)
//    {
//        SetReg(FOC_CR1, CSM0 | CSM1, 0x00);
//        FOC_TSMIN = PWM_TS_LOAD;                                                          // 最小采样窗口
//        FOC_TRGDLY = 0x15;                                                                // 采样时刻在中点，一般考虑开关噪声影响，会设置延迟；
//        // 0x0c表示延迟12个clock，提前用反码形式，如0x84表示提前12个clock。
//        ClrBit(FOC_CR2, F5SEG);                                                           // 7段式
//        SetReg(CMP_CR1, CMP3MOD0 | CMP3MOD1, 0x00);
//    }
//    /*双电阻采样，可设置死区补偿值，在下降沿结束前开始采样Ia，配置81*/
//    #elif (Shunt_Resistor_Mode == Double_Resistor)                  // double resistor sample
//    {
//        SetReg(FOC_CR1, CSM0 | CSM1, CSM0);
//        FOC_TSMIN = PWM_DT_LOAD;                                                            // 死区补偿值
//        FOC_TRGDLY = 0x83;                                                                    // ADC采样的时刻，采样时刻在计数器零点附近，83为下降沿结束前3个clock采样Ia，与单电阻不同
//        // 01为上升沿开始后第一个clock开始采样。根据实际情况调整。
//        FOC_TBLO = PWM_DLOWL_TIME;                            //下桥臂最小脉冲，保证采样
//        SetReg(CMP_CR1, CMP3MOD0 | CMP3MOD1, 0x00);
//        /*五段式或七段式选择*/
//        #if (SVPMW_Mode == SVPWM_7_Segment)
//        {
//            ClrBit(FOC_CR2, F5SEG);                                                         // 7段式
//        }
//        #elif (SVPMW_Mode == SVPWM_5_Segment)
//        {
//            SetBit(FOC_CR2, F5SEG);                                                         // 7段式
//        }
//        #endif
//        #if (DouRes_Sample_Mode == DouRes_1_Cycle)
//        {
//            ClrBit(FOC_CR2, DSS);                                                             // 7段式
//        }
//        #elif (DouRes_Sample_Mode == DouRes_2_Cycle)
//        {
//            SetBit(FOC_CR2, FOC_DSS);                                                       // 7段式
//        }
//        #endif //end DouRes_Sample_Mode
//    }
//    /*三电阻采样*/
//    #elif (Shunt_Resistor_Mode == Three_Resistor)                     // signel resistor sample
//    {
//        SetReg(FOC_CR1, CSM0 | CSM1, CSM0 | CSM1);// 三电阻
//        FOC_TSMIN  = PWM_DT_LOAD;                                                           // 死区补偿值
//        FOC_TRGDLY = 06;                                                                          // ADC采样的时刻，采样时刻在计数器零点附近，83为下降沿结束前3个clock采样Ia，与单电阻不同。
//        // 01为上升沿开始后第一个clock开始采样。根据实际情况调整。
//        SetReg(CMP_CR1, CMP3MOD0 | CMP3MOD1, CMP3MOD0 | CMP3MOD1);
//        FOC_TBLO = PWM_OVERMODULE_TIME;                       // 过调制电流采样处理的TB脉宽
//        /*五段式或七段式选择*/
//        #if (SVPMW_Mode == SVPWM_7_Segment)
//        {
//            ClrBit(FOC_CR2, F5SEG);                                                         // 7段式
//        }
//        #elif (SVPMW_Mode == SVPWM_5_Segment)
//        {
//            SetBit(FOC_CR2, F5SEG);                                                         // 7段式
//        }
//        #endif //end SVPMW_Mode
//        #if (DouRes_Sample_Mode == DouRes_1_Cycle)
//        {
//            ClrBit(FOC_CR2, DSS);                                                           // 7段式
//        }
//        #elif (DouRes_Sample_Mode == DouRes_2_Cycle)
//        {
//            SetBit(FOC_CR2, DSS);                                                           // 7段式
//        }
//        #endif //end DouRes_Sample_Mode
//    }
//    #endif  //end Shunt_Resistor_Mode
//    /* 使能电流基准校正 */
//    #if (CalibENDIS == Enable)
//    {
//        if (mcCurOffset.OffsetFlag == 1)
//        {
//            #if (Shunt_Resistor_Mode == Single_Resistor)          // 单电阻校正
//            {
//                /*set ibus current sample offset*/
//                SetReg(FOC_CR2, CSOC0 | CSOC1, 0x00);
//                FOC_CSO = mcCurOffset.Iw_busOffset;               // 写入Ibus的偏置
//                
//            }
//            #elif (Shunt_Resistor_Mode == Double_Resistor)          // 双电阻校正
//            {
//                /*set ia, ib current sample offset*/
//                SetReg(FOC_CR2, CSOC0 | CSOC1, CSOC0);
//                FOC_CSO  = mcCurOffset.IuOffset;                  // 写入IA的偏置
//            
//                SetReg(FOC_CR2, CSOC0 | CSOC1, CSOC1);
//                FOC_CSO  = mcCurOffset.IvOffset;                    // 写入IB的偏置
//            
//            }
//            #elif (Shunt_Resistor_Mode == Three_Resistor)         // 三电阻校正
//            {
//                /*set ibus current sample offset*/
//                SetReg(FOC_CR2, CSOC0 | CSOC1, CSOC0);
//                FOC_CSO = mcCurOffset.IuOffset;                 // 写入IA的偏置
//            
//                SetReg(FOC_CR2, CSOC0 | CSOC1, CSOC1);
//                FOC_CSO = mcCurOffset.IvOffset;                   // 写入IB的偏置
//            
//                SetReg(FOC_CR2, CSOC0 | CSOC1, 0x00);
//                FOC_CSO = mcCurOffset.Iw_busOffset;               // 写入IC的偏置
//            }
//            #endif  //end Shunt_Resistor_Mode
//        }
//    }
//    #endif  //end CalibENDIS
//    /*  -------------------------------------------------------------------------------------------------
//        DRV_CTL：PWM来源选择
//        OCS = 0, DRV_COMR
//        OCS = 1, FOC/SVPWM/SPWM
//        -------------------------------------------------------------------------------------------------*/
//    /*计数器比较值来源FOC*/
//    SetBit(DRV_CR, OCS);
//    
//    SetBit(DRV_CR, DRVEN);
}

/** 
 * @brief     预充电分三步，第一步是对U相进行预充电，第二步是对V两相进行预充电;第三步是对W三相进行预充电。
 * @brief     低压应用一般不需要预充电，在customer.h禁止预充电功能寄即可
 * @exception 在低功率高压应用中，过流值较小，充电电流过大可能导致触发硬件过流, 需要注意检查
 * @date      2022-07-14
 */
void Motor_Charge(void)
{
    if (McStaSet.SetFlag.ChargeSetFlag == 0)
    {
        McStaSet.SetFlag.ChargeSetFlag = 1;
		
		/*驱动有效电平和空闲电平*/
		#if (PWM_Level_Mode == High_Level)
		{
			DRV_CMR &= 0x003f;
			DRV_OUT &= 0xC0;
		}
		#elif (PWM_Level_Mode == Low_Level)
		{
            SetBit(P1_OE, P10);
            GP10 = 1;			
			DRV_CMR |= 0x0fc0;
			DRV_OUT = 0x3F;
		}
		#elif (PWM_Level_Mode == UP_H_DOWN_L)
		{
			DRV_CMR = 0x0540;
			DRV_OUT = 0x2A;
		}
		#elif (PWM_Level_Mode == UP_L_DOWN_H)
		{
			DRV_CMR &= 0x0a80;
			DRV_OUT = 0x15;
		}
		#endif //end PWM_Level_Mode		
		
        #if (IPMState == IPMtest)
        {
            DRV_DR = 0.7 * DRV_ARR;                          // IPM 70% duty
        }
        #elif (IPMState == NormalRun)            // 正常按电机状态机运行
        {
            DRV_DR = 0.7 * DRV_ARR;                      //下桥臂10% duty
        }
        #endif
        /*  -------------------------------------------------------------------------------------------------
            DRV_CTL：PWM来源选择
            OCS = 0, DRV_COMR
            OCS = 1, FOC/SVPWM/SPWM
            -------------------------------------------------------------------------------------------------*/
        ClrBit(DRV_CR, OCS);
        mcFocCtrl.ChargeStep = 0;
    }
    
    if ((mcFocCtrl.State_Count < Charge_Time) && (mcFocCtrl.ChargeStep == 0))
    {
        mcFocCtrl.ChargeStep = 1;
        #if (IPMState == IPMtest)
        {
            DRV_CMR |= 0x03;                         // U相输出
        }
        #elif (IPMState == NormalRun)                // 正常按电机状态机运行
        {
            DRV_CMR |= 0x01;                         // U相下桥臂通
        }
        #endif
        MOE = 1;
    }
    
    if (( mcFocCtrl.State_Count <= (Charge_Time << 1) / 3) && (mcFocCtrl.ChargeStep == 1))
    {
        mcFocCtrl.ChargeStep = 2;
        #if (IPMState == IPMtest)
        {
            DRV_CMR |= 0x0F;                         // U、V相输出
        }
        #elif (IPMState == NormalRun)                // 正常按电机状态机运行
        {
            DRV_CMR |= 0x04;                         // V相下桥臂导通
        }
        #endif
    }
    
    if ((mcFocCtrl.State_Count <= Charge_Time / 3) && (mcFocCtrl.ChargeStep == 2))
    {
        mcFocCtrl.ChargeStep = 3;
        #if (IPMState == IPMtest)
        {
            DRV_CMR |= 0x3F;                         // U、V、W相输出
        }
        #elif (IPMState == NormalRun)                // 正常按电机状态机运行
        {
            DRV_CMR |= 0x10;                         // W相下桥臂导通
        }
        #endif
    }
}
/*---------------------------------------------------------------------------*/
/*  Name     :   void Motor_Align(void)
/* Input    :   NO
/* Output   :   NO
/* Description: 预定位函数，当无逆风判断时，采用预定位固定初始位置;当有逆风判断时，采用预定位刹车
/*---------------------------------------------------------------------------*/
void Motor_Align(void)
{
    if (McStaSet.SetFlag.AlignSetFlag == 0)
    {
        McStaSet.SetFlag.AlignSetFlag = 1;
        /*FOC初始化*/
        FOC_Init();
        SetBit(FOC_CR2, UQD);
			
        /*配置预定位的电流、KP、KI*/
        FOC_IDREF = ID_Align_CURRENT;
        FOC_IQREF = IQ_Align_CURRENT;
        FOC_DQKP  = DQKP_Alignment;
        FOC_DQKI  = DQKI_Alignment;
        FOC_EKP     = OBSW_KP_GAIN;
        FOC_EKI     = OBSW_KI_GAIN;
			
        /*配置预定位角度*/
        #if (AlignTestMode==1)
        {
            FOC__THETA      = Align_Theta;
        }
        #else
        {
            #if (PosCheckEnable==1)
            {
                FOC__THETA    = mcFocCtrl.mcPosCheckAngle;
            }
            #else
            {
                FOC__THETA      = Align_Theta;
            }
            #endif    //end PosCheckEnable
        }
        #endif  //end AlignTestMode
				
        /*********PLL或SMO/AO**********/
        #if (EstimateAlgorithm == PLL)
        {
            FOC__ETHETA   = FOC__THETA;
        }
				#else
				{
					FOC__ETHETA   = FOC__THETA - 4096;
				}
        #endif //end    EstimateAlgorithm
		
        /*使能输出*/
        DRV_CMR |= 0x3F;                         // U、V、W相输出
        MOE = 1;
    }
}

/** 
 * @brief     静止启动配置函数
 * @date      2022-07-14
 */
void Motor_Open(void)
{   
    if (McStaSet.SetFlag.StartSetFlag == 0)
    {
        McStaSet.SetFlag.StartSetFlag = 1;
			
			  FOC_Init();
        /****启动初始角度赋值**/
        #if (PosCheckEnable)
        {
            FOC__THETA  = mcFocCtrl.mcPosCheckAngle;// 有初始位置检测，则用初始位置角
        }
        #else
        {
            FOC__THETA      = Align_Theta;            // 无初始位置检测，则用预定位角
        }
        #endif
        /*********PLL或SMO/AO**********/
        #if (EstimateAlgorithm == PLL)
        {
            FOC__ETHETA   = FOC__THETA;
        }
				#else
				{
					FOC__ETHETA   = FOC__THETA - 4096;
				}
        #endif //end    EstimateAlgorithm
				
        /*启动电流、KP、KI、FOC_EKP、FOC_EKI*/
        FOC_IDREF = ID_Start_CURRENT;                               // D轴启动电流
        mcFocCtrl.mcIqref = IQ_Start_CURRENT;                       // Q轴启动电流
        #if ((FRDetectMethod==BEMFMethod)&&(TailWind_Mode == TailWind))
        {
            if (BEMFDetect.BEMFCCWFlag == 1)
            {
                mcFocCtrl.mcIqref += I_Value(0.95);                  //逆风时，加大启动电流
            }
            else if (BEMFDetect.BEMFCCWFlag == 2)
            {
                mcFocCtrl.mcIqref += I_Value(0.8);                  //逆风时，加大启动电流
            }
        }
        #endif
        FOC_DQKP = DQKPStart;
        FOC_DQKI = DQKIStart;
				
        //启动时设置Q轴PI下限起始值
        FOC_QMAX          = QOUTMAX;
        FOC_QMIN          = QOUTMINST;
        FOC_EKP     = OBSW_KP_GAIN;
        FOC_EKI     = OBSW_KI_GAIN;
				
        /*启动方式选择*/
        #if (START_MODE == Omega_Start)                  // Omega 启动
        {
            FOC_EFREQACC    = Motor_Omega_Ramp_ACC;
            FOC_EFREQMIN    = Motor_Omega_Ramp_Min;
            FOC_EFREQHOLD = Motor_Omega_Ramp_End;
            SetBit(FOC_CR1, EFAE);                                                          // 估算器强制输出
            ClrBit(FOC_CR1, RFAE);                                                          // 禁止强拉
            SetBit(FOC_CR1, ANGM);                                                          // 估算模式
        }
        #elif (START_MODE == Open_Omega_Start)
        {
            FOC_RTHEACC     = Motor_Open_Ramp_ACC;                                    // 爬坡函数的初始加速度
            FOC__RTHESTEP   = Motor_Open_Ramp_Min;                              // 0.62 degree acce speed
            FOC__RTHECNT    = MOTOR_OPEN_ACC_CNT;                                   // acce time
            FOC_EFREQACC    = Motor_Omega_Ramp_ACC;
            FOC_EFREQMIN    = Motor_Omega_Ramp_Min;
            FOC_EFREQHOLD = Motor_Omega_Ramp_End;
            SetBit(FOC_CR1, EFAE);                                                          // 估算器强制输出
            SetBit(FOC_CR1, RFAE);                                                          // 禁止强拉
            SetBit(FOC_CR1, ANGM);                                                          // 估算模式
        }
		#elif (START_MODE == Observer_Start)
        {
            FOC_EFREQACC    = Motor_Omega_Ramp_ACC;
            FOC_EFREQMIN    = Motor_Omega_Ramp_Min;
            FOC_EFREQHOLD = Motor_Omega_Ramp_End;
            SetBit(FOC_CR1, EFAE);                                                          // 估算器强制输出
            ClrBit(FOC_CR1, RFAE);                                                          // 禁止强拉
            SetBit(FOC_CR1, ANGM);                                                          // 估算模式
        }
        #endif //end Open_Start_Mode
    }
    
    /*不同启动方式下，切换到MCRUN状态*/
    #if (START_MODE == Open_Omega_Start)
    {
        mcFocCtrl.State_Count = 120;
        FOC_EKP = OBSW_KP_GAIN_RUN;                            // 估算器里的PI的KP
        FOC_EKI   = OBSW_KI_GAIN_RUN;                                  // 估算器里的PI的KI
    }
    #elif (START_MODE == Omega_Start)
    {
        /*********PLL或SMO/AO**********/
        #if (EstimateAlgorithm == PLL)
        {
            FOC_EKP = OBSW_KP_GAIN_RUN2;                            // 估算器里的PI的KP
            FOC_EKI   = OBSW_KI_GAIN_RUN2;                                  // 估算器里的PI的KI
        }
				#else
				{
					mcFocCtrl.State_Count = 100;
				}
        #endif //end    EstimateAlgorithm      
    }
	#elif (START_MODE == Observer_Start)
    {
        /*********PLL或SMO/AO**********/
        #if (EstimateAlgorithm == PLL)
        {
            FOC_EKP = OBSW_KP_GAIN_RUN2;                            // 估算器里的PI的KP
            FOC_EKI   = OBSW_KI_GAIN_RUN2;                                  // 估算器里的PI的KI
        }
		#else
		{
			mcFocCtrl.State_Count = 120;
		}
        #endif //end    EstimateAlgorithm  
        LowSpeedObserverInit();		
    }
    #endif //end Open_Start_Mode
    FOC_IQREF = mcFocCtrl.mcIqref;                          // Q轴启动电流
}

/** 
 * @brief     顺逆风检测配置函数，顺逆风处理
 * @date      2022-07-14
 */
void Motor_TailWind(void)
{
    #if (TailWind_Mode == NoTailWind)     // 无顺逆风处理的，直接跳入下一个状态
    {
        mcState                           = mcPosiCheck;
        McStaSet.SetFlag.PosiCheckSetFlag = 0;
        mcFocCtrl.mcPosCheckAngle         = 0xffff;         // 角度赋初值
    }
    #elif (TailWind_Mode == TailWind)
    {
        if (mcFocCtrl.State_Count == 0)
        {
            if (McStaSet.SetFlag.TailWindSetFlag  == 0) //初始化
            {
                McStaSet.SetFlag.TailWindSetFlag = 1;
                #if (FRDetectMethod==BEMFMethod)
                {
                    BEMFDetectInit();
                }
                #elif (FRDetectMethod==FOCMethod)
                {
                    TailWindDetectInit();
                }
                #endif
            }
    
            #if (FRDetectMethod==BEMFMethod)
            {
                BEMFDealwith();
            }
            #elif (FRDetectMethod==FOCMethod)
            {
                FOCTailWindDealwith();
            }
            #endif
        }
    }
    #endif
}

/** 
 * @brief     控制关机和刹车
 * @date      2022-07-14
 */
void MC_Stop(void)
{
    if ((mcFocCtrl.SpeedFlt < Motor_Stop_Speed) || (mcFocCtrl.State_Count == 0)) // 实际转速低于Motor_Min_Speed或延时到了，关闭PWM输出或进入刹车
    {
        #if (StopBrakeFlag == 0)
        {
            FOC_CR1 = 0x00;
            /*关闭FOC*/
            ClrBit(DRV_CR, FOCEN);
			      MOE = 0;
            mcState = mcBrake;
        }
        #else
        {
            if ((mcFocCtrl.SpeedFlt < Motor_Stop_Speed) && (mcFocCtrl.SpeedFlt > Motor_Min_Speed))                                                    // 低于StopSpeed,刹车
            {
                FOC_IQREF             = I_Value(-0.2);
            }
            else if (mcFocCtrl.SpeedFlt < Motor_Min_Speed)
            {
                MOE = 0;
                FOC_CR1 = 0x00;
                ClrBit(DRV_CR, FOCEN);
                DRV_DR  = DRV_ARR + 1;
                DRV_CMR &= 0xFFC0;
                DRV_CMR |= 0x015;                                                                                   // 三相下桥臂通，刹车
                ClrBit(DRV_CR, OCS);                                                                                // OCS = 0, DRV_COMR;OCS = 1, FOC/SVPWM/SPWM
                MOE = 1;
                mcState               = mcBrake;
                mcFocCtrl.State_Count = StopWaitTime;
            }
            else
            {
                FOC_IQREF             = 0;
            }
        }
        #endif
    }
    else if (MCCtrl.FlagONOFF  > 0)                                                                           // Stop状态时，电机在减速状态，又开机进入正常运行模式
    {
        mcState            = mcRun;
        mcFocCtrl.CtrlMode = 0;
        FOC_IQREF          = IQ_RUN_CURRENT;
    }
}

/** 
 * @brief     控制变量上电初始化,包括保护参数的初始化、电机状态初始化
 * @brief     上电只运行一次
 * @date      2022-07-14
 */
void MotorcontrolInit(void)
{
    memset(&mcLedDisplay,0, sizeof(mcLedDisplay));
    
    /***********保护******************/
    memset(&mcFaultDect, 0, sizeof(FaultVarible));                                                          // FaultVarible变量清零
	
    /******保护次数*********/
    memset(&mcProtectTime, 0, sizeof(ProtectVarible));                                                      // ProtectVarible保护次数清零

    /*****电机状态机时序变量***********/
    McStaSet.SetMode                   = 0;
	
    /*****外部控制环*******/
    memset(&mcFocCtrl, 0, sizeof(FOCCTRL));                     // mcFocCtrl变量清零

    mcCurOffset.IuOffsetSum            = 16383;
    mcCurOffset.IvOffsetSum            = 16383;
    mcCurOffset.Iw_busOffsetSum        = 16383;
	
	  Rom.FlagFlashWrite = 0;                                   //Flash写入
}

/** 
 * @brief     初始化电机参数，每次电机重启均会被调用
 * @warning   需要注意填写的变量是否可以在此时刻被初始化
 * @date      2022-07-14
 */
void VariablesPreInit(void)
{
    /***********保护******************/
    mcFaultSource = 0;
    memset(&mcFaultDect, 0, sizeof(FaultVarible));                                                                  // FaultVarible变量清零
	
    /*****顺逆风判断*******/
    #if (TailWind_Mode==TailWind)
    #if(FRDetectMethod==BEMFMethod)
    {
    }
    #elif (FRDetectMethod==FOCMethod)
    {
        memset(&TailWindDetect, 0, sizeof(MotorTailWindTypeDef));                                     //  TailWindDetect所有变量清零
    }
    #endif	
    #endif
	
	  /*****电机状态机时序变量***********/
    McStaSet.SetMode                   = 0;
	
	  memset(&mcFocCtrl, 0, sizeof(FOCCTRL));                     // mcFocCtrl变量清零
	
    memset(&LowSpeedObserver, 0, sizeof(MCLowSpeedObserver));
    
    memset(&mcLedDisplay,0, sizeof(mcLedDisplay));
	  
//    MCCtrl.PowerLimitValue = POWERLPFLIMIT;
}

/** 
 * @brief     上电时，先对硬件电路的电流进行采集，写入对应的校准寄存器中。
              调试时，需观察mcCurOffset结构体中对应变量是否在范围内。采集结束后，OffsetFlag置1。
 * @date      2022-07-14
 */
void GetCurrentOffset(void)
{
    if (mcCurOffset.OffsetFlag == 0)
    {
        SetBit(ADC_CR, ADCBSY);                                  // 使能ADC
        
        while (ReadBit(ADC_CR, ADCBSY));
        
        #if (Shunt_Resistor_Mode == Single_Resistor)                   // 29.2ms 单电阻模式，上电验证硬件电路时，需观察mcCurOffset.IbusOffset是否为4096
        {
            mcCurOffset.Iw_busOffsetSum += ((ADC4_DR & 0x0fff) << 3);
            mcCurOffset.Iw_busOffset = mcCurOffset.Iw_busOffsetSum >> 4;
            mcCurOffset.Iw_busOffsetSum -= mcCurOffset.Iw_busOffset;
        }
        #elif (Shunt_Resistor_Mode == Double_Resistor)                 //44ms 双电阻模式，上电验证硬件电路时，需观察mcCurOffset.IaOffset、mcCurOffset.IbOffset是否为4096
        {
            mcCurOffset.IuOffsetSum += ((ADC0_DR & 0x0fff) << 3);
            mcCurOffset.IuOffset = mcCurOffset.IuOffsetSum >> 4;
            mcCurOffset.IuOffsetSum -= mcCurOffset.IuOffset;
            mcCurOffset.IvOffsetSum += ((ADC1_DR & 0x0fff) << 3);
            mcCurOffset.IvOffset = mcCurOffset.IvOffsetSum >> 4;
            mcCurOffset.IvOffsetSum -= mcCurOffset.IvOffset;
            mcCurOffset.Iw_busOffsetSum += ((ADC4_DR & 0x0fff) << 3);
            mcCurOffset.Iw_busOffset = mcCurOffset.Iw_busOffsetSum >> 4;
            mcCurOffset.Iw_busOffsetSum -= mcCurOffset.Iw_busOffset;
        }
        #elif (Shunt_Resistor_Mode == Three_Resistor)                 //58.2ms 三电阻模式，上电验证硬件电路时，需观察mcCurOffset.IaOffset、mcCurOffset.IbOffset、mcCurOffset.IcOffset是否为4096
        {
            mcCurOffset.IuOffsetSum += ((ADC0_DR & 0x0fff) << 3);
            mcCurOffset.IuOffset = mcCurOffset.IuOffsetSum >> 4;
            mcCurOffset.IuOffsetSum -= mcCurOffset.IuOffset;
            mcCurOffset.IvOffsetSum += ((ADC1_DR & 0x0fff) << 3);
            mcCurOffset.IvOffset = mcCurOffset.IvOffsetSum >> 4;
            mcCurOffset.IvOffsetSum -= mcCurOffset.IvOffset;
            mcCurOffset.Iw_busOffsetSum += ((ADC4_DR & 0x0fff) << 3);
            mcCurOffset.Iw_busOffset = mcCurOffset.Iw_busOffsetSum >> 4;
            mcCurOffset.Iw_busOffsetSum -= mcCurOffset.Iw_busOffset;
        }
        #endif
        mcCurOffset.OffsetCount++;
        
        if (mcCurOffset.OffsetCount > Calib_Time)
        {
            mcCurOffset.OffsetFlag = 1;
        }
    }
}

/** 
 * @brief     关闭输出，关闭FOC，电机切换到mcReady状态被调用一次
 * @date      2022-07-14
 */
void Motor_Ready(void)
{
    if (McStaSet.SetFlag.CalibFlag == 0)
    {
        McStaSet.SetFlag.CalibFlag = 1;
        ClrBit(DRV_CR, FOCEN);            // 关闭FOC
        MOE            = 0;               // 关闭MOE        
    }
}

/** 
 * @brief     电机初始化，对电机相关变量、PI进行初始化设置,关闭FOC所需要使用到的ADC
 * @note      关闭FOC所需要使用到的ADC，FOC模块会自动调用相应ADC 无需外部使能
 * @date      2022-07-14
 */
void Motor_Init(void)
{
    VariablesPreInit();                           // 电机相关变量初始化
    PI_Init();                                        // PI初始化
}