#include<stdio.h>
#include<string.h>

void ordCresc(char *vectorschar[], int n) {
	int i, j;
	char *aux;
	for(i = 0; i < n - 1; i++) {
		for(j = i + 1; j < n; j++) {
			if(strlen(vectorschar[i]) > strlen(vectorschar[j])) {
				aux = (char *)malloc(sizeof(vectors[i]));
				if(aux == NULL) {
					exit(-1);
				}
				strcpy(aux, vectorschar[i]);
				strcpy(vectorschar[i], vectorschar[j]);
				strcpy(vectorschar[j], aux);
				free(aux);
			}
		}
	}
}

char **read(char *str[20], int n) {
	int i;
	str = (char **)malloc(n * sizeof(char));
	if(str == NULL) {
		exit (-1);
	}
	for(i = 0; i < n; i++) {
		str[i] = (char *)malloc(m * sizeof(char));
		if(str[i] == NULL) {
			i--;
			while(i >= 0) {
				free(str[i]);
			}
			free(str);
			exit(-1);
		}
		fgets(str[i], m, stdin);
	}
}

void print(char *str[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		puts(str[i]);
	}
}

int main() {
	int n, m;
	char *str[20];
	scanf("%d %d", &n, &m);
		
	return 0;
}
