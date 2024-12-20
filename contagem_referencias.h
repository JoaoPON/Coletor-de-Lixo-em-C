#ifndef CONTAGEM_REFERENCIAS_H
#define CONTAGEM_REFERENCIAS_H

#include <stddef.h>

typedef struct Contagem {
    void *end;
    int cont;
    struct Contagem *prox;
} Contagem;

void adicionar(void *end);

Contagem* buscar(void *end);

void remover(void *end);

void alterar_contagem(void *end, int x);

void *malloc2(size_t tamanho);

void atrib2(void *destino, void *fonte);

void dump();

void liberar();

#endif