#include <STC15F2K60S2.H>
#include "intrins.h"
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


void main()
{
	unsigned char a=0xFE;//1111 1110
	while(1)
	{
		P2=0x9F;
		P0=a;
		a=_cror_(a,1);
		Delay1000ms();
	}
	
}
