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

void sortare(int a[][N], int l, int c)
{
	int i, j, index, ok, aux;
	//sortez trunchiul inferior
	for(i = 0; i < l; i++)
	{
		do
		{
			ok = index = 0;
			for(j = i; j < l - 1 && index < c - 1; j++)
			{
				if(a[j][index] > a[j + 1][index + 1])
				{
					aux = a[j][index];
					a[j][index] = a[j + 1][index + 1];
					a[j + 1][index + 1] = aux;
					ok = 1;
				}
				index++;
			}
		}
		while(ok);
	}
	//sortez trunchiul superior
	for(i = 0; i < c; i++)
	{
		do
		{
			ok = index = 0;
			for(j = i; j < c - 1 && index < l - 1; j++)
			{
				if(a[index][j] > a[index + 1][j + 1])
				{
					aux = a[index][j];
					a[index][j] = a[index + 1][j + 1];
					a[index + 1][j + 1] = aux;
					ok = 1;
				}
				index++;
			}
		}
		while(ok);
	}
}

int main ()
{
	int a[100][100], n, m;
	scanf("%d %d", &n, &m);
	citire(a, n, m);
	printf("\n");
	sortare(a, n, m);
	afisare(a, n, m);
	return 0;
}
