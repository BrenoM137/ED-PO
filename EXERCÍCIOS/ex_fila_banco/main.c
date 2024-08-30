#include <stdio.h>
#include <stdlib.h>

//PROTOTIPO
struct nod
{
    int entrada;
    int atendimento;
    int espera;
    struct nod *ant;
    struct nod *prox;
};
typedef struct nod Nod;

struct caixa
{
    int atendendo;
    struct caixa *ant;
    struct caixa *prox;
};
typedef struct caixa Nodc;

struct fila
{
    Nod *ini;
    Nod *fim;
};
typedef struct fila Fila;

struct filac
{
    Nodc *ini;
    Nodc *fim;
};
typedef struct filac Filac;

Fila* cria_listad();
Filac* cria_filac();
void mostra_listad(Fila* L);
void mostra_listac(Filac* L);
Nodc* cria_caixa();
int Min_Fila(Filac* L);
Filac* insere_caixa(Filac* L);
Nod* cria_nod(int valor1, int valor2);
Fila* insere_fim_listad(Fila* L, int valor1, int valor2);
int remove_inicio_listad(Fila *L);
Fila* cria_fila();
Fila* enqueue(Fila *f, int elemento1, int elemento2);
int dequeue(Fila *f);
int eh_vazia_fila(Fila *f);
int Acha_Zero (Filac* L);
int preenche_caixa(Filac* L, Fila* C, int dif);
void remove_from_all(Filac* L,int valor);
//FIM PROTOTIPO

//MAIN-----------------------------------------------------------------------------------
int main()
{
    Fila* clientes = cria_fila();
    Filac* caixas = cria_filac();
    Nod *frente = NULL, *ant = NULL;
    Nodc* aux = NULL;
    int D = 0, C = 0, N = 0, T = 0, count = 0, result = 0, last = 0, dif = 0;

    scanf("%d%d",&C,&N);

    while(count < C)
    {
        caixas = insere_caixa(caixas);
        count++;
    }

    count = 0;


    //printf("\nC = %d, N = %d\n", C, N);
    //printf("\nvazia: %d\n",eh_vazia_fila(clientes));

    while(count < N)
    {

        scanf("%d%d", &T, &D);

        //printf("\nT = %d, D = %d\n", T, D);
        clientes = enqueue(clientes,T, D);
        //printf("\nvazia: %d\n",eh_vazia_fila(clientes));
        count++;
    }

    //mostra_listac(caixas);
    //mostra_listad(clientes);

    count = 0;
    while(eh_vazia_fila(clientes) != 1)
    {
        aux = caixas->ini;

        //printf("\nespera antes = %d\n",clientes->ini->espera);
        preenche_caixa(caixas, clientes, dif);

        dif = clientes->ini->entrada;

        if(clientes->ini->espera < 0)
        {
            clientes->ini->espera = 0;
        }

        printf("\nespera depois = %d\n",clientes->ini->espera);

        if(clientes->ini->espera > 20)
        {
            result++;
        }
        dequeue(clientes);
        if(clientes->ini != NULL)
        {
            dif = clientes->ini->entrada - dif;
            printf("\ndif = %d\n",dif);
        }
    }

    printf("%d\n", result);
    free(clientes);
    free(caixas);

    return 0;
}
//FIM MAIN

//FUN��ES
int preenche_caixa(Filac* L, Fila* C, int dif)
{
    Nodc *aux = NULL;
    Nod *aux2 = NULL;
    int insert = 0, espera = 0;
    
    if(L != NULL)
    {
        aux2 = C->ini;
        aux = L->ini;

        if(Acha_Zero(L) > 0)
        {
            while(aux != NULL)
            {
                if((aux->atendendo == 0) && (insert == 0))
                {
                    aux->atendendo = aux2->atendimento;
                    insert++;
                }
                aux = aux->prox;
            }
        } else
        {
            remove_from_all(L,dif);
            aux = L->ini;
            while(aux != NULL)
            {
                if((aux->atendendo == Min_Fila(L)) && (insert == 0))
                {
                    aux2->espera = aux->atendendo;
                    aux->atendendo = aux2->atendimento;
                    insert++;
                }
                aux = aux->prox;
            }
        }
    }

    return espera;
}

void remove_from_all(Filac* L,int valor)
{
    Nodc *aux = NULL;
    aux = L->ini;

    while(aux != NULL)
    {
        aux->atendendo = aux->atendendo - valor;
        if(aux->atendendo < 0)
        {
            aux->atendendo = 0;
        }
        aux = aux->prox;
    }
}

int Min_Fila(Filac* L)
{
    Nodc* aux = NULL;
    int menor = -1;

    if(L != NULL)
    {
        aux = L->ini;

        while(aux != NULL)
        {
          if(aux == L->ini)
          {
            menor = aux->atendendo;
          } else
          {
              if(menor > aux->atendendo)
              {
                  menor = aux->atendendo;
              }
          }

            aux = aux->prox;
        }
    }
    return menor;
}

int Acha_Zero (Filac* L)
{
    Nodc* aux = NULL;
    int zeros = 0;

    if(L != NULL)
    {
        aux = L->ini;

        while(aux != NULL)
        {
            if(aux->atendendo == 0)
            {
                zeros++;
            }
            aux = aux->prox;
        }
    }
    return zeros;
}

void mostra_listad(Fila* L)
{
    Nod* aux = NULL;
    aux = L->ini;
    while(aux != NULL)
    {
        printf("\n%d %d %d\n", aux->atendimento,aux->entrada, aux->espera);
        aux = aux->prox;
    }

}

void mostra_listac(Filac* L)
{
    Nodc* aux = NULL;
    aux = L->ini;
    while(aux != NULL)
    {
        printf(" %d ", aux->atendendo);
        aux = aux->prox;
    }

}


Fila* cria_listad()
{
    Fila* novalista;
    novalista = (Fila *)malloc(sizeof(Fila));
    novalista->ini = novalista->fim = NULL;
    return novalista;
}
Filac* cria_filac()
{
    Filac* novalista;
    novalista = (Filac *)malloc(sizeof(Filac));
    novalista->ini = novalista->fim = NULL;
    return novalista;
}

Filac* insere_caixa(Filac* L)
{
    Nodc *novo = cria_caixa();

    if (L == NULL)
    {
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
            novo->ant = L->fim;
            L->fim->prox = novo;
            L->fim = novo;
        }
    }
    return L;
}

Nodc* cria_caixa()
{
    Nodc* novo = (Nodc*)malloc(sizeof(Nodc));
    novo->ant = novo->prox = NULL;
    novo->atendendo = 0;
    return novo;
}


Nod* cria_nod(int valor1, int valor2)
{
    Nod* novo = (Nod*)malloc(sizeof(Nod));
    novo->ant = novo->prox = NULL;
    novo->entrada = valor1;
    novo->atendimento = valor2;
    novo->espera = 0;
    return novo;
}

Fila* insere_fim_listad(Fila* L, int valor1, int valor2)
{
    Nod *novo = cria_nod(valor1, valor2);

    if (L == NULL)
    {
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
            novo->ant = L->fim;
            L->fim->prox = novo;
            L->fim = novo;
        }
    }
    return L;
}

Fila* cria_fila()
{
    return cria_listad();
}

Fila* enqueue(Fila *f, int elemento1, int elemento2)
{
    return insere_fim_listad(f, elemento1, elemento2);
}
int dequeue(Fila *f)
{
    return remove_inicio_listad(f);
}

int eh_vazia_fila(Fila *f)
{
    if((f->ini != NULL) && (f->fim != NULL))
    {
        return 0;
    } else
    {
        return 1;
    }
}

int remove_inicio_listad(Fila *L)
{
    Nod* aux;
    int resposta = -1;//quando nao tem nada pra remover
    if (L!=NULL)
        if (L->ini != NULL)
        {
            aux = L->ini;

            if (L->ini != L->fim)
            {
                L->ini->prox->ant = NULL;
                L->ini = L->ini->prox;
            }
            else
                L->ini = L->fim = NULL;

            resposta = aux->entrada;
            free(aux);
        }
    return resposta;
}
//FIM FUN��ES
