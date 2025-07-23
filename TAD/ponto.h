#ifndef PONTO_H
#define PONTO_H

typedef struct ponto Ponto;

Ponto* ponto_new(float x, float y);
void ponto_free(Ponto* self);
void ponto_read(Ponto* self, float* x, float* y);
void ponto_write(Ponto* self, float x, float y);
void ponto_compute_distance(Ponto* a, Ponto* b);

#endif