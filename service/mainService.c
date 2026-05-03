#include<stdio.h>
#include<stdlib.h>
#include "ListaService.c"
#include "matrizService.c"
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
                        printf("linha ou coluna invalida.");
                }
                contador++;
                break;
            case 3:{
                int pesquisa=0;
                for(i=0;i<contador;i++){
                    printf("\nmatriz: %d",i);
                }
                printf("\nQUal matriz voce quer pesquisar?: ");
                scanf("%d",&pesquisa);
                mostrarLista(lista[pesquisa]);
                break;
            }
            case 4:
                liberarLista(&lista[contador]);
                break;
            case 5:
                DadosMatriz(&lista[contador]);
                break;
            default:
                printf("nenhuma funcao selecionada.\n");
        }
    }while(opcao != 0);

}

