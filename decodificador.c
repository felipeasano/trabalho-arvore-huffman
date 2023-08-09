#ifndef DECODIFICADOR_C
#define DECODIFICADOR_C

#include "decodificador.h"

// Faz a leitura em binario do .bin e decodifica para o respectivo token
// Entrada: Ponteiro para leitor do .bin, ponteiro de NO para arvore huffman, string contendo a leitura binaria
// Pre-Condicao: Arquivo aberto
// Pos-Condicao: Token eh decodificado a partir da leitura
// Retorno: Nenhum
void decodifica_proximo_token(LEITOR* l, NO* arvore, char str[]) {
    if(arvore->token){
        strcpy(str, arvore->token);
        return;
    }
    int bit;
    bit = ler_bit(l);
    if(bit == 0){
        decodifica_proximo_token(l, arvore->esq, str);
    }else{
        decodifica_proximo_token(l, arvore->dir, str);
    }
}

#endif
