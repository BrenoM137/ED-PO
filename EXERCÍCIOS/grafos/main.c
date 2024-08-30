#include "grafo_matriz.h"

int main()
{
    Grafo *g = cria_grafo(5, 0, 0);

    preenche_vertices(g);
    preenche_arestas(g);

    mostra_grafo(g);

    busca_largura(1,22,g);

    busca_profundidade(1,22,g);
}