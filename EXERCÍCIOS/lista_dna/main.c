#include <stdio.h>
#include <stdlib.h>

//structs
struct no
{
    char gene;
    int qnt;
    int priori;
    struct no *prox;
};

typedef struct no No;


//funções

No* cria_no(char gene)
{
    No* novo;
    novo = (No*) malloc(sizeof(No));

//inicializar campos
    novo->prox = NULL;
    novo->qnt = 0;
    novo->gene = gene;
    if(gene == 'A')
        novo->priori = 1;
    if(gene == 'C')
        novo->priori = 2;
    if(gene == 'T')
        novo->priori = 3;
    if(gene == 'G')
        novo->priori = 4;
    return novo;
}

No* soma_gene(No*L, char gene)
{
    No* aux = L;

    if(L != NULL)
    {
        while(aux != NULL)
        {
            if(aux->gene == gene)
            {
                aux->qnt++;
            }
            aux = aux->prox;
        }
    }

}

void mostra_lista(No* L)
{
    No* aux = L;

    while (aux != NULL)
    {
        printf("%c %i\n",aux->gene, aux->qnt);
        aux = aux->prox;// (*aux).prox
    }
    printf("\n");
}

No* insere_fim(No* L, char valor)
{
    No* novo = cria_no(valor);
    No* aux = L;

    if (L == NULL)
    {
        L = novo;
    }
    else
    {
        //  for (aux = L; aux->prox != NULL; aux = aux->prox)

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return L;
}
//main

int main()
{
    No* total = cria_no('A');
    int i = 0;
    int count = 0;
    char insert[2];

    for(i=0;i<3;i++)
    {
        if(i == 0)
            total = insere_fim(total, 'T');
        if(i == 1)
            total = insere_fim(total, 'G');
        if(i == 2)
            total = insere_fim(total, 'C');
    }

    while(i != 0)
    {
        scanf("%d", &i);
        while(count < i*2)
        {
            scanf("%s", insert);
            getchar();

            soma_gene(total, insert[0]);
            count++;
        }
        mostra_lista(total);
    }
    
    return 0;
}