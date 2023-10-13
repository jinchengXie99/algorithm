/*  -------------------------- (C) COPYRIGHT 2022 Fortiortech ShenZhen ---------------------------*/
/**
 * @copyright (C) COPYRIGHT 2022 Fortiortech Shenzhen
 * @file      LED.c
 * @author    Fortiortech  Appliction Team
 * @since     Create:2022-07-14
 * @date      Last modify:2022-07-18
 * @note      Last modify author is Leo.li
 * @brief      
 */

/* Includes -------------------------------------------------------------------------------------*/
#include <FU68xx_2.h>
#include <Myproject.h>

/* Private variables ----------------------------------------------------------------------------*/
LEDCtl_TypeDef LEDCtl;
MCLedDisplay     xdata   mcLedDisplay;

////温度从21°到140°             21       22     23     24      25     26     27    28      29     30
//uint16 Temperature_Voltage[]={22948 , 22641, 22330, 22017, 21700, 21381, 21059, 20736, 20410, 20083,
//                              19755 , 19425, 19095, 18765, 18435, 18104, 17774, 17445, 17117, 16790,
//                              16464 , 16140, 15818, 15498, 15181, 14866, 14554, 14245, 13939, 13636,
//                              13337 , 13042, 12750, 12462, 12179, 11899, 11624, 11353, 11086, 10824,
//                              10566 , 10313, 10064, 9820 , 9581 , 9346,  9116,  8890,  8669,  8453,
//                              8241  , 8034 , 7832 , 7634 , 7440,  7250,  7066,  6885,  6709,  6537,//80°参考
//                              6369  , 6205,  6045,  5889,  5737,  5589,  5445,  5304,  5166,  5033,
//                              4902,   4776,  4652,  4532,  4414,  4300,  4189,  4081,  3976,  3873,
//                              3774,   3677,  3582,  3490,  3401,  3314,  3229,  3147,  3067,  2989,
//                              2913,   2839,  2768,  2698,  2630,  2564,  2500,  2437,  2376,  2317,
//                              2260,   2204,  2149,  2096,  2045,  1995,  1946,  1898,  1852,  1807,
//                              1763,   1721,  1680,  1639,  1600,  1562,  1525,  1489,  1453,  1419}
volatile uint16 Temperature_Low[3] = {14245, 13636, 12750}; //50°
volatile uint16 Temperature_Mid[3] = {9116, 8453, 7832};  //70
volatile uint16 Temperature_High[3] = {5445, 5033, 4652}; //90

uint8 xdata LED1_EN = 0, LED2_EN = 0, LED3_EN = 0, LED4_EN = 0, LED5_EN = 0, LED6_EN = 0;

/** 
 * @brief      LED控制，目标速度和目标温度赋值
 * @date       2022-07-14
 */

uint8 FeverONtime = 0;
void LEDControl(void)
{
//    if ((mcState != mcFault))
//    {
//        if ((KS.KeyValuetotal & 0x80) == 0)                    //SW3 没有按下
//        {
//			User.ScrOnAngleTime  = Temperature_Off;
//			switch (KS.KeyValuetotal & 0x0F)                   // SW1档位读取
//			{
//				
//				
//				case 0x01:
//				
//				LED1=LED2=LED3=0;
//				FeverONtime=TempOff;
//				
//				break;
//				
//				case 0x02:
//				
//				LED1=1;
//				LED2=LED3=0;
//				FeverONtime=TempLow;
//				
//				break;

//				case 0x04:
//				
//				LED1=LED2=1;
//				LED3=0;
//				FeverONtime=TempMid;
//				
//				break;

//				case 0x08:
//				
//				LED1=LED2=LED3=1;
//				FeverONtime=TempHigh;
//				
//				break;				
//				
//				
//				 default:
//					break;
//			}
////            switch (KS.KeyValuetotal & 0x70)
////            {
////                case 0x10:                          //判定转速					
////                    switch (KS.KeyValuetotal & 0x0F)          //判定温度
////                    {
////                        case 0x01:
////                            				
////						    User.ScrOnAngleTime  = Temperature_Off;
////                            break;
////                            
////                        case 0x02:
////                           
////                            User.ScrOnAngleTime   = Speed_LowTemperature_LOW;
////                            break;
////                            
////                        case 0x04:
////                            
////                            User.ScrOnAngleTime  = Speed_LowTemperature_Mid;
////                            break;
////                            
////                        case 0x08:
////                            
////                            User.ScrOnAngleTime   = Speed_LowTemperature_High;
////                            break;
////                            
////                        default:
////                            break;
////                    }
////                    
////					
////                    MCCtrl.TargetValue = Motor_Speed_Low;         // 转速赋值
////                    break;
////                    
////                case 0x20:
////                    switch (KS.KeyValuetotal & 0x0F)
////                    {
////                        case 0x01:
////                            				
////                            User.ScrOnAngleTime  = Temperature_Off;
////                            break;
////                            
////                        case 0x02:
////                            
////                            User.ScrOnAngleTime  = Speed_MidTemperature_LOW;
////                            break;
////                            
////                        case 0x04:
////                            
////                            User.ScrOnAngleTime  = Speed_MidTemperature_Mid;
////                            break;
////                            
////                        case 0x08:
////                            
////                            User.ScrOnAngleTime  = Speed_MidTemperature_High;
////                            break;
////                            
////                        default:
////                            break;
////                    }
////                                       
////                    MCCtrl.TargetValue   = Motor_Speed_Mid;           // 转速赋值
////                    break;
////                    
////                case 0x40:
////                    switch (KS.KeyValuetotal & 0x0F)
////                    {
////                        case 0x01:
////                           
////                            User.ScrOnAngleTime  = Temperature_Off;
////                            GP10 = 1;
////                            GP11 = 1;
////                            break;
////                            
////                        case 0x02:
////                            
////                            User.ScrOnAngleTime  = Speed_HIghTemperature_LOW;
////                            break;
////                            
////                        case 0x04:
////                            
////                            User.ScrOnAngleTime  = Speed_HIghemperature_Mid;
////                            break;
////                            
////                        case 0x08:
////                            
////                            User.ScrOnAngleTime  = Speed_HIghTemperature_High;   
////                            break;
////                            
////                        default:
////                            break;
////                    }
////				           
////                    MCCtrl.TargetValue = Motor_Speed_HIgh;           // 转速赋值
////                    break;
////                    
////                default:
////                    break;
////            }
//			
//			//温度赋值控制
//			#if(ThermostaticENABLE)
//			{
//				switch (KS.KeyValuetotal & 0x0F)
//				{
//					case 0x01:
//						User.ScrOnAngleTime  = Temperature_Off;
//						break;
//						
//					case 0x02:
//						User.TemperatureDatum[0] = Temperature_Low[0];
//						User.TemperatureDatum[1] = Temperature_Low[1];
//						User.TemperatureDatum[2] = Temperature_Low[2];
//						break;
//						
//					case 0x04:
//						User.TemperatureDatum[0] = Temperature_Mid[0];
//						User.TemperatureDatum[1] = Temperature_Mid[1];
//						User.TemperatureDatum[2] = Temperature_Mid[2];
//						break;
//						
//					case 0x08:
//						User.TemperatureDatum[0] = Temperature_High[0];
//						User.TemperatureDatum[1] = Temperature_High[1];
//						User.TemperatureDatum[2] = Temperature_High[2];
//						break;
//						
//					default:
//						break;
//				}
//			}
//			#endif			
//        }
//        else
//        {
//            
//			
//			User.ScrOnAngleTime  = Temperature_Off;
//            switch (KS.KeyValuetotal & 0x70)
//            {
//                case 0x10:
//                    
//                    MCCtrl.TargetValue = Motor_Speed_Low;              // 转速赋值
//                    break;
//                    
//                case 0x20:
//                    
//                    MCCtrl.TargetValue = Motor_Speed_Mid;             // 转速赋值
//                    break;
//                    
//                case 0x40:
//                    
//                    MCCtrl.TargetValue = Motor_Speed_HIgh;            // 转速赋值
//                    break;
//                    
//                default:
//                    break;
//            }
//        }
//    }
//    User.ScrOnPeriod          = Temperature_Control_Period;
//    User.ScrOnAngleTimeDatum  = User.ScrOnAngleTime;
}


/** 
 * @brief        功能函数，温度闭环控制
 * @date         2022-07-14
 */
void Temperature_Control(void)
{
//    static uint8 Delay = 0;                   //延迟时间
//    #if (ThermostaticENABLE ==1)
//    {
//        if (Delay > 0)                      // 延迟过零个数自减
//        {
//            Delay--;
//        }
//        
//        if ((Delay == 0) && ((mcFocCtrl.TPCtrlDealy == 0)))     // 电机运行超过5s，且补正周期为0
//        {
//            if (User.Temperature < User.TemperatureDatum[2])    // 需要稳定的NTC采集值对比，若实际温度高了
//            {
//                if (User.ScrOnAngleTimeDatum > 0)               // 且实际有开启时间输出
//                {
//                    User.ScrOnAngleTimeDatum --;                // 降低发热丝开启时间
//                    Delay = 15;                                 // 每15个过零周期执行一次
//                }
//            }
//            else if (User.Temperature > User.TemperatureDatum[0])   // 温度低
//            {
//                if (User.ScrOnAngleTimeDatum < User.ScrOnPeriod)    // 开启时间不超过输出周期
//                {
//                    User.ScrOnAngleTimeDatum ++;
//                    
//                    if (User.ScrOnAngleTimeDatum > User.ScrOnAngleTime) // 补正开启时间>给定开启时间
//                    {
//                        Delay = 5;                                      // 5次输出周期为检测周期，升温快
//                    }
//                    else                                                // 补正比给定低，升温快
//                    {
//                        Delay = 1;
//                    }
//                }
//            }
//        }
//    }
//    #else
//    {
//        if (mcFocCtrl.mcDcbusFlt >= 24500)  //随电压变化功率
//        {
//            User.ScrOnAngleTimeDatum = User.ScrOnAngleTime - 2;
//        }
//        else if (mcFocCtrl.mcDcbusFlt >= 23400)
//        {
//            User.ScrOnAngleTimeDatum = User.ScrOnAngleTime - 1;
//        }
//        else if (mcFocCtrl.mcDcbusFlt >= 21400)
//        {
//            User.ScrOnAngleTimeDatum = User.ScrOnAngleTime;
//        }
//        else if (mcFocCtrl.mcDcbusFlt >= 19600)
//        {
//            User.ScrOnAngleTimeDatum = User.ScrOnAngleTime + 1;
//        }
//        else
//        {
//            User.ScrOnAngleTimeDatum = User.ScrOnAngleTime + 2;
//        }
//    }
//    #endif
}


void KEY_LED_Display(void)
{
    if(mcFaultSource == FaultNoSource)                    //只有在运行状态指示灯开启
    {
        if(Ledselfcheckflag)  // 流水灯，检测LED
        {
            Ledselfcheckcnt++;
            if(Ledselfcheckcnt > 1500)
            {
                Ledselfcheckflag = 0;
                Ledselfcheckcnt  = 0;
                LED1_EN = 0;
                LED2_EN = 0;
                LED3_EN = 0;
                LED4_EN = 0;
                LED5_EN = 0;
                LED6_EN = 0;
            }
            else if(Ledselfcheckcnt > 1000)
            {
                LED1_EN = 1;
                LED2_EN = 0;
                LED3_EN = 0;
                LED4_EN = 0;
                LED5_EN = 0;
                LED6_EN = 1;
            }
            else if(Ledselfcheckcnt > 500)
            {
                LED1_EN = 0;
                LED2_EN = 1;
                LED3_EN = 0;
                LED4_EN = 0;
                LED5_EN = 1;
                LED6_EN = 0;
            }
            else
            {
                LED1_EN = 0;
                LED2_EN = 0;
                LED3_EN = 1;
                LED4_EN = 1;
                LED5_EN = 0;
                LED6_EN = 0;
            }
        }
        else
        {
            Ledselfcheckcnt = 0;
            switch (Speed_Lv)
            {
                case  1 :  
                    LED1_EN = 0;
                    LED2_EN = 0;
                    LED3_EN = 1;
                break;
        
                case  2 :  
                    LED1_EN = 0;
                    LED2_EN = 1;
                    LED3_EN = 1;
                break;
        
                case  3 : 
                    LED1_EN = 1;
                    LED2_EN = 1;
                    LED3_EN = 1;
                break;
            }
      
            switch (heat_Lv)
            {
                case  1 : 
                    LED4_EN = 1;
                    LED5_EN = 0;
                    LED6_EN = 0;
                    Ledflashcnt = 0;
                break;
        
                case  2 :  
                    LED4_EN = 1;
                    LED5_EN = 1;
                    LED6_EN = 0;
                    Ledflashcnt = 0;
                break;
        
                case  3 : 
                    LED4_EN = 1;
                    LED5_EN = 1;
                    LED6_EN = 1;
                    Ledflashcnt = 0;
                break;
                
                case  4 :
                    if(++Ledflashcnt < 300)
                    {
                        LED4_EN = 0;
                        LED5_EN = 0;
                        LED6_EN = 1;
                    }
                    else if(Ledflashcnt < 600)
                    {
                        LED4_EN = 0;
                        LED5_EN = 1;
                        LED6_EN = 0;
                    }
                    else if(Ledflashcnt < 900)
                    {
                        LED4_EN = 1;
                        LED5_EN = 0;
                        LED6_EN = 0;
                    }
                    else
                    {
                        Ledflashcnt = 0;
                    }
                break;
            }
      
            if( (Cool_Lv) || (Overtmp_flag) || (OverVoltageflag) )    // 异常或冷风关LED
            {
                LED4_EN = 0;
                LED5_EN = 0;
                LED6_EN = 0;
            }
        }
    }
    else
    {
        if(mcLedDisplay.LED_Step < 600)     // 报错闪灯之前先全关LED一段时间
        {
            LED1_EN = 0;
            LED2_EN = 0;
            LED3_EN = 0;
            LED4_EN = 0;
            LED5_EN = 0;
            LED6_EN = 0;
            mcLedDisplay.LED_Step++;
            Ledselfcheckcnt = 0;
        }
        else
        {
            switch (mcFaultSource)
            {
                case FaultOverVoltage:
                {
                    LED_ONOFF_SET(2, 0);
                }
                break;
                
                case FaultSoftOVCurrent:
                {
                    LED_ONOFF_SET(5, 0);
                }
                break;
                
                case FaultHardOVCurrent:
                {
                    LED_ONOFF_SET(4, 0);
                }
                break;
                
                case FaultStall:
                {
                    LED_ONOFF_SET(3, 0);
                }
                break;
                
                case FaultLossPhase:
                {
                    LED_ONOFF_SET(6, 0);
                }
                break;
                
                case FaultStallenter:
                {
                    LED_ONOFF_SET(1, 1);
                }
                break;
            }
        }
    }

    LED_1MS_CYCLE();
}
extern uint8  PowerOKflag  ;
void LED_Display(void)
{
		if((PowerOKflag==0) )
		{
				GP15 = 0;
				GP16 = 0;
				GP17 = 0;
		
		}
		
		else
		{
			if(mcFaultSource == FaultNoSource)
			{
					switch (heat_Lv)
					{
							case 1:
							{
									GP15 = 1;
									GP16 = 0;
									GP17 = 0;
	//                LED1_EN = 1;
	//                LED2_EN = 0;
	//                LED3_EN = 0;
	//                LED4_EN = 0;
	//                LED5_EN = 0;
	//                LED6_EN = 1;
							}
							break;
							
							case 2:
							{
									GP15 = 0;
									GP16 = 1;
									GP17 = 0;
	//                LED1_EN = 0;
	//                LED2_EN = 1;
	//                LED3_EN = 0;
	//                LED4_EN = 0;
	//                LED5_EN = 1;
	//                LED6_EN = 0;
							}
							break;
							
							case 3:
							{
									GP15 = 0;
									GP16 = 0;
									GP17 = 1;
	//                LED1_EN = 0;
	//                LED2_EN = 0;
	//                LED3_EN = 1;
	//                LED4_EN = 1;
	//                LED5_EN = 0;
	//                LED6_EN = 0;
							}
							break;
					}
			}
			else
			{
					if(mcLedDisplay.LED_Step < 600)     // 报错闪灯之前先全关LED一段时间
					{
							GP15 = 0;
							GP16 = 0;
							GP17 = 0;
	//            LED1_EN = 0;
	//            LED2_EN = 0;
	//            LED3_EN = 0;
	//            LED4_EN = 0;
	//            LED5_EN = 0;
	//            LED6_EN = 0;
							mcLedDisplay.LED_Step++;
					}
					else
					{
							switch (mcFaultSource)
							{
									case FaultOverVoltage:
									{
											LED_ONOFF_SET(2, 1);
									}
									break;
									
									case FaultSoftOVCurrent:
									{
											LED_ONOFF_SET(5, 1);
									}
									break;
									
									case FaultHardOVCurrent:
									{
											LED_ONOFF_SET(4, 1);
									}
									break;
									
									case FaultStall:
									{
											LED_ONOFF_SET(3, 1);
									}
									break;
									
									case FaultLossPhase:
									{
											LED_ONOFF_SET(6, 1);
									}
									break;
									
									case FaultStallenter:
									{
											LED_ONOFF_SET(1, 1);
									}
									break;
							}
					}
			}
    }
//    LED_1MS_CYCLE();
}

void LED_1MS_CYCLE(void)                 // 3个IO分别控制6个LED
{    
//    if(Led_play_mode > 5)
//    {
//        Led_play_mode = 0;
//    }
//    
//    GP15 = 0;
//    GP16 = 0;
//    GP17 = 0;      //LED全关，消影
//    ClrBit(P1_AN, P17 | P16 | P15);
//    
//    switch (Led_play_mode)
//    {
//        case 0:                            //点亮D1
//        {
//            if(LED1_EN)
//            {
//                SetBit(P1_AN, P15);
//                GP16 = 0;
//                GP17 = 1;
//            }
//        }
//        break;
//        
//        case 1:                            //点亮D2
//        {
//            if(LED2_EN)
//            {
//                SetBit(P1_AN, P15);
//                GP17 = 0;
//                GP16 = 1;
//            }
//        }
//        break;
//        
//        case 2:
//        {            //点亮D3
//            if(LED3_EN)
//            {
//                SetBit(P1_AN, P16);
//                GP15 = 0;
//                GP17 = 1;
//            }
//        }
//        break;
//              
//        case 3:                            //点亮D4
//        {
//            if(LED4_EN)
//            {
//                SetBit(P1_AN, P16);
//                GP17 = 0;
//                GP15 = 1;
//            }
//        }
//        break;
//              
//        case 4:                            //点亮D5
//        {
//            if(LED5_EN)
//            {
//                SetBit(P1_AN, P17);
//                GP15 = 0;
//                GP16 = 1;
//            }
//        }
//        break;
//              
//        case 5:                            //点亮D6
//        {
//            if(LED6_EN)
//            {
//                SetBit(P1_AN, P17);
//                GP16 = 0;
//                GP15 = 1;
//            }
//        }
//        break;
//    }
//    
//    Led_play_mode++;
}

void LED_ONOFF_SET(uint8 ShineTimes, uint8 ShineMode)
{
    mcLedDisplay.WaitTime = 1250;       // 闪灯周期之间的等待时间，单位：ms
    
    if(mcLedDisplay.OnOffTimes < ShineTimes)
    {
        mcLedDisplay.OnOffCount++;
        if(mcLedDisplay.OnOffCount < 250)
        {
            GP15 = 1;
            GP16 = 1;
            GP17 = 1;
//            LED1_EN = 1;
//            LED2_EN = 1;
//            LED3_EN = 1;
            
            if(ShineMode == 1)
            {
                LED4_EN = 1;
                LED5_EN = 1;
                LED6_EN = 1;
            }
        }
        else if(mcLedDisplay.OnOffCount < 500)
        {
            GP15 = 0;
            GP16 = 0;
            GP17 = 0;
//            LED1_EN = 0;
//            LED2_EN = 0;
//            LED3_EN = 0;
            
            if(ShineMode == 1)
            {
                LED4_EN = 0;
                LED5_EN = 0;
                LED6_EN = 0;
            }
        }
        else
        {
            mcLedDisplay.OnOffCount=0;
            mcLedDisplay.OnOffTimes++;
        }
    }
    else
    {
        mcLedDisplay.CycleCount++;
        if(mcLedDisplay.CycleCount > mcLedDisplay.WaitTime)
        {
            mcLedDisplay.OnOffTimes=0;
            mcLedDisplay.CycleCount=0; 
        }
    }
}