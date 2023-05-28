#include "global.h"
#include "functions.c"

int main() {
    setlocale(LC_ALL, "Portuguese");
    int running = 1;
        while (running == 1) {
            int selector, option;

            system("cls");

            printf("Bem vindo ao sistema de cadastro de queijos e vinhos!\n\n\n");

            printf("-------------- MENU --------------\n");
            printf("1 - Cadastrar\n");
            printf("2 - Consultar\n");
            printf("0 - Sair\n\n");
            printf("Selecione a opção desejada: ");
            scanf("%d", &selector); //NOLINT(cert-err34-c) <- remove o aviso do "scanf"
            system("cls");


            switch (selector)
            {
            case 1:
                option = generalSelector();
                if (option == 1) {
                    registerProduct(1);
                } else if (option == 2) {
                    registerProduct(2);
                }
                break;

            case 2:
                option = generalSelector();
                if (option == 1) {
                    listProduct(1);
                } else if (option == 2) {
                    listProduct(2);
                }
                break;

            case 0:
                printf("Saindo... volte sempre! :)\n");
                sleep(2);
                running = 0;
                break;

            default:
                printf("Opção inválida!");
                break;
            } //End Switch
    }
}
