#ifndef BIBLIO_H 
#define BIBLIO_H 
#include <stdio.h>
#include <stdlib.h>

void inicializarVetor (float vetor[], int tamanhoVetor);

void armazenarVetor (float vetor[], int tamanhoVetor);

void mostrarVetor (float vetor[], int tamanhoVetor);

float* mostrarMaior50 (float vetor[], int tamanhoVetor, int *newTam);

float* cria_vet (int tamanho);

#endif