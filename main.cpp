#include <iostream>
#include <stdlib.h>
#include <strings.h>
#include <stack>
#include <string>
#include <vector>
#include "include/interacoes.h"
#include "include/cartas.h"
#include "include/config.h"

#ifdef __APPLE__ || __LINUX__
#define limpaTela()      \
    {                    \
        system("clear"); \
    }
#endif

using namespace std;

int main()
{
    Lista *cartas = criar_cartas();
    vector<stack<CARTAS>> colunas;
    vector<stack<CARTAS>> pilhas_finais;
    vector<stack<CARTAS>> cave;

    shuffle(cartas, 52);
    gerar_colunas(cartas, colunas);
    gerar_bolo_cave(cartas, cave);
    gerar_pilhas_finais(pilhas_finais);
    char acao;

    int col, index, alvo;
    while (1)
    {
        print_colunas(colunas);
        apresentar_carta_cave(cave);
        print_acoes();

        cout << "Escreva: ";
        cin >> acao;
        cout << acao << endl;
        switch (acao)
        {
        case 'A':
            puxar_carta_cave(cave);
            break;
        case 'B':
            limpaTela();
            print_colunas(colunas);
            cout << "De qual pilha deseja retirar a carta?" << endl;
            cin >> col;
            cout << "Qual a posicao da carta?" << endl;
            cin >> index;
            cout << "Em qual pilha deseja colocar a carta?" << endl;
            cin >> alvo;
            movimenta_cartas(colunas[col], index, colunas[alvo]);
            break;
        case 'C':
            cout << endl;
            cout << "Em qual pilha deseja colocar a carta?" << endl;

            break;
        case 'D':
            cout << endl;
            cout << "De qual coluna deseja retirar a carta?" << endl;
            break;
        case 'E':
            cout << endl;
            //Coloca funcao de remove_do_cava
            break;
        default:
            cout << "Opcao invalida, tente novamente" << endl;
        }
    }

    return 0;
}
