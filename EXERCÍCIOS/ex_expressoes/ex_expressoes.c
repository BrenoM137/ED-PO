#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pilha
{
    char info;
    int abre;
    int qual;
    struct pilha *prox;
};

typedef struct pilha Pilha;

Pilha* cria_no(char valor)
{
    Pilha* novo;
    novo = (Pilha*) malloc(sizeof(Pilha));

//inicializar campos
    novo->prox = NULL;
    novo->info = valor;

    switch (valor)
    {
        case '(':
            novo->abre = 1;
            novo->qual = 1;
        break;

        case '[':
            novo->abre = 1;
            novo->qual = 2;
        break;

        case '{':
            novo->abre = 1;
            novo->qual = 3;
        break;

        case ')':
            novo->abre = 0;
            novo->qual = 1;
        break;

        case ']':
            novo->abre = 0;
            novo->qual = 2;
        break;

        case '}':
            novo->abre = 0;
            novo->qual = 3;
        break;

        }

    return novo;
}

void mostrarPilha(Pilha* p) {

    Pilha *aux = p; //criando uma vaiavel auxiliar ponteiro do tipo nó que recebe o primeiro ponteiro da lista.
    printf("\nLISTA: \n");
    while (aux != NULL) { //enquano o auxiliar for diferente de NULL.

        printf("%c\n", aux->info); //printar a informação contida na variavel auxiliar.
        aux = aux->prox; //a variavel auxiliar recebe o ponteiro do proximo da lista.

    }

}

Pilha* insere_inicio(Pilha *L, char valor)
{
    Pilha* nuevo = cria_no(valor);
    if (L != NULL)
    {
        nuevo->prox = L;
    } else
    {
        nuevo = cria_no(valor);
        nuevo->prox = L;
        L = nuevo;
    }
    return nuevo;
}

int remove_inicio(Pilha** L)
{
    Pilha* aux = *L;

    if (*L != NULL)
    {
        if(aux->prox != NULL)
        {
            *L = aux->prox;
            free(aux);
        } else
        {
            *L = NULL;
        }
    }
}

Pilha* cria_pilha()
{
    Pilha *p = NULL;
    return p;
}

Pilha* push(Pilha *p, char elemento)
{
   return(insere_inicio(p, elemento));
}

int eh_vazia_pilha(Pilha *p)
{
    if (p == NULL)
        return 1; //pilha esta vazia
    else
        return 0; //a pilha tem valores
}

//versao 1
int pop(Pilha **p)
{
    Pilha *pont = *p;
    int resposta = -1;
    if (eh_vazia_pilha(*p) == 0)
        resposta = remove_inicio(&pont);// ou poderia ser remove_inicio(&(*p));
    return resposta;
}
/*
versao 2
Pilha* pop(Pilha *p, int *reposta)
{
    *resposta = -1;
    if (!eh_vazia_pilha(p))
        *resposta = remove_inicio(&p);
    return p;
}
*/

Pilha* top(Pilha *p)
{
    return p;
}

int main()
{
    int T = 0, count = 0, check = 0;
    char exp, result;
    Pilha* aberto = cria_pilha(), *fechado = cria_pilha(), *no = NULL;

    //printf("Insira o tamanho T: ");
    scanf("%d", &T);
    getchar();
    while (count < T)
    {
        do
        {
            scanf("%c", &exp);

            //printf("saiu: %c\n", exp);

            if((exp != '\n') && (check == 0))
            {

                no = cria_no(exp);
                //printf("\n%c %i %i\n", no->info, no->abre, no->qual);
                if(no->abre == 1)
                {
                    aberto = push(aberto, exp);
                    //mostrarPilha(aberto);
                } else
                {
                    fechado = push(fechado,exp);
                    //mostrarPilha(fechado);

                    if(eh_vazia_pilha(aberto) == 0)
                    {
                        //mostrarPilha(fechado);
                        //mostrarPilha(aberto);
                        if(top(aberto)->qual == top(fechado)->qual)
                        {
                            remove_inicio(&aberto);
                            remove_inicio(&fechado);
                        }
                    } else
                    {
                        check = 1;
                    }

                    //printf("\n%d %d\n", eh_vazia_pilha(aberto),eh_vazia_pilha(fechado));
                }

            }

        }while(exp != '\n');

        if((eh_vazia_pilha(aberto) != 1) || (eh_vazia_pilha(fechado) != 1))
        {
            printf("N\n");
        } else
        {
            printf("S\n");
        }
        //remove_inicio(&fechado);

        //printf("\n%d %d\n", eh_vazia_pilha(aberto),eh_vazia_pilha(fechado));
        while(aberto != NULL)
        {
            remove_inicio(&aberto);
        }
        while(fechado != NULL)
        {
            remove_inicio(&fechado);
        }
        //printf("\n%d %d\n", eh_vazia_pilha(aberto),eh_vazia_pilha(fechado));


        check = 0;
        count++;
    }

    return 0;
}

