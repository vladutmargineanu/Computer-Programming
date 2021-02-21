#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 4

typedef struct Persoana{
        char* nume;
        char* prenume;
} Persoana;

void serializeaza(Persoana v[], int nrPersoane, char* fileName)
{
	int i, dim;	
    	char string[1024];

    	FILE* f = fopen(fileName, "wb");

	for(i = 0; i < nrPersoane; i++){

		dim = strlen(v[i].prenume); //determin lungimea sirului ce urmeaza sa fie scris
		fwrite(&dim, 1, sizeof(dim), f); //scriu in fisier dimensiunea sirului
		strcpy(string, v[i].prenume);
		fwrite(string, 1, dim, f); // scriu in fisier numele (continutul variabilei)

		dim = strlen(v[i].nume); 
		fwrite(&dim, 1, sizeof(dim), f); 
		strcpy(string, v[i].nume);
		fwrite(string, 1, dim, f); 

	}

    fclose(f);
}

void deserializeaza(Persoana w[], int nrPersoane, char* fileName)
{
	int i, dim;
	char str[1024];

    	FILE* f = fopen(fileName, "rb");

	for(i = 0; i < nrPersoane; i++) {

		fread(&dim, 1, sizeof(dim), f); //determin dimensiunea sirului care urmeaza sa fie citit
		fread(str, 1, dim, f); //citesc sirul
		str[dim] = 0; //pun NULL la sfarsitul sirului
		w[i].prenume = strdup(str); //initializez campul prenume cu ce am citit din fisier
		
		fread(&dim, 1, sizeof(dim), f); 
        	fread(str, 1, dim, f);
        	str[dim] = 0;
		w[i].nume = strdup(str); 

	}

    	fclose(f);
}

int main()
{
        Persoana v[N],w[N];
        char* prenume[N] = { "Eric", "Kyle", "Stan", "Kenny" };
        char* nume[N] = { "Cartman", "Broflovski", "Marsh", "McCormick" };
        int i;
        for (i = 0; i < N; i++){
                v[i].nume = nume[i];
                v[i].prenume = prenume[i];
        }
        
        // Serializam vectorul intr-un fisier
        serializeaza(v, N, "persoane.bin");
        // Deserializam in alt vector, din acelasi fisier. Ar trebui sa obtinem aceleasi informatii.
        deserializeaza(w, N, "persoane.bin");

        for (i = 0; i < N; i++){
                printf("%s %s\n",w[i].prenume,w[i].nume);
        }

        return 0;
}
