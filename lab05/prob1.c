#include<stdio.h>
void citire(int v[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
}
int main ()
{
	int a[100], b[100], n, m, i, j, ok;
	scanf("%d%d", &n, &m);
	citire(a, n);
	citire(b, m);
	for(i = 0; i < n; i++)
	{
		ok = 0;
		for(j = 0; j < m; j++)
		{
			if(a[i] == b[j])
			{
				ok = 1;
				break;
			}
		}
		if(ok == 0)
		{
			printf("%d\n", a[i]);
		}
	}
	return 0;
}
