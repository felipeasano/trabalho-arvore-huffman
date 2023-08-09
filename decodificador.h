#ifndef DECODIFICADOR_H
#define DECODIFICADOR_H

#include "no.h"
#include "arquivo_binario.h"

// Faz a leitura em binario do .bin e decodifica para o respectivo token
// Entrada: Ponteiro para leitor do .bin, ponteiro de NO para arvore huffman, string contendo a leitura binaria
// Pre-Condicao: Arquivo aberto
// Pos-Condicao: Token eh decodificado a partir da leitura
// Retorno: Nenhum
void decodifica_proximo_token(LEITOR* l, NO* arvore, char str[]);

#endif
