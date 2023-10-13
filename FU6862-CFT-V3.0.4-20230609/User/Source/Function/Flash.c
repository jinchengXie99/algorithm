/*  -------------------------- (C) COPYRIGHT 2022 Fortiortech ShenZhen ---------------------------*/
/**
 * @copyright (C) COPYRIGHT 2022 Fortiortech Shenzhen
 * @file      
 * @author    Fortiortech  Appliction Team
 * @since     Create:2022-07-14
 * @date      Last modify:2022-07-14
 * @note      Last modify author is Leo.li
 * @brief      
 */

/* Includes ------------------------------------------------------------------*/
#include <FU68xx_2.h>
#include <Myproject.h>

ROM_TypeDef xdata  Rom;

uint8 Flash_GetAddress(void);

uint8 FlashPieceNum = 0;


uint8 xdata table1[] = {0, 0, 0, 0, 0};
/**
 * @brief        读取固定地址值
 * @date         2022-07-14
 */
uint8 ReadFlashValue(uint16 ReadAddress)
{
    uint16 TempAddress0 = ReadAddress;
    __IO uint8 tevalue = 0;        //临时变量
    tevalue = *(uint8 code *)TempAddress0;   //读取回地址的值
    return tevalue;
}

/**
 * @brief        擦除指定扇区
 * @brief        WriteAddress--指定写入地址
 * @brief        value--写入数值
 * @date         2022-07-14
 */
void Flash_KeyWriteValue(uint16 WriteAddress, uint8 value)
{
    uint8 i;
    uint8 TempReadRomValue;
    uint16 FlashWriteAddr = WriteAddress;
    __IO uint8 revalue = 0;        //返回值
    TempReadRomValue = Rom.ReadValue;
    Rom.WriteValue   = value;
    
    for (i = 0; ((Rom.WriteValue != TempReadRomValue) && (i < 5)); i++)
    {
        revalue = Flash_Sector_Write(FlashWriteAddr, Rom.WriteValue);
        
        if (revalue == 1) //无效操作
        {
            TempReadRomValue = 0; //写入错误
        }
        
        TempReadRomValue = *(uint8 code *)(FlashWriteAddr);
    }
    
    if (Rom.WriteValue == TempReadRomValue)
    {
        Rom.ReadValue = TempReadRomValue;
    }                                                                    //读出有效数据
}

/**
 * @brief        擦除指定扇区
 * @brief        FlashAddress--Flash自擦除扇区内任意地址
 * @return       0--Flash自擦除成功，1--Flash自擦除失败
 * @date         2022-07-14
 */
uint8 Flash_Sector_Erase(uint8 xdata * FlashAddress)
{
    bool TempEA;
    uint16 TempFlashAddress;
    TempEA = EA;
    EA = 0;
    TempFlashAddress = FlashAddress;
    
    if ((TempFlashAddress) < (0x3f80))      // 不擦除最后一个扇区
    {
        FLA_CR = 0x03;                                   //使能自擦除
        FLA_KEY = 0x5a;
        FLA_KEY = 0x1f;                                   //flash预编程解锁
        _nop_();
        *FlashAddress = 0xff;                   //写任意数据
        FLA_CR = 0x08;                                   //开始预编程，完成后Flash再次上锁
    }
    
    EA = TempEA;
    
    if (ReadBit(FLA_CR, FLAERR))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief        擦除指定扇区
 * @brief        FlashAddress--指定写入地址
 * @brief        FlashData--写入数值
 * @return       0--Flash自擦除成功，1--Flash自擦除失败
 * @date         2022-07-14
 */
uint8 Flash_Sector_Write(uint8 xdata * FlashAddress, uint8 FlashData)
{
    bool TempEA = 0;
    uint16 TempFlashAddress;
    TempEA = EA;
    EA = 0;
    TempFlashAddress = FlashAddress;
    
    if ((TempFlashAddress) < 0x3f80)        // 不编程最后一个扇区
    {
        FLA_CR = 0x01;              // 使能Flash编程
        FLA_KEY = 0x5a;
        FLA_KEY = 0x1f;             // flash预编程解锁
        _nop_();
        *FlashAddress = FlashData;  // 写编程数据
        FLA_CR = 0x08;              // 开始预编程，完成后Flash再次上锁
    }
    
    EA = TempEA;
    
    if (ReadBit(FLA_CR, FLAERR))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief        保存按键
 * @date         2022-07-14
 */
void  Save_KeyValue(void)
{
    if((mcFaultDect.VoltDetecBraketCount <= 0) && (heat_Lv != heat_Lv_Init) && (heat_Lv != 0))
    {
        __IO uint8 revalue = 0;        //返回值
        
        if (Rom.FlagFlashWrite == 0)
        {
//        
//        Rom.WriteValue = KS.KeyValuetotal;   //档位存储
//        if(Rom.ReadValue != Rom.WriteValue)  //确认写入前后数据不一致
//		{
            EA = 0;	
//			if ((Rom.ReadValue == 0x11) || (Rom.ReadValue == 0x21) || (Rom.ReadValue == 0x41) || (Rom.ReadValue == 0x12) || (Rom.ReadValue == 0x22)
//				|| (Rom.ReadValue == 0x42) || (Rom.ReadValue == 0x14) || (Rom.ReadValue == 0x24) || (Rom.ReadValue == 0x44) || (Rom.ReadValue == 0x18)
//				|| (Rom.ReadValue == 0x28) || (Rom.ReadValue == 0x48))
//			{
//				revalue = Flash_Sector_Erase(Rom.WriteAddress);     //擦除扇区
//				
//				if (! revalue)
//				{
//					Flash_KeyWriteValue(Rom.WriteAddress, Rom.WriteValue);     //指定地址写值
//					Rom.ReadValue = Rom.WriteValue;
//					Rom.FlagFlashWrite = 1;
//				}
//				else
//				{
//					Rom.ReadValue = 0;
//				}
//			}
//			else
//			{
//				revalue = Flash_Sector_Erase(Rom.WriteAddress);     //擦除扇区
//				
//				if (! revalue)
//				{
//					Flash_KeyWriteValue(Rom.WriteAddress, 0x21);     //指定地址写值
//					Rom.ReadValue = 0x21;
//					Rom.FlagFlashWrite = 1;
//				}
//				else
//				{
//					Rom.ReadValue = 0;
//				}
//			}
            #if (SPEED_MODE == KEYSCANMODE)
            {
                if(FlashPieceNum >= 25)
                {
                    Flash_Sector_Erase(Rom.WriteAddress);     //擦除扇区
                    FlashPieceNum = 0;
                }

                Flash_Sector_Write( (Rom.WriteAddress + FlashPieceNum*5), 0xA5);
                _nop_();
          
                Flash_Sector_Write( (Rom.WriteAddress + FlashPieceNum*5 + 1), (uint8)(RuntimeCntXn >> 8) );
                _nop_();
                Flash_Sector_Write( (Rom.WriteAddress + FlashPieceNum*5 + 2), (uint8)(RuntimeCntXn) );
                _nop_();
                Flash_Sector_Write( (Rom.WriteAddress + FlashPieceNum*5 + 3), RuntimeCntX1min);
                _nop_();
                Flash_Sector_Write( (Rom.WriteAddress + FlashPieceNum*5 + 4), Keysavevalue);    
                _nop_();
                
                FlashPieceNum++;
            }
            #elif (SPEED_MODE == TOUCHMODE)
            {
                if(BlockFlashNum >= 128)    // 一个扇区128个字节，算上首地址，BlockFlashNum范围应在0-127
                {
                    Flash_Sector_Erase(Rom.WriteAddress);   // 扇区写满，需要擦除
                    BlockFlashNum = 0;                      // 清0自加
                }
                Flash_Sector_Write( (Rom.WriteAddress + BlockFlashNum), Keysavevalue);    // 自加是为了防止断电掉电过程中或电源调整欠压，芯片未掉电再次写数据出错
                _nop_();
                BlockFlashNum++;                        // 上一个字节写入数据后自加一个地址，下次写入数据直接调用
            }
            #endif
      
            Rom.FlagFlashWrite = 1;
      
			EA = 1;
        }
    
        if(Rom.FlagFlashWrite)
        {
            heat_Lv_Init       = heat_Lv;
            Rom.FlagFlashWrite = 0;
        }
    }
}
