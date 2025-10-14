#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "vendas.h"


void menu_venda(void) {
    char op_venda;
    do {
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                                Módulo Venda                                 ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      1 - Cadastrar venda                                                    ♡\n");
        printf("♡      2 - Exibir dados da venda                                              ♡\n");
        printf("♡      3 - Alterar dados da venda                                             ♡\n");
        printf("♡      4 - Excluir venda                                                      ♡\n");
        printf("♡      0 - Retornar ao menu principal                                         ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("\nEscolha sua opção: ");
        scanf(" %c", &op_venda);
        
        switch(op_venda) {
            case '1':
                cadastrar_venda();
                break;
            case '2':
                exibir_venda();
                break;
            case '3':
                alterar_venda();
                break;
            case '4':
                excluir_venda();
                break;
            case '0':
                break;
            default:
                getchar();
                printf("\nPor favor, digite uma opção válida\n");
                getchar();
                break;
        }
    } while (op_venda != '0');
}


void cadastrar_venda(void) {
    Venda* venda = (Venda*) malloc(sizeof(*venda));
    FILE *arq_venda = fopen("vendas.DAT", "ab");
    if (!arq_venda) {
        printf("Não foi possível abrir o arquivo vendas.DAT\n");
        free(venda);
        getchar();
        return;
    }

    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                              Cadastrar Venda                                ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      CPF cliente: ");
    scanf("%s", venda->cpf);
    getchar();
    printf("♡      ID do produto: ");
    scanf("%s", venda->id_produto);
    getchar();
    printf("♡      Quantidade: ");
    scanf("%s", venda->quant);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    getchar();

    venda->status = 1; 
    fwrite(venda, sizeof(Venda), 1, arq_venda);
    fclose(arq_venda);
    free(venda);
    
    continuar_acao();
}


void exibir_venda(void) {
    Venda* venda = (Venda*) malloc(sizeof(*venda));
    FILE *arq_vendas = fopen("vendas.DAT", "rb");
    if (!arq_vendas) {
        printf("Não foi possível ler o arquivo vendas.DAT\n");
        free(venda);
        getchar();
        return;
    }

    char cpf_lido[12];
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                        Exibir Dados da Venda                                ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o CPF do cliente: ");
    scanf("%s", cpf_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    int encontrado = 0;
    while (fread(venda, sizeof(Venda), 1, arq_vendas)) {
        if (strcmp(venda->cpf, cpf_lido) == 0 && venda->status == 1) {
            printf("\nVenda encontrada!\n");
            printf("CPF: %s\n", venda->cpf);
            printf("ID do produto: %s\n", venda->id_produto);
            printf("Quantidade: %s\n", venda->quant);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nVenda não encontrada.\n");
    }

    fclose(arq_vendas);
    free(venda);
    getchar();
    continuar_acao();
}


void alterar_venda(void) {
    Venda* venda = (Venda*) malloc(sizeof(*venda));
    FILE *arq_vendas = fopen("vendas.DAT", "rb");
    if (!arq_vendas) {
        printf("Não foi possível ler o arquivo vendas.DAT\n");
        free(venda);
        getchar();
        return;
    }

    FILE *arq_temp = fopen("temp_vendas.DAT", "wb");
    if (!arq_temp) {
        printf("Não foi possível criar arquivo temporário\n");
        fclose(arq_vendas);
        free(venda);
        getchar();
        return;
    }

    char cpf_lido[12];
    int encontrado = 0;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                        Alterar Dados da Venda                               ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o ID da venda: ");
    scanf("%s",cpf_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(venda, sizeof(Venda), 1, arq_vendas)) {
        if (strcmp(venda->cpf, cpf_lido) != 0 || venda->status == 0) {
            fwrite(venda, sizeof(Venda), 1, arq_temp);
        } else {
            encontrado = 1;
        }
    }
    
    fclose(arq_vendas);
    free(venda);

    if (encontrado) {
        Venda* nova_venda = (Venda*) malloc(sizeof(*nova_venda));
        if (nova_venda == NULL) {
            printf("Erro ao alocar memória.\n");
            fclose(arq_temp);
            getchar();
            return;
        }

        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                             Novos dados da venda                            ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      CPF: ");
        scanf("%s",nova_venda->cpf);
        getchar();
        printf("♡      ID do Produto: ");
        scanf("%s",nova_venda->id_produto);
        getchar();
        printf("♡      Quantidade: ");
        scanf("%s",nova_venda->quant);
        getchar();
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        nova_venda->status = 1;
        fwrite(nova_venda, sizeof(Venda), 1, arq_temp);

        fclose(arq_temp);
        free(nova_venda);

        remove("vendas.DAT");
        rename("temp_vendas.DAT", "vendas.DAT");

        printf("\t\t Venda ALTERADA com sucesso! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;

    } else {
        fclose(arq_temp);
        remove("temp_vendas.DAT");
        printf("\t\t Venda NAO encontrada! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    }
    getchar();
    continuar_acao();
}


void excluir_venda(void) {
    Venda* venda = (Venda*) malloc(sizeof(*venda));
    FILE *arq_vendas = fopen("vendas.DAT", "r+b");
    if (!arq_vendas) {
        printf("Não foi possível ler o arquivo vendas.DAT\n");
        free(venda);
        getchar();
        return;
    }

    char cpf_lido[12];
    int encontrado = 0;

    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                              Excluir Venda                                  ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o ID da venda:                                                 ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(venda, sizeof(Venda), 1, arq_vendas)) {
        if (strcmp(venda->cpf, cpf_lido) == 0 && venda->status) {
            venda->status = 0; // marca como excluído
            fseek(arq_vendas, -sizeof(Venda), SEEK_CUR);
            fwrite(venda, sizeof(Venda), 1, arq_vendas);
            encontrado = 1;
            printf("\n♡ Venda encontrada e EXCLUÍDA com sucesso!\n");
            break;
        }
    }
    fclose(arq_vendas);
    free(venda);
    
    if (encontrado) {
        printf("\n♡ Venda NÃO encontrada! ♡\n");
    
    printf("♡ Pressione <ENTER> para continuar...");
    getchar();
    continuar_acao();
}
    