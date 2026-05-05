// funções da lista
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "../model/Lista.h"


Matriz_Esparsa* CriarNodo(float dado,int lin,int col){
    Matriz_Esparsa *novo = (Matriz_Esparsa*) malloc(sizeof(Matriz_Esparsa));
    if(novo == NULL){
        return NULL;
    }
    novo -> dado = dado;
    novo -> lin = lin;
    novo -> col = col;
    novo -> prox = NULL;

    return novo;
}
bool validaTamanho(int lin, int col,int linhaMax,int colunaMax){
    return ((0<= lin) && (lin<linhaMax) && (0<=col)&&(col< colunaMax));
}

void inserirLista(Matriz_Esparsa **lista,float dado, int lin, int col){

    Matriz_Esparsa* novo = CriarNodo(dado,lin,col);
    if(novo == NULL){
        return;
    }
    novo -> prox = *lista;
    *lista = novo;
}
float listCompleta(Matriz_Esparsa *lista, int lin, int col) {
    while (lista != NULL) {
        if (lista->lin == lin && lista->col == col)
            return lista->dado;
        lista = lista->prox;
    }
    return 0;
}

void mostrarLista(Matriz_Esparsa *lista) {
    Matriz_Esparsa *atual = lista;

    if (atual == NULL) {
        printf("Lista vazia\n");
        return;
    }

    while (atual != NULL) {
        printf("Dado: %.2f | Linha: %d | Coluna: %d\n",
               atual->dado, atual->lin, atual->col);

        atual = atual->prox; // vai para o próximo nodo
    }
}
void mostrarMatriz(Matriz_Esparsa *lista,int linhaMaxima,int colunaMaxima) {
    Matriz_Esparsa *atual = lista;
    int i,j;
    if (atual == NULL) {
        printf("Lista vazia\n");
        return;
    }

    for(i=0;i<linhaMaxima;i++){
        printf("|");
        for(j=0;j<colunaMaxima;j++){
             printf("%8.2f ", listCompleta(lista, i, j));
            }
        printf("|\n");
    }
}

void liberarLista(Matriz_Esparsa **lista){
    Matriz_Esparsa *atual = *lista;
    while(atual != NULL){
        Matriz_Esparsa *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    *lista = NULL;
}


//OPERAÇÕES MATEMÁTICAS

void atualizaLista(Matriz_Esparsa **lista, float valor, int lin, int col) {
    Matriz_Esparsa *aux = *lista;

    while (aux != NULL) {
        if (aux->lin == lin && aux->col == col) {
            aux->dado += valor;
            return;
        }        aux = aux->prox;
    }
    inserirLista(lista, valor, lin, col);
}

void somaMatriz(Matriz_Esparsa *A, Matriz_Esparsa *B, Matriz_Esparsa **C) {

    while (A != NULL) {
        atualizaLista(C, A->dado, A->lin, A->col);
        A = A->prox;
    }
    while (B != NULL) {
        atualizaLista(C, B->dado, B->lin, B->col);
        B = B->prox;
    }
    printf("Operacao concluida.\n");
}


void subMatriz(Matriz_Esparsa *A, Matriz_Esparsa *B, Matriz_Esparsa **C) {

    while (A != NULL) {
        atualizaLista(C, A->dado, A->lin, A->col);
        A = A->prox;
    }
    while (B != NULL) {
        atualizaLista(C, -B->dado, B->lin, B->col);
        B = B->prox;
    }
    printf("Operacao concluida.\n");
}


void multMatriz(Matriz_Esparsa *A, Matriz_Esparsa *B, Matriz_Esparsa **C) {
    *C = NULL;
    if (A == NULL || B == NULL) {
    printf("Operacao concluida.\n");
        return;
    }
    Matriz_Esparsa *auxA = A;
    while (auxA != NULL) {
        Matriz_Esparsa *auxB = B;
        while (auxB != NULL) {
            if (auxA->col == auxB->lin) {
                float valor = auxA->dado * auxB->dado;
                atualizaLista(C, valor, auxA->lin, auxB->col);
            }
            auxB = auxB->prox;
        }
        auxA = auxA->prox;
    }
    printf("Operacao concluida.\n");
}

void MatrizTrans(Matriz_Esparsa *A, Matriz_Esparsa **T) {

    while (A != NULL) {
        inserirLista(T, A->dado, A->col, A->lin);
        A = A->prox;
    }

    printf("Transposta gerada.\n");
}


void diagonalPrincipal(Matriz_Esparsa *lista, int tamanho) {

    printf("Diagonal principal: ");

    for (int i = 0; i < tamanho; i++) {
        printf("%.2f ", listCompleta(lista, i, i));
    }

    printf("\n");
}
