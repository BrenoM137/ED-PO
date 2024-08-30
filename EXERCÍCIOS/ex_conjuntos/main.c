#include <stdio.h>
#include <stdlib.h>

struct conjunto
{
    int info;
    struct conjunto* prox;
};

typedef struct conjunto Conj;

Conj* RecebeConj(int valor, Conj* conjunto);
Conj* CriaNo(int valor);
Conj* Inter(Conj* conjunto1, Conj* conjunto2);
Conj* Uniao(Conj* conjunto1, Conj* conjunto2);
Conj* remove_elemento(Conj** end_L, int elemento);
Conj* remove_repetido(Conj* L);
Conj *Crescente(Conj*L);
void libera_lista(Conj *L);
void mostra_lista(Conj* conjunto);

int main()
{
    int tamanho1 = 0, tamanho2 = 0, count = 0, valor = 0;
    Conj* Uconjunto1 = NULL;
    Conj* Uconjunto2 = NULL;
    Conj* Iconjunto1 = NULL;
    Conj* Iconjunto2 = NULL;
    Conj* inter = NULL;
    Conj* uniao = NULL;

    //printf("Insere tamanho 1: ");
    scanf("%d", &tamanho1);
    //printf("Insere tamanho 2: ");
    scanf("%d", &tamanho2);

    while (count < tamanho1)
    {
        //printf("Insere %d valor: ", count+1);
        scanf("%d", &valor);
        Uconjunto1 = RecebeConj(valor, Uconjunto1);
        Iconjunto1 = RecebeConj(valor, Iconjunto1);     
        count++;
    }

    count = 0;

    while (count < tamanho2)
    {
        //printf("Insere %d valor: ", count+1);
        scanf("%d", &valor);
        Uconjunto2 = RecebeConj(valor, Uconjunto2);  
        Iconjunto2 = RecebeConj(valor, Iconjunto2);  
        count++;
    }

    uniao = Uniao(Uconjunto1,Uconjunto2);
    inter = Inter(Iconjunto1,Iconjunto2);

    mostra_lista(inter);
    printf("\n");
    mostra_lista(uniao);

    libera_lista(Uconjunto1);
    libera_lista(Uconjunto2);
    libera_lista(Iconjunto1);
    libera_lista(Iconjunto2);
    libera_lista(inter);
    libera_lista(uniao);

    printf("\n");

    return 0;
}

Conj* CriaNo(int valor)
{
    Conj *novo = NULL;
    novo = (Conj*) malloc(sizeof(Conj));

    novo->prox = NULL;
    novo->info = valor;
    
    return novo;
}

Conj* RecebeConj(int valor, Conj* conjunto)
{
    int count = 0;
    
    Conj* novo = CriaNo(valor);
    Conj* aux = conjunto;

    if(conjunto == NULL)
    {
        conjunto = novo;
    } else
    {
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    return conjunto;
}

Conj* Inter(Conj* conjunto1, Conj* conjunto2)
{
    Conj* novo = conjunto2;
    Conj* aux1 = conjunto1;
    Conj* aux2 = conjunto2;
    Conj* inter = NULL;

    if(conjunto1 == NULL)
    {
        conjunto1 = novo;
    } else
    {
        while(aux1->prox != NULL)
        {
            while(aux2->prox != NULL)
            {
                if(aux1->info == aux2->info)
                {
                    inter = RecebeConj(aux1->info, inter);

                }

                aux2 = aux2->prox;

                if(aux2->prox == NULL)
                {
                    if(aux1->info == aux2->info)
                    {
                        inter = RecebeConj(aux1->info, inter);

                    }
                }
            }

            aux2 = conjunto2;

            aux1 = aux1->prox;
            

            if(aux1->prox == NULL)
            {
                while(aux2->prox != NULL)
                {
                    if(aux1->info == aux2->info)
                    {
                        inter = RecebeConj(aux1->info, inter);
                    }

                    aux2 = aux2->prox;

                }                
            }
            
        }
        aux1->prox = novo;

    }
    return inter;
}

Conj* Uniao(Conj* conjunto1, Conj* conjunto2)
{
    Conj* aux1 = conjunto1;
    Conj* aux2 = conjunto2;
    Conj* une = NULL;

    while(aux1 != NULL)
    {
        une = RecebeConj(aux1->info,une);
        aux1=aux1->prox;
    }
    while(aux2 != NULL)
    {
        une = RecebeConj(aux2->info,une);
        aux2=aux2->prox;
    }

    une = Crescente(une);
    remove_repetido(une);

    return une;
}

void mostra_lista(Conj* conjunto)
{
    //printf("\nMOSTRA LISTA: \n");
    Conj *aux = conjunto;

    while(aux != NULL)
    {
        printf("%d ",aux->info);
        aux = aux->prox;
    }
}

void libera_lista(Conj *L)
{
    Conj *aux = L;
    while (aux != NULL) 
    {
        L = L->prox;
        free(aux);
        aux = L;
    }
}

Conj* remove_elemento(Conj** end_L, int elemento)
{
    Conj *aux, *anterior=NULL, *resposta = NULL;
    if (*end_L != NULL)
    {
        aux = *end_L;
        while ((aux != NULL) && (aux->info != elemento))
        {
            anterior = aux;
            aux = aux->prox;
        }
        if (aux != NULL)
        {
            if(*end_L != aux)
                anterior->prox = aux->prox;
            else
                *end_L=aux->prox;
        }
        resposta = aux;
    }
    return resposta;
}

Conj* remove_repetido(Conj* L)
{
    Conj*ant, *atual, *proximo;

    for(atual = L;atual != NULL; atual = atual->prox)
    {
        ant = NULL;

        for(proximo = atual->prox; proximo != NULL;)
        {
            if(atual->info == proximo->info)
            {
                if(ant == NULL)
                    atual->prox = proximo->prox;
                    else
                    ant->prox;
                Conj*remover = proximo;
                proximo = proximo->prox;
                free(remover);
            }
            else
            {
                ant = proximo;
                proximo = proximo->prox;
            }
        }
    }

    return L;
}

Conj *Crescente(Conj*L)
{
    Conj *aux1 = L;
    Conj *aux2 = L;
    int aux3 = 0;

    while(aux1->prox != NULL)
    {
        while(aux2->prox != NULL)
        {
            if(aux2->info > aux2->prox->info)
            {
                aux3 = aux2->prox->info;
                aux2->prox->info = aux2->info;
                aux2->info = aux3;
            }
            aux2 = aux2->prox;
        }
        aux2 = L;
        aux1 = aux1->prox;
    }

    return L;
}