#include<stdio.h>

//zz 5 biti
//ll 4 biti
//aa 7 biti
unsigned short pack(int zz, int ll, int aa)
{	
	int i;
	unsigned short numar;
	//masca zi
	unsigned short mask = 1;
	for(i = 0; i < 4; i++)
	{
		mask <<= 1;
		mask = mask + 1;
	}
	numar = zz & mask;
	numar <<= 4;
	mask = 1;
	for(i = 0; i < 3; i++)
	{
		mask <<= 1;
		mask = mask + 1;
	}
	numar = numar | (ll & mask);
	numar <<= 7;
	mask = 1;
	for(i = 0; i < 6; i++)
	{
		mask <<=1;
		mask = mask + 1;
	}
	numar = numar | (aa & mask);
	return numar;
}
int main ()
{
	unsigned short n;
	n = pack(1, 1, 1);
	printf("%hu\n", n);
	return 0;
}
