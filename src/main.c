#include <STC89C5xRC.H>
#include "Int_Key.h"

// ����PWM�������
sbit PWM_PIN = P1^0;  // ʹ��P1.0��ΪPWM���

// PWM��ر�������
unsigned char PWM_Duty = 50;    // ռ�ձ� 0-100
unsigned char PWM_Counter = 0;  // PWM������
unsigned char PWM_Cycle = 100;  // PWM����(�жϴ���)



// ʾ������̬�ı�ռ�ձȣ�ʵ�ֺ�����Ч��
unsigned char i;
unsigned char press_key = 0;

/**
 * @brief ��ʱ��0��ʼ������
 * @param none
 * @return none
 * @note ʹ�ö�ʱ��0��ģʽ2(8λ�Զ���װ)�������̶�ʱ�����ж�
 */
void  ���Timer0_Init(void)
{
    // ���ö�ʱ��0Ϊģʽ2(8λ�Զ���װ)
    TMOD &= 0xF0;   // �����ʱ��0ģʽλ
    TMOD |= 0x02;   // ���ö�ʱ��0Ϊģʽ2
    
    // ���㶨ʱ����ֵ - ���辧��Ϊ11.0592MHz
    // ��ʱʱ�� = (256 - TH0) �� 12 / 11.0592 MHz
    // ����ΪԼ2us�ж�һ�� 
    TH0 = 256 - 2; // ��ʱ����װֵ
    TL0 = 256 - 2; // ��ʱ����ʼֵ
    
    // ������ʱ��0�ж�
    ET0 = 1;
    // �������ж�
    EA = 1;
    // ������ʱ��0
    TR0 = 1;
}

/**
 * @brief ��ʱ��0�жϷ�����
 * @param none
 * @return none
 * @note ���ж���ʵ��PWM�������ɵĺ����߼�
 */
void Timer0_ISR(void) interrupt 1
{
    // ģʽ2�Զ���װ�������ֶ���װTH0
    
    PWM_Counter++;           // PWM��������1
    
    if(PWM_Counter >= PWM_Cycle)
    {
        PWM_Counter = 0;     // ���������㣬��ʼ�µ�PWM����
    }
    
    // PWM����߼�
    if(PWM_Counter < PWM_Duty)
    {
        PWM_PIN = 1;        // �ߵ�ƽ�׶�
    }
    else
    {
        PWM_PIN = 0;        // �͵�ƽ�׶�
    }
}

/**
 * @brief ����PWMռ�ձ�
 * @param duty: ռ�ձ� 0-100 
 * @return none
 */
void Set_PWM_Duty(unsigned char duty)
{
    if(duty <= 100)
    {
        PWM_Duty = duty;    // ����ռ�ձ�
    }
}

/**
 * @brief ��ʱ����
 * @param ms: ��ʱ������
 * @return none
 */
void Delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 123; j++); // 11.0592MHz�µĽ�����ʱ
}

/**
 * @brief ������
 */
void main(void)
{
    // ��ʼ��
    PWM_PIN = 0;           // ��ʼ��Ϊ�͵�ƽ
    Timer0_Init();         // ��ʼ����ʱ��0
    
    // ��ʼռ�ձ�
    Set_PWM_Duty(0);      // ��ʼ30%ռ�ձ�


    while(1)
    {

            if (Int_Key_IsSW1Pressed())
            {
                // �𽥱���
                for(i = 0; i <= 8; i++)
                {
                    Set_PWM_Duty(i);
                    Delay_ms(60);
                }
            
            }
            else if (Int_Key_IsSW2Pressed())
            {   
                // �𽥱䰵
                for(i = 8; i > 0; i--)
                {
                    Set_PWM_Duty(i);
                    Delay_ms(60);
                }
                
            }
    
    }
}