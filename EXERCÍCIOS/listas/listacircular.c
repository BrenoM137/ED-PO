#include "listacircular.h"

Noc* cria_noc(int valor)
{
    return (Noc*) cria_no(valor);
}

Noc* insere_circular(int valor, Noc *L)
{
    Noc *novo = cria_noc(valor);
    Noc * aux;
    if(L == NULL)
    {
        L = novo;
        L->prox = novo;
    }
    else
    {
        aux = L;
        while (aux->prox != L)
            aux = aux->prox;

        aux->prox = novo;
        novo->prox = L;
        L = novo;
    }
    return L;
}

Noc* remove_circular(int valor, Noc *L)
{
    Noc *aux = L, *ant=NULL, *aux2;

    if (L != NULL)
    {
        while (aux->prox != L && aux->info != valor)
        {
            ant = aux;
            aux=aux->prox;
        }
        if(aux->info == valor)
        {
            if(aux == aux->prox)
                L=NULL;
            else if (ant != NULL)
                ant->prox = aux->prox;
            else
            {
                aux2=L;
                while (aux2->prox != L)
                    aux2 = aux2->prox;
                //ultimo elemento aponta para o novo primeiro elemento
                aux2->prox = L->prox;
                //
                L = aux->prox;
            }

        }
        free(aux);
    }
    return L;
}


Noc* libera_listac(Noc *L)
{
    Noc *aux = L;
    Noc *aux2 = aux->prox;

    while (aux2 != L)
    {
        aux = aux2;
        aux2 = aux2->prox;
        free(aux);
    }
    free(L);
    return NULL;
}

void mostra_listac(Noc* L)
{
    Noc* aux = L;
    do
    {
        printf(" %i ", aux->info);
        aux = aux->prox;
    }
    while (aux!=L);
}
