#include<stdio.h>
int main ()
{
	int x;
	scanf("%d", &x);
	printf("%d\n", 2 << (x - 1));
	return 0;
}
