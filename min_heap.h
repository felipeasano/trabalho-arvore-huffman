#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "no.h"

// Estrutura para vetor de heap (ordenando do menor para o maior)
typedef struct min_heap{
    NO** vet;
    int tam;
} MIN_HEAP;

// Alocacao de memoria e set da variavel Tam(Tamanho) da heap
// Entrada: inteiro contendo o tamanho maximo da heap
// Pre-Condicao: Entrada positiva
// Pos-Condicao: Espaco para heap alocado
// Retorno: Ponteiro para Heap
MIN_HEAP* cria_min_heap(int tam_max);

// Insere no na heap mantendo sua propriedade
// Entrada: Ponteiro para heap, ponteiro de no a ser inserido na heap
// Pre-Condicao: Nenhum
// Pos-Condicao: heap recebe um novo no, seu tamanho consequentemente aumenta
// Retorno: Nenhum
void insere_min_heap(MIN_HEAP* min_heap, NO* no);

// Remove a raiz do heap e o ajusta mantendo sua propriedade
// Entrada: Ponteiro para heap
// Pre-Condicao: Nenhum
// Pos-Condicao: Raiz do heap eh removido e heap ajustado mantendo propriedade
// Retorno: Retorna a raiz do heap (removida do heap)
NO* remove_min_heap(MIN_HEAP* min_heap);

#endif