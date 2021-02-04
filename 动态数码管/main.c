#include <STC15F2K60S2.H>
#include <intrins.h>
typedef unsigned long uint32;
typedef unsigned int uint16;
typedef unsigned char uint8;

void closebuzzer();
void display();
void Delay1000ms();
void xxxdispro();


uint8 dp[8];//œ‘ æª∫≥Â«¯

const uint8 dm[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0x80,0x90,0x88,
									0x83,0xc6,0xa1,0x86,0x8e};

							
void main()
{
	closebuzzer();
	while(1)
	{
			xxxdispro();
			display();
	}
}



void xxxdispro()
{
	dp[0]=dm[5];
	dp[1]=dm[0];
	dp[2]=dm[4];
	dp[3]=dm[9];
	dp[4]=dm[4];
	dp[5]=dm[4];
	dp[6]=dm[3];
	dp[7]=0xff;
}

void display()
{
	P2=0x9f;//1001 1111 100 y4
	P0=0xff;//1111 1111
	P2=0xdf;//1101 1111 101 y6
	P0=0xff;//0000 0001
	P2=0xff;//1111 1111 111 y7
	P0=dm[num];//œ‘ æ
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