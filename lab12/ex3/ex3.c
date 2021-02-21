#include <stdio.h>
#include "struct.h"

int main()
{
	int i;
	student s[LEN];
	
	init_struct(s);
	
	FILE *out = fopen("ex3.file", "wb");
	fwrite(s, sizeof(student), LEN, out);
	fclose(out);
	
	clean_struct(s);
	
	FILE *in = fopen("ex3.file", "rb");
	fread(s, sizeof(student), LEN, in);
	fclose(in);

	printf("\n");
	for (i = 0; i < LEN; i++){
		printf("%s\n%02d.%02d.%d\n%.2f\n\n", s[i].nume, 
			s[i].d.zi, s[i].d.luna, s[i].d.an, s[i].medie);
	}
	
	return 0;
}
