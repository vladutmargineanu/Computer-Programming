#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int n, x;
	int i;
	
	FILE *out;
	
	out = fopen("ex1.out", "wb");
	srand(time(NULL));
	
	printf("Introduceti numar 'n': ");
	scanf("%d", &n);
	
	for (i = 0; i < n; i++){
		x = rand() % 10;
		
		fwrite(&x, sizeof(int), 1, out);
		printf("%d\n", x);
	}
	
	fclose(out);
}
