#include<stdio.h>
#define N_max 10000
typedef int huge[N_max];
void convert (int n , huge H)
{
	H[0] = 0;
	if(n == 0) {
		H[0] = 1;
	} else {
		while(n != 0)
		{
			H[++H[0]] = n % 10;
			n /= 10;
		}
	}	
}
int revert(huge H)
{
	int n = 0, i = 0;
	for(i = H[0]; i >= 1; --i)
	{
		n = n * 10 + H[i];
	}
	return n;
}
void padding_huge(huge A, int p, int q)
{
	int i;
	for(i = p; i <= q; ++i)
	{
		A[i] = 0;
	}
}
void adunare(huge C, huge A, huge B)
{
	int i, sum, t = 0;
	if(A[0] < B[0])
	{
		adunare(C, B, A);
	}
	else
	{
		padding_huge(A, A[0] + 1, A[0] + 1);
		padding_huge(B, B[0] + 1, A[0] + 1);
		padding_huge(C, 1, A[0] + 1);
		C[0] = A[0] + 1;
		for(i = 1; i <= A[0] || t == 1; ++i)
		{
			sum = 0;
			sum = A[i] + B[i] + t;
			C[i] = sum % 10;
			t = sum / 10;
		}
	}
}
void scadere(huge C, huge A, huge B)
{
	int i, dif, t = 0;
	if(A[0] < B[0])
	{
		scadere(C, B, A);
	}
	else
	{
		padding_huge(B, B[0] + 1, A[0]);
		C[0] = A[0];
		for(i = 1; i <= A[0]; i++)
		{
			dif = A[i] - B[i] + t;
			if(dif < 0)
			{
				dif += 10;
				t = -1;
			}
			else
			{
				t = 0;
			}
			C[i] = dif;
		}
	}
}
void inmultire(huge C, huge A, huge B)
{
	int factor, i, j, t ;
	C[0] = A[0] + B[0] + 1;
	padding_huge(C, 1, C[0]);
	padding_huge(A, A[0] + 1, C[0]);
	padding_huge(B, B[0] + 1, C[0]);
	for(i = 1; i <= A[0]; i++)
	{
		t = 0;
		for(j = 1; j <= B[0] || t != 0; j++)
		{	
			factor = A[i] * B[j] + t;
			C[i + j - 1] = C[i + j - 1] + factor % 10;
			t = factor/10;
			if(C[i + j - 1] >= 10)
			{
				C[i + j -1 ] %= 10;
				t += 1;
			}
		}
	}
}
void trailing (huge H)
{
	while(H[H[0]] == 0)
	{
		H[0]--;
	}
}
int impartire(huge A, huge C, int B)
{
	int t, i, imp;
	padding_huge(C, 1, A[0]);
	C[0] = A[0];
	t = 0;
	for(i = A[0]; i >= 1; i--)
	{
		imp = (t * 10 + A[i]) / B;
		C[i] = imp;
		t = (t * 10 + A[i]) % B;
	}
	return t;
}
void afisare(huge H)
{
	int i;
	for(i = H[0]; i >= 1; --i) {
		printf("%d", H[i]);
	}
	printf("\n");
}
int main()
{
	huge A, C;
	int B;
	B = 7;
	convert(1997, A);
	printf("%d\n", impartire(A, C, B));
	trailing(C);
	afisare(C);
	return 0;
}
