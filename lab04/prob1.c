#include<stdio.h>
int sum(int a, int b, int s)
{
	s=a+b;
	return s;
}
int main ()
{
	int s;
	s=sum(2, 3, s);
	printf("Suma este %d\n", s);
	return 0;
}
