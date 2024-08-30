#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n, int *recursao);

int main ()
{
    int n = 0, r = 0, size = 0, count = 0;
    scanf("%d", &size);
    while(count < size)
    {

        scanf("%d", &n);
        printf("fib(%d) = %d, ", n, fibonacci(n, &r));
        printf("fazendo %d chamadas\n", r-1);
        r = 0;
        count++;
    }
    return 0;
}

int fibonacci(int n, int *recursao)
{
    *recursao = *recursao + 1;
    if(n == 0)
    {
        return 0;
    } else
    {
        if(n == 1)
        {
            return 1;
        } else
        {
            return (fibonacci(n-1, recursao) + fibonacci(n-2, recursao));
        }
    }
}