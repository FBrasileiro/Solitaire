#ifndef CARTAS_H
#define CARTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaseq.h"

using namespace std;

Lista *criar_cartas()
{
    Lista *cartas = criar_lista();
    int valor;
    char tipo[] = {'e', 'o', 'p', 'c'};

    for (int j = 0; j < 4; j++)
    {
        for (int i = 1; i <= 13; i++)
        {
            inserir_fim_lista(cartas, i, tipo[j], (j % 2 ? 'v' : 'p'));
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
    l->cont--;
    return carta;
}

#endif