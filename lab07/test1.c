#include<stdio.h>
int is_set(char byte, int i) {
    int mask = (1 << i);
    return (byte & mask) != 0;
}
int main()
{
	int mybyte = 15;
	int i = 4;
	if (is_set(mybyte, i)) {
    	printf("bitul %d din byteul %d este setat!\n", i, mybyte);
	} else {
    	printf("bitul %d din byteul %d NU este setat!\n", i, mybyte);
	}
 	return 0;
}
