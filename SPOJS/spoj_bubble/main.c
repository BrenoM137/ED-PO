#include <stdio.h>
#include <stdlib.h>

void sort(int intercambio[], int N, int M);

int main()
{
    int N = -1, M = -1;

    do
    {
        scanf("%i", &N);
        scanf("%i", &M);

        if (N != 0 && M != 0) {
            int* intercambio = malloc(M * sizeof(int));

            for (int i = M - 1; i >= 0; i--)
            {
                scanf("%i", &intercambio[i]);
            }

            sort(intercambio, N, M);
            printf("\n");

            free(intercambio);
        }

    } while (N != 0 && M != 0);

    return 0;
}

void sort(int intercambio[], int N, int M)
{
    int count = M, aux = 0, flag = 0, indice = 0;
    int* vetor = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        vetor[i] = i + 1;
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            if (vetor[j] == count)
            {
                indice = j;

                while (flag < intercambio[i])
                {
                    aux = vetor[indice];
                    vetor[indice] = vetor[indice + 1];
                    vetor[indice + 1] = aux;

                    flag++;
                    indice++;
                }
            }
        }

        count--;
        flag = 0;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%i ", vetor[i]);
    }

    free(vetor);
}