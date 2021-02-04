#include <STC15F2K60S2.H>
#include <intrins.h>
typedef unsigned int uint16;
typedef unsigned long uint32;
typedef unsigned char uint8;

void closebuzzer();
void Delay1000ms();
void display();

const uint8 dm[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,
									0x83,0xc6,0xa1,0x86,0x8e
};

uint8 num=0;
void main()
{
	closebuzzer();
	while(1)
	{
		for(num=0;num<16;num++)
		{
			display();
			Delay1000ms();
		}
	}
		
}

void display()
{
	P2=0x9f;//1001 1111 100 y4
	P0=0xff;//1111 1111
	P2=0xdf;//1101 1111 101 y6
	P0=0xff;//0000 0001
	P2=0xff;//1111 1111 111 y7
	P0=dm[num];//ÏÔÊ¾
}

void closebuzzer()
{
	P2=0xBF;
	P0=0x00;
}

void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 43;
	j = 6;
	k = 203;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}