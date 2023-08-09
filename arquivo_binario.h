#ifndef ARQUIVO_BINARIO_H
#define ARQUIVO_BINARIO_H

#include <stdio.h>

// Estrutura para escritor de arquivo .bin
typedef struct Escritor {
    FILE* arquivo;
    int temp;
    int tamanho;
} ESCRITOR;

// Estrutura para ler arquivo .bin
typedef struct Leitor {
    FILE* arquivo;
    int temp;
    int tamanho;
} LEITOR;

// Abre um arquivo .bin para escrita e seta as variaveis do escritor
// Entrada: Ponteiro para escritor e string contendo nome do arquivo .bin
// Pre-Condicao: Nenhuma
// Pos-Condicao: Arquivo .bin aberto para ser gravado
// Retorno: Nenhum
void abrir_escritor_binario(ESCRITOR* e, char *nomeArquivo);

// Grava 1 bit na variavel temp da estrutura do escritor
// Entrada: Ponteiro para escritor de .bin e um inteiro representando o bit a ser gravado
// Pre-Condicao: Arquivo estar aberto
// Pos-Condicao: Bit gravado na var temp
// Retorno: Nenhum
void grava_bit(ESCRITOR* e, int bit);

// Grava bit a bit na variavel temp do escritor
// Entrada: Ponteiro para escritor e string contendo binario a ser gravado
// Pre-Condicao: arquivo aberto
// Pos-Condicao: Binario gravado na var temp
// Retorno: Nenhum
void grava_binario(ESCRITOR* e, char binario[]);

// Fecha o arquivo .bin
// Entrada: Ponteiro para Escritor do .bin
// Pre-Condicao: Nenhum
// Pos-Condicao: Arquivo .bin fechado
// Retorno: Nenhum
void fechar_escritor_binario(ESCRITOR* e);

// Grava um caracter no arquivo .bin
// Entrada: Ponteiro para estrutura escritor e char contendo o caracter a ser gravado
// Pre-Condicao: Arquiv aberto
// Pos-Condicao: Caracter gravado no arquivo .bin
// Retorno: Nenhum
void grava_char(ESCRITOR* e, char c);

// Grava uma string no arquivo .bin
// Entrada: Ponteiro para escritor e string contendo o string a ser gravada
// Pre-Condicao: Arquivo Aberto
// Pos-Condicao: String gravada no .bin
// Retorno: Nenhum
void grava_string(ESCRITOR* e, char str[]);

// Grava a quantidade de tokens, contabilizados da leitura, no arquivo .bin
// Entrada: Ponteiro de escritor e inteiro ontendo a quantidade d tokens contabilizados
// Pre-Condicao: Arquivo aberto
// Pos-Condicao: Quantidade de tokens contabilizados gravado no arquivo .bin
// Retorno: Nenhum
void grava_int(ESCRITOR* e, int i);

// abrir arquivo .bin para leitura
// Entrada: Ponteiro para leitor de .bin, string contendo o nome do .bin
// Pre-Condicao: Arquivo .bin existente
// Pos-Condicao: Arquivo .bin aberto
// Retorno: Nenhuma
void abrir_leitor_binario(LEITOR* l, char *nomeArquivo);

// leitura bit a bit do arquivo .bin
// Entrada: Ponteiro para leitor do .bin
// Pre-Condicao: Arquivo aberto
// Pos-Condicao: bit lido
// Retorno: retorna o bit lido do .bin
int ler_bit(LEITOR* l);

// a partir da funcao ler_bit ler caracter e retornar o mesmo
// Entrada: Ponteiro para Leitor do .bin
// Pre-Condicao: Arquivo aberto
// Pos-Condicao: Caracter lido do .bin
// Retorno: retorna o caracter da leitura
char ler_char(LEITOR* l);

// a partir da funcao ler char, fazer a leitura da string
// Entrada: Ponteiro para o leitor e ponteiro de char contendo a string a ser lida do .bin
// Pre-Condicao: Arquivo aberto
// Pos-Condicao: leitura do token gravada na string
// Retorno: Nenhum
void ler_string(LEITOR* l, char binario[]);

// leitura do inteira inicial do .bin (quantidade total de tokens)
// Entrada: Ponteiro para leitor do .bin
// Pre-Condicao: Arquivo Aberto
// Pos-Condicao: leitura do da quantidade total d token
// retorna a quantidade d tokens para construcao do .txt
int ler_int(LEITOR* l);

// fecha o arquivo .bin
// se houver lixo, ignorar usando o retorno de "ler_int"
// Entrada: Ponteiro para leitor de .bin
// Pre-Condicao: Nenhum
// Pos-Condicao: arquivo fechado
// Retorno: Nenhum
void fechar_leitor_binario(LEITOR* l);

#endif
