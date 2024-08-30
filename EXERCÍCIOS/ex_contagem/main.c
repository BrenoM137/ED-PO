#include <stdio.h>
#include <stdlib.h>

int main()
{
    int soma = 0, count = 0, somaresult = 1;

    scanf("%d", &soma);

    while(count < 20)
    {
        if(count < 19)
        {
            printf("%d,", somaresult);
        } else
        {
            printf("%d.\n", somaresult);
        }

        somaresult = somaresult + soma;
        count++;
    }
    
    return 0;
}