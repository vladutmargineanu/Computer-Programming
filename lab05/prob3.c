#include<stdio.h>
void citire(int v[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
}
int in_interval(int v[], int low, int high, int x, int y)
{
	if(low > high)
	{
		return 0;
	}


	int mid = low + (high - low) / 2;


	if(v[mid] >= x && v[mid] <= y)
	{
		return 1 + in_interval(v, low, mid-1, x, y) + in_interval(v, mid + 1, high, x, y);
	}
	else
	{
		if(v[mid] < x)
		{
			return in_interval(v, mid + 1, high, x, y);
		}
		else
		{
			return in_interval(v, low, mid - 1, x, y);
		}
	}
}
int main ()
{
	int a[100], n, x, y;
	scanf("%d", &n);
	citire(a, n);
	while(1)
	{
		scanf("%d", &x);
		if(x == -1)
		{
			break;
		}
		scanf("%d", &y);
		printf("Numarul de numere aflate intre %d si %d este %d", x, y, in_interval(a, 0, n-1, x, y));
	}
	return 0;
}
