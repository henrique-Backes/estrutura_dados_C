#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto
{
    float x;
    float y;
}

Ponto* ponto_new(float x, float y)
{
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));

    if (p != NULL)
    {
        p->x = x;
        p->y = y;
    }

    return p;
}
void ponto_free(Ponto* self)
{
    free(self);
}
void ponto_read(Ponto* self, float* x, float* y)
{
    *x = self->x;
    *y = self->y;
}
void ponto_write(Ponto* self, float x, float y)
{
    self->x = x;
    self->y = y;
}
void ponto_compute_distance(Ponto* a, Ponto* b)
{
    float dx = a->x - b->x;
    float dy = a->y - b->y;
    return sqrt(pow(dx, 2) + pow(dy, 2));
}