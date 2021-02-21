#include<stdio.h>
#include<stdlib.h>

int **read_sup(int n) {
    int **matrix, i, j;
    matrix = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(i * sizeof(int));
        for(j = 0; j < i; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

int **read_inf(int n) {
    int **matrix, i, j;
    matrix = (int **)malloc(n * sizeof(int *));
    for(i = n - 1; i >= 0; i++) {
        matrix[i] = (int**)malloc(i *
    }
}
int main() {

}
