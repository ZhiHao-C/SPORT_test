#include <REGX52.H>
#include "delay.h"
#include "SPORT.h"
#define unchar unsigned char
unchar byte;

void sendbyte(unchar byte)
{
	SBUF=byte;
	while(TI==0)         //TI����1�������ѭ��˵�����ݷ������
	{}
	TI=0;                //����
}


void UART() interrupt 4
{
	if(RI==1)            //���ձ�־Ϊ1ʱ˵��SBUF �������
	{
		sendbyte(SBUF);
		delay_ms(20);
		P2=~SBUF;
		RI=0;
	}
	
}



void main()
{
	SPORT_init();
	while(1)
	{
	}
	
}

//ʵ�ַ�������
//void main()
//{
	//	byte=0;
//	while(1)
//	{
//		byte++;
//		sendbyte(byte);
//		delay_ms(200);
//	}
//}