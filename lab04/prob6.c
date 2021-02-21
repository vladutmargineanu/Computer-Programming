#include<stdio.h>
int prim(int a)
{
	int i, ok;
	ok = 1;
	if(a <= 1)
		return 0;
	else
	{
		for(i = 2; i < a; i++)
		{
			if(a%i == 0)
				ok = 0;
		}	
		return ok;
	}
}
int main()
{
	int x, k = 1;
	scanf("%d", &x);
	while(1)
	{
		if(prim(x+k) || prim(x-k))
			break;
		k++;
	}
	if(prim(x+k) && prim(x-k))
		printf("%d %d\n", x+k, x-k);
	else
	{
		if(prim(x+k))
			printf("%d\n", x+k);
		else
			printf("%d\n", x-k);
	}
	return 0;
}
