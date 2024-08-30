#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct relogio
{
    int horas;
    int minutos;
    int segundos;
};

typedef struct relogio Relogio;

Relogio IncrementaSegundos(Relogio  relogio);
Relogio MostraRelogio(Relogio  relogio);

int main()
{
    Relogio MeuRelogio;
    
    MeuRelogio.horas = 0;
    MeuRelogio.minutos = 0;
    MeuRelogio.segundos = 0;

    while (1)
    {
        system("clear"); //Limpar tela
        MeuRelogio = IncrementaSegundos(MeuRelogio);
        printf("                  +------+  \n");
        printf("                 /        \\  \n");
        printf("                |          |  \n");         
        printf("Meu Relogio:    | ");
        MostraRelogio(MeuRelogio); 
        printf(" |  \n");
        printf("                |          |  \n");         
        printf("                 \\        /  \n");  
        printf("                  +------+  \n");       
        sleep(1); 
    } 

}

Relogio IncrementaSegundos(Relogio  relogio)
{
    if(relogio.segundos<59)
    {
        relogio.segundos++;
    } else
    {
        relogio.segundos = 0;

        if(relogio.minutos < 59)
        {
            relogio.minutos++;
        } else
        {
            relogio.minutos = 0;
            relogio.horas++;
        }
    }

    return relogio;
}


Relogio MostraRelogio(Relogio  relogio)
{
    printf("%d:%d:%d",relogio.horas,relogio.minutos,relogio.segundos);
}

