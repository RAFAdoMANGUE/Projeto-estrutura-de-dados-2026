#include<stdio.h>
#include<stdlib.h>

int menu() {
    int opcao = 0;

    do{
        printf("====================\n");
        printf("%10s","MENU\n");
        printf("%10s","Criar nodo\n");
        printf("====================\n");

        scanf("%d", &opcao);

    }while(opcao != 0);

}

