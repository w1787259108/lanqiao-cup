#include <STC15F2K60S2.H>
#include <intrins.h>

typedef unsigned char uint8;
typedef unsigned int  uint16;
typedef unsigned long uint32;

const uint8 dm[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0x80,0x90,0x88,
									0x83,0xc6,0xa1,0x86,0x8e};
uint8 dp[8]={0},Keynum=0;

void Display();
//void Delay120(unit8 i);
void ikey();
//void closebuzzer();

void main()
{
		dp[1]=0xff;
		dp[2]=0xff;
		dp[3]=0xff;
	  dp[4]=0xff;
		dp[5]=0xff;
		dp[6]=0xff;
		dp[7]=0xff;
//		closebuzzer();
		while(1)
		{
			ikey();
			dp[0]=dm[Keynum];
			Display();
		}
		
}
void Display()
{
		unsigned char i,d;
		i=0x01;
		for(d=0;d<8;d++)
		{
			P2=0xdf;
			P0=i;
			P2=0x1f;
			P0=0xff;
			P2=0x1f;
			P0=dp[d];
			P2=0x1f;
			P0=0x00;
//			Delay120(20);
			i=_crol_(i,1);
		}
}


void ikey()
{
		P3=0xff;
		if(P3!=0xff)
		{
//			Delay120(100);
			while(P3!=0Xff)
			{
				switch(P3)
				{
					case 0xf7:
						Keynum=1;
						break;
					case 0xfb:
						Keynum=2;
						break;
					case 0xfd:
						Keynum=3;
						break;
					case 0xfe:
						Keynum=4;
						break;
				}
			}
		}
}