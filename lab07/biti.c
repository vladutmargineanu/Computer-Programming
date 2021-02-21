#include<stdio.h>
#define SIZE 100
typedef unsigned char SET[SIZE];
//verificam valoare bit
char bit_is (char byte, int i) {
	int mask = (1 << i);
	return (byte & mask) != 0;
}

//setam bit pe 1
char set1 (char byte, int i) {
	int mask = (1 << i);
	return (mask | byte);
}

//setam bit pe 0
char set2 (char byte, int i) {
	int mask = ~(1 << i);
	return (mask & byte);
}

//afisam bitul nr dintr-un numar
void afisare (int n) {
	int i;
	for(i =31; i >= 0; i--) {
		printf("%d", bit_is(n, i));
	} 
	printf("\n");
}

//inseram element in multime
void insert (SET S, int n) {
	S[n / 8] = set1(S[n / 8], n % 8);
}

//stergem element din multime
void del (SET S, int n) {
	S[n / 8] = set2(S[n / 8], n % 8);
}

//verificare element in multime
void has (SET S, int n) {
	if(bit_is(S[n / 8], n)
		printf("este\n");
	else
		printf("nu este\n");
}

//eliminam elementele multimii
void del_all (SET S)
{
	int i;
	for(i = 0; i < SIZE; i++)
		S[i] = 0;
}

//cardinal multime
int  card (SET S)
{
	int i, j, nr = 0;
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < 8; j++)
			{
				if(bit_is(S[i], j)
					nr++;
			}
	}
	return nr;
}

//reuniune
void reuniune(SET A, SET B, SET C)
{
	int i, j;
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(bit_is(A[i], j) | bit_is(B[i], j) == 1)
				C[i] = set1(C[i], j);
		}
	}
}

//intersectie
void intersectie(SET A, SET B, SET C)
{
	int i, j;
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(bit_is(A[i], j) & bit_is(B[i], j) == 1)
				C[i] = set1(C[i], j);
		}
	}
}

//diferenta
void diferenta(SET A, SET B, SET C)
{
	int i, j;
	reuniune(A, B, C);
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < 8; j++)
			if(bit_is(B[i], j) & bit_is(C[i], j) == 1)
				C[i] = set2(C[i], j)	
	}
}
 
int main ()
{
	SET A, B, C;
	afisare(5);
	return 0;
}
