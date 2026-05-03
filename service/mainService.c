#include<stdio.h>
#include<stdlib.h>
#include "ListaService.c"
#include "matrizService.c"
int menu() {
    int opcao = 0;
    Matriz_Esparsa *lista = NULL;

    do{
        printf("====================\n");

        printf("%10s","MENU\n");
        //printf("%10s", "1 - Criar Matriz\n");
        printf("%10s","2 - Criar nodo\n");
        printf("%10s", "3 - Mostrar lista\n");
        printf("%10s", "4 - Esvaziar lista\n");
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
                int linhaMax = 0,colunaMax = 0,lin = 0,col = 0;
                float dado = 1;
                scanf("%d%d",&linhaMax,&colunaMax);

                while(dado != 0){
                    printf("qual o dado, coluna e linha que precisa inserir: \n");
                    scanf("%f%d%d",&dado,&lin,&col);
                    if(validaTamanho(lin,col,linhaMax,colunaMax))
                        inserirLista(&lista,dado,lin,col);
                    else
                        printf("linha ou coluna invalida.");
                }

                break;
            case 3:
                mostrarLista(lista);
                break;
            case 4:
                liberarLista(&lista);
                break;
            case 5:
                DadosMatriz(&lista);
                break;
            default:
                printf("nenhuma função selecionada.\n");
        }
    }while(opcao != 0);

}

