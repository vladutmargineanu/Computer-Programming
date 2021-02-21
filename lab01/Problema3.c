#include<stdio.h>
int main ()
{
	int a,b,c;
	printf("dati dimensiunile laturilor\n");
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	printf("c=");
	scanf("%d",&c);
	if(a+b>c&&b+c>a&&a+c>b)
		printf("DA\n");
	else
		printf("NU\n");
	return 0;
}
