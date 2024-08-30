#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include "listasimples.h"

struct noc
{
    int info;
    struct noc *prox;
};

typedef struct noc Noc;

Noc* cria_noc(int);
Noc* libera_listac(Noc *L);
Noc* remove_circular(int valor, Noc *L);
Noc* insere_circular(int valor, Noc *L);
void mostra_listac(Noc* L);


#endif // LISTACIRCULAR_H_INCLUDED
