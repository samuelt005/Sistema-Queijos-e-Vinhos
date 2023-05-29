#include "global.h"

void registerProduct (int productType) {

    productStruct newProduct;


    //Inserção de dados pelo usuário
    printf("Digite o número do lote: ");
    scanf("%d", &newProduct.lot); //NOLINT(cert-err34-c) <- remove o aviso do "scanf"
    printf("Digite a data de produção: ");
    scanf("%s", newProduct.production);
    printf("Digite o tipo do produto: ");
    scanf("%s", newProduct.type);
    printf("Digite a quantidade: ");
    scanf("%d", &newProduct.amount); //NOLINT(cert-err34-c) <- remove o aviso do "scanf"


    //Obtém a data e hora atual do sistema
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    // Extrai os componentes da data
    newProduct.day = localTime->tm_mday;
    newProduct.month = localTime->tm_mon + 1; // Os meses são indexados a partir de zero
    newProduct.year = localTime->tm_year + 1900; // Adiciona 1900 ao valor do ano



    // Registrar produto no arquivo data1.bin
    if (productType == 1) {
        FILE* file = fopen("data1.bin", "ab"); //Abre o arquivo
        if (file == NULL) {printf("Erro ao abrir o arquivo!\n"); return;} //Verifica se o arquivo existe
        fwrite(&newProduct, sizeof(productStruct), 1, file); //Escreve o produto
        fclose(file); //Fecha o arquivo
        printf("Lote de queijos cadastrado com sucesso!\n");
    }

    // Registrar produto no arquivo data2.bin
    if (productType == 2) {
        FILE* file = fopen("data2.bin", "ab"); //Abre o arquivo
        if (file == NULL) {printf("Erro ao abrir o arquivo!\n"); return;} //Verifica se o arquivo existe
        fwrite(&newProduct, sizeof(productStruct), 1, file); //Escreve o produto
        fclose(file); //Fecha o arquivo
        printf("Lote de vinhos cadastrado com sucesso!\n");
    }

}

void listProduct (int productType) {
    FILE* file;

    if (productType == 1) {
        file = fopen("data1.bin", "rb");
        if (file == NULL) {
            printf("Erro ao abrir o arquivo!\n");
            return;
        }
    }

    if (productType == 2) {
        file = fopen("data2.bin", "rb");
        if (file == NULL) {
            printf("Erro ao abrir o arquivo!\n");
            return;
        }
    }

    //Impressão dos produtos
    printf("Lote:\tData de produção:\tTipo:\t\tQuantidade:\tData de cadastro:\n");
    productStruct product;
    while (fread(&product, sizeof(product), 1, file) == 1) {
        printf("%d\t"
               "%s\t\t"
               "%s\t\t"
               "%d\t\t"
               "%d/%d/%d\n",
               product.lot,
               product.production,
               product.type,
               product.amount,
               product.day,
               product.month,
               product.year);
    }

    sleep(10);

    fclose(file);

}