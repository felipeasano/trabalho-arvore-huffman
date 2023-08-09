#ifndef ARQUIVO_ARVORE_C
#define ARQUIVO_ARVORE_C

#include "arquivo_arvore.h"

// Grava a arvore de Huffman no arquivo
// Entrada: Ponteiro para escritor de arquivo .bin e ponteiro de no para raiz da arvore Huffman
// Pre-Condicao: Nenhum
// Pos-Condicao: arquivo .bin recebe a arvore Huffman
// Retorno: Nenhum
void grava_arvore_huffman(ESCRITOR* e, NO* arvore){
    if(arvore->token){
        grava_bit(e, 1);
        grava_string(e, arvore->token);
    }else{
        grava_bit(e, 0);
        grava_arvore_huffman(e, arvore->esq);
        grava_arvore_huffman(e, arvore->dir);
    }
}

// Faz a leitura da arvore Huffman de um arquivo .bin
// Entrada: Ponteiro para estrutura de leitor de arvore .bin
// Pre-Condicao: Leitor existente
// Pos-Condicao: Nenhum
// Retorno: Raiz da arvore Huffman
NO* ler_arvore_huffman(LEITOR* l) {
    NO* no = cria_no();
    char str[256];
    int bit = ler_bit(l);
    if(bit == 1){
        ler_string(l, str);
        no->token = (char*)malloc(strlen(str)+1);
        strcpy(no->token, str);
    }else{
        no->esq = ler_arvore_huffman(l);
        no->dir = ler_arvore_huffman(l);
    }
    return no;
}

#endif
