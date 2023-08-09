#ifndef ARQUIVO_BINARIO_1
#define ARQUIVO_BINARIO_C

#include "arquivo_binario.h"

// Abre um arquivo .bin para escrita e seta as variaveis do escritor
// Entrada: Ponteiro para escritor e string contendo nome do arquivo .bin
// Pre-Condicao: Nenhuma
// Pos-Condicao: Arquivo .bin aberto para ser gravado
// Retorno: Nenhum
void abrir_escritor_binario(ESCRITOR* e, char *nomeArquivo){
    e->arquivo = fopen(nomeArquivo, "wb");
    e->tamanho = 0;
    e->temp = 0;
}

// Grava 1 bit na variavel temp da estrutura do escritor
// Entrada: Ponteiro para escritor de .bin e um inteiro representando o bit a ser gravado
// Pre-Condicao: Arquivo estar aberto
// Pos-Condicao: Bit gravado na var temp
// Retorno: Nenhum
void grava_bit(ESCRITOR* e, int bit){
    if(bit == 1){
        int shift = 7 - e->tamanho;
        e->temp = e->temp + (1 << shift);
    }
    e->tamanho++;
    if(e->tamanho == 8){
        fputc(e->temp, e->arquivo);
        e->temp = 0;
        e->tamanho = 0;
    }
}

// Grava bit a bit na variavel temp do escritor
// Entrada: Ponteiro para escritor e string contendo binario a ser gravado
// Pre-Condicao: arquivo aberto
// Pos-Condicao: Binario gravado na var temp
// Retorno: Nenhum
void grava_binario(ESCRITOR* e, char binario[]) {
    while(1){
        if(*binario == '\0'){
            break;
        }
        if(*binario == '1'){
            grava_bit(e, 1);
        }else {
            grava_bit(e, 0);
        }
        binario++;
    }
}

// Fecha o arquivo .bin
// Entrada: Ponteiro para Escritor do .bin
// Pre-Condicao: Nenhum
// Pos-Condicao: Arquivo .bin fechado
// Retorno: Nenhum
void fechar_escritor_binario(ESCRITOR* e){
    if(e->tamanho != 0){
        putc(e->temp, e->arquivo);
    }
    fclose(e->arquivo);
}

// Grava um caracter no arquivo .bin
// Entrada: Ponteiro para estrutura escritor e char contendo o caracter a ser gravado
// Pre-Condicao: Arquiv aberto
// Pos-Condicao: Caracter gravado no arquivo .bin
// Retorno: Nenhum
void grava_char(ESCRITOR* e, char c){
    int shift = 7;
    char aux;
    for(int i = 0; i < 8; i++){
        aux = c >> (shift - i);
        aux = aux & 1;
        grava_bit(e, aux);
    }
}

// Grava uma string no arquivo .bin
// Entrada: Ponteiro para escritor e string contendo o string a ser gravada
// Pre-Condicao: Arquivo Aberto
// Pos-Condicao: String gravada no .bin
// Retorno: Nenhum
void grava_string(ESCRITOR* e, char str[]){
    while(1){
        grava_char(e, *str);
        if(*str == '\0'){
            break;
        }
        str++;
    }
}

// Grava a quantidade de tokens, contabilizados da leitura, no arquivo .bin
// Entrada: Ponteiro de escritor e inteiro ontendo a quantidade d tokens contabilizados
// Pre-Condicao: Arquivo aberto
// Pos-Condicao: Quantidade de tokens contabilizados gravado no arquivo .bin
// Retorno: Nenhum
void grava_int(ESCRITOR* e, int i){
    fwrite(&i, 1, sizeof(int),e->arquivo);
}

// abrir arquivo .bin para leitura
// Entrada: Ponteiro para leitor de .bin, string contendo o nome do .bin
// Pre-Condicao: Arquivo .bin existente
// Pos-Condicao: Arquivo .bin aberto
// Retorno: Nenhuma
void abrir_leitor_binario(LEITOR* l, char *nomeArquivo){
    l->arquivo = fopen(nomeArquivo, "rb");
    l->tamanho = 0;
    l->temp = 0;
}

// leitura bit a bit do arquivo .bin
// Entrada: Ponteiro para leitor do .bin
// Pre-Condicao: Arquivo aberto
// Pos-Condicao: bit lido
// Retorno: retorna o bit lido do .bin
int ler_bit(LEITOR* l){
    int bit = 0;
    if(l->tamanho == 0){
        char c = fgetc(l->arquivo);
        l->temp = c;
        l->tamanho = 8;
    }
    bit = (l->temp >> (l->tamanho-1)) & 1;
    l->tamanho--;
    return bit;
}

// a partir da funcao ler_bit ler caracter e retornar o mesmo
// Entrada: Ponteiro para Leitor do .bin
// Pre-Condicao: Arquivo aberto
// Pos-Condicao: Caracter lido do .bin
// Retorno: retorna o caracter da leitura
char ler_char(LEITOR* l){
    char c = 0;
    int aux;
    for(int i = 0; i < 8; i++){
        int shift = 7 - i;
        aux = ler_bit(l);
        aux = aux << shift;
        c += aux;
    }
    return c;
}

// a partir da funcao ler char, fazer a leitura da string
// Entrada: Ponteiro para o leitor e ponteiro de char contendo a string a ser lida do .bin
// Pre-Condicao: Arquivo aberto
// Pos-Condicao: leitura do token gravada na string
// Retorno: Nenhum
void ler_string(LEITOR* l, char str[]){
    while(1){
        *str = ler_char(l);
        if(*str == '\0'){
            break;
        }
        str++;
    }
}

// leitura do inteira inicial do .bin (quantidade total de tokens)
// Entrada: Ponteiro para leitor do .bin
// Pre-Condicao: Arquivo Aberto
// Pos-Condicao: leitura do da quantidade total d token
// retorna a quantidade d tokens para construcao do .txt
int ler_int(LEITOR* l){
    int i;
    fread(&i, 1, sizeof(int), l->arquivo);
    return i;
}

// fecha o arquivo .bin
// se houver lixo, ignorar usando o retorno de "ler_int"
// Entrada: Ponteiro para leitor de .bin
// Pre-Condicao: Nenhum
// Pos-Condicao: arquivo fechado
// Retorno: Nenhum
void fechar_leitor_binario(LEITOR* l){
    fclose(l->arquivo);
}

#endif
