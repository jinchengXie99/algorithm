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


/* Includes --------------------------------------------------------------------------------------*/
#include <FU68xx_2.h>
#include <Myproject.h>


uint8 SW1_Flag = 0;
uint8 SW2_Flag = 0;
uint8 SW3_Flag = 0;

uint8 Flag_Key1Value = 0;      //档位变换顺序
uint8 Flag_Key2Value = 0;

uint8 Loop1msCnt = 0;

uint8 xdata Key_spd_Flag = 0;
uint8 Key_spd_old = 0;
uint8 Key_spd_new = 0;
uint8 Key_spd_Lv_old = 0;
uint8 Key_spd_Lv_new = 0;

uint8 xdata Key_heat_Flag = 0;
uint8 Key_heat_old = 0;
uint8 Key_heat_new = 0;
uint8 Key_heat_Lv_old = 0;
uint8 Key_heat_Lv_new = 0;

uint8 Speed_Lv = 0;
uint8 Speed_Lv_old = 0; 
uint8 heat_Lv = 0, heat_Lv_Init = 0;
uint8 heat_Lv_old = 0;

uint8 Heat_on_flag = 0;
int8  Heat_duty = 0;
int16 Heat_duty_act = 0;
uint8 Heat_duty_yu  = 0;
int8  Heat_duty_cycle = 0;
int8  Heat_duty_max = 0;
uint8 Heat_on_cnt = 0;
uint16 Heat_on_delay = 0;

uint16 Key_ADvalue_avg = 0;

uint8 Led_play_mode = 0;                 //6LED分时显示状态位    
//bit Led_D1_Lv = 0;
//bit Led_D2_Lv = 0;
//bit Led_D3_Lv = 0;
//bit Led_D4_Lv = 0;
//bit Led_D5_Lv = 0;
//bit Led_D6_Lv = 0;                    //0位-D1   1位-D2   2位-D3   3位-D4   4位-D5   5位-D6


uint32 HeatTmp_ADvalue_sum = 0;
uint16 HeatTmp_ADvalue_avg = 0;
uint8  HeatTmp_sum_cnt = 0;
uint8  HeatTmp_real =0;
uint8  Overtmpcnt = 0, Overtmp_flag = 0;
uint16 Overtmp_recovercnt = 0;

uint8  WindTemperCmd = 0;
uint16 Tmpregularcnt = 0;
int8   TmpPwmdelta = 0;
uint8  HeatTmp_old = 0, HeatTmp_new = 0;
uint8  HeatTmp_updowmLv = 0;              //0：上升    1：恒定    2：下降


uint8  Keysavevalue = 0;

uint16 RuntimeCntX1ms  = 0;
uint8  RuntimeCntX1min = 0;               //运行时间计数——分钟
uint16 RuntimeCntXn   = 0;                //运行时间计数——RuntimeCntX1ms的倍数
extern uint8 FlashPieceNum;

uint16  Ledflashcnt = 0;

uint16 Heatonoffcnt = 0;

uint8  Ledselfcheckflag = 0;
uint16 Ledselfcheckcnt = 0;

uint8  Cool_Lv = 0;
uint8  Cool_Lv_on_cnt = 0;
uint8  Cool_Lv_off_cnt = 0;

uint8  DatTxCnt = 0;

uint16 LedErrflashcnt = 0;

uint16 Heaterrcnt = 0;
uint8  Secoff_flag = 0;
uint8  Secoffcnt = 0;

uint8 xdata Heatduty[6] = {0, 0, 0,0, 0, 0};

uint8 Heatdutycnt = 0;

uint8  Spd_looptime = 0;
uint8 xdata BlockFlashNum = 0;
/* Private variables ----------------------------------------------------------------------------*/
KeyScanParam_TypeDef xdata KS;


/*  -------------------------------------------------------------------------------------------------
    Function Name : void KeyInit(void)
    Description   : 按键参数初始化
    Input         : 无
    Output                :   无
    -------------------------------------------------------------------------------------------------*/
void KeyInit(void)
{
    uint8 i;
//    uint8 revalue = 1;
//    KS.Key1Value = 0x01;
//    KS.Key2Value = 0x10;
//    KS.Key3Value = 0x00;
//    KS.KeyValuetotal     = KS.Key1Value ^ KS.Key2Value ^ KS.Key3Value;
    Rom.WriteAddress = STARTPAGEROMADDRESS;              //给定写入初地址
//    Rom.ReadValue  = ReadFlashValue(Rom.WriteAddress);    //读取指定地址值 
//    
//    if ((Rom.ReadValue == 0x11) || (Rom.ReadValue == 0x21) || (Rom.ReadValue == 0x41) || (Rom.ReadValue == 0x12) || (Rom.ReadValue == 0x22)
//        || (Rom.ReadValue == 0x42) || (Rom.ReadValue == 0x14) || (Rom.ReadValue == 0x24) || (Rom.ReadValue == 0x44) || (Rom.ReadValue == 0x18)
//        || (Rom.ReadValue == 0x28) || (Rom.ReadValue == 0x48))
//    {
//        KS.KeyValuetotal   = Rom.ReadValue;
//        KS.Key1Value = Rom.ReadValue & 0x0F;
//        KS.Key2Value = Rom.ReadValue & 0x70;;
//        KS.Key3Value = 0x00;
//    }
//    else
//    {
//		revalue = Flash_Sector_Erase(Rom.WriteAddress);     //擦除扇区
//    if(! revalue)
//		{			
//           Flash_KeyWriteValue(Rom.WriteAddress,0x21);      //指定地址写值
//		}
//		else
//		{
//		   Rom.ReadValue = 0;	
//		}
//        EA = 1;
//    }
//    
//    KS.OldKeyValuetotal  = 0;
//    KS.ChangeKeyFlg      = 0;
//    KS.Key1PressCnt = 0;

    #if (SPEED_MODE == KEYSCANMODE)
    {
        FlashPieceNum = 0;
        if(ReadFlashValue(Rom.WriteAddress) != 0xA5)  //第一次上电，未存储过
        {
            Flash_Sector_Erase(Rom.WriteAddress);       //擦除扇区
            Speed_Lv = SPD_LV_ON; //SPD_LV_ON;
            heat_Lv  = HEAT_LV_ON; // HEAT_LV_ON;
            RuntimeCntX1min = 0;
            RuntimeCntXn = 0;
        }
        else
        {
            for(i=0;i<=24;i++)
            {
                if((*(uint8 code *)(Rom.WriteAddress + i*5)) == 0xA5)
                FlashPieceNum = i;                   
            }
        
            RuntimeCntXn = 0;
            RuntimeCntXn |= (*(uint8 code *)(Rom.WriteAddress + FlashPieceNum*5 + 1)) << 8;
            RuntimeCntXn |= (*(uint8 code *)(Rom.WriteAddress + FlashPieceNum*5 + 2));
            RuntimeCntX1min = (*(uint8 code *)(Rom.WriteAddress + FlashPieceNum*5 + 3));
            Speed_Lv = (*(uint8 code *)(Rom.WriteAddress + FlashPieceNum*5 + 4)) >> 4;
            heat_Lv  = ( (*(uint8 code *)(Rom.WriteAddress + FlashPieceNum*5 + 4)) & 0x0F);
            FlashPieceNum++;                            //下一次存储的为本扇区第几次存储
        }
        
        if(FlashPieceNum >= 25)
        {
          Flash_Sector_Erase(Rom.WriteAddress);     //擦除扇区    
          FlashPieceNum = 0;
        }
        
        Ledselfcheckflag = 1;
    }
    #elif (SPEED_MODE == TOUCHMODE)
    {
        while(ReadFlashValue(Rom.WriteAddress + BlockFlashNum))
        {
            BlockFlashNum++;
            if(BlockFlashNum >= 128)
            {
                Flash_Sector_Erase(Rom.WriteAddress);
                BlockFlashNum = 0;
            }
        }
        
        if(BlockFlashNum == 0)
        {
            heat_Lv = 1;
        }
        else    // 实际输出下来的 Rom.WriteAddress + BlockFlashNum 地址是空地址，上一个地址才有数据
        {
            heat_Lv = ReadFlashValue(Rom.WriteAddress + BlockFlashNum - 1);
        }
    }
    #endif
    
    heat_Lv_Init = heat_Lv;
}

/*  -------------------------------------------------------------------------------------------------
    Function Name : uint8 KeyValue(void)
    Description   : 功能函数，获取按键值，选择返回键位值还是管脚电平KeyValue
    Input         : 无
    Output                :   键位值或者管脚电平KeyValue
    -------------------------------------------------------------------------------------------------*/
int KeyValue(void)
{
/* SW1 Scan */
    if (SW1 == 0)                       // 0x00-0x01-0x04....
    {
        if (SW1_Flag == 0)
        {
            KS.Key1PressCnt ++;
            
            if (KS.Key1PressCnt >= KeyFilterTime)           // 按键滤波
            {
                KS.Key1PressCnt = KeyFilterTime;
                SW1_Flag = 1;                               // SW1按下标记，自锁
                
			   	if(KS.Key1Value < 0x08)                     // 变量初始值？
					  KS.Key1Value = KS.Key1Value << 1;     // [1]0x01-0x02 \ [2]0x04-0x08 \ [3]0x04-0x08-1
				  else                                      // [4]0x04-0x08-1
					  KS.Key1Value = 0x01;
          
                if ((KS.Key1Value < 0x08) && (Flag_Key1Value == 0))
                {
                    KS.Key1Value = KS.Key1Value << 1;       // [1]0x02-0x04
                }
                else if ((KS.Key1Value > 0x01) && (Flag_Key1Value == 1))
                {
                    KS.Key1Value = KS.Key1Value >> 1;       // [3]0x08-0x04-1 \ [4]0x08-0x04-1
                }
                else if (KS.Key1Value == 0x08)
                {
                    Flag_Key1Value = 1;
                    KS.Key1Value = KS.Key1Value >> 1;       // [2]0x08-0x04-1
                }
                else if (KS.Key1Value == 0x01)
                {
                    Flag_Key1Value = 0;
                    KS.Key1Value = KS.Key1Value << 1;
                }
                else                                // KS.Key1Value = 0x00时进入
                {
                    Flag_Key1Value = 0;
                    KS.Key1Value = 0x01;            // 第一次给定初始值0x01 [0]0x00-0x01
                }
            }
        }
        else if (SW1_Flag == 1)
        {
            KS.Key1Value = KS.Key1Value ;
        }
        else                        // SW1_Flag != 0   // 1
        { SW1_Flag = 0; }
    }
    else                            // 松开按键
    {
        KS.Key1PressCnt --;
        
        if (KS.Key1PressCnt <= 0)       // 按键滤波
        {
            KS.Key1PressCnt = 0;
            SW1_Flag = 0;               // 清0按键自锁标记
        }
    }
    
    /* SW2 Scan */
    if (SW2 == 0)                       // 0x00-0x10-[0x20-0x40-0x20-0x10]循环   3个档位循环
    {
        if (SW2_Flag == 0)
        {
            KS.Key2PressCnt ++;
            
            if (KS.Key2PressCnt >= KeyFilterTime)
            {
                KS.Key2PressCnt = KeyFilterTime;
                SW2_Flag = 1;
                
                if ((KS.Key2Value < 0x40) && (Flag_Key2Value == 0))
                {
                    KS.Key2Value = KS.Key2Value << 1;
                }
                else if ((KS.Key2Value > 0x10) && (Flag_Key2Value == 1))
                {
                    KS.Key2Value = KS.Key2Value >> 1;
                }
                else if (KS.Key2Value == 0x40)
                {
                    Flag_Key2Value = 1;
                    KS.Key2Value = KS.Key2Value >> 1;
                }
                else if (KS.Key2Value == 0x10)
                {
                    Flag_Key2Value = 0;
                    KS.Key2Value = KS.Key2Value << 1;
                }
                else
                {
                    Flag_Key2Value = 0;
                    KS.Key2Value = 0x10;
                }
            }
        }
        else if (SW2_Flag == 1)
        {
            KS.Key2Value = KS.Key2Value ;
        }
        else
        { SW2_Flag = 0; }
    }
    else
    {
        KS.Key2PressCnt --;
        
        if (KS.Key2PressCnt <= 0)
        {
            KS.Key2PressCnt = 0;
            SW2_Flag = 0;
        }
    }
    
    /* SW3 Scan */
//    if (SW3 == 0)
//    {
//        KS.Key3releaseCnt = 0;
//        
//        if (KS.Key3PressCnt < KeyFilterTime + 10)
//        {
//            KS.Key3PressCnt++;
//        }
//        
//        if (SW3_Flag == 0)
//        {
//            if (KS.Key3PressCnt >= KeyFilterTime)
//            {
//                KS.Key3PressCnt = KeyFilterTime;
//                SW3_Flag = 1;
//                KS.Key3Value = 0x80;
//            }
//        }
//        else if (SW3_Flag == 1)
//        {
//            KS.Key3Value = KS.Key3Value ;
//        }
//    }
//    else
//    {
//        KS.Key3PressCnt = 0;
//        
//        if (KS.Key3releaseCnt < 100)
//        { KS.Key3releaseCnt++; }
//        
//        if (KS.Key3releaseCnt >= 80)
//        {
//            SW3_Flag = 0;
//            KS.Key3Value = 0x00;
//        }
//    }
    
    return (KS.Key1Value ^ KS.Key2Value ^ KS.Key3Value);
}

/*  -------------------------------------------------------------------------------------------------
    Function Name : void KeyScan(void)
    Description   : 功能函数，按键扫描，按键触发传递出按键命令
    Input         : 无
    Output                :   无
    -------------------------------------------------------------------------------------------------*/
void KeyScan(void)
{
    KS.OldKeyValuetotal = KS.KeyValuetotal;
  	KS.KeyValuetotal = KeyValue();               // 两个按键信号
    
    if (KS.OldKeyValuetotal != KS.KeyValuetotal)    // 按键信号有改变
    {
        if ((mcState == mcRun))
        {
            KS.ChangeKeyFlg = 1;
        }
    }
}



int16 CalTemperOffset(uint16 base,uint16 val, uint16 warm, uint16 cool)
{
  return(base - 25*(val-warm)/(cool-warm));
}

void UARTDataSend(void)
{
    if(DatTxCnt == 0)
    {
        UT_DR = 0xA5;
        DatTxCnt++;
    }
    else if(DatTxCnt == 1)
    {
        if(TI == 1)
        {
            TI = 0;
            UT_DR = (RuntimeCntXn >> 8);
            DatTxCnt++;
        }
    }
    else if(DatTxCnt == 2)
    {
        if(TI == 1)
        {
            TI = 0;
            UT_DR = RuntimeCntXn;
            DatTxCnt++;
        }
    }
    else if(DatTxCnt == 3)
    {
        if(TI == 1)
        {
            TI = 0;
            UT_DR = RuntimeCntX1min;
            DatTxCnt++;
        }
    }
}

void Key_Led_Ctrl(void)
{
    if(++Loop1msCnt > 9)
    {
        Loop1msCnt = 0;                 // 10ms计时
    }
  
    if(++RuntimeCntX1ms >= 60000)
    {
        RuntimeCntX1ms = 0;
        if(++RuntimeCntX1min >= 255)    // min计时
        {
            RuntimeCntXn++;
        }
    }
  
    UARTDataSend();       // UART传输上电时间
    
    Keysavevalue = (Speed_Lv << 4) + heat_Lv;   // 速度和温度档位掉电存储变量
  
    //调速按键
    if(Loop1msCnt == 0)       // 10ms执行一次，速度档位信号获取
    {            
        if((Key_ADvalue_avg > 3100) && (Key_ADvalue_avg < 3600)) // 按键信号处理，AD信号，速度调档有效信号
        {
            Key_spd_old = 0;
            Key_spd_new++;
            
            if((Key_spd_new > 1) && (Key_spd_Flag == 1))
            {
                Key_spd_new  = 0;
                Key_spd_Flag = 0;        // AD信号在速度调整档位范围内
                Speed_Lv++;
                if(Speed_Lv > SPD_LV_MAX)         //1-2-3   对应    1-2-3
                {
                    Speed_Lv = 1;
                }
            }
        }
        else
        {
            Key_spd_new  = 0;
            Key_spd_old++;
            if((Key_spd_old > 1) && (Key_spd_Flag == 0))
            {
                Key_spd_old  = 0;
                Key_spd_Flag = 1;
            }
        }
    }
    
    else if(Loop1msCnt == 2)      // 10ms执行一次，温度档位获取
    {
        if(mcState == mcRun)
        {      
            if((Key_ADvalue_avg > 1800) && (Key_ADvalue_avg < 2300)) // 冷风档判断
            {
                Cool_Lv_off_cnt = 0;
                Cool_Lv_on_cnt++;
                if(Cool_Lv_on_cnt >= 100)
                {
                    Cool_Lv_on_cnt = 100;
                    Cool_Lv = 1;
                }
            }
            else
            {
                Cool_Lv_on_cnt = 0;
                Cool_Lv_off_cnt++;
                if(Cool_Lv_off_cnt >= 100)
                {
                    Cool_Lv_off_cnt = 100;
                    Cool_Lv = 0;
                }
            }
      
            if(Cool_Lv != 1)
            {
                Key_heat_old = 0;
                Key_heat_new++;
                if((Key_heat_new > 1) && (Key_heat_Flag == 1))
                {
                    Key_heat_new  = 0;
                    Key_heat_Flag = 0;
                    
                    heat_Lv++;
                    if(heat_Lv > HEAT_LV_MAX)             //0-1-2-3-4    对应    0-1-2-3-4
                    {
                        heat_Lv = 0;
                    }
                }
            }
            else
            {
                Key_heat_new = 0;
                Key_heat_old++;
                if((Key_heat_old > 1) && (Key_heat_Flag == 0))
                {
                    Key_heat_old  = 0;
                    Key_heat_Flag = 1;
                }
            }
        }
    }
  
    /************转速/温度给定*************/
    else if(Loop1msCnt == 4)              // 10ms执行一次，和上述判断周期错开
    {
        switch (Speed_Lv)
        {
            case  1 :  MCCtrl.TargetValue = Motor_Speed_Low;
            break;
      
            case  2 :  MCCtrl.TargetValue = Motor_Speed_Mid;
            break;
      
            case  3 :  MCCtrl.TargetValue = Motor_Speed_HIgh;
            break;
        }
      
        switch (heat_Lv)                            // 发热丝输出duty限制
        {
            case  0 :  Heat_duty_max = 0;        
            break;
      
            case  1 :  Heat_duty_max = HEAT_PWM_MAX;
            break;
      
            case  2 :  Heat_duty_max = HEAT_PWM_MAX;
            break;
      
            case  3 :
                if(Speed_Lv == 3)
                {
                    Heat_duty_max = HEAT_PWM_MAX;
                }
                else
                {
                    Heat_duty_max = HEAT_PWM_MAX;
                }
            break;
          
            case  4 :
                if(Speed_Lv == 3)
                {
                    Heat_duty_max = HEAT_PWM_MAX;
                }
                else
                {
                    Heat_duty_max = HEAT_PWM_MAX;
                }
          
                if(++Heatonoffcnt > 1000)         // 5s开5s关
                {
                    Heatonoffcnt = 0;
                }
                else if(Heatonoffcnt > 500)
                {
                    Heat_duty_max = 0;              // 每5s清0一次，即每5s关闭一次发热丝输出
                }
            break;
        }
    
        if( (heat_Lv != 4) || (mcState != mcRun) || (Cool_Lv) )  // 温度档不为4|电机未运行|冷风档
        {
            Heatonoffcnt = 0;
        }
    
        if(Cool_Lv)                 // 冷风模式，关输出
        {
            Heat_duty_max = 0;        // 限制duty给0，相当于关发热丝输出
        }
    
        switch (heat_Lv)
        {
            case  1 :
                if(Speed_Lv == 1)
                {
                    Heat_duty = HEAT_PWM_LV1_1;
                    WindTemperCmd = TMPVALUECMD_LV1_1;
                }
            else if(Speed_Lv == 2)
            {
                Heat_duty = HEAT_PWM_LV1_2;
                WindTemperCmd = TMPVALUECMD_LV1_2;
            }
            else
            {
                Heat_duty = HEAT_PWM_LV1_3;
                WindTemperCmd = TMPVALUECMD_LV1_3;
            }
            break;
      
            case  2 :
                if(Speed_Lv == 1)
                {
                  Heat_duty = HEAT_PWM_LV2_1;
                  WindTemperCmd = TMPVALUECMD_LV2_1;
                }
                else if(Speed_Lv == 2)
                {
                  Heat_duty = HEAT_PWM_LV2_2;
                  WindTemperCmd = TMPVALUECMD_LV2_2;
                }
                else
                {
                  Heat_duty = HEAT_PWM_LV2_3;
                  WindTemperCmd = TMPVALUECMD_LV2_3;
                }
            break;
      
            case  3 :
                if(Speed_Lv == 1)
                {
                    Heat_duty = HEAT_PWM_LV3_1;
                    WindTemperCmd = TMPVALUECMD_LV3_1;
                }
                else if(Speed_Lv == 2)
                {
                    Heat_duty = HEAT_PWM_LV3_2;
                    WindTemperCmd = TMPVALUECMD_LV3_2;
                }
                else
                {
                    Heat_duty = HEAT_PWM_LV3_3;              
                    WindTemperCmd = TMPVALUECMD_LV3_3;             
                }
            break;
                
            case  4 :
                if(Speed_Lv == 1)
                {
                    Heat_duty = HEAT_PWM_LV3_1;
                }
                else if(Speed_Lv == 2)
                {
                    Heat_duty = HEAT_PWM_LV3_2;
                }
                else
                {
                    Heat_duty = HEAT_PWM_LV3_3;
                }
            break;
        }
    
        if( (heat_Lv == 3) && (Speed_Lv == 3) )     // 高温高速档恒温限幅值
        {
            if((mcFocCtrl.mcDcbusFlt > 22380) && (HeatTmp_real>=148))     // 母线电压平均值
            {            
                WindTemperCmd = 140;
            }
            else if((mcFocCtrl.mcDcbusFlt < 22130) && (HeatTmp_real<142))
            {
                WindTemperCmd = 150;
            }
        }
    }

    /* -----出风口实际温度计算----- */
    else if(Loop1msCnt == 6)
    {
        if(HeatTmp_ADvalue_avg <= CELSIUS_P25_ADC_B)
        {
            // <50℃
            if(HeatTmp_ADvalue_avg > CELSIUS_P50_ADC_B)
                HeatTmp_real = CalTemperOffset(50,HeatTmp_ADvalue_avg,CELSIUS_P50_ADC_B,CELSIUS_P25_ADC_B);
            // <75℃
            else if(HeatTmp_ADvalue_avg > CELSIUS_P75_ADC_B)
                HeatTmp_real = CalTemperOffset(75,HeatTmp_ADvalue_avg,CELSIUS_P75_ADC_B,CELSIUS_P50_ADC_B);
//            // <100℃
//            else if(HeatTmp_ADvalue_avg > CELSIUS_P100_ADC_B)
//                HeatTmp_real = CalTemperOffset(100,HeatTmp_ADvalue_avg,CELSIUS_P100_ADC_B,CELSIUS_P75_ADC_B);
//            // <125℃
//            else if(HeatTmp_ADvalue_avg > CELSIUS_P125_ADC_B)
//                HeatTmp_real = CalTemperOffset(125,HeatTmp_ADvalue_avg,CELSIUS_P125_ADC_B,CELSIUS_P100_ADC_B);
//            // >125℃
//            else if(HeatTmp_ADvalue_avg > CELSIUS_P150_ADC_B)
//                HeatTmp_real = CalTemperOffset(150,HeatTmp_ADvalue_avg,CELSIUS_P150_ADC_B,CELSIUS_P125_ADC_B);
//            else if(HeatTmp_ADvalue_avg > CELSIUS_P175_ADC_B)
//                HeatTmp_real = CalTemperOffset(175,HeatTmp_ADvalue_avg,CELSIUS_P175_ADC_B,CELSIUS_P150_ADC_B);
//            else
//                HeatTmp_real = 175;
        }
        // <25℃
        else
        {
            HeatTmp_real = 25;
        }
    }
  
//  else if(Loop1msCnt == 8)    // 1ms执行一次
    {
        if( (mcState == mcRun)&&(Overtmp_flag == 0)&&(OverVoltageflag == 0) )
        {
            if(++Heat_on_delay >= 1200)           // 延时1.2s
            {
                Heat_on_delay = 1201;
        
                if(++Tmpregularcnt > 1000)          // 每10ms执行一次
                {
                    Tmpregularcnt = 0;
                    if( (heat_Lv != 0) && (heat_Lv != 4) && (Cool_Lv != 1) )
                    {
                        HeatTmp_old = HeatTmp_new;
                        HeatTmp_new = HeatTmp_real;
                        if(HeatTmp_new > HeatTmp_old)       // 当前温度比上次低，升温
                        {
                            HeatTmp_updowmLv = HEATUP;             //温度上升
                        }
                        else if(HeatTmp_new < HeatTmp_old)  // 当前温度比上次高，降温
                        {
                            HeatTmp_updowmLv = HEATDOWN;           //温度下降
                        }
                        else
                        {
                            HeatTmp_updowmLv = HEATHOLDON;       //恒温模式
                        }
            
                        if(HeatTmp_real < WindTemperCmd)         // 实际温度低于设定温度值
                        {
                            if(HeatTmp_updowmLv != HEATUP)         // 温度比上次低
                            {
                                if(WindTemperCmd - HeatTmp_real >= 12)
                                {
                                    TmpPwmdelta += 5;
                                }
                                else
                                {
                                    TmpPwmdelta++;
                                }
                            }
                        }
                        else if(HeatTmp_real > WindTemperCmd)
                        {
                            if(HeatTmp_updowmLv != HEATDOWN)
                            {
                                if(HeatTmp_real - WindTemperCmd >= 12)
                                {
                                    TmpPwmdelta -= 5;
                                }
                                else
                                {
                                    TmpPwmdelta--;
                                }
                            }
                        }          
                        
                        if(TmpPwmdelta < -48)       // 变量限幅
                        {
                            TmpPwmdelta = -48;
                        }
                        
                        if(TmpPwmdelta > 9)
                        {
                            TmpPwmdelta = 9;
                        }
            
                    }
                    else
                    {
                        TmpPwmdelta = 0;
                    }
                }
        
                /* -----        档位给定    当前温度和实际温度差  电源电压误差补正----- */
                Heat_duty_act = Heat_duty + TmpPwmdelta + PWMadapt;  // 延时1200ms后，1ms执行一次
        
                if(Heat_duty_act > Heat_duty_max + PWMadapt)    // 限幅
                {
                    Heat_duty_act = Heat_duty_max + PWMadapt;
                }
          
                if(Heat_duty_act < 0)
                {
                    Heat_duty_act = 0;
                }
        
                Heatduty[0] = Heat_duty_act/3;
                Heatduty[1] = Heatduty[0] + Heat_duty_act%3/2;
                Heatduty[2] = Heat_duty_act - Heatduty[0] - Heatduty[1];
        
                if(Getzero_flag)            // 交流电过零点
                {
                    Getzero_flag = 0;
                  
//                    if(Heat_duty_cycle&0x01)  // 最低位是否为1
//                    {
//                        if(Heat_on_cnt == (Heat_duty_cycle/2))
//                        {
//                            Secoff_flag = 1;
//                        }
//                    }
//                    else
//                    {
//                        Secoff_flag = 0;
//                        Secoffcnt = 0;
//                    }
                  
                    if(++Heat_on_cnt >= HEAT_TIMECNT_MAX)
                    {
                        Heat_on_cnt = 0;
                        if(++Heatdutycnt > 2)
                        {
                            Heatdutycnt = 0;
                        }
                        Heat_duty_cycle = Heatduty[Heatdutycnt];
                    }
                
                    if(Heat_on_cnt < Heat_duty_cycle)
                    {
                        Heat_on_flag = 1;
                    }
                    else
                    {
                        Heat_on_flag = 0;
                    }
                } 
            
//                if(Secoff_flag)
//                {
//                    if(++Secoffcnt > 3)
//                    {
//                        Secoffcnt = 0;
//                        Secoff_flag = 0;
//                        GP07 = !HEAT_ON_LEVEL;                             //奇数占空比在第1个半波关闭可控硅，从而实现第二个半波的关闭
//                    }
//                }
            }
            else
            {
                TmpPwmdelta = 0;
                Tmpregularcnt = 0;
                Getzero_flag = 0;
                Secoff_flag = 0;
                Secoffcnt = 0;
            }
        }
        else
        {
            GP07 = !HEAT_ON_LEVEL;
            Heat_on_flag = 0;
            Heat_on_cnt = 0;
            Heat_on_delay = 0;
            Tmpregularcnt = 0;
            TmpPwmdelta = 0;
            Secoff_flag = 0;
            Secoffcnt = 0;
        }
    }
}