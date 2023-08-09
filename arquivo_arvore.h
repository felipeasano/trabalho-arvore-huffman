#ifndef ARQUIVO_ARVORE_H
#define ARQUIVO_ARVORE_H

#include "arquivo_binario.h"
#include "no.h"

// Grava a arvore de Huffman no arquivo
// Entrada: Ponteiro para escritor de arquivo .bin e ponteiro de no para raiz da arvore Huffman
// Pre-Condicao: Nenhum
// Pos-Condicao: arquivo .bin recebe a arvore Huffman
// Retorno: Nenhum
void grava_arvore_huffman(ESCRITOR* e, NO* arvore);

// Faz a leitura da arvore Huffman de um arquivo .bin
// Entrada: Ponteiro para estrutura de leitor de arvore .bin
// Pre-Condicao: Leitor existente
// Pos-Condicao: Nenhum
// Retorno: Raiz da arvore Huffman
NO* ler_arvore_huffman(LEITOR* l);

#endif
