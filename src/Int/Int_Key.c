#include "Int_Key.h"
#include <STC89C5xRC.H>
#include "Com_Util.h"

// 定义按键引脚
#define SW1 P42  // 按键1连接到P4.2
#define SW2 P43  // 按键2连接到P4.3
#define SW3 P32  // 按键3连接到P3.2
#define SW4 P33  // 按键4连接到P3.3

/**
 * 检测SW1按键是否被按下
 * @return 1: 按键被按下, 0: 按键未被按下
 */
bit Int_Key_IsSW1Pressed()
{
    // 检查按键是否按下（低电平表示按下）
    if (SW1 == 0) {
        // 消抖延时10ms
        Com_Util_Delay1ms(10);
        // 再次确认按键状态
        if (SW1 == 0) {
            // 等待按键释放
            while (SW1 == 0);
            // 返回按键按下的结果
            return 1;
        }
    }
    // 按键未按下
    return 0;
}

/**
 * 检测SW2按键是否被按下
 * @return 1: 按键被按下, 0: 按键未被按下
 */
bit Int_Key_IsSW2Pressed()
{
    // 检查按键是否按下（低电平表示按下）
    if (SW2 == 0) {
        // 消抖延时10ms
        Com_Util_Delay1ms(10);
        // 再次确认按键状态
        if (SW2 == 0) {
            // 等待按键释放
            while (SW2 == 0);
            // 返回按键按下的结果
            return 1;
        }
    }
    // 按键未按下
    return 0;
}

/**
 * 检测SW3按键是否被按下
 * @return 1: 按键被按下, 0: 按键未被按下
 */
bit Int_Key_IsSW3Pressed()
{
    // 检查按键是否按下（低电平表示按下）
    if (SW3 == 0) {
        // 消抖延时10ms
        Com_Util_Delay1ms(10);
        // 再次确认按键状态
        if (SW3 == 0) {
            // 等待按键释放
            while (SW3 == 0);
            // 返回按键按下的结果
            return 1;
        }
    }
    // 按键未按下
    return 0;
}

/**
 * 检测SW4按键是否被按下
 * @return 1: 按键被按下, 0: 按键未被按下
 */
bit Int_Key_IsSW4Pressed()
{
    // 检查按键是否按下（低电平表示按下）
    if (SW4 == 0) {
        // 消抖延时10ms
        Com_Util_Delay1ms(10);
        // 再次确认按键状态
        if (SW4 == 0) {
            // 等待按键释放
            while (SW4 == 0);
            // 返回按键按下的结果
            return 1;
        }
    }
    // 按键未按下
    return 0;
}