#include "contagem_referencias.h"
#include <stdio.h>
#include <stdlib.h>

static Contagem *head = NULL;

void adicionar(void *end) {
    Contagem *node = (Contagem *)malloc(sizeof(Contagem));
    node->end = end;
    node->cont = 1;
    node->prox = head;
    head = node;
}

Contagem* buscar(void *end) {
    Contagem *lista = head;
    while (lista != NULL) {
        if (lista->end == end)
            return lista;
        lista = lista->prox;
    }
    return NULL;
}

void remover(void *end) {
    Contagem *lista = head;
    Contagem *anterior = NULL;

    while (lista != NULL) {
        if (lista->end == end) {
            if (anterior != NULL) {
                anterior->prox = lista->prox;
            } else {
                head = lista->prox;
            }

            printf("\nRemovido: %p\n", lista->end);
            free(lista->end);
            free(lista);
            return;
        }
        anterior = lista;
        lista = lista->prox;
    }
}

void alterar_contagem(void *end, int x) {
    Contagem *node = buscar(end);
    if (node != NULL) {
        if (x > 0) {
            node->cont += x;
        } else {
            node->cont += x;
            if (node->cont < 1) {
                remover(end);
            }
        }
    }
}

void *malloc2(size_t tamanho) {
    void *end = malloc(tamanho);
    adicionar(end);
    return end;
}

void atrib2(void *destino, void *fonte) {
    alterar_contagem(destino, -1);
    alterar_contagem(fonte, 1);
    destino = fonte;
}

void dump() {
    printf("\nContagem por Referência:\n");
    Contagem *lista = head;
    while (lista != NULL) {
        printf("Endereço: %p, Contagem: %d\n", lista->end, lista->cont);
        lista = lista->prox;
    }
}

void liberar() {
    printf("\nLiberando toda a memória...\n");
    Contagem *lista = head;
    while (lista != NULL) {
        alterar_contagem(lista->end, -lista->cont);
        lista = lista->prox;
    }
}
