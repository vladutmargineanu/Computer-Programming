#include <stdio.h>

#include "itoa.h"

int countFiles()
{
	int c;
	char str[4 + LENofLEN + 1];
	char num[LENofLEN + 1];
	int i;
	
	FILE *in;
	
	c = 0;
	i = 0;
	
	while (1){
		strcpy(str, "file");
		itoa(i, num);
		
		in = fopen(strcat(str, num), "rb");
		if (in != NULL){
			c++;
			i++;
		}
		else{
			break;
		}
	}
	
	return c;
}

void getMin(int v[], int n, int *min, int *pos)
{
	int i, mnt, pst;
	
	mnt = -1;
	
	for (i = 0; i < n; i++){
		if (v[i] > 0){
			if (mnt < 0 || v[i] < mnt){
				mnt = v[i];
				pst = i;
			}
		}
	}
	
	*min = mnt;
	*pos = pst;
}

int main()
{
	int n;
	char str[4 + LENofLEN + 1];
	char num[LENofLEN + 1];
	int v[LEN];
	int min, pos;
	int i;
	
	FILE *in[LEN];
	
	n = countFiles();
	printf("numarul de fisiere: %d\n", n);
	
	for (i = 0; i < n; i++){
		strcpy(str, "file");
		itoa(i, num);
		
		in[i] = fopen(strcat(str, num), "rb");

		fread(&v[i], sizeof(v[i]), 1, in[i]);
	}
	
	getMin(v, n, &min, &pos);
	
	printf("\nNumerele ordonate sunt:\n");
	while (min != -1){
		printf("%d ", min);
		fread(&v[pos], sizeof(v[pos]), 1, in[pos]);
		if (feof(in[pos])){
			v[pos] = -1;
		}
		getMin(v, n, &min, &pos);
	}
	
	printf("\n\n");
}
