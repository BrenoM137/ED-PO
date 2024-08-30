#include <stdio.h>
#include <stdlib.h>


struct nod
{
    int info;
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

typedef struct grafo
{
    Listad* lista;
    int ordem;
    int *vertices;
    int **adjacencias;
    int eh_direcionado;
    int eh_valorado;
    int *visitados;
}Grafo;


Grafo *cria_grafo(int n, int valorado, int direcionado);
void preenche_vertices(Grafo *g);
void preenche_arestas(Grafo *g);
void mostra_grafo(Grafo *g);
int verifica_grafo(Grafo *g);

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
    novo->info = valor;
    return novo;
}

/*Listad* insere_ordem(Listad* L, int valor)
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
                if(L->ini->info > novo->info)
                {
                    L->ini = novo;
                    L->fim->ant = novo;
                    novo->ant = L->ini;
                } else
                {
                    L->fim = novo;
                    L->ini->prox = novo;
                    novo->ant = L->ini;
                }
            } else
            {
                Nod* aux = L->ini;
                int insert = 0;
                while(aux != NULL)
                {
                    
                    if(aux->prox != NULL)
                    {
                        if((aux->prox->info <= novo->info) && (insert == 0))
                        {
                            if(aux->info <= novo->info)
                            {
                                if(L->fim == aux->prox)
                                {
                                    L->fim = novo;
                                }
                                aux->prox->prox = novo;
                                novo->ant = aux->prox;
                                insert = 1;
                            }

                        } else
                        {
                            if(L->ini == aux)
                            {
                                L->ini = novo;
                            }
                            aux->ant = novo;
                            novo->prox = aux;
                        }
                    } else
                    {
                        if(insert == 0)
                        {

                            L->fim = novo;
                            aux->prox = novo;
                            novo->ant = aux;

                        }


                    }

                    aux = aux->prox;
                }
            }

        }
    }
    return L;
}*/

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
                if(L->ini->info > novo->info)
                {
                    L->ini = novo;
                    L->fim->ant = novo;
                    novo->ant = L->ini;
                } else
                {
                    L->fim = novo;
                    L->ini->prox = novo;
                    novo->ant = L->ini;
                }
            } else
            {
                Nod* aux = L->fim;
                int insert = 0;
                while(aux != NULL)
                {
                    
                    if(aux->ant != NULL)
                    {
                        if((aux->ant->info <= novo->info) && (insert == 0))
                        {

                            if(aux->info <= novo->info)
                            {
                                if(L->fim == aux)
                                {
                                    L->fim = novo;
                                }
                                aux->prox = novo;
                                novo->ant = aux;
                                insert = 1;
                            } else
                            {
                                aux->ant->prox = novo;
                                novo->ant = aux->ant;
                                novo->prox = aux;
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

                        }


                    }

                    aux = aux->prox;
                }
            }

        }
    }
    return L;
}

void busca_largura(Grafo *g, int vertice, int max, int vertice_inicial)
{
    int i = 0;
    if (g->visitados[vertice - 1] != 1)
    {
        g->visitados[vertice - 1] = 1;
        if (vertice_inicial != vertice)
        {
            max--;
            g->lista = insere_ordem(g->lista, vertice);
            //printf("%d ", vertice);
        }
        if (max != 0)
        {
            for (i = 0; i < g->ordem; i++)
            {
                if (g->adjacencias[vertice - 1][i] == 1)
                {
                    busca_largura(g, i + 1, max, vertice_inicial);
                }
            }
        }
    }
}

Grafo *cria_grafo(int n, int valorado, int direcionado)
{
    int i;
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));

    g->eh_direcionado = direcionado;
    g->eh_valorado = valorado;
    g->ordem = n;
    g->vertices = (int *)malloc(sizeof(int) * n);
    g->visitados = (int *)malloc(sizeof(int) * n);
    g->adjacencias = (int **)malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++)
        g->adjacencias[i] = (int *)malloc(sizeof(int) * n);
    return g;
}

void preenche_vertices(Grafo *g)
{
    int i;
    for (i = 0; i < g->ordem; i++)
        g->vertices[i] = i + 1;
}

void preenche_arestas(Grafo *g)
{
    int i, j;
    for (i = 0; i < g->ordem; i++)
        for (j = 0; j < g->ordem; j++)
           g->adjacencias[i][j] = 0;

}

void mostra_grafo(Grafo *g)
{
    int i, j;
    for (i = 0; i < g->ordem; i++)
    {
        printf("%i -> ", g->vertices[i]);
        for (j = 0; j < g->ordem; j++)
            if (g->adjacencias[i][j] != 0)
                printf("%d - ", j + 1);
    }
}

int percorre_lista(Listad *l)
{
    Nod* aux = l->ini;

    while(aux != NULL)
    {
        printf("%d ",aux->info);
        aux = aux->prox;
    }
}

int main()
{
    int C = 1, E = 1, L = 1, P = 1;
    int X,Y, N =1 ;
    while((E != 0)||(L != 0)||(C != 0)||(P!=0))
    {
        scanf("%d",&C);
        Grafo* G = cria_grafo(C,0,0);
        G->lista = cria_listad();
        scanf("%d",&E);
        scanf("%d",&L);
        scanf("%d",&P);
        preenche_vertices(G);
        preenche_arestas(G);
        if((C != 0)||(E != 0))
        {

            while(E > 0)
            {
                scanf("%d",&X);
                scanf("%d",&Y);

                G->adjacencias[X-1][Y-1] = G->adjacencias[Y-1][X-1] = 1; 
                E--;
            }
            
            printf("Teste %d\n", N);
            busca_largura(G, L, P, L);
            percorre_lista(G->lista);
            printf("\n\n");
            N++;
        }
        free(G);
    }

    return 0;
}