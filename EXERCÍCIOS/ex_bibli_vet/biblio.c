#include "biblio.h"

void inicializarVetor (float vetor[], int tamanhoVetor)
{
    int i=0;
    for (i=0; i<tamanhoVetor;i++)
        vetor[i]=0;
}

void armazenarVetor (float vetor[], int tamanhoVetor)
{
    int i=0;
    for (i=0; i<tamanhoVetor;i++)
    {
        printf("Informe o numero do espaco %i do vetor: ", i+1);
        scanf("%f",&vetor[i]);
    } 
}

void mostrarVetor (float vetor[], int tamanhoVetor)
{
    int i=0;
    for(i=0;i<tamanhoVetor;i++)
        printf("Vetor %i = %.2f\n",i+1,vetor[i]);
}

float* mostrarMaior50 (float vetor[], int tamanhoVetor, int *newTam)
{
    int i=0, count=0;
    float* newVet;

    for(i=0;i<tamanhoVetor;i++)
    {
        if(vetor[i] > 50)
        {
            count++;
        }
    }

    newVet = cria_vet(count);

    count = 0;

    for(i=0;i<tamanhoVetor;i++)
    {
        if(vetor[i] > 50)
        {
            newVet[count] = vetor[i];
       //     printf("%dº numero maior que 50: %.2f", count+1, newVet[count]);
            count++;
        }
    }

   // free(newVet);
   *newTam = count;
   return newVet;
}

float* cria_vet (int tamanho)
{
    float* vet;

    vet = (float*) malloc(tamanho*(sizeof(float)));
    
    return vet;
}