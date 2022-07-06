#include <REGX52.H>
void SPORT_init()
{
	SCON=0X50;      //串口方式一，RI TI清零 ，允许接收
	PCON= 0x00;     //波特率不加倍
	TMOD=TMOD&0X0F; //工作在T1定时方式2(八位自重装)
	TMOD=TMOD|0X20;
	TL1 = 0xFA;		//设定定时初值
	TH1 = 0xFA;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1=1;          //开始计时
	EA=ES=1;        //串口中断打开
}