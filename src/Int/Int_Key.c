#include "Int_Key.h"
#include <STC89C5xRC.H>
#include "Com_Util.h"

// ���尴������
#define SW1 P42  // ����1���ӵ�P4.2
#define SW2 P43  // ����2���ӵ�P4.3
#define SW3 P32  // ����3���ӵ�P3.2
#define SW4 P33  // ����4���ӵ�P3.3

/**
 * ���SW1�����Ƿ񱻰���
 * @return 1: ����������, 0: ����δ������
 */
bit Int_Key_IsSW1Pressed()
{
    // ��鰴���Ƿ��£��͵�ƽ��ʾ���£�
    if (SW1 == 0) {
        // ������ʱ10ms
        Com_Util_Delay1ms(10);
        // �ٴ�ȷ�ϰ���״̬
        if (SW1 == 0) {
            // �ȴ������ͷ�
            while (SW1 == 0);
            // ���ذ������µĽ��
            return 1;
        }
    }
    // ����δ����
    return 0;
}

/**
 * ���SW2�����Ƿ񱻰���
 * @return 1: ����������, 0: ����δ������
 */
bit Int_Key_IsSW2Pressed()
{
    // ��鰴���Ƿ��£��͵�ƽ��ʾ���£�
    if (SW2 == 0) {
        // ������ʱ10ms
        Com_Util_Delay1ms(10);
        // �ٴ�ȷ�ϰ���״̬
        if (SW2 == 0) {
            // �ȴ������ͷ�
            while (SW2 == 0);
            // ���ذ������µĽ��
            return 1;
        }
    }
    // ����δ����
    return 0;
}

/**
 * ���SW3�����Ƿ񱻰���
 * @return 1: ����������, 0: ����δ������
 */
bit Int_Key_IsSW3Pressed()
{
    // ��鰴���Ƿ��£��͵�ƽ��ʾ���£�
    if (SW3 == 0) {
        // ������ʱ10ms
        Com_Util_Delay1ms(10);
        // �ٴ�ȷ�ϰ���״̬
        if (SW3 == 0) {
            // �ȴ������ͷ�
            while (SW3 == 0);
            // ���ذ������µĽ��
            return 1;
        }
    }
    // ����δ����
    return 0;
}

/**
 * ���SW4�����Ƿ񱻰���
 * @return 1: ����������, 0: ����δ������
 */
bit Int_Key_IsSW4Pressed()
{
    // ��鰴���Ƿ��£��͵�ƽ��ʾ���£�
    if (SW4 == 0) {
        // ������ʱ10ms
        Com_Util_Delay1ms(10);
        // �ٴ�ȷ�ϰ���״̬
        if (SW4 == 0) {
            // �ȴ������ͷ�
            while (SW4 == 0);
            // ���ذ������µĽ��
            return 1;
        }
    }
    // ����δ����
    return 0;
}