#include <iostream>
#include <stdlib.h>
#include <strings.h>
#include <stack>
#include <string>
#include <vector>
#include "include/cartas.h"
#include "include/config.h"

using namespace std;

int main()
{
    Lista *cartas = criar_cartas();
    vector<stack<CARTAS>> colunas;
    CARTAS carta;
    shuffle(cartas, 52);

    gerar_colunas(cartas, colunas);
    print_colunas(colunas);

    cout << endl;

    return 0;
}