#ifndef INTERACOES_H
#define INTERACOES_H
#include <iostream>
#include "config.h"

#if defined(__APPLE__) || defined(__linux__)
#define limpaTela()      \
    {                    \
        system("clear"); \
    }
#define limpaTelaDelay()   \
    {                      \
        system("sleep 3"); \
        limpaTela();       \
    }

#elif defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define limpaTela()    \
    {                  \
        system("cls"); \
    }
#define limpaTelaDelay() \
    {                    \
        Sleep(2);        \
        limpaTela();     \
    }
#endif

using namespace std;

void printLogo() // Funçao que vai printar o Logo do jogo
{
    printf("   _________ __         .__       __________                   .___             __  .__                      \n");
    printf(" /   _____//  |________|__|__  __\\______   \\_______  ____   __| _/_ __   _____/  |_|__| ____   ____   ______\n");
    printf(" \\_____  \\\\   __\\_  __ \\  \\  \\/  /|     ___/\\_  __ \\/  _ \\ / __ |  |  \\_/ ___\\   __\\  |/  _ \\ /    \\ /  ___/\n");
    printf(" /        \\|  |  |  | \\/  |>    < |    |     |  | \\(  <_> ) /_/ |  |  /\\  \\___|  | |  (  <_> );   |  \\___ \\ \n");
    printf("/_______  /|__|  |__|  |__/__/\\_ \\|____|     |__|   \\____/\\____ |____/  \\___  >__| |__|\\____/|___|  /____  >\n");
    printf("        \\/                      \\/                             \\/           \\/                    \\/     \\/ \n");
    printf("__________                                      __               \n");
    printf("\\______   \\_______   ____   ______ ____   _____/  |_  ______     \n");
    printf(" |     ___/\\_  __ \\_/ __ \\ /  ___// __ \\ /    \\   __\\/  ___/     \n");
    printf(" |    |     |  | \\/\\  ___/ \\___ \\   ___/|   |  \\  |  \\___ \\      \n");
    printf(" |____|     |__|    \\___  >____  >\\___  >___|  /__| /____  >     \n");
    printf("                        \\/     \\/     \\/     \\/          \\/      \n");

    limpaTelaDelay();
}

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