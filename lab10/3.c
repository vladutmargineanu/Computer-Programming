#include<stdio.h>
#include<string.h>

int main() {
	char *p, str[100];
	fgets(str, 100, stdin);
	p = strtok(str, " ,-.\n");
	while(p != NULL) {
		printf("%s\n", p);
		p = strtok(NULL, " ,-.\n");
	}
	return 0;
}
