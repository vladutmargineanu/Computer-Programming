#include<stdio.h>
int main ()
{
	int numar,numar1;
	printf("numar=");
	scanf("%d",&numar);
	if(numar%2==0)
		printf("numarul %d este par\n", numar);
	else
		printf("numarul %d este impar\n", numar);
	numar1=numar;	
	numar1/=2;
	numar1*=2;
	if(numar==numar1)
		printf("numarul %d este par \n", numar);
	else
		printf("numarul %d este impar \n", numar);
	if(numar&1==0)
		printf("numarul %d este par \n", numar);
	else
		printf("numarul %d este impar \n", numar);
	return 0;
}
