#include "profs.h"

int main()
{
    Prof profs[10];
    int count = 0;

    while(count < 10)
    {
        profs[count] = Lerlista();
        count++;
    }

    count = 0;

    while(count < 10)
    {
        Calcsal(&profs[count]);
        count++;
    }

    count = 0;

    while(count < 10)
    {
        Mostralista(profs[count]);
        count++;
    }

    return 0;
}