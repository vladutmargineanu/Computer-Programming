#include<stdio.h>
#include<math.h>
int main ()
{
	float a, b, c;
	float delta;
	scanf("%f%f%f", &a, &b, &c);
	delta=b*b-4*a*c;
	if(delta<0)
		{
		 printf("ecuatia nu are solutii reale\n");
		}
	else
		if(delta == 0)
			{
			 printf("ecuatia are o solutie: %f", (-b)/(2*a)); 
			}
		else
			{
			 printf("ecuatia are doua solutiii: %f si %f", (-b-sqrt(delta))/(2*a), (-b+sqrt(delta))/(2*a));
			}
	return 0;
}
