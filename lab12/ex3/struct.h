#ifndef STRUCT_H
#define STRUCT_H

#include <string.h>
#define LEN 4

typedef struct {
	int zi;
	int luna;
	int an;
}data;

typedef struct {
	char nume[30];
	data d;
	float medie;
}student;

void init_struct(student s[]);
void clean_struct(student s[]);
#endif
