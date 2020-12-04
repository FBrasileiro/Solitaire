#include <iostream>
#include <stdlib.h>
#include <strings.h>
#include <stack>
#include <string>
#include <vector>
#include "interacoes.h"
#include "cartas.h"
#include "config.h"

Lista *criar_cartas_final()
{
    Lista *cartas = criar_lista();
    int valor;
    char tipo[] = {'e', 'o', 'p', 'c'};

    for (int j = 0; j < 4; j++)
    {
        for (int i = 1; i < 13; i++)
        {
            inserir_fim_lista(cartas, i, tipo[j], (j % 2 ? 'v' : 'p'));
        }
    }
    return cartas;
}

void gerar_set_final(Lista *cartas, vector<stack<CARTAS>> &pilhas_finais)
{
    for (int i = 0; i < 4; i++)
    {
        stack<CARTAS> aux;
        CARTAS aux_c;
        for (int j = 0; j < 12; j++)
        {
            aux_c = retirar_topo(cartas);
            aux_c.visivel = 1;
            aux.push(aux_c);
        }
        pilhas_finais.push_back(aux);
    }
}

void print_set_final(vector<stack<CARTAS>> pilhas_finais)
{
    string cartas[5] = {"Copas", "Espadas", "Paus", "Ouros"};
    for (int i = 0; i < 4; i++)
    {
        stack<CARTAS> aux;
        CARTAS aux_c;
        cout << "(" << pilhas_finais[i].size() << ") " << cartas[i] << ": ";
        for (int j = 0; j < 13; j++)
        {
            print_carta(visualizar_carta(pilhas_finais[i], j), ' ');
        }
        cout << endl;
        pilhas_finais.push_back(aux);
    }
}

void gerar_colunas_final(Lista *cartas, vector<stack<CARTAS>> &colunas)
{
    stack<CARTAS> aux, aux2, aux3, aux4;
    CARTAS aux_c, aux_c2, aux_c3, aux_c4;
    aux_c.valor = 13;
    aux_c2.valor = 13;
    aux_c3.valor = 13;
    aux_c4.valor = 13;

    aux_c.cor = 'v';
    aux_c2.cor = 'v';
    aux_c3.cor = 'p';
    aux_c4.cor = 'p';

    aux_c.tipo = 'c';
    aux_c2.tipo = 'o';
    aux_c3.tipo = 'e';
    aux_c4.tipo = 'p';

    aux_c.visivel = 1;
    aux_c2.visivel = 1;
    aux_c3.visivel = 1;
    aux_c4.visivel = 1;

    aux.push(aux_c);
    aux2.push(aux_c2);
    aux3.push(aux_c3);
    aux4.push(aux_c4);

    colunas.push_back(aux);
    colunas.push_back(aux2);
    colunas.push_back(aux3);
    colunas.push_back(aux4);
}

void print_coluna_final(vector<stack<CARTAS>> &colunas)
{
    for (int i = 0; i < 4; i++)
    {
        print_carta(visualizar_carta(colunas[i], 0), '\t');
    }
    cout << endl;
    cout << endl;
}