#include <sys\timeb.h>
#include "no.h"
#include "leitor_token.h"
#include "arquivo_binario.h"
#include "arquivo_arvore.h"
#include "decodificador.h"

#define caracter 0
#define palavra 1

struct timeb inicio;

void marca_tempo() {
    ftime(&inicio);
}

void imprime_tempo() {
    struct timeb fim;
    ftime(&fim);
    int ms = fim.millitm - inicio.millitm + 1000*(fim.time - inicio.time);
    printf("%d ms\n", ms);
}

int compactar(int opcao, char nome_arquivo_entrada[], char nome_arquivo_saida[]) {
    ESCRITOR escritor;
    abrir_escritor_binario(&escritor, nome_arquivo_saida);

    LEITOR_TOKEN leitor;
    abrir_leitor_token(&leitor, nome_arquivo_entrada);

    NO* arvore = NULL;
    char token[256];

    printf("\nContando frequencia ");
    marca_tempo();
    for (;;) {
        int conseguiu;
        if (opcao == caracter){
            conseguiu = prox_char(&leitor, token);
        } else {
            conseguiu = prox_token(&leitor, token);
        }
        if (!conseguiu) break;
        arvore = conta_token(arvore, token);
    }
    imprime_tempo();

    printf("\nTransformando Arvore em Lista ");
    marca_tempo();
    NO* lista = NULL;
    lista = insere_arvore_lista(arvore, lista);
    imprime_tempo();


    printf("\nGerando arvore huffman ");
    marca_tempo();
    arvore = converter_lista_em_arvore_huffman2(lista);
    imprime_tempo();

    printf("\nDistribuindo binarios ");
    marca_tempo();
    char binario[256] = "";
    distribuir_binarios(arvore, binario, 0);
     imprime_tempo();

    // printf("\nGravando tamanho ");
    marca_tempo();
    grava_int(&escritor, arvore->contador);
    // imprime_tempo();

    printf("\nGravando arvore huffman ");
    //marca_tempo();
    grava_arvore_huffman(&escritor, arvore);
    imprime_tempo();

    printf("\nConvertendo Huffman em Arvore de Busca ");
    marca_tempo();
    arvore = insere_Huffman_em_busca(arvore, NULL);
    imprime_tempo();

    printf("\nCodificando arquivo ");
    marca_tempo();
    reiniciar_leitor(&leitor);
    for (;;) {
        int conseguiu;
        if(opcao == caracter){
            conseguiu = prox_char(&leitor, token);
        }else {
            conseguiu = prox_token(&leitor, token);
        }
        if (!conseguiu) break;
        NO* temp = busca_no_por_token(arvore, token);
        grava_binario(&escritor, temp->binario);
    }
    fechar_escritor_binario(&escritor);
    imprime_tempo();
    
    printf("\nFim\n");
}


int desc(char nome_arquivo_entrada[], char nome_arquivo_saida[]) {
    FILE *f = fopen(nome_arquivo_saida, "wb");
    LEITOR leitor, *l = &leitor;

    abrir_leitor_binario(l, nome_arquivo_entrada);
    int tamanho = ler_int(l);
    char str[256];
    NO* arvore = ler_arvore_huffman(l);
    for(int i = 0; i < tamanho; i++){
        decodifica_proximo_token(l, arvore, str);
        fprintf(f, "%s", str);
    }
    fclose(f);
    fechar_leitor_binario(l);
}

void main(){
    int operacao = 0;
    char entrada[50], saida[50];
    system("cls");
    printf("______________________________________________________________________\n\n");
    printf("\tTRABALHO 1 - PROJETO E ANALISE DE ALGORITMOS\n");
    printf("______________________________________________________________________\n\n");
    
    printf("    [1] - Compactar arquivo (por caracter).\n");
    printf("    [2] - Compactar arquivo (por palavra).\n");
    printf("    [3] - Descompactar arquivo (por caracter).\n\n");

    printf("Entre com uma das opcoes acima: ");
    scanf("%d", &operacao);

    switch(operacao){
        case 1:
            system("cls");
            printf("Entre com o nome do arquivo a ser compactado:\n");
            scanf("%s", &entrada);
            printf("Entre com o nome do arquivo de saida:\n");
            scanf("%s", &saida);
            compactar(caracter, entrada, saida);
            break;
        case 2:
            system("cls");
            printf("Entre com o nome do arquivo a ser compactado:\n");
            scanf("%s", &entrada);
            printf("Entre com o nome do arquivo de saida:\n");
            scanf("%s", &saida);
            compactar(palavra, entrada, saida);
            break;
        case 3:
            system("cls");
            printf("Entre com o nome do arquivo a ser descompactado:\n");
            scanf("%s", &entrada);
            printf("Entre com o nome do arquivo de saida:\n");
            scanf("%s", &saida);
            desc(entrada, saida);
            break;
        default:
            printf("Valor invalido\n");
    }
    printf("\nfim do programa!\n");
}