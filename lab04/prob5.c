#include<stdio.h>
int nr_cifre(long a)
{
	if(a/10 == 0)
		return 1;
	return 1+nr_cifre(a/10);
}
long power(int b, int e)
{
	if(e == 0)
		return 1;
	long half = power(b, e/2);
	if(e%2 == 0)
		return half*half;
	return b*half*half;
}
long oglindit(long a)
{
	if(a/10 == 0)
		return a;
	return (a%10)*power(10, nr_cifre(a)-1)+oglindit(a/10);
}
int main()
{
	long a, o;
	scanf("%ld", &a);
	o = a;
	while(1)
	{
		if(o == oglindit(o))
			break;
		o++;
	}
	printf("%ld\n", o);
	return 0;
}
