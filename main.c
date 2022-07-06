#include <REGX52.H>
#include "delay.h"
#include "SPORT.h"
#define unchar unsigned char
unchar byte;

void sendbyte(unchar byte)
{
	SBUF=byte;
	while(TI==0)         //TI等于1跳出这个循环说明数据发送完毕
	{}
	TI=0;                //清零
}


void UART() interrupt 4
{
	if(RI==1)            //接收标志为1时说明SBUF 接收完成
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

//实现发送数据
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