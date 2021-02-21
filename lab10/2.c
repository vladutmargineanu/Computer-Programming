#include<stdio.h>
#include<string.h>
#include<ctype.h>

void pali(char str[]) {
	int i, j, ok;
	char a, b;
	i = 0;
	j = strlen(str) - 1;
	ok = 0;
	while(i <= j && ok == 0) {
		while(isalpha(str[i]) == 0) {
			i++;
		}
		while(isalpha(str[j]) == 0) {
			j--;
		}
		a = str[i];
		b = str[j];
		if(isupper(a)) {
			a += 32;
		}
		if(isupper(b)) {
			b += 32;
		}
		if(a != b) {
			ok = 1;
		} else {
			i++;
			j--;
		}
	}
	if(ok == 0) {
		printf("PALINDROM\n");
	}
}
int main() {
	char str[] = "ele fac ccafele";
	pali(str);
	return 0;
}
