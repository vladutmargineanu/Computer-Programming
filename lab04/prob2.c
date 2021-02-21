#include<stdio.h>
long power(int b, int e)
{
	if(e == 0)
		return 1;
	long half = power(b, e/2);
	if(e%2 == 0)
		return half*half;
	return b*half*half;
}
int main ()
{
	printf("2 la a 3-a=%ld\n", power(2, 3));
	printf("7 la a 3-a=%ld\n", power(7, 3));
	return 0;
}
