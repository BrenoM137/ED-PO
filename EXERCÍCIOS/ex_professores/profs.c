#include "profs.h"

Prof Lerlista()
{
    Prof professor;

    printf("Insira o codigo: ");
    scanf("%d", &professor.cod);
    printf("Insira o sexo (F ou M): ");
    scanf("%s", professor.sexo);
    printf("Insira as horas de aulas dadas por mes: ");
    scanf("%d", &professor.hrs);
    printf("\n");

    return professor;
}

void Mostralista(Prof professor)
{
    printf("=============================================\n");
    printf("CODIGO: %d\n", professor.cod);
    printf("SEXO: %s\n", professor.sexo);
    printf("SALARIO BRUTO: %.2f\n", professor.salB);
    printf("SALARIO LIQUIDO: %.2f\n", professor.salL);
    printf("=============================================\n");
}

void Calcsal(Prof* professor)
{
    professor->salB = professor->hrs * 21.50;

    if((strcmp(professor->sexo,"M") == 0) && (professor->hrs <= 70))
    {
        professor->salL = professor->salB - (professor->salB * 0.08);
    } else
    if(((strcmp(professor->sexo,"M") == 0) && (professor->hrs > 70)))
    {
        professor->salL = professor->salB - (professor->salB * 0.10);
    } else
    if(((strcmp(professor->sexo,"F") == 0) && (professor->hrs <= 70)))
    {
        professor->salL = professor->salB - (professor->salB * 0.05);
    } else
    if(((strcmp(professor->sexo,"F") == 0) && (professor->hrs > 70)))
    {
        professor->salL = professor->salB - (professor->salB * 0.07);
    }

}