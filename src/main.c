/**
 * @file        main.c
 * @brief       8051单片机SG90舵机驱动程序主文件
 * @description 使用定时器0中断实现PWM波形输出，控制SG90舵机位置
 *              支持按键控制舵机角度调节，PWM频率约46Hz，占空比可调
 * @author      ESJIAN
 * @version     v1.0
 * @date        2025-10-23
 * @copyright   Copyright (c) 2025 STALAB
 * 
 * @note        硬件配置:
 *              - 晶振频率: 11.0592MHz
 *              - PWM输出引脚: P1.0
 *              - 定时器: Timer0 (模式2, 8位自动重装)
 *              - 中断周期: 约217μs
 *              - PWM周期: 约21.7ms (46Hz)
 *              - 占空比范围: 0-100 (对应0-2.3ms高电平)
 *              - 精度: 1% (约217μs)
 * 
 * @changelog   
 *              v1.0 - 2025-10-23 - 初始版本，实现基本PWM输出功能
 */

#include <STC89C5xRC.H>
#include "Int_Key.h"

// 定义PWM输出引脚
sbit PWM_PIN = P1^0;  // 使用P1.0作为PWM输出

// PWM相关变量定义
unsigned char PWM_Duty = 50;    // 占空比 0-100
unsigned char PWM_Counter = 0;  // PWM计数器
unsigned char PWM_Cycle = 100;  // PWM周期(中断次数)



// 示例：动态改变占空比，实现呼吸灯效果
unsigned char i;
unsigned char press_key = 0;

/**
 * @brief 定时器0初始化函数
 * @param none
 * @return none
 * @note 使用定时器0，模式2(8位自动重装)，产生固定时间间隔中断
 */
void  Timer0_Init(void)
{
    // 设置定时器0为模式2(8位自动重装)
    TMOD &= 0xF0;   // 清除定时器0模式位
    TMOD |= 0x02;   // 设置定时器0为模式2
    
    // 计算定时器初值 - 假设晶振为11.0592MHz
    // 定时时间 = (256 - TH0) × 12 / 11.0592 MHz
    // 设置为约217us中断一次 
    TH0 = 256 - 200; // 定时器重装值
    TL0 = 256 - 200; // 定时器初始值
    
    // 开启定时器0中断
    ET0 = 1;
    // 开启总中断
    EA = 1;
    // 启动定时器0
    TR0 = 1;
}

/**
 * @brief 定时器0中断服务函数
 * @param none
 * @return none
 * @note 在中断中实现PWM波形生成的核心逻辑
 */
void Timer0_ISR(void) interrupt 1
{
    // 模式2自动重装，无需手动重装TH0
    
    PWM_Counter++;           // PWM计数器加1
    
    if(PWM_Counter >= PWM_Cycle)
    {
        PWM_Counter = 0;     // 计数器归零，开始新的PWM周期
    }
    
    // PWM输出逻辑
    if(PWM_Counter < PWM_Duty)
    {
        PWM_PIN = 1;        // 高电平阶段
    }
    else
    {
        PWM_PIN = 0;        // 低电平阶段
    }
}

/**
 * @brief 设置PWM占空比
 * @param duty: 占空比 0-100 
 * @return none
 */
void Set_PWM_Duty(unsigned char duty)
{
    if(duty <= 100)
    {
        PWM_Duty = duty;    // 更新占空比
    }
}

/**
 * @brief 延时函数
 * @param ms: 延时毫秒数
 * @return none
 */
void Delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 123; j++); // 11.0592MHz下的近似延时
}

/**
 * @brief 主函数
 */
void main(void)
{
    // 初始化
    PWM_PIN = 0;           // 初始化为低电平
    Timer0_Init();         // 初始化定时器0
    
    // 初始占空比
    Set_PWM_Duty(0);      // 初始30%占空比


    while(1)
    {

            if (Int_Key_IsSW1Pressed())
            {
                // 逐渐变亮
                for(i = 0; i <= 5; i++)
                {
                    Set_PWM_Duty(i);
                    Delay_ms(60);
                }
            
            }
            else if (Int_Key_IsSW2Pressed())
            {   
                // 逐渐变暗
                for(i = 5; i > 1; i--)
                {
                    Set_PWM_Duty(i);
                    Delay_ms(60);
                }
                
            }
    
    }
}