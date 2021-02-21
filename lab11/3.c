#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int grd;
	float *coef;
}poly;

poly read() {
	poly P;
	int i;
	scanf("%d", &P.grd);
	P.coef = (float *)malloc((P.grd + 1) * sizeof(float));
	if(P.coef == NULL) {
		exit (-1);
	}
	for(i = 0; i <= P.grd; i++) {
		scanf("%f", &P.coef[i]);
	}
	return P;
}

void print(poly P) {
	int i;
	printf("%.0f*(x^%d)", P.coef[P.grd], P.grd);
	for(i = P.grd - 1; i >= 0; i--) {
		if(P.coef[i] != 0) {
			if(P.coef[i] > 0) {
				printf("+%.0f*(x^%d)", P.coef[i], i);
			} else {
				printf("%.0f*(x^%d)", P.coef[i], i);
			}
		}
	}
	printf("\n");
}

poly add(poly A, poly B) {
	poly C;
	int i;
	C.grd = (A.grd > B.grd) ? A.grd : B.grd;
	C.coef = (float *)calloc(C.grd + 1, sizeof(float));
	if(C.coef == NULL) {
		free(A.coef);
		free(B.coef);
		exit (-1);
	}
	for(i = 0; i <= B.grd; i++) {
		C.coef[i] += B.coef[i];
	}
	for(i = 0; i <= A.grd; i++) {
		C.coef[i] += A.coef[i];
	}
	return C;
}

poly dif(poly A, poly B) {
	poly C;
	int i;
	C.grd = (A.grd > B.grd) ? A.grd : B.grd;
	C.coef = (float *)calloc(C.grd + 1, sizeof(float));
	if(C.coef == NULL) {
		free(A.coef);
		free(B.coef);
		exit (-1);
	}
	for(i = 0; i <= A.grd; i++) {
		C.coef[i] += A.coef[i];
	}
	for(i = 0; i <= B.grd; i++) {
		C.coef[i] -= B.coef[i];
	}
	return C;
}

poly trail(poly C) {
	while(C.coef[C.grd] == 0 && C.grd != 0) {
		C.grd--;
	}
	return C;
}

int main () {
	poly A, B, C;
	A = read();
	print(A);
	B = read();
	print(B);
	C = dif(A, B);
	C = trail(C);
	print(C);
	free(C.coef);
	free(B.coef);
	free(A.coef);
	return 0;
}
