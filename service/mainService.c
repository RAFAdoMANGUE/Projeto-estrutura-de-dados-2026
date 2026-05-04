#include<stdio.h>
#include<stdlib.h>
#include "ListaService.c"
#include "matrizService.c"
#include "../utils/Utils.c"
#define MAX 100
int menu() {
    int opcao = 0;
    int contador=0;
    int i = 0;
    int linhaMax[MAX],colunaMax[MAX];
    Matriz_Esparsa *lista[MAX];
    for(i=0;i<MAX;i++){
        lista[i] = NULL;
    }

    do{
        printf("====================\n");

        printf("%10s","MENU\n");
        //printf("%10s", "1 - Criar Matriz\n");
        printf("%10s","2 - Criar uma nova matriz\n");
        printf("%10s", "3 - Mostrar lista\n");
        printf("%10s", "4 - Esvaziar matriz\n");
        printf("%10s","6 - Soma\n");
        printf("%10s", "0 - Para encerrar\n");

        printf("====================\n");

        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                printf("qual tamanho da sua matriz?: ");
                criarMatriz();
                break;
            case 2:
                printf("Qual dimensao da matriz?: linha, coluna: \n");
                int lin = 0,col = 0;
                float dado = 1;
                scanf("%d%d",&linhaMax[contador],&colunaMax[contador]);

                while(dado != 0){
                    printf("qual o dado, coluna e linha que precisa inserir: \n");
                    scanf("%f%d%d",&dado,&lin,&col);
                    if(validaTamanho(lin,col,linhaMax[contador],colunaMax[contador]))
                        inserirLista(&lista[contador],dado,lin,col);
                    else
                        printf("\nlinha ou coluna invalida.");
                }
                contador++;
                break;
            case 3:{
                int pesquisa=0;
                printf("\nQUal matriz voce quer pesquisar?: ");
                quantidadeListas(contador);
                scanf("%d",&pesquisa);
                mostrarLista(lista[pesquisa]);
                break;
            }
            case 4:{
                int pesquisa = 0;
                printf("\nQual matriz voce quer excluir?\n");
                scanf("%d",&pesquisa);
                liberarLista(&lista[pesquisa]);
                printf("\nLista excluida com sucesso. ");
                break;
            }
            case 5:
                DadosMatriz(&lista[contador]);
                break;
            case 6:
                printf("\nQuais matrizes voce quer somar:\n ");
                int pesquisaA=0,pesquisaB=0;
                quantidadeListas(contador);
                scanf("%d%d", &pesquisaA, &pesquisaB);
                if(linhaMax[pesquisaA] == linhaMax[pesquisaB] && colunaMax[pesquisaA] == colunaMax[pesquisaB]){
                    somaMatriz (lista[pesquisaA],lista[pesquisaB], &lista[contador]);
                    contador++;
                }
                else
                    printf("\ndimensoes diferentes.\n");

                break;
            default:
                printf("\nnenhuma funcao selecionada.\n");
        }
    }while(opcao != 0);

}

