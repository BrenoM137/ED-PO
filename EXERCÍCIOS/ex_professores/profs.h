#ifndef PROFS_H
#define PROFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct professores
{
    int cod;
    char sexo[2];
    int hrs;
    float salB;
    float salL;
};

typedef struct professores Prof;

Prof Lerlista();
void Mostralista(Prof professor);
void Calcsal(Prof* professor);
#endif