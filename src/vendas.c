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
    FILE *arq_venda;
    arq_venda = fopen("vendas.csv","at");
    char cpf[12];
    char id_produto[4];
    char quant[4];

    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                              Cadastrar Venda                                ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      CPF cliente: ");
    scanf("%s", cpf);
    getchar();
    printf("♡      ID do produto: ");
    scanf("%s", id_produto);
    getchar();
    printf("♡      Quantidade: ");
    scanf("%s", quant);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    getchar();

    fprintf(arq_venda,"%s;",cpf);
    fprintf(arq_venda,"%s;",id_produto);
    fprintf(arq_venda,"%s\n", quant);
    fclose(arq_venda);
    
    continuar_acao();
}


void exibir_venda(void) {
    char cpf[12];
    char cpf_lido[12];
    char id_produto[4];
    char quant[4];

    FILE *arq_vendas;
    arq_vendas = fopen("vendas.csv", "rt");
    if (arq_vendas == NULL) {
        printf("nao consigo ler nada");
        printf("pressione <enter>");
        getchar();
        return;
    }
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

    while (fscanf(arq_vendas, "%11[^;];%3[^;];%3[^\n]\n", cpf, id_produto, quant) == 3) {
        if (strcmp(cpf, cpf_lido) == 0) {
            printf("\nVenda encontrado!\n");
            printf("CPF: %s\n", cpf);
            printf("ID do produto: %s\n", id_produto);
            printf("Horas: %s\n", quant);
            fclose(arq_vendas);
            getchar();
            return;
        }
    }
    fclose(arq_vendas);
    printf("\nVenda não encontrado.\n");
    getchar();
    continuar_acao();
}


void alterar_venda(void) {
        Venda venda;
    FILE *arq_venda;
        arq_venda = fopen("venda.csv", "rt");
    if (arq_venda == NULL) {
        printf("Não foi possivel ler o arquivo de vendas");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    FILE *arq_temp;
    arq_temp = fopen("temp_venda.csv", "wt");
    if (arq_temp == NULL) {
        printf("Não foi possivel criar arquivo temporário");
        fclose(arq_venda);
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    char cpf_lido[12];
    int encontrado = 0;
    int tam;
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
    while (fscanf(arq_venda, "%11[^;];%3[^;];%3[^\n]\n",
        venda.cpf, venda.id_produto,venda.quant)==6) {
        if (strcmp(venda.cpf,cpf_lido)!=0){
            fprintf(arq_temp,"%s;",venda.cpf);
            fprintf(arq_temp,"%s;",venda.id_produto);
            fprintf(arq_temp,"%s\n",venda.quant);
        } else {
            encontrado = 1;
        }
    }
    
    fclose(arq_venda);

    if (encontrado) {
        Venda novo_venda;
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                            Novos dados de Cliente                           ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      CPF: ");
        scanf("%s",novo_venda.cpf);
        getchar();
        printf("♡      ID do Produto: ");
        scanf("%s",novo_venda.id_produto);
        getchar();
        printf("♡      Quantidade: ");
        scanf("%s",novo_venda.quant);
        getchar();
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

        fprintf(arq_temp,"%s;",novo_venda.cpf);
        fprintf(arq_temp,"%s;",novo_venda.id_produto);
        fprintf(arq_temp,"%s\n",novo_venda.quant);
        fclose(arq_temp);

        remove("venda.csv");
        rename("temp.csv","venda.csv");
        printf("\t\t Venda ALTERADA com sucesso! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;

    } else {
        printf("\t\t venda NAO encontrado! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    }
    getchar();
    continuar_acao();
}


void excluir_venda(void) {
    Venda venda;
    FILE *arq_vendas;
    FILE *arq_temp;
    char cpf_lido[12];
    int encontrado = 0;
    
    arq_vendas = fopen("vendas.csv", "rt");
    if (arq_vendas == NULL) {
        printf("Não foi possivel ler o arquivo vendas.csv\n");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    
    arq_temp = fopen("temp.csv", "wt");
    if (arq_temp == NULL) {
        printf("Não foi possivel criar o arquivo temp.csv\n");
        fclose(arq_vendas);
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }

    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                              Excluir Venda                                  ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o ID da venda:                                                 ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        while (fscanf(arq_vendas, "%11[^;];%3[^;];%3[^\n]\n",
        venda.cpf, venda.id_produto, venda.quant) == 3) {
        
        if (strcmp(venda.cpf, cpf_lido) != 0) {
            fprintf(arq_temp, "%s;%s;%s\n",
                venda.cpf, venda.id_produto, venda.quant);
        } else {
            encontrado = 1;
            printf("\n♡ Venda encontrada:\n");
            printf("♡ CPF: %s\n", venda.cpf);
            printf("♡ Produto: %s\n", venda.id_produto);
            printf("♡ Quantidade: %s\n", venda.quant);
        }
    }
    
    fclose(arq_vendas);
    fclose(arq_temp);
    
    if (encontrado) {
        remove("vendas.csv");
        rename("temp.csv", "vendas.csv");
        printf("\n♡ Venda EXCLUÍDA com sucesso! ♡\n");
    } else {
        remove("temp.csv");
        printf("\n♡ Venda NÃO encontrada! ♡\n");
    }
    
    printf("♡ Pressione <ENTER> para continuar...");
    getchar();
    continuar_acao();
}
    