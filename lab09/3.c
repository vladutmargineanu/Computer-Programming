#include<stdio.h>
#include<stdlib.h>

char *build_number(int value) {
    char *num;
    int digits = 0, clone, i;
    clone = value;
    while(clone) {
        digits++;
        clone /= 10;
    }
    if(digits == 0) {
        num = (char*)malloc(2 * sizeof(char));
    } else {
        num = (char*)malloc((digits + 1) * sizeof(char));
        num[0] = digits + 48;
        printf("%d\n", num[0] - 48);
        for(i = 1; i <= digits; i++) {
            num[i] = value % 10 + 48;
            value /= 10;
        }
    }
    return num;
}

char *add_numbers(char *a, char *b) {
    char *rez, *aux;
    int t, i;
    if(b[0] > a[0]) {
        return add_numbers(b, a);
    } else {
        rez = (char*)malloc((a[0] - 46) * sizeof(char));
        aux = (char*)realloc(b, (a[0] - 47) * sizeof(char));
        b = aux;
        for(i = b[0] - 47; i <
        rez[0] = a[0] + 1;
        t = 0;
        for(i = 1; i <= rez[0] - 48; i++) {
            rez[i] = t + 
        }
    }
}
void print(char *num) {
    int i;
    for(i = num[0] - 48; i >= 1; i--) {
        printf("%d", num[i] - 48);
    }
    printf("\n");
}
int main() {
    char *num;
    num = build_number(12345);
    print(num);
    return 0;
}
