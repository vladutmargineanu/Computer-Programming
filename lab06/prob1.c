#include<stdio.h>
# define N 100

void citire (int a[][N], int l, int c)
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

void afisare (int a[][N], int l, int c)
{
	int i, j;
	for(i = 0; i < l; i++)
	{
		for(j = 0; j < c; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void inmultire (int a[][N], int b[][N], int c[][N], int n, int m, int p)
{
	int i, j, z;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < p; j++)
		{
			for(z = 0; z < m; z++)
				c[i][j] += a[i][z] * b[z][j];
		}
	}	
}

int main()
{
	int a[100][100], b[100][100], c[100][100], n, m, p;
	scanf("%d %d %d", &n, &m, &p);
	citire(a, n, m);
	citire(b, m, p);
	inmultire(a, b, c, n, m, p);
	printf("\n");
	afisare(c, n, p);
	printf("\n");
	return 0;
}
