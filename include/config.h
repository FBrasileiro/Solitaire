#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <stdlib.h>
#include <strings.h>
#include <string>
#include <stack>
#include <string>
#include <vector>
#include "interacoes.h"
#include "cartas.h"

using namespace std;

void print_carta(CARTAS carta, char EOL)
{
    if (carta.visivel == 1)
    {
        switch (carta.valor)
        {
        case 1:
            cout << 'A' << carta.tipo << EOL;
            break;
        case 11:
            cout << 'J' << carta.tipo << EOL;
            break;
        case 12:
            cout << 'Q' << carta.tipo << EOL;
            break;
        case 13:
            cout << 'K' << carta.tipo << EOL;
            break;
        default:
            cout << carta.valor << carta.tipo << EOL;
            break;
        }
    }
    else if (carta.visivel == 2)
    {
        cout << "*"
             << EOL;
    }
    else
    {
        cout << " "
             << EOL;
    }
}

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

void gerar_pilhas_finais(vector<stack<CARTAS>> &pilhas_finais)
{
    for (int i = 0; i < 4; i++)
    {
        stack<CARTAS> p_cartas;
        pilhas_finais.push_back(p_cartas);
    }
}

void add_pilhas_final(stack<CARTAS> &pilha, stack<CARTAS> &coluna)
{
    // cout << coluna.top().valor << endl;
    CARTAS aux;
    if (pilha.empty()) //caso seja a primeira carta na pilha
        if (coluna.top().valor == 1)
        {
            // cout << "IF IF" << endl;
            aux = coluna.top();
            coluna.top().visivel = 0;
            pilha.push(aux); //empilha
            coluna.pop();
        }
        else
            return;
    else if (coluna.top().valor == pilha.top().valor + 1) //caso n for a primeira carta na pilha
    {
        // cout << "ELSE IF" << endl;
        aux = coluna.top();
        coluna.top().visivel = 0;
        pilha.push(coluna.top()); //empilha
        coluna.pop();
    }
    else
    {
        limpaTela();
        cout << "Impossivel realizar essa acao" << endl;
        delay05();
    }
}

void apresentar_pilhas_finais(vector<stack<CARTAS>> pilhas_finais)
{
    string cartas[5] = {"Copas", "Espadas", "Paus", "Ouros"};
    for (int i = 0; i < pilhas_finais.size(); i++)
    {
        cout << cartas[i] << ": ";
        cout << "[ ";
        if (pilhas_finais[i].empty())
            cout << "*";
        else
        {
            pilhas_finais[i].top().visivel = 1;
            print_carta(pilhas_finais[i].top(), '\0');
        }
        cout << " ] ";
    }
    cout << endl;
}

void gerar_bolo_cave(Lista *cartas, vector<stack<CARTAS>> &cave)
{
    stack<CARTAS> bolo;
    CARTAS aux;
    int cont = cartas->cont;
    cave.push_back(bolo); // empurra a pilha vazia para o cave
    for (int i = 0; i < cont; i++)
    {
        aux = retirar_topo(cartas);
        aux.visivel = 1;
        bolo.push(aux);
    }
    cave.push_back(bolo);
}

void puxar_carta_cave(vector<stack<CARTAS>> &cave)
{
    if (cave[0].empty() && cave[1].empty())
    {
        limpaTela();
        cout << "O cave nao tem mais cartas" << endl;
        delay05();
        return;
    }
    if (!cave[1].empty())
    {
        cave[0].push(cave[1].top());
        cave[1].pop();
    }
    else
    {
        for (int i = cave[0].size(); i > 0; i--)
        {
            cave[1].push(cave[0].top());
            cave[0].pop();
        }
    }
}

void apresentar_carta_cave(vector<stack<CARTAS>> cave)
{
    cout << "BOLO: ";
    if (cave[1].empty())
        cout << "   ";
    else
        print_carta(cave[1].top(), ' ');
    cout << " - RETIRADAS: ";
    if (cave[0].empty())
        cout << "   ";
    else
        print_carta(cave[0].top(), ' ');
    cout << endl;
}

CARTAS visualizar_carta(const stack<CARTAS> &coluna, int index)
{
    struct cheat : stack<CARTAS>
    {
        using stack<CARTAS>::c;
    };
    const auto &seq = static_cast<const cheat &>(coluna).c;

    return seq[index];
}

void print_conteudo(stack<CARTAS> &coluna, int index)
{
    if (coluna.empty())
    {
        cout << " "
             << "\t";
        return;
    }
    CARTAS seq = visualizar_carta(coluna, index);

    print_carta(seq, '\t');
}

void print_colunas(vector<stack<CARTAS>> &colunas)
{
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            !colunas[j].empty() ? colunas[j].top().visivel = 1 : NULL;
            print_conteudo(colunas[j], i);
        }
        cout << endl;
    }
}

int possivel_empilhar(CARTAS carta, stack<CARTAS> coluna_alvo)
{
    if (coluna_alvo.empty())
    {
        if (carta.valor == 13)
            return 1;
        return 0;
    }
    CARTAS carta2 = coluna_alvo.top();
    // printf("%c - %c\n", carta.cor, carta2.cor);
    if (carta.cor == carta2.cor || carta.valor != carta2.valor - 1)
        return 0;
    return 1;
}

void movimenta_cartas(stack<CARTAS> &coluna, int index, stack<CARTAS> &coluna_alvo)
{
    CARTAS carta_desejada = visualizar_carta(coluna, index);
    stack<CARTAS> aux;
    if (carta_desejada.visivel == 2 || !possivel_empilhar(carta_desejada, coluna_alvo))
    {
        limpaTela();
        cout << "Impossivel realizar essa acao" << endl;
        delay05();
        return;
    }
    int c = 0;
    for (int i = coluna.size(); i > index; i--)
    {
        // cout << "TOPO: " << coluna.top().valor << endl;
        aux.push(coluna.top());
        coluna.top().visivel = 0;
        coluna.pop();
        c++;
    }
    for (int i = 0; i <= c; i++)
    {
        if (aux.empty() && i != 0)
            break;
        coluna_alvo.push(aux.top());
        aux.pop();
    }
}

int verificar_se_ganhou(vector<stack<CARTAS>> lista)
{
    CARTAS aux;
    for (int i = 0; i < 4; i++) //se as pilhas finais estiverem com1 13 cartas
    {
        if (lista[i].size() != 13)
            return 0;
    }
    return 1;
}

#endif