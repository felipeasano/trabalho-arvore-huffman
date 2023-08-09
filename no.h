#ifndef NO_H
#define NO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa no de Lista e no em Arvore Binaria
// Contem string para token e para dado binario e um contador para quantidade de token
typedef struct no {
    char *token;
    char *binario;
    int contador;
    struct no* prox;
    struct no* esq;
    struct no* dir;
} NO;

// verifica se a lista ou arvore esta vazia
// Entrada: Ponteiro de no para lista ou arvore
// Pre-Condicao: Nenhum
// Pos-Condicao: Nenhum
//  Retorno: 1 caso esteja vazia, 0 caso contrario
int vazia(NO* l);

// Cria um o Vazio e seta o mesmo
// Entrada: Nenhum
// Pre-condicao: Nenhuma
// Pos-condicao: Espaco para novo no alocado
// retorno: Novo no;
NO* cria_no();

// Apos a leitura de um token novo do arquivo .txt, a funcao insere um novo no
// em uma estrutura de Arvore
// Pre-Condicao: Nao pode enviar String(token) vazia
// Pos-Condicao: Arvore atualizada com novo no ou no do token incrementado o contador
// Retorno: Retorna um novo no contendo o novo token na arvore, com o contador em 1
// ou retorna o no do token da existente incrementando o contador
NO* conta_token(NO* l, char c[]);

// insere arvore Binaria em Lista encadeada
// Entrada: Ponteiro de no para arvore e ponteirode no para Lista ecadeada
// Pre-Condicao: Nenhum
// Pos-Condicao: Arvore Binaria se torna uma Lista encadeada
// Retorno: Ponteiro de no para Lista encadeada
NO* insere_arvore_lista(NO* arvore, NO* lista);

// converte uma lista encadeada em uma arvore de Huffman
// Entrada: Ponteiro de no para Lista a ser convertida
// Pre-Condicao: Nenhuma
// Pos-Condicao: Lista encadeada eh transformada em uma arovre de Huffman
// Retorno: Retorna a raiz da arvore de Huffman
NO* converter_lista_em_arvore_huffman2(NO* l);

// Preenche a arvore huffman com seus devidos binarios nos nos
// Entrada: ponteiro de no para arvore, string contendo o binario(caminho), tamanho da string
// Pre-condicao: nenhum
// Pos-condicao: Arvore huffman atualizado com os binarios nos nos folha
// Retorno: Nenhum
void distribuir_binarios(NO* arvore, char binario[], int tamanho);

// Faz a busca de um no da arvore usando o token como chave
// Entrada: Ponteiro de no para arvore
// Pre-Condicao: Nenhum
// Pos-Condicao: Nenhum
// retorno: devolve o no que contem o token buscado
NO* busca_no_por_token(NO* arvore, char token[]);

// transforma uma arvore de huffman em uma arvore de Binaria de Busca
// Entrada: Ponteiro para no de arvore huffman, ponteiro para no da nova arvore
// Pre-Condicao: Nenhum
// Pos-Condicao: arvore de Huffman eh transformada em uma arvore Binaria de Busca
// Retorno: Retorna um ponteiro de no para arvore binaria de busca
NO* insere_Huffman_em_busca(NO* huffman, NO* arvore);

#endif
