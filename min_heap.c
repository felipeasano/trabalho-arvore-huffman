#ifndef MIN_HEAP_C
#define MIN_HEAP_C

#include"min_heap.h"
#include<stdlib.h>

// Alocacao de memoria e set da variavel Tam(Tamanho) da heap
// Entrada: inteiro contendo o tamanho maximo da heap
// Pre-Condicao: Entrada positiva
// Pos-Condicao: Espaco para heap alocado
// Retorno: Ponteiro para Heap
MIN_HEAP* cria_min_heap(int tam_max) {
    MIN_HEAP* min_heap = (MIN_HEAP*) malloc(sizeof(MIN_HEAP));
    min_heap->vet = (NO**) malloc(sizeof(NO*) * tam_max);
    min_heap->tam = 0;
    return min_heap;
}

// Calcula a posicao do pai do no atual no vetor de heap
// Entrada: Entra com um inteiro que corresponde a posicao atual do no no vetor heap
// Pre-Condicao: i positivo
// Pos-Condicao: Nenhum
// Retorno: Posicao do pai no vetor heap
int calcula_pos_pai(int i) {
    return (i-1)/2;
}

// Calcula a posicao do primeiro filho do no atual no vetor de heap
// Entrada: Entra com um inteiro que corresponde a posicao atual do no no vetor heap
// Pre-Condicao: i positivo
// Pos-Condicao: Nenhum
// Retorno: Posicao do primeiro filho no vetor heap
int calcula_pos_filho1(int i) {
    return (i*2)+1;
}

// Troca dois nos de posicao no vetor heap
// Entrada: Ponteiro para heap, posicao do primeiro no a ser trocado, posicao do segundo no a ser trocado
// Pre-Condicao: Posicoes positivas
// Pos-Condicao: Nos trocados de posicao no vetor heap
// Retorno: Nenhum
void troca_min_heap(MIN_HEAP* min_heap, int i, int j) {
    NO* temp = min_heap->vet[i];
    min_heap->vet[i] = min_heap->vet[j];
    min_heap->vet[j] = temp;
}

// Sobe o no de nivel na heap d acordo com a frequencia guardada
// Dessa forma, mantem sua propriedade d forma a deixar os nos mais abaixo com maior freqencia d token e os menores mais proximos a raiz
// Entrada: Ponteiro para heap, posicao atual do no na heap
// Pre-Condicao: posicao positiva
// Pos-Condicao: Atualiza o heap afim d manter sua propriedade
// Retorno: Nenhum
void sobe_min_heap(MIN_HEAP* min_heap, int pos) {
    while(pos != 0){
        int pos_pai = calcula_pos_pai(pos);
        if(min_heap->vet[pos]->contador >= min_heap->vet[pos_pai]->contador){
            break;
        }
        troca_min_heap(min_heap, pos, pos_pai);
        pos = pos_pai;
    }
}

// Desce o no de nivel na heap d acordo com a frequencia guardada
// Dessa forma, mantem sua propriedade de forma a deixar os nos mais abaixo com maior freqencia d token e os menores mais proximos a raiz
// Entrada: Ponteiro para heap, posicao atual do no na heap
// Pre-Condicao: posicao positiva
// Pos-Condicao: Atualiza o heap afim d manter sua propriedade
// Retorno: Nenhum
void desce_min_heap(MIN_HEAP* min_heap, int pos) {
    while(1){
        int pos_filho1 = calcula_pos_filho1(pos);
        if(pos_filho1 >= min_heap->tam){
            break;
        }   
        int pos_filho2 = pos_filho1+1;
        int pos_menor_filho = pos_filho1;
        if(pos_filho2 < min_heap->tam){
            if(min_heap->vet[pos_filho2]->contador < min_heap->vet[pos_filho1]->contador){
                pos_menor_filho = pos_filho2;
            }
        }
        if(min_heap->vet[pos]->contador > min_heap->vet[pos_menor_filho]->contador){
            troca_min_heap(min_heap, pos, pos_menor_filho);
            pos = pos_menor_filho;
        }else {
            break;
        }
    }
}

// Insere no na heap mantendo sua propriedade
// Entrada: Ponteiro para heap, ponteiro de no a ser inserido na heap
// Pre-Condicao: Nenhum
// Pos-Condicao: heap recebe um novo no, seu tamanho consequentemente aumenta
// Retorno: Nenhum
void insere_min_heap(MIN_HEAP* min_heap, NO* no) {
    min_heap->vet[min_heap->tam] = no;
    min_heap->tam++;
    sobe_min_heap(min_heap, min_heap->tam-1);
}

// Remove a raiz do heap e o ajusta mantendo sua propriedade
// Entrada: Ponteiro para heap
// Pre-Condicao: Nenhum
// Pos-Condicao: Raiz do heap eh removido e heap ajustado mantendo propriedade
// Retorno: Retorna a raiz do heap (removida do heap)
NO* remove_min_heap(MIN_HEAP* min_heap) {
    NO* raiz = min_heap->vet[0];
    if(min_heap->tam == 1){
        min_heap->tam = 0;
        return raiz;
    }
    NO* nova_raiz = min_heap->vet[min_heap->tam-1];
    min_heap->vet[0] = nova_raiz;
    min_heap->tam--;
    desce_min_heap(min_heap, 0);
    return raiz;
}

#endif