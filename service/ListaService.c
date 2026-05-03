// funções da lista
#include<stdio.h>
#include<stdlib.h>
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

void inserirLista(Matriz_Esparsa **lista){
    float dado;
    int lin;
    int col;

    scanf("%f%d%d",&dado,&lin,&col);
    Matriz_Esparsa* novo = CriarNodo(dado,lin,col);
    if(novo == NULL){
        return NULL;
    }
    novo -> prox = *lista;
    *lista = novo;
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

void liberarLista(Matriz_Esparsa **lista){
    Matriz_Esparsa *atual = *lista;
    while(atual != NULL){
        Matriz_Esparsa *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    *lista = NULL;
}

ListaService:

void DadosMatriz(Matriz_Esparsa **lista) {
    int lin, col;
    float valor;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &lin);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &col);

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("Valor para posicao [%d][%d]: ", i, j);
            scanf("%f", &valor);
            if (valor != 0) {
                Matriz_Esparsa* novo = CriarNodo(valor, i, j);
                if (novo != NULL) {
                    novo->prox = *lista;
                    *lista = novo;
                }
            }
        }
    }
    printf("\nMatriz lida com sucesso.\n");

}

void somaMatriz(Matriz_Esparsa *A, Matriz_Esparsa *B, Matriz_Esparsa **C) {
    int linhas, colunas;
    float mA, mB, soma;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {

            mA = 0;
            Matriz_Esparsa *auxA = A;
            while (auxA != NULL) {
                if (auxA->lin == i && auxA->col == j) {
                    mA = auxA->dado;
                    break;
                }
                auxA = auxA->prox;
            }

            mB = 0;
            Matriz_Esparsa *auxB = B;
            while (auxB != NULL) {
                if (auxB->lin == i && auxB->col == j) {
                    mB = auxB->dado;
                    break;
                }
                auxB = auxB->prox;
            }
            soma = mA + mB;
            if (soma != 0) {
                Matriz_Esparsa *novo = CriarNodo(soma, i, j);
                if (novo != NULL) {
                    novo->prox = *C;
                    *C = novo;
                }
            }
        }
    }
    printf("Operacao de soma concluida.\n");
}


