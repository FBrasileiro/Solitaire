#ifndef CARTAS_H
#define CARTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaseq.h"

Lista *criar_cartas()
{
    Lista *cartas = criar_lista();
    char carta[4];
    char *numeros[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    char *tipo[] = {"e", "o", "c", "p"};
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 13; i++)
        {
            strcpy(carta, numeros[i]);
            strcat(carta, tipo[j]);
            inserir_fim_lista(cartas, carta);
        }
    }
    return cartas;
}

void swap(Lista *l, int i, int j)
{
    CARTAS aux = l->dados[i];

    l->dados[i] = l->dados[j];
    l->dados[j] = aux;
}

int shuffle(Lista *l, int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int j = i + (rand() % (52 - i));
        swap(l, i, j);
    }
    return 0;
}

CARTAS retirar_topo(Lista *l)
{
    CARTAS carta = l->dados[l->ini];
    l->ini++;
    return carta;
}

#endif