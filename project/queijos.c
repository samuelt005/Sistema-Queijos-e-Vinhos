#include "global.h"

struct structQueijo {
    int lote;
    char dataProducao[MAX_LENGTH];
    char tipo[MAX_LENGTH];
    int quantidade;
    int dia;
    int mes;
    int ano;
};

int cadastrarQueijos () {
    int running = 1;

    //Abertura do arquivo para salvamento dos dados
    FILE *data = fopen("data.txt", "a");
    if (data == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }

    while (running == 1) {

        //Nova estrutura de dados
        struct structQueijo novoRegistro;


        //Dados inseridos pelo usuário
        printf("Número do lote: ");
        scanf("%d", &novoRegistro.lote);

        printf("Data de produção no formato dd/mm/aaaa: ");
        scanf("%s", &novoRegistro.dataProducao);

        printf("Tipo do queijo: ");
        scanf("%s", &novoRegistro.tipo);

        printf("Quantidade no lote: ");
        scanf("%d", &novoRegistro.quantidade);


        //Obtém a data e hora atual do sistema
        time_t currentTime;
        time(&currentTime);
        struct tm *localTime = localtime(&currentTime);
        // Extrai os componentes da data
        novoRegistro.dia = localTime->tm_mday;
        novoRegistro.mes = localTime->tm_mon + 1; // Os meses são indexados a partir de zero
        novoRegistro.ano = localTime->tm_year + 1900; // Adiciona 1900 ao valor do ano


        //Registro do lote no arquivo
        fwrite(&novoRegistro, sizeof(struct structQueijo), 1, data);
        printf("Dados gravados com sucesso.\n");


        //Verificador de repetição do sistema de cadastro
        printf("Deseja cadastrar mais um lote?\n");
        printf("1 - Sim\n");
        printf("0 - Não\n");
        scanf("%d", &running);
    }

    //fechamento do arquivo
    fclose(data);
    return 0;
}

void consultarQueijos () {

}

void editarQueijos () {

}

void deletarQueijos () {

}