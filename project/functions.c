#include "global.h"

void deleteProduct(int productType) {
    FILE* file;
    char filename[20];
    int lotToDelete;

    if (productType == 1) {
        strcpy(filename, "data1.bin");
    } else if (productType == 2) {
        strcpy(filename, "data2.bin");
    }

    file = fopen(filename, "rb"); //Abrir o arquivo data em modo de leitura

    printf("Digite o número do lote para excluir: ");
    scanf("%d", &lotToDelete); //NOLINT(cert-err34-c) <- remove o aviso do "scanf"

    FILE* tempFile = fopen("temp.bin", "wb"); //Abrir o arquivo data em modo de escrita
    if (tempFile == NULL) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(file);
        return;
    }

    //Loop para copiar os dados para o arquivo temporário
    productStruct product;
    while (fread(&product, sizeof(product), 1, file) == 1) {
        if (product.lot != lotToDelete) {
            fwrite(&product, sizeof(product), 1, tempFile);
        }
    }

    //Fecha os arquivos
    fclose(file);
    fclose(tempFile);

    //Remove o arquivo original
    remove(filename);

    //Renomeia o arquivo temporário para o nome do arquivo original
    rename("temp.bin", filename);

    printf("Produto excluído com sucesso!\n");
    sleep(2);
}

void editProduct(int productType) {
    FILE* file;
    char filename[20];
    int lotToEdit, dataToEdit;

    if (productType == 1) {
        strcpy(filename, "data1.bin");
    } else if (productType == 2) {
        strcpy(filename, "data2.bin");
    }

    file = fopen(filename, "r+b"); //Abrir o arquivo data em modo de leitura

    printf("Digite o número do lote para editar: ");
    scanf("%d", &lotToEdit); //NOLINT(cert-err34-c) <- remove o aviso do "scanf"

    //Encontrar o lote do produto para editar
    productStruct product; // Declaração da variável product

    // Loop para procurar o produto com o número do lote a ser editado
    int found = 0; // Variável para verificar se o produto foi encontrado
    while (fread(&product, sizeof(product), 1, file) == 1) {
        if (product.lot == lotToEdit) {
            found = 1; // O produto foi encontrado
            break;
        }
    }

    //Menu para escolher o que deseja editar

    if (found) {
        printf("\n1 - Lote\n");
        printf("2 - Data de produção\n");
        printf("3 - Tipo\n");
        printf("4 - Quantidade\n");
        printf("0 - Cancelar\n");
        printf("Digite o que deseja editar: ");
        scanf("%d", &dataToEdit); //NOLINT(cert-err34-c) <- remove o aviso do "scanf"

        switch (dataToEdit) {
            case 1:
                printf("Digite o novo número do lote: ");
                scanf("%d", &product.lot);
                break;

            case 2:
                printf("Digite a nova data de produção: ");
                scanf("%s", product.production);
                break;

            case 3:
                printf("Digite o novo tipo do produto: ");
                scanf("%s", product.type);
                break;

            case 4:
                printf("Digite a nova quantidade: ");
                scanf("%d", &product.amount);
                break;

            case 0:
                printf("Voltando...\n");
                sleep(2);
                fclose(file);
                break;

            default:
                printf("Opção inválida!");
                sleep(2);
                break;
        }

        // Posicione o ponteiro do arquivo na posição correta para atualizar o produto
        fseek(file, -sizeof(product), SEEK_CUR);
        fwrite(&product, sizeof(product), 1, file);
        fclose(file);

        printf("Produto editado com sucesso!\n");
        sleep(2);
    } else {
        printf("Número do lote não encontrado!\n");
        sleep(2);
        fclose(file);
    }
}

void registerProduct (int productType) {

    productStruct newProduct;


    //Inserção de dados pelo usuário
    printf("Digite o número do lote: ");
    scanf("%d", &newProduct.lot); //NOLINT(cert-err34-c) <- remove o aviso do "scanf"
    //TODO Verificador de lotes duplicados
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
        FILE* file = fopen("data1.bin", "ab"); //Abrir o arquivo data em modo acrescentar
        if (file == NULL) {printf("Erro ao abrir o arquivo!\n"); return;} //Verifica se o arquivo existe
        fwrite(&newProduct, sizeof(productStruct), 1, file); //Escreve o produto
        fclose(file); //Fecha o arquivo
        printf("Lote de queijos cadastrado com sucesso!\n");
    }

    // Registrar produto no arquivo data2.bin
    if (productType == 2) {
        FILE* file = fopen("data2.bin", "ab"); //Abrir o arquivo data em modo acrescentar
        if (file == NULL) {printf("Erro ao abrir o arquivo!\n"); return;} //Verifica se o arquivo existe
        fwrite(&newProduct, sizeof(productStruct), 1, file); //Escreve o produto
        fclose(file); //Fecha o arquivo
        printf("Lote de vinhos cadastrado com sucesso!\n");
    }

}

void listProduct (int productType) {
    FILE* file;

    if (productType == 1) {
        file = fopen("data1.bin", "rb"); //Abrir o arquivo data em modo de leitura
        if (file == NULL) {
            printf("Arquivo não encontrado!\n");
            sleep(2);
            return;
        }
    }

    if (productType == 2) {
        file = fopen("data2.bin", "rb"); //Abrir o arquivo data em modo de leitura
        if (file == NULL) {
            printf("Arquivo não encontrado!\n");
            sleep(2);
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
               //TODO Imprimir tempo desde o cadastro do produto
    }

    fclose(file);

    int subSelector;

    printf("\n-------------- MENU --------------\n");
    printf("1 - Editar Produto\n");
    printf("2 - Excluir Produto\n");
    printf("0 - Sair\n\n");
    printf("Selecione a opção desejada: ");
    scanf("%d", &subSelector); //NOLINT(cert-err34-c) <- remove o aviso do "scanf"

    switch (subSelector)
    {
        //Case para editar produto
        case 1:
            editProduct (productType);
            break;

        //Case para excluir produto
        case 2:
            deleteProduct (productType);
            break;

        case 0:
            printf("Voltando...\n");
            sleep(2);
            fclose(file);
            break;

        default:
            printf("Opção inválida!");
            sleep(2);
            break;
    }
}