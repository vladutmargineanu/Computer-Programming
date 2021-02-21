#ifndef __NUMEFISIER__
#define __NUMEFISIER__
#define NF "input.bin"
#endif

#ifndef __STDLIB__
#define __STDLIB__
#include <stdlib.h>
#endif

#ifndef __STRING__
#define __STRING__
#include <string.h>
#endif

// Problema 1.
#ifndef __STDIO__
#define __STDIO__
#include <stdio.h>
#endif

typedef struct {
	char nume_produs[20];
	int cantitate;
	float pret_produs;
}Produs;
// --- Problema 1.

void creare_fisier(char*); // Problema 2.

void afisare_ecran(char*); // Problema 3.

void sortare_nume(char*); // Problema 4.

void update(char*); //Problema 5.
