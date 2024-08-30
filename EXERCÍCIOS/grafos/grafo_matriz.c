#include "grafo_matriz.h"

Grafo *cria_grafo(int n, int valorado, int direcionado)
{
    int i;
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));

    g->eh_direcionado = direcionado;
    g->eh_valorado = valorado;
    g->ordem = n;
    g->vertices = (int *)malloc(sizeof(int) * n);
    g->visitados = (int *)malloc(sizeof(int) * n);
    g->adjacencias = (int **)malloc(sizeof(int) * n);
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
           scanf("%d", &g->adjacencias[i][j]);

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

/*

Procedimento BUSCA-AMPL(v)
   visitado(v)  sim
   Colocar v em uma fila
   Enquanto fila não vazia faça
      w  retirar o elemento da frente da fila
      Para cada vértice i adjacente a w faça
         Se visitado(i) = não então
           visitado(i)  sim
           Colocar i no final da fila
         fim-se
      fim-para
   fim-enquanto
Fim

*/

void limpa(Grafo *g)
{
    int i;
    for (i = 0; i < g->ordem; i++)
        g->visitados[i] = 0;
}

/*
Procedimento PROF(nó v)
   visitado(v)  sim
   Para cada nó w adjacente a v faça
      Se visitado(w) = não então
         PROF(w)
   fim-para
Fim
*/

void prof(int v, Grafo* g)
{
    int w;
    g->visitados[v] = 1;
    printf("%d \n", v+1);
    for (w = 0; w < g->ordem; w++)
    {
        if (g->adjacencias[v][w] == 1)
        {
            if (!g->visitados[w])
            {
                prof(w, g);
            }
        }
    }
}

/*
Procedimento BUSCA-PROF
   Para i = 1,...,n faça
      visitado(i)  não
   fim-para
   Para i = 1,...,n faça
      Se visitado(i) = não então
         PROF(i)
   fim-para
Fim
*/

void profundidade(Grafo *g)
{
    int i;
    limpa(g);

    for (i = 0; i < g->ordem; i++)
    {

        if (!g->visitados[i])
        {
            prof(i, g);
        }
    }
}

// retorna 1 se existe caminho de origem para destino
int busca_largura(int origem, int destino, Grafo *g)
{
    Fila *f = cria_fila();
    int *w;
    int i;

    limpa(g);
    g->visitados[origem] = 1;
    w = (int *)malloc(sizeof(int));
    *w = origem;
    enqueue(f, (void *)w);

    while (!eh_vazia_fila(f))
    {
        w = (int *)dequeue(f);
        printf(" LARGURA %d \n", g->vertices[*w]);
        if (*w == destino)
        {
            return 1;
        }
        for (i = 0; i < g->ordem; i++)
        {
            if (g->adjacencias[*w][i] == 1)
            {
                if (!g->visitados[i])
                {
                    g->visitados[i] = 1;
                    w = (int *)malloc(sizeof(int));
                    *w = i;
                    enqueue(f, (void *)w);
                }
            }
        }
    }

    return 0;
}

// retorna 1 se existe caminho de origem para destino
int busca_profundidade_recursao(int origem, int destino, Grafo *g)
{
   if(origem == destino){
    return 1;
   }

   g->visitados[origem] = 1;
   printf(" PROFUNDIDADE %d \n", origem+1);
   for(int i = 0; i < g->ordem; i++){
        
        if(g->adjacencias[origem][i] >= 1 && !g->visitados[i]){
            if(busca_profundidade_recursao(i, destino, g)){
                return 1;
            }
        }
   }
    
    return 0;
}

int busca_profundidade(int origem, int destino, Grafo *g)
{
    limpa(g);
    return busca_profundidade_recursao(origem, destino, g);
}