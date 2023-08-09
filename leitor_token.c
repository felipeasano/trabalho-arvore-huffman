#ifndef LEITOR_TOKEN_C
#define LEITOR_TOKEN_C

#include "leitor_token.h"

// Abre ao arquivo .txt a ser lido/compactado
// Entrada: Ponteiro para estrutura de leitor de arquivo, string contendo o nome do arquivo a ser lido
// Pre-Condicao: Nenhum
// Pos-Condicao: Arquivo aberto
// Retorno: Nenhum
void abrir_leitor_token(LEITOR_TOKEN* c, char *nomeArquivo){
    c->f = fopen(nomeArquivo, "rb");
    while(c->f == NULL){
        printf("Arquivo de entrada invalido, tente novamente:\n");
        scanf("%*c%s", nomeArquivo);
        c->f = fopen(nomeArquivo, "rb");
    }
    c->temp = '\0';
}

// Faz a leitura do proximo caracter do arquivo .txt 
// Entrada: Ponteiro para o leitor de arquivo .txt, poteiro de char para o caracter q sera lido
// Pre-Condicao: Arquivo Aberto
// Pos-Condicao: string de entrada recebe o proximo caracter
// Retorno: Retorna 1 caso tenha encontrado um token novo, 0 caso seja final d arquivo
int prox_char(LEITOR_TOKEN* leitor, char* s){
    char c = fgetc(leitor->f);
    if(feof(leitor->f)) return 0;
    *s = c;
    s++;
    *s = '\0';
    return 1;
}

// Valida se o caracter lido eh uma letra do alfabeto da lingua portuguesa
// Entrada: Caracter a ser validado
// Pre-Condicao: Nenhum
// Pos-Condicao: Nenhum
// Retorno: 1 caso a entrada seja uma letra pertencente ao alfabeto da lingua portuguesa
// 0 caso nao pertenca
int caracter_eh_letra(char c) {
    if ((c >= 'a' && c <= 'z') || c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c < 0) {
        return 1;
    } else {
        return 0;
    }
}

// Faz a leitura do proximo token no arquivo .txt
// Entrada: Ponteiro para o leitor do .txt, string que vai guardar o token
// Pre-Condicao: Arquivo aberto
// Pos-Condicao: string de entrada recebe o proximo token
// Retorno: 1 caso tenha lido um token, 0 caso nao encontre
int prox_token(LEITOR_TOKEN* w, char *s) {
    int i = 0;
    if (w->temp != '\0') {
        s[i] = w->temp;
        i++;
        w->temp = '\0';
        s[i] = '\0';
        return 1;
    }
    while (1) {
        char c = fgetc(w->f);
        if (feof(w->f)) {
            break;
        }
        if (caracter_eh_letra(c)) {
            s[i] = c;
            i++;
        } else {
            if (i == 0) {
                s[i] = c;
                i++;
                break;
            } else{
                w->temp = c;
                break;
            }   
        }
    }
    s[i] = '\0';
    return (i != 0);
}

// Volta a leitura para o comeco do .txt a ser compactado
// Entrada: Ponteiro do leitor
// Pre-Condicao: Arquivo aberto
// Pos-Condicao: Leitor vai para o comeco do arquivo .txt
// Retorno: Nenhum
void reiniciar_leitor(LEITOR_TOKEN* leitor) {
    fseek(leitor->f, 0, SEEK_SET);
}

#endif
