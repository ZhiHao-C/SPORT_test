#include <REGX52.H>
void SPORT_init()
{
	SCON=0X50;      //���ڷ�ʽһ��RI TI���� ���������
	PCON= 0x00;     //�����ʲ��ӱ�
	TMOD=TMOD&0X0F; //������T1��ʱ��ʽ2(��λ����װ)
	TMOD=TMOD|0X20;
	TL1 = 0xFA;		//�趨��ʱ��ֵ
	TH1 = 0xFA;		//�趨��ʱ����װֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1=1;          //��ʼ��ʱ
	EA=ES=1;        //�����жϴ�
}