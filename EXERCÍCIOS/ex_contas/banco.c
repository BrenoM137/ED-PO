#include "banco.h"

Conta lerDados()
{
    Conta lerConta;

    printf("\nDigite o numero da sua conta: ");
    scanf("%d",&lerConta.num);

    printf("Digite o nome da sua conta: ");
    scanf("%s",lerConta.nome);

    printf("Digite o saldo da conta: ");
    scanf("%f",&lerConta.saldo);

    return lerConta;
}

void mostrarDados(Conta mostraConta)
{
    printf("\n===========================================\n");
    printf("NUMERO DA CONTA: %d\n", mostraConta.num);
    printf("NOME DA CONTA: %s\n", mostraConta.nome);
    printf("SALDO DA CONTA: %.2f\n", mostraConta.saldo);
    printf("===========================================");
}

void transferir(char* contaTransf, char* contaBenef, float* saldoTransf, float* saldoBenef)
{
    float transf = 0, newSaldoTransf = 0, newSaldoBenef = 0;

    printf("\nQuanto sera transferido? (conta %s para conta %s): ", contaTransf, contaBenef);
    scanf("%f", &transf);

    newSaldoTransf = *saldoTransf - transf;
    newSaldoBenef = *saldoBenef + transf;

    *saldoBenef = newSaldoBenef;
    *saldoTransf = newSaldoTransf;

}
