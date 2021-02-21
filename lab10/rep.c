#include<stdio.h>
#include<string.h>

void string(char str[],char w[], char w1[]) {
	char *p, s[100];
	p = strtok(str, " ,.\n");
	while(p != NULL) {
		if(strcmp(p, w) == 0) {
			strcat(s, w1);
			strcat(s, " ");
		} else {
			strcat(s, p);
			strcat(s, " ");
		}
		p = strtok(NULL, " ,.\n");
	}
	puts(s);
}

int main() {
	char str[] = "ana are mere mere pere", w[] = "mere", w1[] = "capsuni";
	string(str, w, w1);
	return 0;
}
