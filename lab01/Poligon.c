#include<stdio.h>
#include<math.h>
int main()
{
	int n, i, x, y, x1, y1, a, b;
	float perimetru;
	do 
	{
         printf("n=");
	 scanf("%d",&n);	
	}while(n<3);
	scanf("%d%d", &x, &y);
	a=x;
	b=y;
	i=2;
	while(i<n+1)
        {
	 scanf("%d%d", &x1, &y1);
	 perimetru+=sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
	 x=x1;
	 y=y1;
	 i++;
	}
	perimetru+=sqrt((a-x)*(a-x)+(b-y)*(b-y));
	printf("perimetrul este %7.2f \n",perimetru);
	return 0;
}

