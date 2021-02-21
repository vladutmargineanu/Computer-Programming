#include<stdio.h>
#define N 100

void citire(int a[][N], int x)
{
	int i, j;
	for(i = 0; i < x; i++)
	{
		for(j = 0; j < x; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
}

void afisare(int a[][N], int x)
{
	int i, j;
	for(i = 0; i < x; i++)
	{
		for(j = 0; j < x; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void inmultire(int a[][N], int b[][N], int c[][N], int n)
{
	int i, j, z;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			for(z = 0; z < n; z++)
				c[i][j] += a[i][z]*b[z][j];
		}
	}	
}

void atribuire(int a[][N], int b[][N], int x)
{
	int i, j;
	for(i = 0; i < x; i++)
	{
		for(j = 0; j < x; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}

void init(int a[][N], int x)
{
	int i, j;
	for(i = 0; i < x; i++)
	{
		for(j = 0; j < x; j++)
		{
			a[i][j] = 0;
		}
	}
}

int main()
{
	int a[100][100], b[100][100], rez[100][100], n, p;
	scanf("%d%d", &n, &p);
	citire(a, n);
	if(p == 1)
	{
		afisare(a, n);
	}
	else
	{
		atribuire(rez, a, n);
		while(p != 1)
		{
			inmultire(a, rez, b, n);
			atribuire(rez, b, n);
			init(b, n);
			p--;
		}
	}
	afisare(rez, n);
	return 0;
}
