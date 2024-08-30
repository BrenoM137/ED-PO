#include <stdio.h>
#include <stdlib.h>

typedef struct grafo
{
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

int verifica_grafo(Grafo *g) //1 = sucesso, 0 = falha
{
    int i,j, x;

    for (i = 0; i < g->ordem; i++)
    {
        x = 0;
        for (j = 0; j < g->ordem; j++)
        {
            x = x + g->adjacencias[i][j];
        }

        if(x == 0)
        {
            return 0;
        }
    }

    return 1;

}

int main()
{
    int X,Y;
    int N = 1;
    int E = 1;
    int L = 1;

    while((E != 0)||(L != 0))
    {
        scanf("%d",&E);
        Grafo* G = cria_grafo(E,0,0);
        scanf("%d",&L);
        if((E != 0)||(L != 0))
        {

            preenche_vertices(G);
            preenche_arestas(G);

            while(L > 0)
            {
                scanf("%d",&X);
                scanf("%d",&Y);

                G->adjacencias[X-1][Y-1] = G->adjacencias[Y-1][X-1] = 1; 
                L--;
            }

            if(verifica_grafo(G) == 1)
            {
                printf("Teste %d\n", N);
                printf("normal\n\n");
            } else
            {
                printf("Teste %d\n", N);
                printf("falha\n\n");
            }
            N++;
        }
        free(G);
    }

    return 0;
}