#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int L, C, N, *LIN, *COL;
	float *X;
}rare;

void dealloc(rare *M) {
	free(M->X);
	free(M->LIN);
	free(M->COL);
}

rare read() {
	int i;
	rare M;
	scanf("%d %d %d", &M.N, &M.L, &M.C);
	M.X = (float *)calloc(M.N, sizeof(float));
	if(M.X == NULL) {
		exit (-1);
	}
	M.LIN = (int *)calloc(M.N, sizeof(int));
	if(M.LIN == NULL) {
		free(M.X);
		exit (-1);
	}
	M.COL = (int *)calloc(M.N, sizeof(int));
	if(M.COL == NULL) {
		free(M.LIN);
		free(M.X);
		exit (-1);
	}
	for(i = 0; i < M.N; i++) {
		scanf("%d %d %f", &M.LIN[i], &M.COL[i], &M.X[i]);
	}
	return M;
}

void print(rare *M) {
	int i, j, z;
	z = 0;
	for(i = 0; i < M->L; i++) {
		for(j = 0; j < M->C; j++) {
			if(M->LIN[z] == i && M->COL[z] == j) {
				printf("%.0f ", M->X[z]);
				z++;
			} else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}

void trail(rare *C) {
	while(C->LIN[C->N - 1] == 0 && C->COL[C->N - 1] == 0) {
		C->N--;
	}
}
rare add(rare *A, rare *B) {
	int i, j, z, y, t, ok;
	rare C;
	if(A->N < B->N) {
		add(B, A);
	} else {
		C.L = A->L;
		C.C = A->C;
		C.N = A->N;
		C.X = (float *)calloc(A->N, sizeof(float));
		if(C.X == NULL) {
			dealloc(A);
			dealloc(B);
			exit (-1);
		}
		C.LIN = (int *)calloc(A->N, sizeof(int));
		if(C.LIN == NULL) {
			free(C.X);
			dealloc(A);
			dealloc(B);
			exit (-1);
		}
		C.COL = (int *)calloc(A->N, sizeof(int));
		if(C.COL == NULL) {
			free(C.X);
			free(C.LIN);
			dealloc(A);
			dealloc(B);
			exit (-1);
		}
		t = y = z = 0;
		for(i = 0; i < A->L; i++) {
			for(j = 0; j < A->C; j++) {
				ok = 0;
				if(i == B->LIN[y] && j == B->COL[y] && y < B->N) {
					C.LIN[t] = B->LIN[y];
					C.COL[t] = B->COL[y];
					C.X[t] += B->X[y]; 
					ok = 1;
					y++;
				}
				if(i == A->LIN[z] && j == A->COL[z] && z < A->N) {
					C.LIN[t] = A->LIN[z];
					C.COL[t] = A->COL[z];
					C.X[t] += A->X[z];
					ok = 1;
					z++;
				}
				if(C.X[t] == 0) {
					ok = 0;
				}
				if(ok == 1) {
					t++;
				}
			}
		}
	}
	return C;
}
int main() {
	rare A, B, C;
	A = read();
	print(&A);
	B = read();
	print(&B);
	C = add(&A, &B);
	trail(&C);
	print(&C);
	dealloc(&A);
	dealloc(&B);
	dealloc(&C);
	return 0;
}
