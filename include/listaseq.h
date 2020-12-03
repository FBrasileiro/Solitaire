#ifndef LISTASEQ_H
#define LISTASEQ_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string>

typedef struct
{
    short visivel;
    int valor;
    char tipo; // e, c, p, o
    char cor;  // P ou V

} CARTAS;

using namespace std;

#define MAX 54

typedef struct
{
    int cont;
    int ini;
    CARTAS dados[MAX];
} Lista;

Lista *criar_lista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l != NULL)
    {
        l->cont = 0;
        l->ini = 0;
    }
    return l;
}

int lista_esta_vazia(Lista *l)
{
    if (l == NULL)
        return -1;
    return l->cont == 0;
}

int lista_esta_cheia(Lista *l)
{
    if (l == NULL)
        return -1;
    return l->cont == MAX;
}

int inserir_inicio_lista(Lista *l, int valor, char tipo, char cor)
{
    CARTAS cartas;
    cartas.valor = valor;
    cartas.tipo = tipo;
    cartas.cor = cor;
    cartas.visivel = 0;
    if (l == NULL)
        return 0;
    if (lista_esta_cheia(l))
        return 0;
    for (int i = l->cont - 1; i >= 0; i--)
    {
        l->dados[i + 1] = l->dados[i];
    }
    l->dados[0] = cartas;
    l->cont++;
    return 1;
}

int inserir_meio_lista(Lista *l, int valor, char tipo, char cor, int pos)
{
    CARTAS cartas;
    cartas.valor = valor;
    cartas.tipo = tipo;
    cartas.cor = cor;
    if (l == NULL)
        return 0;
    if (lista_esta_cheia(l))
        return 0;
    for (int i = l->cont - 1; i >= pos; i--)
    {
        l->dados[i + 1] = l->dados[i];
    }
    l->dados[pos] = cartas;
    l->cont++;
    return 1;
}

int inserir_fim_lista(Lista *l, int valor, char tipo, char cor)
{
    CARTAS cartas;
    cartas.valor = valor;
    cartas.tipo = tipo;
    cartas.cor = cor;
    if (l == NULL)
        return 0;
    if (lista_esta_cheia(l))
        return 0;
    l->dados[l->cont] = cartas;
    l->cont++;
    return 1;
}

void imprimir_lista(Lista *l)
{
    for (int i = l->ini; i < 54; i++)
    {
        cout << l->dados[i].valor << l->dados[i].tipo << " ";
    }
    printf("\n");
}

void destruir_lista(Lista *l)
{
    free(l);
}

#endif