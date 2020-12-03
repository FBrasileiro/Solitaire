#ifndef INTERACOES_H
#define INTERACOES_H
#include <iostream>
#include "config.h"

using namespace std;

void print_acoes()
{
    cout << "O que voce deseja fazer?" << endl;
    cout << endl;
    cout << "[A] - Retirar carta do topo do cava" << endl;
    cout << "[B] - Mover uma carta de uma pilha para outra pilha" << endl;
    cout << "[C] - Mover uma carta do cava a uma pilha" << endl;
    cout << "[D] - Mover uma carta de uma pilha ate a pilha final" << endl;
    cout << "[E] - Mover carta do monte para pilha final" << endl;
    cout << endl;
}

void print_ganhou()
{
    cout << "\n"
         << endl;
    cout << "|------------------------------|" << endl;
    cout << "| Parabéns, você ganhou o jogo |" << endl;
    cout << "|------------------------------|" << endl;
}

void print_perdeu()
{
    cout << "\n"
         << endl;
    cout << "|---------------------------------|" << endl;
    cout << "| Infelizmente você perdeu o jogo |" << endl;
    cout << "|---------------------------------|" << endl;
}

#endif