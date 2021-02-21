#include <stdio.h>

int main()
{
	int x, s;
	
	FILE *in;
	
	if((in = fopen("ex2.in", "rb") == NULL) break;
	
	s = 0;
	
	fread(&x, sizeof(int), 1, in);
	while (!feof(in)){
		if (x % 2 == 1){
			s += x;
		}
		
		fread(&x, sizeof(int), 1, in);
	}
	
	printf("Suma numerelor impare este %d.\n", s);
	
	fclose(in);
	
	return 0;
}
