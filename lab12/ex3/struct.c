#include "struct.h"

void init_struct(student s[])
{
	strcpy(s[0].nume, "Dinu Andrei");
	s[0].medie = 8.76;
	s[0].d.zi = 31;
	s[0].d.luna = 7;
	s[0].d.an = 1997;

	strcpy(s[1].nume, "Gherghita David");
	s[1].medie = 9.33;
	s[1].d.zi = 30;
	s[1].d.luna = 6;
	s[1].d.an = 1998;
	
	strcpy(s[2].nume, "Macovei Antonio");
	s[2].medie = 8.47;
	s[2].d.zi = 18;
	s[2].d.luna = 6;
	s[2].d.an = 1998;
	
	strcpy(s[3].nume, "Raileanu Arina");
	s[3].medie = 9.78;
	s[3].d.zi = 1;
	s[3].d.luna = 7;
	s[3].d.an = 1998;
}

void clean_struct(student s[])
{
	int i;
	
	for (i = 0; i < LEN; i++){
		strcpy(s[i].nume, "");
		s[i].medie = 0;
		s[i].d.zi = 0;
		s[i].d.luna = 0;
		s[i].d.an = 0;
	}
}

