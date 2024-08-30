#include "biblio.h"

int main ()
{
    int tamanhoVetor = 0, newTam = 0;
    float* vetor;
    float* maior50;

    printf("Insira o tamanha do vetor: ");
    scanf("%d", &tamanhoVetor);

    vetor = cria_vet(tamanhoVetor);

    inicializarVetor(vetor,tamanhoVetor);
    armazenarVetor(vetor,tamanhoVetor);
    mostrarVetor(vetor,tamanhoVetor);
    maior50 = mostrarMaior50 (vetor,tamanhoVetor, &newTam);
    mostrarVetor(maior50,newTam);

    free(vetor);
    free(maior50);
    return 0;
}