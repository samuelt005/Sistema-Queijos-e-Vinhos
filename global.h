//Função para limpar o terminal
void cleanTerminal () {
    system("cls");
}

//Função de seleção entre queijos e vinhos
int queijoOuVinho () {
    int selector2;
    printf("-------------- MENU --------------\n");
    printf("1 - Lotes de Queijos\n");
    printf("2 - Garrafas de Vinhos\n");
    printf("0 - Voltar\n");
    printf("Selecione o que deseja cadastrar: ");
    scanf("%i", &selector2);
    printf("\n");

    switch (selector2)
    {
        case 1:
            return  1;

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
