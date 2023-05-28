#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#ifndef GLOBAL_H
#define GLOBAL_H


#define MAX_LENGTH 50



//GLOBAL FUNCTIONS

//Função de seleção entre queijos e vinhos
int generalSelector () {
    int selector2;
    printf("-------------- MENU --------------\n");
    printf("1 - Lotes de Queijos\n");
    printf("2 - Garrafas de Vinhos\n");
    printf("0 - Voltar\n");
    printf("Selecione o que deseja: ");
    scanf("%i", &selector2);
    printf("\n");

    switch (selector2)
    {
        case 1:
            return 1;

        case 2:
            return 2;

        case 0:
            printf("Voltando...\n");
            sleep(2);
            break;

        default:
            break;
    }
}


#endif // GLOBAL_H