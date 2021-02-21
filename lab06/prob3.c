#include<stdio.h>
#define N 100

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

void d_dreapta(int b[][N], int l, int c, int index)
{
	int i;
	for(i = 0; i < l && index < c; i++)
	{
		b[i][index] = 0;
		index++;	
	}
	afisare(b, l, c);
	printf("\n");
}

void s_stanga(int b[][N], int l, int c, int index)
{
	int i;
	for(i = 0; i < l && index >= 0; i++)
	{
		b[i][index] = 0;
		index--;	
	}
	afisare(b, l, c);
	printf("\n");
}

void atribuire(int a[][N], int b[][N], int l, int c)
{
	int i, j;
	for(i = 0; i < l; i++)
	{
		for(j = 0; j < c; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}

int main()
{
	int a[100][100], b[100][100], n, m, index;
	scanf("%d %d %d", &n, &m, &index);
	citire(a, n, m);
	printf("\n");
	atribuire(b, a, n, m);
	d_dreapta(b, n, m, index);
	atribuire(b, a, n, m);
	s_stanga(b, n, m, index);
	return 0;
}
