#include "banco.h"

int main()
{
    Conta conta[100];
    int check = 0, contas = 1, i = 0, transf = 0, benef = 0;

    while(contas == 1)
    {
        conta[i] = lerDados();
        printf("\nDeseja adicionar mais uma conta? (sim = 1): ");
        scanf("%d", &contas);
        i++;
    }
    while(check < i)
    {
        mostrarDados(conta[check]);
        check++;
    }

    check = 0;

    printf("\nDeseja fazer uma transferência? (1 = sim): ");
    scanf("%d", &check);
    while(check == 1)
    {
        i = 0;
        contas = 0;

        printf("\nDe qual conta deseja retirar o dinheiro?: ");
        scanf("%d",&transf);

        while(i < 100)
        {
            if(conta[i].num == transf)
            {
                contas++;
                transf = i;
                i = 99;
            }

            i++;
        }

        if(contas > 0)
        {
            i = 0;
            contas = 0;

            printf("\nPara qual conta deseja mandar o dinheiro?: ");
            scanf("%d",&benef);

            while(i < 100)
            {
                if(conta[i].num == benef)
                {
                    contas++;
                    benef = i;
                    i = 99;
                }

                i++;
            }

            if(contas > 0)
            {
                transferir(conta[transf].nome,conta[benef].nome,&conta[transf].saldo,&conta[benef].saldo);

                mostrarDados(conta[transf]);
                mostrarDados(conta[benef]);
            } else
            {
                printf("\nConta nao encontrada.");
            }

        } else
        {
            printf("\nConta nao encontrada.");
        }

        printf("\nDeseja fazer outra transferencia?(sim = 1): ");
        scanf("%d", &check);
    }

    return 0;
}