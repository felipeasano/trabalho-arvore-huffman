#ifndef NO_C
#define NO_C

#include "no.h"
#include "min_heap.h"

// verifica se a lista ou arvore esta vazia
// Entrada: Ponteiro de no para lista ou arvore
// Pre-Condicao: Nenhum
// Pos-Condicao: Nenhum
//  Retorno: 1 caso esteja vazia, 0 caso contrario
int vazia(NO* l){
	return (l == NULL);
}

// Cria um o Vazio e seta o mesmo
// Entrada: Nenhum
// Pre-condicao: Nenhuma
// Pos-condicao: Espaco para novo no alocado
// retorno: Novo no;
NO* cria_no(){
	NO* novo = (NO*) malloc(sizeof(NO));
	novo->token = NULL;
	novo->binario = NULL;
	novo->contador = 0;
	novo->prox = NULL;
	novo->esq = NULL;
	novo->dir = NULL;
	return novo;
}

// Apos a leitura de um token novo do arquivo .txt, a funcao insere um novo no
// em uma estrutura de Arvore
// Pre-Condicao: Nao pode enviar String(token) vazia
// Pos-Condicao: Arvore atualizada com novo no ou no do token incrementado o contador
// Retorno: Retorna um novo no contendo o novo token na arvore, com o contador em 1
// ou retorna o no do token da existente incrementando o contador
NO* conta_token(NO* arvore, char c[]){
	if (vazia(arvore)) {
		NO* novo = cria_no();
		novo->token = (char*) malloc(strlen(c)+1);
		novo->contador++;
		strcpy(novo->token, c);
		return novo;
	}
	int dif = strcmp(c, arvore->token);
	if (!dif) {
		arvore->contador++;
		return arvore;
	}
	if(dif < 0){
		arvore->esq = conta_token(arvore->esq, c);
	}else{
		arvore->dir = conta_token(arvore->dir, c);
	}
	return arvore;
}

// insere arvore Binaria em Lista encadeada
// Entrada: Ponteiro de no para arvore e ponteirode no para Lista ecadeada
// Pre-Condicao: Nenhum
// Pos-Condicao: Arvore Binaria se torna uma Lista encadeada
// Retorno: Ponteiro de no para Lista encadeada
NO* insere_arvore_lista(NO* arvore, NO* lista){
	if(!arvore){
		return lista;
	}
	lista = insere_arvore_lista(arvore->esq, lista);
	lista = insere_arvore_lista(arvore->dir, lista);
	arvore->esq = NULL;
	arvore->dir = NULL;
	arvore->prox = lista;
	return arvore;
}


// calcula o tamanho de uma lista encadeada
// Entrada: ponteiro de no para lista
// Pre-Condicao: nanhuma
// Pos-Condicao: Nenhuma
// Retorno: inteiro contendo a quantidade de nos da lista
int tam_lista(NO* l){
	int cont = 0;
	while(l){
		cont++;
		l = l->prox;
	}
	return cont;
}

// converte uma lista encadeada em uma arvore de Huffman
// Entrada: Ponteiro de no para Lista a ser convertida
// Pre-Condicao: Nenhuma
// Pos-Condicao: Lista encadeada eh transformada em uma arovre de Huffman
// Retorno: Retorna a raiz da arvore de Huffman
NO* converter_lista_em_arvore_huffman2(NO* l){
	int tam_max = tam_lista(l) * 2;
	MIN_HEAP* min_heap = cria_min_heap(tam_max);
	while(l){
		NO* aux = l;
		l = l->prox;
		aux->prox = NULL;
		insere_min_heap(min_heap, aux);
	}

	while(min_heap->tam > 1){
		NO* esq = remove_min_heap(min_heap);
		NO* dir = remove_min_heap(min_heap);
		NO* novo = cria_no();
		novo->esq = esq;
		novo->dir = dir;
		novo->contador = esq->contador + dir->contador;
		insere_min_heap(min_heap, novo);
	}
	return min_heap->vet[0];
}

// Preenche a arvore huffman com seus devidos binarios nos nos
// Entrada: ponteiro de no para arvore, string contendo o binario(caminho), tamanho da string
// Pre-condicao: nenhum
// Pos-condicao: Arvore huffman atualizado com os binarios nos nos folha
// Retorno: Nenhum
void distribuir_binarios(NO* arvore, char binario[], int tamanho) {
	if(arvore->token != NULL){
		arvore->binario = (char*) malloc(tamanho+1);
		strcpy(arvore->binario, binario);
		return;
	}
	binario[tamanho] = '0';
	binario[tamanho+1] = '\0';
	distribuir_binarios(arvore->esq, binario, tamanho+1);
	binario[tamanho] = '1';
	binario[tamanho+1] = '\0';
	distribuir_binarios(arvore->dir, binario, tamanho+1);
}

// Faz a busca de um no da arvore usando o token como chave
// Entrada: Ponteiro de no para arvore
// Pre-Condicao: Nenhum
// Pos-Condicao: Nenhum
// retorno: devolve o no que contem o token buscado
NO* busca_no_por_token(NO* arvore, char token[]) {
	int dif = strcmp(token, arvore->token);
	if(dif == 0){
		return arvore;
	}
	if(dif > 0){
		return busca_no_por_token(arvore->dir, token);
	}else{
		return busca_no_por_token(arvore->esq, token);
	}
}

// transforma uma arvore de huffman em uma arvore de Binaria de Busca
// Entrada: Ponteiro para no de arvore huffman, ponteiro para no da nova arvore
// Pre-Condicao: Nenhum
// Pos-Condicao: arvore de Huffman eh transformada em uma arvore Binaria de Busca
// Retorno: Retorna um ponteiro de no para arvore binaria de busca
NO* insere_Huffman_em_busca(NO* huffman, NO* arvore){
	if(huffman->token){
		if(!arvore){
			return huffman;
		}
		if(strcmp(huffman->token, arvore->token) < 0){
			arvore->esq = insere_Huffman_em_busca(huffman, arvore->esq);
		}else{
			arvore->dir = insere_Huffman_em_busca(huffman, arvore->dir);
		}
		return arvore;
	}
	arvore = insere_Huffman_em_busca(huffman->esq, arvore);
	arvore = insere_Huffman_em_busca(huffman->dir, arvore);
	free(huffman);
	return arvore;
}

#endif
