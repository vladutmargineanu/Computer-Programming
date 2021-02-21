#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 4


typedef struct {
	int zi;
	int luna;
	int an;
}data;

typedef struct {
	char *nume;
	data d;
	float medie;
}student;


void init_struct(student s[])
{
	s[0].nume = malloc(30);
	strcpy(s[0].nume, "Margineanu Andrei");
	s[0].medie = 8.76;
	s[0].d.zi = 24;
	s[0].d.luna = 7;
	s[0].d.an = 1997;
   
    s[1].nume = malloc(30);
	strcpy(s[1].nume, "Margineanu Vladut");
	s[1].medie = 9.33;
	s[1].d.zi = 23;
	s[1].d.luna = 8;
	s[1].d.an = 1996;
	
	s[2].nume = malloc(30);
	strcpy(s[2].nume, "Sprinceana Ariana");
	s[2].medie = 8.47;
	s[2].d.zi = 19;
	s[2].d.luna = 6;
	s[2].d.an = 1998;
	
	s[3].nume = malloc(30);
	strcpy(s[3].nume, "Radu Constantin");
	s[3].medie = 9.78;
	s[3].d.zi = 1;
	s[3].d.luna = 7;
	s[3].d.an = 1998;
}

void clean_struct(student s[])
{
	int i;
	
	for (i = 0; i < LEN; i++){
		
		free(s[i].nume);
		s[i].medie = 0;
		s[i].d.zi = 0;
		s[i].d.luna = 0;
		s[i].d.an = 0;
	}
}


int main()
{
	int i;
	student s[LEN];
	
	init_struct(s);
	
	FILE *out = fopen("ex3.file", "wb");
	fwrite(s, sizeof(student), LEN, out);
	fclose(out);
	
	FILE *in = fopen("ex3.file", "rb");
	fread(s, sizeof(student), LEN, in);
	fclose(in);

	printf("\n");
	for (i = 0; i < LEN; i++){
		printf("%s\n%02d.%02d.%d\n%.2f\n\n", s[i].nume, 
			s[i].d.zi, s[i].d.luna, s[i].d.an, s[i].medie);
	} 
	clean_struct(s);
	
	return 0;
}
