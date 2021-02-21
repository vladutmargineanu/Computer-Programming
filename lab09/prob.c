#include<stdio.h>
#include<stdlib.h>

void **alloc_2d(int rows, int cols, int size_elem) {
    int i, j;
    void **rez = malloc(rows * sizeof(void *));
    if(rez == NULL) {
        return NULL;
    }
    for(i = 0; i < rows; i++) {
        rez[i] = malloc(cols * size_elem);
        if(rez[i] == NULL) {
            for(j = i - 1; j >= 0; j--) {
                free(rez[i]);
            }
            free(rez);
        }
    }
}
void free_2d(void **m, int rows) {
    int i;
    for(i = 0; i < rows; i++) {
        free(m[i]);
    }
    free(m);
}
int main() {
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    int **a = (int **) alloc_2d(5, 5, sizeof(int));
    if(a == NULL) {
        printf("Nu am reusit\n");
        exit(-1);
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            a[i][j] = i + j;
        }
    }
    for(i = 0; i < n; i++) {
         for(j = 0; j < m; j++) {
             printf("%d", a[i][j]);
        }
        printf("\n");
    }
    free_2d((void **)a, n);
    return 0;
}
