#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//prototipação

struct time
{
    char letra;  //letra que representa o time. A letra vai de A a P

    char nome[30];   //nome do time (país). Por exemplo: BRASIL.

    int  continente;   //Continente do país. 1: AMERICA; 2: EUROPA; 3: AFRICA; 4: ASIA; 5: OCEANIA.

    int qtde_partidas;   //quantidade de partidas realizadas na Fase Final. De 1 a 4.

    int gols_a_favor;   //todos os gols realizados pela equipe na Fase Final.

    int gols_contra;    //todos os gols que a equipe sofreu na Fase Final.

    int saldo_gols;    // gols a favor – gols contra strcmp(&VetorTstrcmp(&VetorTimes[1].letra,&VetorPartidas[1].time1);imes[1].letra,&VetorPartidas[1].time1);na Fase Final.
};

typedef struct time Time;

struct partida
{
    int codigo;   //código da partida. Por exemplo: 3, significa a partida entre E e F nas oitavas de final.

    char time1;  //letra do time 1. Por exemplo E.

    char time2;  //letra do time 2. Por exemplo F.

    int gols_time1;   //a quantidade de gols que o time 1 realizou na partida.

    int gols_time2;   //a quantidade de gols que o time 2 realizou na partida.
};

typedef struct partida Partida;

void MostraStructTIME(Time VetorTimes[], int tamanho);

void InicializaTimes(Time VetorTimes[], int tamanho);

void InicializaPartidas(Partida VetorPartidas[], int tamanho);

void ReceberTimes(Time VetorTimes[], int tamanho);

void ReceberPartidas(Partida VetorPartidas[], int tam_part,Time VetorTimes[], int tam_times);

Time MelhorSaldoGols(Time VetorTimes[], int tamanho);

Time PiorSaldoGols(Time VetorTimes[], int tamanho);

Time MelhorClassificadoContinente(Partida VetorPartidas[], int tam_part, Time VetorTimes[], int tam_times, int continente);

//main

int main()
{
    int tam_partidas = 40, tam_times = 40, continente = 0;
    Partida partidas[tam_partidas];
    Time times[tam_times];

    while(continente < 6)
    {
        MelhorClassificadoContinente(partidas,tam_partidas,times,tam_times,continente);
        continente++;
    }

    MostraStructTIME(times,tam_times);

    return 0;
}

//funções

void MostraStructTIME(Time VetorTimes[], int tamanho)
{
    int i = 0;
    for (i = 0; i < tamanho; i++)
    {
        printf("\nLETRA TIME %d: %c\n",i+1, VetorTimes[i].letra);
        printf("\nNOME TIME %d: %s\n",i+1, VetorTimes[i].nome);
        printf("\nCONTINENTE TIME %d: %d\n",i+1, VetorTimes[i].continente);
        printf("\nPARTIDAS TIME %d: %d\n",i+1, VetorTimes[i].qtde_partidas);
        printf("\nGOLS TIME %d: %d\n",i+1, VetorTimes[i].gols_a_favor);
        printf("\nCONTRA TIME %d: %d\n",i+1, VetorTimes[i].gols_contra);
        printf("\nSALDO TIME %d: %d\n",i+1, VetorTimes[i].saldo_gols);
    }
    
}

void InicializaTimes(Time VetorTimes[], int tamanho)
{
    int i = 0;

    while(i < tamanho)
    {
        VetorTimes[i].continente = 0;
        VetorTimes[i].qtde_partidas = 0;
        VetorTimes[i].gols_a_favor = 0;
        VetorTimes[i].gols_contra = 0;
        VetorTimes[i].saldo_gols = 0;

        i++;
    }
}

void InicializaPartidas(Partida VetorPartidas[], int tamanho)
{
    int i = 0;

    while(i < tamanho)
    {
        VetorPartidas[i].codigo = 0;
        VetorPartidas[i].gols_time1 = 0;
        VetorPartidas[i].gols_time2 = 0;

        i++;
    }  
}

void ReceberTimes(Time VetorTimes[], int tamanho)
{
    int i = 0, n = 0;

    scanf("%d", &n);

    while(i < n)
    
    {
        getchar();
        //printf("\nEntre com a letra do time %d: ", i);
        scanf("%c", &VetorTimes[i].letra);
        //printf("\nEntre com o nome do time %d: ", i);
        getchar();
        fgets(VetorTimes[i].nome,30,stdin);
        //printf("\nEntre com o continente do time %d (1: AMERICA, 2: EUROPA, 3: AFRICA, 4: ASIA, 5: OCEANIA): ", i);
        scanf("%d", &VetorTimes[i].continente);
        i++;
    }
}

void ReceberPartidas(Partida VetorPartidas[], int tam_part,Time VetorTimes[], int tam_times)
{
    int i = 0, change = 0, m = 0;

    scanf("%d", &m);

    for(i=0;i<m;i++)
    {
        scanf("%d", &VetorPartidas[i].codigo);
        getchar();
        scanf("%c", &VetorPartidas[i].time1);
        getchar();
        scanf("%c", &VetorPartidas[i].time2);
        scanf("%d", &VetorPartidas[i].gols_time1);
        scanf("%d", &VetorPartidas[i].gols_time2);


            for(change = 0;change < tam_times; change++)
            {

                    if(VetorTimes[change].letra == VetorPartidas[i].time1)
                    {
                        VetorTimes[change].gols_a_favor = VetorPartidas[i].gols_time1;
                        VetorTimes[change].gols_contra = VetorPartidas[i].gols_time2;
                        VetorTimes[change].saldo_gols = VetorTimes[change].saldo_gols + (VetorTimes[change].gols_a_favor - VetorTimes[change].gols_contra);
                        VetorTimes[change].qtde_partidas++;
                    } else
                    {
                        if(VetorTimes[change].letra == VetorPartidas[i].time2)
                        {
                            VetorTimes[change].gols_a_favor = VetorPartidas[i].gols_time2;
                            VetorTimes[change].gols_contra = VetorPartidas[i].gols_time1;
                            VetorTimes[change].saldo_gols = VetorTimes[change].saldo_gols + (VetorTimes[change].gols_a_favor - VetorTimes[change].gols_contra);
                            VetorTimes[change].qtde_partidas++;
                        } 
                    }
            }

    }
}

Time MelhorSaldoGols(Time VetorTimes[], int tamanho)
{
    int i = 0, maior = 0, aux = 0;

    while(i < tamanho)
    {
        if (i == 0)
        {
            maior = VetorTimes[i].saldo_gols;
        }

        if(maior > VetorTimes[i].saldo_gols)
        {
            maior = VetorTimes[i].saldo_gols;
            aux = i;
        }

        i++;
    }

    return VetorTimes[aux];
}

Time PiorSaldoGols(Time VetorTimes[], int tamanho)
{
    int i = 0, menor = 0, aux = 0;

    while(i < tamanho)
    {
        if (i == 0)
        {
            menor = VetorTimes[i].saldo_gols;
        }

        if(menor > VetorTimes[i].saldo_gols)
        {
            menor = VetorTimes[i].saldo_gols;
            aux = i;
        }

        i++;
    }

    return VetorTimes[aux];
}

Time MelhorClassificadoContinente(Partida VetorPartidas[], int tam_part, Time VetorTimes[], int tam_times, int continente)
{
    int melhor = 0, count = 0, i = 0, aux = 0;
    Time foda;
    Time nao;

    if(continente == 0)
    {

        InicializaPartidas(VetorPartidas,tam_part);
        InicializaTimes(VetorTimes,tam_times);

        ReceberTimes(VetorTimes,tam_times);
        ReceberPartidas(VetorPartidas,tam_part,VetorTimes,tam_times);

        foda = MelhorSaldoGols(VetorTimes,tam_times);
        nao = PiorSaldoGols(VetorTimes,tam_times);

        printf("%c\n",foda.letra);
        printf("%c\n",nao.letra);
    } else
    {
        while(count<tam_times)
        {
            if(VetorTimes[count].continente == continente)
            {
                if(aux == 0)
                {
                    melhor = VetorTimes[count].saldo_gols;
                    aux++;
                    i = count;
                } else
                {
                    if(melhor < VetorTimes[count].saldo_gols)
                    {
                        melhor = VetorTimes[count].saldo_gols;
                        i = count;
                    }
                }
            }

            count++;
        }

        printf("%d:%c\n",continente,VetorTimes[i].letra);
        
        
    }

}