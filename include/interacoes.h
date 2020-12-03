#ifndef INTERACOES_H
#define INTERACOES_H
#include <iostream>

#if defined(__APPLE__) || defined(__linux__)
#define limpaTela()      \
    {                    \
        system("clear"); \
    }
#define delay()            \
    {                      \
        system("sleep 3"); \
    }
#define delay05()          \
    {                      \
        system("sleep 1"); \
    }
#define limpaTelaDelay() \
    {                    \
        delay();         \
        limpaTela();     \
    }

#elif defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define limpaTela()    \
    {                  \
        system("cls"); \
    }
#define delay()      \
    {                \
        Sleep(2000); \
    }
#define delay05()    \
    {                \
        Sleep(1000); \
    }
#define limpaTelaDelay() \
    {                    \
        delay();         \
        limpaTela();     \
    }
#endif
#include "config.h"

using namespace std;

void printLogo() // Funçao que vai printar o Logo do jogo
{
    cout << "   _________ __         .__       __________                   .___             __  .__                      " << endl;
    cout << " /   _____//  |________|__|__  __\\______   \\_______  ____   __| _/_ __   _____/  |_|__| ____   ____   ______" << endl;
    cout << " \\_____  \\\\   __\\_  __ \\  \\  \\/  /|     ___/\\_  __ \\/  _ \\ / __ |  |  \\_/ ___\\   __\\  |/  _ \\ /    \\ /  ___/" << endl;
    cout << " /        \\|  |  |  | \\/  |>    < |    |     |  | \\(  <_> ) /_/ |  |  /\\  \\___|  | |  (  <_> );   |  \\___ \\ " << endl;
    cout << "/_______  /|__|  |__|  |__/__/\\_ \\|____|     |__|   \\____/\\____ |____/  \\___  >__| |__|\\____/|___|  /____  >" << endl;
    cout << "        \\/                      \\/                             \\/           \\/                    \\/     \\/ " << endl;
    cout << "__________                                      __               " << endl;
    cout << "\\______   \\_______   ____   ______ ____   _____/  |_  ______     " << endl;
    cout << " |     ___/\\_  __ \\_/ __ \\ /  ___// __ \\ /    \\   __\\/  ___/     " << endl;
    cout << " |    |     |  | \\/\\  ___/ \\___ \\   ___/|   |  \\  |  \\___ \\      " << endl;
    cout << " |____|     |__|    \\___  >____  >\\___  >___|  /__| /____  >     " << endl;
    cout << "                        \\/     \\/     \\/     \\/          \\/      " << endl;

    limpaTelaDelay();

    cout << "__________               .__                     .__        " << endl;
    cout << "\\______   \\_____    ____ |__| ____   ____   ____ |__|____   " << endl;
    cout << " |     ___/\\__  \\ _/ ___\\|  |/ __ \\ /    \\_/ ___\\|  \\__  \\  " << endl;
    cout << " |    |     / __ \\\\  \\___|  \\  ___/|   |  \\  \\___|  |/ __ \\_ " << endl;
    cout << " |____|    (____  /\\___  >__|\\___  >___|  /\\___  >__(____  / " << endl;
    cout << "               \\/     \\/        \\/     \\/     \\/        \\/  " << endl;
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