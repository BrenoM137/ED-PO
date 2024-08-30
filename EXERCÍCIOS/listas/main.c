#include "listasimples.h"
#include "listadupla.h"
#include "listacircular.h"

int main()
{
    int resposta;
    No* L = cria_no(20);
    Listad *LD = cria_listad();

    L = insere_inicio(L, 10);
    L = insere_fim(L,5);

    resposta = remove_inicio(&L);
    printf("%d ", resposta);

    LD = insere_inicio_listad(LD, 34);
    LD = insere_fim_listad(LD,22);

    resposta = remove_inicio_listad(LD);
    printf("%d ", resposta);

        return 0;
}
