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


