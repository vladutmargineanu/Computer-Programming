#include <stdio.h>

int main(int argC, char *argV[])
{
	if (argC != 2){
		return -1;
	}
	
	int x;
	FILE* in;
	
	in = fopen(argV[1], "rb");
	
	fread(&x, sizeof(x), 1, in);
	while (!feof(in)){
		printf("%d ", x);
		fread(&x, sizeof(x), 1, in);
	}
	
	printf ("\n");
	
	return 0;
}
