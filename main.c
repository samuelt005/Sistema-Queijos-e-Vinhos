#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "queijos.h"
#include "vinhos.h"
#include "global.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    int running = 1;
        while (running >= 1) {
            int selector1, opcao;

            cleanTerminal();

            printf("Bem vindo ao sistema de cadastro de queijos e vinhos!\n\n\n");

            printf("-------------- MENU --------------\n");
            printf("1 - Cadastrar\n");
            printf("2 - Consultar\n");
            printf("3 - Editar\n");
            printf("4 - Deletar\n");
            printf("0 - Sair\n\n");
            printf("Selecione a opção desejada: ");
            scanf("%i", &selector1);
            cleanTerminal();


            switch (selector1)
            {
            case 1:
                opcao = queijoOuVinho();
                if (opcao == 1) {
                    cadastrarQueijos();
                } else if (opcao == 2) {
                    cadastrarVinhos();
                };
                break;

            case 2:
                opcao = queijoOuVinho();
                if (opcao == 1) {
                    consultarQueijos();
                } else if (opcao == 2) {
                    consultarVinhos();
                };
                break;

            case 3:
                opcao = queijoOuVinho();
                if (opcao == 1) {
                    editarQueijos();
                } else if (opcao == 2) {
                    editarVinhos();
                };
                break;

            case 4:
                opcao = queijoOuVinho();
                if (opcao == 1) {
                    deletarQueijos();
                } else if (opcao == 2) {
                    deletarVinhos();
                };
                break;

            case 0:
                printf("Saindo... volte sempre! :)\n");
                sleep(2);
                return running = 0;

            default:
                printf("Opção Inválida!");
                break;
            }
    }
}
