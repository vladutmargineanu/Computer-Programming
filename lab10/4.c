#include<stdio.h>
#include<string.h>

int count(char str[],char word[]) {
	int num = 0;
	char *p;
	p = strtok(str, " ,.\n");
	while(p != NULL) {
		if(strcmp(p, word) == 0) {
			num++;
		}
		p = strtok(NULL, " ,.\n");
	}
	return num;
}

int main() {
	char str[] = "are mere si pere si pere", word[] = "pere";
	printf("%d\n", count(str, word));
	return 0;
}
