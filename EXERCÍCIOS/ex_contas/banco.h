#ifndef BANCO_H
#define BANCO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct containfo
{
    int num;
    char nome[50];
    float saldo;
};

typedef struct containfo Conta;

Conta lerDados();
void mostrarDados(Conta mostraConta);
void transferir(char* contaTransf, char* contaBenef, float* saldoTransf, float* saldoBenef);

#endif