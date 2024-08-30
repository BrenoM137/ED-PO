#include <stdio.h>
#include <stdlib.h>

struct nod
{
	int info;
	struct nod* prox;
	struct nod* ant;
};
typedef struct nod Nod;

struct listad
{
	Nod* ini;
	Nod* fim;
};
typedef struct listad Listad;

Nod* CriaNo(int valor);
Listad* cria_listad();
Listad* insere_fim(Listad* L, int valor);
Listad* mostra_lista(Listad* L);
void libera_lista(Listad *L);
int Maximun(Listad* L);
int Minimun(Listad* L);

int main()
{
    Listad* L = NULL;
    int tamanho = 0, count = 0, valor = 0;

    L = cria_listad(L);

    printf("Tamanho da lista: ");
    scanf("%d",&tamanho);

    while(count < tamanho)
    {
        printf("Insira o valor %d: ", count+1);
        scanf("%d",&valor);

        L = insere_fim(L,valor);
        count++;
    }

    mostra_lista(L);

    libera_lista(L);
}

Listad* insere_fim(Listad* L,int valor)
{
    Nod* no = CriaNo(valor), *anterior = NULL;

    if(L->ini == NULL)
    {
        L->ini = no;
    } else
    {
        anterior = L->fim;
        anterior->prox = no->ant;
        no->ant = anterior->prox;
    }

    L->fim = no;

    return L;
}

Listad* mostra_lista(Listad* L)
{
    Nod* no = NULL;

    no = L->ini;
    printf("\nMOSTRA LISTA:\n");

    while(no->prox != NULL)
    {
        printf("%d ", no->info);
        no = no->prox;
    }
}

int Maximun(Listad* L)
{
    
}

int Minimun(Listad* L)
{

}

void libera_lista(Listad *L)
{
    Nod *aux = NULL, *remover = NULL;

    aux = L->ini;
    remover = L->ini;
    while (aux != NULL) 
    {
        remover = remover->prox;
        free(aux);
        aux = remover;
    }
}

Nod* CriaNo(int valor)
{
    Nod *novo = NULL;
    novo = (Nod*) malloc(sizeof(Nod));

    novo->ant = NULL;
    novo->prox = NULL;
    novo->info = valor;
    
    return novo;
}

Listad* cria_listad()
{
    Listad *L = (Listad*)malloc(sizeof(Listad));
    L->ini = L->fim = NULL;
    return L;
}