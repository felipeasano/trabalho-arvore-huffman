#ifndef LEITOR_TOKEN_H
#define LEITOR_TOKEN_H

#include <stdio.h>

// Estrutura para leitura do token d um arquivo .txt
typedef struct Leitor_Token {
    FILE* f;
    char temp;
} LEITOR_TOKEN;

int valida_arquivo(LEITOR_TOKEN* c);

// Abre ao arquivo .txt a ser lido/compactado
// Entrada: Ponteiro para estrutura de leitor de arquivo, string contendo o nome do arquivo a ser lido
// Pre-Condicao: Nenhum
// Pos-Condicao: Arquivo aberto
// Retorno: Nenhum
void abrir_leitor_token(LEITOR_TOKEN* c, char *nomeArquivo);

// Faz a leitura do proximo caracter do arquivo .txt 
// Entrada: Ponteiro para o leitor de arquivo .txt, poteiro de char para o caracter q sera lido
// Pre-Condicao: Arquivo Aberto
// Pos-Condicao: string de entrada recebe o proximo caracter
// Retorno: Retorna 1 caso tenha encontrado um token novo, 0 caso seja final d arquivo
int prox_char(LEITOR_TOKEN* leitor, char* s);

// Faz a leitura do proximo token no arquivo .txt
// Entrada: Ponteiro para o leitor do .txt, string que vai guardar o token
// Pre-Condicao: Arquivo aberto
// Pos-Condicao: string de entrada recebe o proximo token
// Retorno: 1 caso tenha lido um token, 0 caso nao encontre
int prox_token(LEITOR_TOKEN* leitor, char *s);

// Volta a leitura para o comeco do .txt a ser compactado
// Entrada: Ponteiro do leitor
// Pre-Condicao: Arquivo aberto
// Pos-Condicao: Leitor vai para o comeco do arquivo .txt
// Retorno: Nenhum
void reiniciar_leitor(LEITOR_TOKEN* leitor);

#endif
