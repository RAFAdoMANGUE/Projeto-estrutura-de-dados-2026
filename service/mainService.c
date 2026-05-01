#include<stdio.h>
#include<stdlib.h>
#include "ListaService.c"

int menu() {
    int opcao = 0;
    Matriz_Esparsa *lista = NULL;

    do{
        printf("====================\n");


        printf("%10s","MENU\n");
        printf("%10s", "1 - Criar Lista\n");
        printf("%10s","2 - Criar nodo\n");
        printf("%10s", "3 - Mostrar lista\n");
        printf("%10s", "0 - Para encerrar\n");

        printf("====================\n");

        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                printf("Qual nome da sua lista?: ");
                break;
            case 2:
                inserirLista(&lista);
                break;

            case 3:
                mostrarLista(lista);
                break;
        }
    }while(opcao != 0);

}

