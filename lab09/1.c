#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *read(int n, int MAX) {
    int *v, i;
    v = (int *)malloc(n * sizeof(int));
    if(v == NULL) {
        printf("NU am memorie\n");
        exit(-1);
    }
    srand((unsigned) time(NULL));
    for(i = 0; i < n; i++) {
        v[i] = rand() % MAX;
    }
    return v;
}

void print(int n, int *v) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void sort(int *v, int n) {
    int i, ok;
    do {
        ok = 0;
        for(i = 0; i < n - 1; i++) {
            if(v[i] > v[i + 1]) {
                v[i] = v[i] ^ v[i + 1];
                v[i + 1] = v[i] ^ v[i + 1];
                v[i] = v[i] ^ v[i + 1];
                ok = 1;
            }
        }
    } while(ok);
}

int main() {
    int *v, n, maxim;
    scanf("%d %d", &n, &maxim);
    v = read(n, maxim);
    print(n, v);
    sort(v, n);
    print(n, v);
    free(v);
    return 0;
}
