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
            aux_c.visivel = -1;
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
void print(const stack<T> &stk, int index)
{
    struct cheat : stack<T>
    {
        using stack<T>::c;
    };
    const auto &seq = static_cast<const cheat &>(stk).c;

    // for (const auto &v : seq)
    // {
    //     if (v.visivel == 1)
    //         cout << v.carta << ' ';
    //     else
    //         cout << "*"
    //              << " ";
    // }
    // cout << '\n';

    if (seq[index].visivel == 1)
        cout << seq[index].carta << "\t";
    else if (seq[index].visivel == -1)
        cout << "*"
             << "\t";
    else
        cout << " "
             << "\t";
}

int main()
{
    Lista *cartas = criar_cartas();
    vector<stack<CARTAS>> colunas;
    CARTAS carta;
    shuffle(cartas, 52);

    gerar_colunas(cartas, colunas);

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            print(colunas[j], i);
        }
        cout << endl;
    }

    return 0;
}