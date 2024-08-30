#include <stdio.h>
#include <stdlib.h>

struct nod
{
    int filhos;
    int infectado;
    struct nod *ant;
    struct nod *prox;
};
typedef struct nod Nod;

struct listad
{
    Nod *ini;
    Nod *fim;
};
typedef struct listad Listad;

Listad* cria_listad();
int all_infect(Listad* L);
void infect(Listad* L);
void remove_infect(Listad* L);
int tempo_infect(Listad* L);
Nod* cria_nod(int valor);
int eh_nula(Listad* L);
void mostra_listad(Listad* L);
Listad* libera_listad(Listad *L);
Listad* insere_ordem(Listad* L, int valor);

int main()
{
    Listad* tree = cria_listad();
    int n, vert,check, filhos = 0;

    int count1 = 0;
    int count2 = 0;

    scanf("%d", &n);
    while(count1<n)
    {
        scanf("%d", &vert);
        int i = 1;
        count2 = 0;
        while(count2<vert)
        {
            if(count2 < (vert-1))
            {

                scanf("%d", &filhos);

                if(check == filhos)
                {
                    i++;
                } else
                {
                    if(count2 != 0)
                    {

                        tree = insere_ordem(tree,i);
                        i = 1;

                    }
                    check = filhos;
                }

            } else
            {
                if(check == filhos)
                {
                    tree = insere_ordem(tree,i);
                } else
                {
                    i = 1;
                    tree = insere_ordem(tree,i);
                }
            }


            
            count2++;
        }
        mostra_listad(tree);
        printf("%d\n",tempo_infect(tree));
        tree = libera_listad(tree);
        count1++;
    }

}

int eh_nula(Listad* L)
{
    Nod* aux = L->ini;
    int i = 1;

    while(aux != NULL)
    {
        if(aux->filhos != 0)
        {
            i = 0;
        }

        aux = aux->prox;
    }

    return i;
}

void remove_infect(Listad* L)
{
    Nod*aux=L->ini;

    while(aux != NULL)
    {
        if(aux->infectado == 1)
        {
            if(aux->filhos != 0)
            {
                aux->filhos = aux->filhos-1;
            }
        }

        aux = aux->prox;        
    }

}

void infect(Listad* L)
{
    Nod*aux=L->ini;
    int infected = 0;

    if(aux->infectado == 0)
    {
        aux->infectado = 1;
    }else
    {

        while(aux!= NULL)
        {
            if(aux->ant != NULL)
            {

                if((aux->ant->infectado == 1) && (infected == 0) && (aux->infectado != 1))
                {
                    aux->infectado = 1;
                    infected = 1;
                }

            }

            aux = aux->prox;
        }

    }

}

int all_infect(Listad* L)
{
    Nod*aux=L->ini;
    int i = 1;
    while(aux != NULL)
    {
        if(aux->infectado == 1)
        {
            if(aux->infectado == 0)
            {
                i = 0;
            }
        }

        aux = aux->prox;        
    }

    return i;

}

int tempo_infect(Listad* L)
{
    int t = 0;

    while(eh_nula(L) == 0)
    {

        infect(L);
        remove_infect(L);
        
        if(all_infect(L) == 1)
        {
            remove_infect(L);
        }
        //mostra_listad(L);
        
        t++;
           
    }


    return t+1;
}

Listad* cria_listad()
{
    Listad* novalista;
    novalista = (Listad *)malloc(sizeof(Listad));
    novalista->ini = novalista->fim = NULL;
    return novalista;
}

Nod* cria_nod(int valor)
{
    Nod* novo = (Nod*)malloc(sizeof(Nod));
    novo->ant = novo->prox = NULL;
    novo->filhos = valor;
    novo->infectado = 0;
    return novo;
}

void mostra_listad(Listad* L)
{
    Nod* aux = L->ini;

    while(aux != NULL)
    {
        printf("%d %d\n", aux->filhos, aux->infectado);
        aux = aux->prox;
    }
    printf("\n ");
}

Listad* insere_ordem(Listad* L, int valor)
{
    Nod *novo = cria_nod(valor);

    if (L == NULL)
    {
        L = cria_listad();
        L->ini = L->fim = novo;
    }
    else
    {


        if(L->ini == NULL)
        {
            L->ini = L->fim = novo;
        }
        else
        {

            if(L->ini == L->fim)
            {
                if(L->ini->filhos > novo->filhos)
                {
                    L->fim = novo;
                    L->ini->prox = novo;
                    novo->ant = L->ini;
                } else
                {
                    L->ini = novo;
                    L->fim->ant = novo;
                    novo->prox = L->fim;
                }
            } else
            {
                Nod* aux = L->ini;
                int insert = 0;
                while(aux != NULL)
                {
                    
                    if(aux->prox != NULL)
                    {
                        if((aux->prox->filhos <= novo->filhos) && (insert == 0))
                        {
                            if(aux->filhos <= novo->filhos)
                            {
                                L->ini = novo;
                                novo->prox = aux;
                                aux->ant = novo;
                                insert = 1;
                            } else
                            {
                                aux->prox->ant = novo;
                                novo->prox = aux->prox;
                                aux->prox = novo;
                                novo->ant = aux;
                                insert = 1;
                            }

                        }
                    } else
                    {
                        if(insert == 0)
                        {

                            L->fim = novo;
                            aux->prox = novo;
                            novo->ant = aux;
                            insert = 1;

                        }


                    }

                    aux = aux->prox;
                }
            }

        }
    }
    return L;
}

Listad* libera_listad(Listad *L)
{
    Nod *aux = L->ini;

    while (aux != NULL)
    {
        L->ini = L->ini->prox;
        free(aux);
        aux = L->ini;
    }

    free(L);
    return NULL;

}