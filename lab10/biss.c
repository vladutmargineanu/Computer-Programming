#include<stdio.h>
#include<string.h>

void string(char str[],char w[],char w1[]) {
	char *p, new[100];
	p = strtok(str, " ,.\n");
	while(p != NULL) {
		if(strcmp(p, w) == 0) {
			strcpy(new + strlen(new), w1);
			strcpy(new + strlen(new), " ");
		} else {
			strcpy(new + strlen(new), p);
			strcpy(new + strlen(new), " ");
		}
		p = strtok(NULL, " ,.\n");
	}
	puts(new);
}
int main() {
	char str[] = "ana are mere mere pere", w[] = "mere", w1[] = "capsuni";
	string(str, w, w1);
	return 0;
}
