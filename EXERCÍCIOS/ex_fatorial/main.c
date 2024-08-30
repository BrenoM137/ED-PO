#include <stdlib.h>
#include <stdio.h>

int fat(int num);

int main()
{
    int k = 0, i = 0, soma = 0, aux = 0, minus = 1;

    scanf("%d", &k);
    
    if((k == 2) || (k == 1))
    {
        i = 1;
    }else
    {
        while(soma != k)
        {
            aux = k - minus;
            if(fat(aux) < k)
            {
                soma = soma + fat(aux);
                i++;
                if(soma > k)
                {
                    i--;
                    minus++;
                    soma = soma - fat(aux);
                }
            } else
            {
                minus++;
            }
        }
    }
    

    printf("%d\n", i);

    return 0;

}

int fat(int num)
{
    int i = 0, fat = 1, aux1 = 0;

    aux1 = num;
    fat = num;

    while(num > 1)
    {
        aux1--;
        fat = fat * aux1;
        num--;
    }

    return fat;
}