#include <iostream>
#include <stdlib.h>
#include <strings.h>
#include <stack>
#include <string>
#include <vector>
#include "include/interacoes.h"
#include "include/cartas.h"
#include "include/config.h"

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
    int u_cave;
    limpaTela();
    printLogo();
    cout << "Gerando cartas..." << endl;
    delay();
    while (1)
    {
        if (verificar_se_ganhou(pilhas_finais))
        {
            print_ganhou();
            break;
        }

        limpaTela();
        print_colunas(colunas);
        apresentar_carta_cave(cave);
        apresentar_pilhas_finais(pilhas_finais);
        print_acoes();

        cout << "Escreva: ";
        cin >> acao;
        limpaTela();
        print_colunas(colunas);
        switch (acao)
        {
        case 'A':

            puxar_carta_cave(cave);
            break;
        case 'B':

            cout << "De qual pilha deseja retirar a carta?" << endl;
            cin >> col;
            cout << "Qual a posicao da carta?" << endl;
            cin >> index;
            cout << "Em qual pilha deseja colocar a carta?" << endl;
            cin >> alvo;
            movimenta_cartas(colunas[col - 1], index - 1, colunas[alvo - 1]);

            break;
        case 'C':

            cout << endl;
            if (cave[0].empty() && cave[1].empty())
            {
                limpaTela();
                cout << "O cave nao tem mais cartas" << endl;
                delay05();
                break;
            }

            cout << "De qual pilha deseja retirar a carta?" << endl;
            cout << "[1] - Bolo" << endl;
            cout << "[0] - Retiradas" << endl;
            cin >> u_cave;
            if (u_cave > cave.size() || cave[u_cave].empty())
            {
                limpaTela();
                cout << "Nao existem cartas ai" << endl;
                delay05();
                break;
            }
            cout << "Em qual pilha deseja colocar a carta?" << endl;
            cin >> alvo;
            movimenta_cartas(cave[u_cave], cave[u_cave].size() - 1, colunas[alvo - 1]);
            break;

        case 'D':
            cout << endl;
            cout << "De qual coluna deseja retirar a carta?" << endl;
            cin >> col;
            if (colunas[col - 1].empty())
            {
                limpaTela();
                cout << "Nao existem cartas ai" << endl;
                delay();
                break;
            }
            switch (colunas[col - 1].top().tipo)
            {
            case 'c':
                add_pilhas_final(pilhas_finais[0], colunas[col - 1]);
                break;
            case 'e':
                add_pilhas_final(pilhas_finais[1], colunas[col - 1]);
                break;
            case 'p':
                add_pilhas_final(pilhas_finais[2], colunas[col - 1]);
                break;
            case 'o':
                add_pilhas_final(pilhas_finais[3], colunas[col - 1]);
                break;
            }
            break;

        case 'E':
            cout << endl;
            if (cave[0].empty() && cave[1].empty())
            {
                limpaTela();
                cout << "O cave nao tem mais cartas" << endl;
                delay();
                break;
            }

            cout << "De qual pilha deseja retirar a carta?" << endl;
            cout << "[1] - Bolo" << endl;
            cout << "[0] - Retiradas" << endl;
            cin >> u_cave;
            if (u_cave > cave.size() || cave[u_cave].empty())
            {
                limpaTela();
                cout << "Nao existem cartas ai" << endl;
                delay();
                break;
            }

            switch (cave[u_cave].top().tipo)
            {
            case 'c':
                add_pilhas_final(pilhas_finais[0], cave[u_cave]);
                break;
            case 'e':
                add_pilhas_final(pilhas_finais[1], cave[u_cave]);
                break;
            case 'p':
                add_pilhas_final(pilhas_finais[2], cave[u_cave]);
                break;
            case 'o':
                add_pilhas_final(pilhas_finais[3], cave[u_cave]);
                break;
            }

            break;
        default:
            limpaTela();
            cout << "Opcao invalida, tente novamente" << endl;
            delay05();
        }
    }

    return 0;
}
