#include<stdio.h>
#include<stdlib.h>
int **read(int n, int m) {
    int **a, i;
    for(i = 0; i < n; i++) {
        *a[i] = (int **) malloc(sizeof(int*));
        a[i] = (int *) malloc(m * sizeof(int));
    }
    return a;
}
int main() {
    int **a, n, m, i, j;
    scanf("%d %d", &n, &m);
    a = read(n, m);
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            a[i][j] = i + j;
        }
    }
    return 0;
}
