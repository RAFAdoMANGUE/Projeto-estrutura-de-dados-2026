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
        printf("===========================\n");

        printf("%10s","MENU\n");
        printf("%10s", " 1 - Criar uma nova matriz\n");
        printf("%10s", " 2 - Mostrar lista\n");
        printf("%10s", " 3 - Esvaziar matriz\n");
        printf("%10s", " 4 - Mostrar matriz\n");
        printf("%10s", " 5 - Somar Matriz\n");
        printf("%10s", " 6 - Subtratir matriz\n");
        printf("%10s", " 7 - Multiplicar matriz\n");
        printf("%10s", " 8 - Gerar matriz transposta\n");
        printf("%10s", " 9 - Diagonal principal de uma matriz\n");
        printf("%10s", " 0 - Para encerrar\n");

        printf("===========================\n");

        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                printf("Qual dimensao da matriz?: linha, coluna: \n");
                int lin = 0,col = 0;
                float dado = 1;
                scanf("%d%d",&linhaMax[contador],&colunaMax[contador]);

                do{
                    printf("qual o dado, linha e coluna que precisa inserir: \n");
                    scanf("%f%d%d",&dado,&lin,&col);
                    if((validaTamanho(lin,col,linhaMax[contador],colunaMax[contador])) && (dado!=0))
                        inserirLista(&lista[contador],dado,lin,col);
                    else
                        printf("\nlinha ou coluna invalida.\n");
                }
                while(dado != 0);
                contador++;
                break;
            case 2:{
                int pesquisa=0;
                printf("\nQUal matriz voce quer pesquisar?: ");
                quantidadeListas(contador);
                scanf("%d",&pesquisa);
                mostrarLista(lista[pesquisa]);
                break;
            }
            case 3:{
                int pesquisa = 0;
                printf("\nQual matriz voce quer excluir?\n");
                quantidadeListas(contador);
                scanf("%d",&pesquisa);
                liberarLista(&lista[pesquisa]);
                printf("\nLista excluida com sucesso. ");
                break;
            }

            case 4:{
                printf("\nQual matriz voce quer mostrar?: \n");
                quantidadeListas(contador);
                int pesquisa;
                scanf("%d",&pesquisa);
                mostrarMatriz(lista[pesquisa],linhaMax[pesquisa],colunaMax[pesquisa]);
                break;
            }
            case 5:{
                printf("\nQuais matrizes voce quer somar:\n ");
                int pesquisaA=0,pesquisaB=0;
                quantidadeListas(contador);
                scanf("%d%d", &pesquisaA, &pesquisaB);
                if(linhaMax[pesquisaA] == linhaMax[pesquisaB] && colunaMax[pesquisaA] == colunaMax[pesquisaB]){
                    somaMatriz (lista[pesquisaA],lista[pesquisaB], &lista[contador]);
                    linhaMax[contador] = linhaMax[pesquisaA];
                    colunaMax[contador] = colunaMax[pesquisaA];
                    contador++;
                }
                else
                    printf("\ndimensoes diferentes.\n");
                break;
            }
            case 6:{
                int pesquisaA = 0,pesquisaB = 0;
                printf("\nquais matrizes voce quer subtrair?:\n ");
                quantidadeListas(contador);
                scanf("%d%d", &pesquisaA,&pesquisaB);
                if(linhaMax[pesquisaA] == linhaMax[pesquisaB] && colunaMax[pesquisaA] == colunaMax[pesquisaB]){
                    subMatriz(lista[pesquisaA],lista[pesquisaB], &lista[contador]);
                    linhaMax[contador] = linhaMax[pesquisaA];
                    colunaMax[contador] = colunaMax[pesquisaA];
                    contador++;
                }
                else
                    printf("\ndimensoes diferentes.\n");
                break;
            }
            case 7:{
                printf("\nQuais matrizes voces quer multiplicar?: \n");
                int pesquisaA=0,pesquisaB=0;
                quantidadeListas(contador);
                scanf("%d%d", &pesquisaA, &pesquisaB);
                if(colunaMax[pesquisaA] == linhaMax[pesquisaB]){
                    multMatriz (lista[pesquisaA],lista[pesquisaB], &lista[contador]);
                    linhaMax[contador] = linhaMax[pesquisaA];
                    colunaMax[contador] = colunaMax[pesquisaB];
                    contador++;
                }
                else
                    printf("\ndimensoes diferentes.\n");
                break;
            }
            case 8:{
                printf("\nQual matriz você quer deixar transposta? \n");
                int pesquisaA=0;
                quantidadeListas(contador);
                scanf("%d", &pesquisaA);
                MatrizTrans(lista[pesquisaA], &lista[contador]);
                linhaMax[contador] = colunaMax[pesquisaA];
                colunaMax[contador] = linhaMax[pesquisaA];
                contador++;
                printf("Matriz transposta gerada com sucesso! \n");
                break;
		    }
            case 9:{
                printf("\nQual matriz voce quer mostrar a diagonal principal?: \n");
                int pesquisaA=0;
                quantidadeListas(contador);
                scanf("%d",&pesquisaA);
                diagonalPrincipal(lista[pesquisaA],linhaMax[pesquisaA]);
                break;
            }
            default:
                printf("\nnenhuma funcao selecionada.\n");
        }
    }while(opcao != 0);

}

