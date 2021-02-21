#include<stdio.h>
#include<stdlib.h>

int ***mat_3d(int row, int col, int high) {
    int ***m, i, j;
    m = (int ***) malloc(row * sizeof(int **));
    for(i = 0; i < row; i++) {
        m[i] = (int **) malloc(col * sizeof(int *));
    }
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            m[i][j] = (int *) malloc(high * sizeof(int));  
        }
    }
    return m;
}

void init(int ***m, int row, int col, int high) {
    int i, j, k;
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            for(k = 0; k < high; k++) {
                m[i][j][k] = (i + j) * k;
            }
        }
    }
}

void print(int ***m, int row, int col, int high) {
    int i, j, k;
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            for(k = 0; k < high; k++) {
                printf("m[%d][%d][%d] = %d\n", i, j, k, m[i][j][k]);
            }
        }
    }
}

void free_m(int ***m, int row, int col) {
    int i, j;
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            free(m[i][j]);
        }
    }
    for(i = 0; i < row; i++) {
        free(m[i]);
    }
    free(m);
}
int main() {
    int ***matrix, x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    matrix = mat_3d(x, y, z);
    init(matrix, x, y, z);
    print(matrix, x, y, z);
    free_m(matrix, x, y);
    return 0;
}
