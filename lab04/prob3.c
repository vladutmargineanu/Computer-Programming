#include<stdio.h>
int nr_cifre(long a)
{
	if(a/10 == 0)
		return 1;
	return 1+nr_cifre(a/10);
}
int main()
{
	long a;
	scanf("%ld", &a);
	printf("numarul %ld are %d cifre\n", a, nr_cifre(a));
	return 0;
}
