#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "vendas.h"
#include "validacao.h"


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
        getchar();
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
    Venda* venda;
    venda = (Venda*) malloc(sizeof(*venda));
    FILE *arq_vendas = fopen("data/vendas.DAT", "ab");
    if (!arq_vendas) {
        printf("Não foi possível abrir o arquivo vendas.DAT\n");
        free(venda);
        getchar();
        return;
    }
    char entrada_id[10];
    char entrada_quant[10];
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                              Cadastrar Venda                                ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o CPF do cliente\n");
    ler_cpf(venda->cpf_cliente);
    printf("♡      Informe o CPF do funcionario\n");
    ler_cpf(venda->cpf_funcionario);
    printf("♡      ID do produto: \n");
    ler_id(entrada_id);
    venda->id_produto = atoi(entrada_id);
    ler_quantidade(entrada_quant);
    venda->quant = atoi(entrada_quant);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    fwrite(venda, sizeof(Venda), 1, arq_vendas);
    fclose(arq_vendas);
    free(venda);
    continuar_acao();
}


void exibir_venda(void) {
    Venda* venda;
    venda = (Venda*) malloc(sizeof(*venda));
    FILE *arq_vendas = fopen("data/vendas.DAT", "rb");
    if (!arq_vendas) {
        printf("Não foi possível ler o arquivo vendas.DAT\n");
        free(venda);
        printf("Pressione <ENTER> ...");
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
    printf("♡      Informe o CPF do cliente.\n");
    ler_cpf(cpf_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(venda,sizeof(Venda),1,arq_vendas)) {
        if (strcmp(venda->cpf_cliente,cpf_lido) == 0){
            printf("\t\t Venda encontrado! >>>> \n");
            printf("\t\tCPF Cliente: %s\n",venda->cpf_cliente);
            printf("\t\tCPF Funcionario: %s\n",venda->cpf_funcionario);
            printf("\t\tID do Produto: %d\n",venda-> id_produto);
            printf("\t\tQuantidade: %d\n",venda-> quant);
            fclose(arq_vendas);
            free(venda);
            continuar_acao();
            return;
        }
    }
    printf("\t\t Cliente NAO encontrado! >>>> \n");
    fclose(arq_vendas);
    free(venda);
    continuar_acao();
    return;
}


void alterar_venda(void) {
    Venda* venda;
    venda = (Venda*) malloc(sizeof(*venda));
    FILE *arq_vendas = fopen("data/vendas.DAT", "rb");
    if (!arq_vendas) {
        printf("Não foi possível ler o arquivo vendas.DAT\n");
        free(venda);
        getchar();
        return;
    }

    FILE *arq_temp = fopen("data/temp.DAT", "wb");
    if (!arq_temp) {
        printf("Não foi possível criar arquivo temporário\n");
        fclose(arq_vendas);
        free(venda);
        getchar();
        return;
    }
    char cpf_lido[12];
    int encontrado;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                        Alterar Dados da Venda                               ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o CPF do cliente: ");
    ler_cpf(cpf_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    while (fread(venda,sizeof(Venda),1,arq_vendas)) {
        if (strcmp(venda->cpf_cliente,cpf_lido) != 0){
            fwrite(venda,sizeof(Venda),1,arq_temp);
        } else {
            encontrado = True;
        }
    }
    
    fclose(arq_vendas);
    free(venda);

    if (encontrado) {
        Venda* nova_venda;
        nova_venda = (Venda*) malloc(sizeof(*nova_venda));
        system("clear||cls");
        char entrada_id[10];
        char entrada_quant[10];
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                             Novos dados da venda                            ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      Informe o CPF do cliente\n");
        ler_cpf(nova_venda->cpf_cliente);
        printf("♡      Informe o CPF do funcionario\n");
        ler_cpf(nova_venda->cpf_funcionario);
        printf("♡      ID do produto: \n");
        ler_id(entrada_id);
        nova_venda->id_produto = atoi(entrada_id);
        ler_quantidade(entrada_quant);
        nova_venda->quant = atoi(entrada_quant);
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        fwrite(nova_venda, sizeof(Venda), 1, arq_temp);
        fclose(arq_temp);
        free(nova_venda);
        remove("data/vendas.DAT");
        rename("data/temp.DAT", "data/vendas.DAT");
        printf("\t\t Venda ALTERADA com sucesso! >>>> \n");
        continuar_acao();
        return;
    } else {
        printf("\t\t Venda NÃO encontrada! >>>> \n");
        continuar_acao();
        return;
    }
}


void excluir_venda(void) {
    Venda* venda;
    venda = (Venda*) malloc(sizeof(*venda));
    FILE *arq_vendas = fopen("data/vendas.DAT", "rb");
    if (!arq_vendas) {
        printf("Não foi possível ler o arquivo vendas.DAT\n");
        free(venda);
        getchar();
        return;
    }
    FILE *arq_temp = fopen("data/temp.DAT", "ab");
    if (!arq_temp) {
        printf("Não foi possível criar arquivo temporário\n");
        fclose(arq_vendas);
        free(venda);
        getchar();
        return;
    }
    char cpf_lido[12];
    int encontrado = False;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                              Excluir Venda                                  ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o CPF do cliente:                                              ♡\n");
    ler_cpf(cpf_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(venda, sizeof(Venda), 1, arq_vendas)) {
        if (strcmp(venda->cpf_cliente, cpf_lido) != 0) {
            fwrite(venda, sizeof(Venda), 1, arq_temp);
        } else {
            encontrado = True;
        }
    }
    
    fclose(arq_vendas);
    fclose(arq_temp);
    free(venda);

    if (encontrado) {
        remove("data/vendas.DAT");
        rename("data/temp.DAT", "data/vendas.DAT");
        printf("\t\t Venda EXCLUIDA com sucesso! >>>> \n");
    } else {
        remove("data/temp.DAT");
        printf("\t\t Venda NAO encontrada! >>>> \n");
    }
    continuar_acao();
}