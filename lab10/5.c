#include<stdio.h>
#include<string.h>

int main() {
	char *p, str[] = "ana are mere mere pere", w[] = "mere", w1[] = "capsuni";
	if(strstr(str, w) != NULL) {
		p = strstr(str, w);
		strcpy(p, p + strlen(w));
		puts(p);
	}
	puts(str);
	return 0;
}
