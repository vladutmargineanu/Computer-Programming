#include "itoa.h"

void itoa(int x, char a[])
{
	int i;	
	
	a[LENofLEN] = '\0';
	
	for (i = 0; i < LENofLEN; i++){
		a[i] = '0';
	}
	
	i = 0;
	while (x > 0){
		a[LENofLEN - 1 - i] = '0' + (x % 10);
		x /= 10;
		i++;
	}
}
