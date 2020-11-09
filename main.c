#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "cartas.h"

int main()
{
    Lista *cartas = criar_cartas();
    imprimir_lista(cartas);

    printf("\n");
    shuffle(cartas, 52);
    printf("\n");
    imprimir_lista(cartas);

    return 0;
}