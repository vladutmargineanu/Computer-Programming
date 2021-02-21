#include<stdio.h>
#define N 100
void citire(int a[][N], int l, int c)
{
	int i, j;
	for(i = 0; i < l; i++)
	{
		for(j = 0; j < c; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
}

int main ()
{
	int a[100][100], n, m, n1, n2, m1, m2, i, count;
	scanf("%d%d", &n, &m);
	citire(a, n, m);
	printf("\n");
	n1 = 0;
	n2 = n-1;
	m1 = 0;
	m2 = m-1;
	count = 0;
	while(1)
	{
		for(i = m1; i <= m2; i++)
			{printf("%d ", a[n1][i]);count++;}
		if(count == n*m)
			break;
		n1++;
		for(i = n1; i <= n2; i++)
			{printf("%d ", a[i][m2]);count++;}
		if(count == n*m)
			break;
		m2--;
		for(i = m2; i >= m1; i--)
			{printf("%d ", a[n2][i]);count++;}
		if(count == n*m)
			break;
		n2--;
		for(i = n2; i >= n1; i--)
			{printf("%d ", a[i][m1]);count++;}
		if(count == n*m)
			break;
		m1++;
	}
	printf("\n");
	return 0;
}
