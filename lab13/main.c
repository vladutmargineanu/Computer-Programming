#include "Produs.h"

int main(){
	creare_fisier(NF);

	printf("=== Afisare fisier ===\n");
	afisare_ecran(NF);

	printf("=== Afisare dupa sortare ===\n");
	sortare_nume(NF);

	update(NF);
	printf("=== Afisare dupa update ===\n");
	afisare_ecran(NF);
	return 0;
}

void creare_fisier(char* nume_fisier){
	int i, x;
	Produs p;
	char nume[9];
	srand (time(NULL));
	FILE *f = fopen(nume_fisier, "wb");
	for(i = 0; i < 100; i++) {  
		x = rand() % 768; //consider ca x apartine intervalului 0 ... 767
		sprintf(nume, "Produs%d", x); 
		strcpy(p.nume_produs, nume);
		p.pret_produs = x <= 100 ? x : x % 100;
		p.cantitate = x % 100;
		fwrite(&p, 1, sizeof(Produs), f);
	}
	fclose(f);
}

void afisare_ecran(char* nume_fisier){
	Produs p;
	int i;
	FILE *f = fopen(nume_fisier, "rb");
	for(i = 0; i < 100; i++) {
		fread(&p, 1, sizeof(Produs), f);
		printf("%s %d %.2f\n", p.nume_produs, p.cantitate, p.pret_produs);
	}
	fclose(f);
}

int compare(const void *a, const void *b){
	return strcmp((char*)a, (char*)b);
}

void afisare(Produs p[]){
	int i;
	for(i = 0; i < 100; i++)
		printf("%s %d %.2f\n", p[i].nume_produs, p[i].cantitate, p[i].pret_produs);
}

void sortare_nume(char* nume_fisier){
	Produs p[100];
	int i;
	FILE *f = fopen(nume_fisier, "rb");
	fread(p, 100, sizeof(Produs), f); // o alta metoda de a citi cele 100 de inregistrari din fisier
	fclose(f);
	qsort(p, 100, sizeof(Produs), compare);
	afisare(p);	
}

void update(char* nume_fisier){
	int x, j;
	Produs *y, p[100];
	char nr[3], np1[64];
	char n1[9]; int n2; float n3;
	char np[9]; // nume produs cautat

	printf("x="); scanf("%d", &x);
	sprintf(nr, "%d", x); // il convertesc pe x de la int la char* si rezultatul il retin in nr
	strcpy(np, "");
	strcat(np, strcat(strdup("Produs"), nr)); // creez numele produsului cautat

	//incarc datele din fisier
	FILE *f = fopen(nume_fisier, "rb");
	fread(p, 100, sizeof(Produs), f); // o alta metoda de a citi cele 100 de inregistrari din fisier
	fclose(f);
	qsort(&p, 100, sizeof(Produs), compare); //sortez vectorul pentru a putea aplica cautarea binara

	y = (Produs*) bsearch (&np, &p, 100, sizeof(Produs), compare); // caut produsul cu numele retinut de np
	if (y == NULL) 
		printf("Nu exista produsul %s.\n", np);
	else {
		printf("%s %d %f\n", y->nume_produs, y->cantitate, y->pret_produs);
		getchar();
		fflush(stdin);
		fgets(np1, 64, stdin);
		if (strcmp(np1, "\n") != 0) { // au fost introduse valori
			sscanf(np1, "%s %d %f", n1, &n2, &n3);
			for(j = 0; j < 100; j++) //parcurg toate produsele
				if (strcmp(p[j].nume_produs, y->nume_produs) == 0) { // daca am gasit produsul cautat
					strcpy(p[j].nume_produs, "");
					strcat(p[j].nume_produs, n1); 	// actualizez numele,
					p[j].cantitate = n2; 		// cantitatea,
					p[j].pret_produs = n3;		// si pretul
				}
		}
		FILE *f = fopen(NF, "wb");
		fwrite(p, 100, sizeof(Produs), f); //rescriu cele 100 de inregistrari
		fclose(f);				
	}
}

