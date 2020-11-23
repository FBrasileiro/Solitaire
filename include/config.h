#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <stdlib.h>
#include <strings.h>
#include <stack>
#include <string>
#include <vector>
#include "cartas.h"

using namespace std;

void gerar_colunas(Lista *cartas, vector<stack<CARTAS>> &colunas)
{
    for (int i = 1; i < 8; i++)
    {
        stack<CARTAS> aux;
        CARTAS aux_c;
        for (int j = 0; j < i; j++)
        {
            aux_c = retirar_topo(cartas);
            aux_c.visivel = 2;
            aux.push(aux_c);
        }
        colunas.push_back(aux);
    }

    for (int i = 0; i < 7; i++)
    {
        colunas[i].top().visivel = 1;
    }
}

template <typename T>
void print_conteudo(const stack<T> &stk, int index)
{
    struct cheat : stack<T>
    {
        using stack<T>::c;
    };
    const auto &seq = static_cast<const cheat &>(stk).c;

    switch (seq[index].visivel)
    {
    case 1:
        cout << seq[index].carta << "\t";
        break;
    case 2:
        cout << "*"
             << "\t";
        break;
    default:
        cout << " "
             << "\t";
        break;
    }
}

void print_colunas(vector<stack<CARTAS>> &colunas)
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < colunas[j].size(); j++)
        {
            print_conteudo(colunas[j], i);
        }
        cout << endl;
    }
}

#endif