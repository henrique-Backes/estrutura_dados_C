#include <stdio.h>
#include <stdlib.h>
#include "lista_estatica.h"

int main (void)
{
    lista_estatica_t *lista_exemplo;
    int32_t tamanho_lista = 0;

    lista_exemplo = lista_new();
    tamanho_lista = lista_size(lista_exemplo);

    lista_free(lista_exemplo);
    system("pause");
    return 0;
}