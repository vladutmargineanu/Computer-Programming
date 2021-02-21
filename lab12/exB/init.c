#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "itoa.h"

int main()
{
	int n, nr, x1, x2;
	int i, j;
	char str[4 + LENofLEN + 1];
	char num[LENofLEN + 1];
	
	FILE *out[LEN];
	
	printf("\nIntroduceti numarul de fisiere pe care vreti sa le creati: ");
	scanf("%d", &n);
	
	for (i = 0; i < n; i++){
		strcpy(str, "file");
		itoa(i, num);
		
		out[i] = fopen(strcat(str, num), "wb");
		
		srand(time(NULL) + i);		
		nr = rand() % 100 + 1;
		
		x1 = 0;
		for (j = 0; j < nr; j++){
			x2 = rand() % 100 + x1;
			fwrite(&x2, sizeof(x2), 1, out[i]);
			x1 = x2;
		}
		
		fclose(out[i]);
	}
	
	printf("\n");
	
	return 0;
}
