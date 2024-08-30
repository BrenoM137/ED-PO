#include <stdio.h>
#include <stdlib.h>

struct nod
{
	char gene;
	int quantidade;
	int alfa;
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

Nod* CriaNo(char gene, int quantidade);
Listad* mostra_listaaux(Listad* L);
Listad* cria_listad();
Listad* insere_fim(Listad* L, char gene, int quantidade);
Listad* mostra_lista(Listad* L);
Listad* somaquant(Listad* L, char gene1, char gene2);
Listad* sort(Listad* lista);
Nod* minimum(Nod* lista);
void zeraquant(Listad* L);
void libera_lista(Listad *L);
Nod* removeElemento(Nod **lista, int elemento);

int main()
{
    Nod* teste = NULL;
    Listad* L = NULL;
    Listad* aux = NULL;
    int count = 0, tamanho = 0;
    char gene1[2], gene2[2];

    aux = cria_listad();
    L = cria_listad();

    zeraquant(L);

    //printf("Insira tamanho:");
    scanf("%d", &tamanho);

    while(tamanho != 0)
    {
        while (count < tamanho)
        {
            //printf("Digite o gene 1: ");
            scanf("%s", gene1);
            getchar();
            //printf("Digite o gene 2: ");
            scanf("%s", gene2);
            getchar();

            somaquant(L,gene1[0], gene2[0]);

            count++;
        }
        //teste = minimum(L->ini);
        //printf("\n MINIMUM: %c %d %d\n",teste->gene,teste->quantidade, teste->alfa);
        aux = sort(L);
        mostra_lista(aux);
        zeraquant(L);
        //mostra_listaa(L);
        count = 0;
        //printf("Para acabar, digite 0: ");
        scanf("%d", &tamanho);
    }

    printf("\n");
    libera_lista(L);
    libera_lista(aux);

    return 0;
}

Nod* CriaNo(char gene, int quantidade)
{
    Nod *novo = NULL;
    novo = (Nod*) malloc(sizeof(Nod));

    novo->ant = NULL;
    novo->prox = NULL;
    if(gene == 'A')
    {
        novo->alfa = 1;
    } else
    {
        if(gene == 'C')
        {
            novo->alfa = 2;
        } else
        if( gene == 'G')
        {
            novo->alfa = 3;
        } else
        if( gene == 'T')
        {
            novo->alfa = 4;
        }
    }
    novo->gene = gene;
    novo->quantidade = quantidade;

    return novo;
}

Listad* cria_listad()
{
    Listad *L = (Listad*)malloc(sizeof(Listad));
    L->ini = L->fim = NULL;
    return L;
}

Listad* mostra_lista(Listad* L)
{
    Nod* no = NULL;

    no = L->ini;

    //printf("\nMOSTRA LISTA:\n");

    while(no != NULL)
    {
        printf("%c %d\n", no->gene, no->quantidade, no->alfa);
        no = no->prox;
    }
}
Listad* insere_fim(Listad* L, char gene, int quantidade)
{
    Nod* no = CriaNo(gene,quantidade), *anterior = NULL;

    if(L->ini == NULL)
    {
        L->ini = no;
    } else
    {
        anterior = L->fim;
        anterior->prox = no;
        no->ant = anterior;
    }

    L->fim = no;

    return L;
}

Listad* somaquant(Listad* L, char gene1, char gene2)
{
    Nod *aux = NULL;
    aux = L->ini;
    while(aux!=NULL)
    {
        if((aux->gene == gene1) || (aux->gene == gene2))
        {
            aux->quantidade++;
            if(gene1 == gene2)
            {
                aux->quantidade++;
            }
        }
        aux = aux->prox;
    }

    return L;
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

void zeraquant(Listad* L)
{
    Nod*aux = NULL;
    int count = 0;
    char gene;

        libera_lista(L);
        L->ini = NULL;
        L->fim = NULL;
        while(count < 4)
        {
            switch (count)
            {
                case 0:
                    gene = 'A';
                    insere_fim(L,gene,0);
                break;

                case 1:
                    gene = 'C';
                    insere_fim(L,gene,0);
                break;

                case 2:
                    gene = 'G';
                    insere_fim(L,gene,0);
                break;

                case 3:
                    gene = 'T';
                    insere_fim(L,gene,0);
                break;
            }
            count++;
        }
}
Nod* removeElemento(Nod **lista, int elemento)
{

    Nod *aux = NULL;
    Nod *ant = NULL;
    Nod *resposta = NULL;


	if(*lista != NULL) {

		aux = *lista;
		while((aux != NULL) && (aux->alfa != elemento)) {

			ant = aux;
			aux = aux->prox;

		}

		if(aux != NULL) {

			if(*lista != aux) {

				ant->prox = aux->prox;
			}else {

				*lista = aux->prox;

			}

			resposta = aux;

		}

		return resposta;

	}

    return NULL;
}

Nod* minimum(Nod* lista) {//Encontra o elemento com o menor valor da lista

    Nod* aux = lista;
    Nod* minimo = lista;

    while(aux != NULL) {

        if(aux->quantidade < minimo->quantidade) {

            minimo = aux;

        }else if((aux->quantidade == minimo->quantidade) && (aux->alfa < minimo->alfa)) {

        	minimo = aux;

        }

        aux = aux->prox;

    }

    return minimo;

}

Listad* sort(Listad* lista) { //retorna uma lista ordenada em ordem crescente

    Listad* aux_lista = NULL;
    Nod* aux = lista->ini;
    Nod* aux2 = lista->ini;
    Nod* min = NULL;
    int i = 0, count = 1;
    aux_lista = cria_listad();

    while (aux2->prox != NULL)
    {
        count++;
        aux2 = aux2->prox;
    }

    for(i = 0; i < count; i++) {
        min = minimum(aux);
        //printf("\n MINIMUM: %c %d %d\n",min->gene,min->quantidade, min->alfa);
        removeElemento(&aux, min->alfa);
        insere_fim(aux_lista, min->gene, min->quantidade);
        //mostra_listaaux(aux_lista);

    }

    return aux_lista;

}
