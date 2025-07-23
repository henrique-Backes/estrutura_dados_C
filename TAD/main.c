#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main (void)
{
    float distancia;
    Ponto *p = ponto_new(2.0, 3.0);
    Ponto *q = ponto_new(5.0, 8.0);

    distancia = ponto_compute_distance(&p, &q);
    printf("A distancia eh: %f\n", d);
    ponto_free(&p);
    ponto_free(&q);

    system("pause");
    return 0;
}