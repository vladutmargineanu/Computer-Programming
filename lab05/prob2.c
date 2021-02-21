#include<stdio.h>
int main()
{
	int v[100], i, j, z, n, sum, S;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
	S = v[0];
	for(i = 0; i < n; i++)
	{
		for(j = n-1; j >= i; j--)
		{
			sum = 0;
			for(z = i; z <= j; z++)
			{
				sum += v[z];
			}
			if(sum > S)
			{
				S = sum;
			}
		}
	}
	printf("%d\n", S);
	return 0;
}
