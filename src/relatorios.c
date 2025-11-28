#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "relatorios.h"
#include "clientes.h"
#include "funcionarios.h"
#include "quartos.h"
#include "hospedagem.h"
#include "produtos.h"
#include "vendas.h"
#include "validacao.h"

void menu_relatorio(void) {
    int op_relatorio;
    do {
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                              Módulo Relatório                               ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      1  - Relatórios de Clientes                                            ♡\n");
        printf("♡      2  - Relatórios de Funcionários                                        ♡\n");
        printf("♡      3  - Relatórios de Quartos                                             ♡\n");
        printf("♡      4  - Relatórios de Hospedagens                                         ♡\n");
        printf("♡      5  - Relatórios de Produtos                                            ♡\n");
        printf("♡      6  - Relatórios de Vendas                                              ♡\n");
        printf("♡      0  - Retornar ao Menu Principal                                        ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("\n");
        printf("Escolha sua opção: ");
        scanf(" %d", &op_relatorio);
        getchar();
        
        switch (op_relatorio) {
        case 0:
            break;
        case 1:
            menu_relatorio_clientes();
            break;
        case 2:
            menu_relatorio_funcionarios();
            break;
        case 3:
            menu_relatorio_quartos();
            break;
        case 4:
            menu_relatorio_hospedagens();
            break;
        case 5:
            menu_relatorio_produtos();
            break;
        case 6:
            menu_relatorio_vendas();
            break;
        default:
            printf("\n");
            printf("Por favor, digite uma opção válida");
            getchar();
            break;
        }
    } while (op_relatorio != 0);
}

// ============================= MENU DOS RELATÓRIOS =============================

void menu_relatorio_clientes(void) {
    int op_relatorio;
    do {
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                           Relatórios de Clientes                            ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      1  - Lista geral de clientes                                           ♡\n");
        printf("♡      2  - Lista geral de clientes (Ordem Alfabética)                        ♡\n");
        printf("♡      3  - Lista clientes por nome                                           ♡\n");
        printf("♡      0  - Retornar ao Menu de Relatórios                                    ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("\n");
        printf("Escolha sua opção: ");
        scanf(" %d", &op_relatorio);
        getchar();
        
        switch (op_relatorio) {
        case 0:
            break;
        case 1:
            lista_geral_clientes();
            break;
        case 2:
            lista_geral_clientes_ordenado();
            break;
        case 3:
            clientes_por_nome();
            break;
        default:
            printf("\n");
            printf("Por favor, digite uma opção válida");
            getchar();
            break;
        }
    } while (op_relatorio != 0);
}

void menu_relatorio_funcionarios(void) {
    int op_relatorio;
    do {
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                         Relatórios de Funcionários                          ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      1  - Lista geral de funcionários                                       ♡\n");
        printf("♡      2  - Lista geral de funcionários (Ordem Alfabética)                     ♡\n");
        printf("♡      3  - Lista funcionarios por cargo                                      ♡\n");
        printf("♡      0  - Retornar ao Menu de Relatórios                                    ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("\n");
        printf("Escolha sua opção: ");
        scanf(" %d", &op_relatorio);
        getchar();
        
        switch (op_relatorio) {
        case 0:
            break;
        case 1:
            lista_geral_funcionarios();
            break;
        case 2:
            lista_geral_funcionarios_ordenado();
            break;
        case 3:
            funcionarios_por_cargo();
            break;
        default:
            printf("\n");
            printf("Por favor, digite uma opção válida");
            getchar();
            break;
        }
    } while (op_relatorio != 0);
}

void menu_relatorio_quartos(void) {
    int op_relatorio;
    do {
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                            Relatórios de Quartos                            ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      1  - Lista geral de quartos                                            ♡\n");
        printf("♡      2  - Lista quartos por tipo                                            ♡\n");
        printf("♡      3  - Lista Geral de Quartos (Ordem Numerica)                           ♡\n");
        printf("♡      0  - Retornar ao Menu de Relatórios                                    ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("\n");
        printf("Escolha sua opção: ");
        scanf(" %d", &op_relatorio);
        getchar();
        
        switch (op_relatorio) {
        case 0:
            break;
        case 1:
            lista_geral_quartos();
            break;
        case 2:
            quartos_por_tipo();
            break;
        case 3:
            lista_geral_quartos_ordenado();
            break;
        default:
            printf("\n");
            printf("Por favor, digite uma opção válida");
            getchar();
            break;
        }
    } while (op_relatorio != 0);
}

void menu_relatorio_hospedagens(void) {
    int op_relatorio;
    do {
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                        Relatórios de Hospedagens                            ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      1  - Lista geral de hospedagens                                        ♡\n");
        printf("♡      2  - Lista hospedagem por cliente                                      ♡\n");
        printf("♡      3  - Lista geral de hospedagens ordenada                               ♡\n");
        printf("♡      0  - Retornar ao Menu de Relatórios                                    ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("\n");
        printf("Escolha sua opção: ");
        scanf(" %d", &op_relatorio);
        getchar();
        
        switch (op_relatorio) {
        case 0:
            break;
        case 1:
            lista_geral_hospedagens();
            break;
        case 2:
            hospedagens_por_cliente();
            break;
        case 3:
            lista_geral_hospedagens_ordenado();
            break;
        default:
            printf("\n");
            printf("Por favor, digite uma opção válida");
            getchar();
            break;
        }
    } while (op_relatorio != 0);
}

void menu_relatorio_produtos(void) {
    int op_relatorio;
    do {
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                            Relatórios de Produtos                           ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      1  - Lista geral de produtos                                           ♡\n");
        printf("♡      2  - Lista geral de produtos (Ordem Alfabética)                        ♡\n");
        printf("♡      3  - Lista produtos por nome                                           ♡\n");
        printf("♡      0  - Retornar ao Menu de Relatórios                                    ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("\n");
        printf("Escolha sua opção: ");
        scanf(" %d", &op_relatorio);
        getchar();
        
        switch (op_relatorio) {
        case 0:
            break;
        case 1:
            lista_geral_produtos();
            break;
        case 2:
            lista_geral_produtos_ordenado();
            break;
        case 3:
            produtos_por_nome();
            break;
        default:
            printf("\n");
            printf("Por favor, digite uma opção válida");
            getchar();
            break;
        }
    } while (op_relatorio != 0);
}

void menu_relatorio_vendas(void) {
    int op_relatorio;
    do {
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                           Relatórios de Vendas                              ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      1  - Lista geral de vendas                                             ♡\n");
        printf("♡      2  - Lista venda por cliente                                           ♡\n");
        printf("♡      3  - Lista venda por funcionario                                       ♡\n");
        printf("♡      4  - Lista geral de vendas ordenada                                    ♡\n");
        printf("♡      0  - Retornar ao Menu de Relatórios                                    ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("\n");
        printf("Escolha sua opção: ");
        scanf(" %d", &op_relatorio);
        getchar();
        
        switch (op_relatorio) {
        case 0:
            break;
        case 1:
            lista_geral_vendas();
            break;
        case 2:
            vendas_por_cliente();
            break;
        case 3:
            vendas_por_funcionario();
            break;
        case 4:
            lista_geral_vendas_ordenado();
            break;
        default:
            printf("\n");
            printf("Por favor, digite uma opção válida");
            getchar();
            break;
        }
    } while (op_relatorio != 0);
}

// ============================= RELATÓRIOS GERAIS =============================

void lista_geral_clientes(void) {
    Cliente* cliente;
    cliente = (Cliente*)malloc(sizeof(*cliente));
    FILE *arq_clientes;
    arq_clientes = fopen("data/clientes.DAT", "rb");
    if (arq_clientes == NULL) {
        printf("Não foi possivel ler o arquivo clientes.dat\n");
        printf("pressione <enter>\n");
        getchar();
        return;
    }
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Lista Geral de Clientes                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(cliente,sizeof(Cliente),1,arq_clientes)) {
        if (cliente->status){
            printf("\n");
            printf("\t\tCPF: %s\n",cliente->cpf);
            printf("\t\tNome: %s\n",cliente->nome);
            printf("\t\tData de nascimento: %s\n",cliente->nasc);
            printf("\t\tTelefone: %s\n",cliente->telef);
            printf("\t\tEmail: %s\n",cliente->email);
        }
    }
    fclose(arq_clientes);
    free(cliente);
    continuar_acao();
}

void lista_geral_funcionarios(void) {
    Funcionario* funcionario;
    funcionario = (Funcionario*)malloc(sizeof(*funcionario));
    FILE *arq_funcionario;
    arq_funcionario = fopen("data/funcionarios.DAT", "rb");
    if (arq_funcionario == NULL) {
        printf("Não foi possivel ler o arquivo funcionarios.dat\n");
        printf("pressione <enter>\n");
        getchar();
        return;
    }
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                         Lista Geral de Funcionários                         ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(funcionario,sizeof(Funcionario),1,arq_funcionario)) {
        if (funcionario->status){
            printf("\n");
            printf("\t\tCPF: %s\n",funcionario->cpf);
            printf("\t\tNome: %s\n",funcionario->nome);
            printf("\t\tTelefone: %s\n",funcionario->telefone);
            printf("\t\tEmail: %s\n",funcionario->email);
            printf("\t\tCargo: %s\n",funcionario->cargo);
            printf("\t\tSalário: %f\n",funcionario->salario);
        }
    }
    fclose(arq_funcionario);
    free(funcionario);
    continuar_acao();
}

void lista_geral_quartos(void) {
    Quarto* quarto;
    quarto = (Quarto*)malloc(sizeof(*quarto));
    FILE *arq_quartos;
    arq_quartos = fopen("data/quartos.DAT", "rb");
    if (arq_quartos == NULL) {
        printf("Não foi possivel ler o arquivo quartos.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Lista Geral de Quartos                           ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(quarto,sizeof(Quarto),1,arq_quartos)) {
        if (quarto->status){
            printf("\n");
            printf("\t\tID: %d\n",quarto->id);
            printf("\t\tTipo: %s\n",NOME_TIPOS_QUARTO[quarto->tipo]);
            printf("\t\tDescricao: %s\n",quarto->descricao);
            printf("\t\tPreco/hora: %f\n",quarto->preco_hora);
            printf("\t\tPreco/diaria: %f\n",quarto->preco_diaria);
        }
    }
    fclose(arq_quartos);
    free(quarto);
    continuar_acao();
}

void lista_geral_hospedagens(void) {
    Hospedagem* hospedagem;
    hospedagem = (Hospedagem*)malloc(sizeof(*hospedagem));
    FILE *arq_hospedagem;
    arq_hospedagem = fopen("data/hospedagem.DAT", "rb");
    if (arq_hospedagem == NULL) {
        printf("Não foi possivel ler o arquivo hospedagem.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    char* nome_cliente;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                         Lista Geral de Hospedagens                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(hospedagem,sizeof(Hospedagem),1,arq_hospedagem)) {
        if (hospedagem->status){
            nome_cliente = get_nome_cliente(hospedagem->cpf);
            printf("\n");
            printf("\t\tCPF Cliente: %s\n",hospedagem->cpf);
            printf("\t\tNome Cliente: %s\n",nome_cliente);
            printf("\t\tID do Quarto: %d\n",hospedagem->id_quarto);
            printf("\t\tHoras: %d\n",hospedagem->horas);
        }
    }
    fclose(arq_hospedagem);
    free(hospedagem);
    continuar_acao();
}

void lista_geral_produtos(void){
    Produto* produto;
    produto = (Produto*)malloc(sizeof(*produto));
    FILE *arq_produtos;
    arq_produtos = fopen("data/produtos.DAT", "rb");
    if (arq_produtos == NULL) {
        printf("Não foi possivel ler o arquivo produtos.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Lista Geral de Produtos                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(produto,sizeof(Produto),1,arq_produtos)) {
        if (produto->status){
            printf("\n");
            printf("\t\tID: %d\n",produto->id);
            printf("\t\tNome: %s\n",produto->nome);
            printf("\t\tDescricao: %s\n",produto->descricao);
            printf("\t\tPreco: %f\n",produto->preco);
            printf("\t\tQuantidade: %d\n",produto->quant);
        }
    }
    fclose(arq_produtos);
    free(produto);
    continuar_acao();
}

void lista_geral_vendas(void) {
    Venda* venda;
    venda = (Venda*)malloc(sizeof(*venda));
    FILE *arq_vendas;
    arq_vendas = fopen("data/vendas.DAT", "rb");
    if (arq_vendas == NULL) {
        printf("Não foi possivel ler o arquivo vendas.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    char* nome_cliente;
    char* nome_funcionario;
    char* nome_produto;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Lista Geral de Vendas                            ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(venda,sizeof(Venda),1,arq_vendas)) {
        if (venda->status){
            nome_cliente = get_nome_cliente(venda->cpf_cliente);
            nome_funcionario = get_nome_funcionario(venda->cpf_funcionario);
            nome_produto = get_nome_produto(venda->id_produto);
            printf("\n");
            printf("\t\tCPF Cliente: %s\n",venda->cpf_cliente);
            printf("\t\tNome Cliente: %s\n",nome_cliente);
            printf("\t\tCPF Funcionario: %s\n",venda->cpf_funcionario);
            printf("\t\tNome Funcionario: %s\n",nome_funcionario);
            printf("\t\tID do Produto: %d\n",venda->id_produto);
            printf("\t\tNome Produto: %s\n",nome_produto);
            printf("\t\tQuantidade: %d\n",venda->quant);
        }
    }
    fclose(arq_vendas);
    free(venda);
    continuar_acao();
}

// ============================= RELATÓRIOS ESPECÍFICOS =============================

void clientes_por_nome(void) {
    Cliente* cliente;
    cliente = (Cliente*)malloc(sizeof(*cliente));
    FILE *arq_clientes;
    arq_clientes = fopen("data/clientes.DAT", "rb");
    if (arq_clientes == NULL) {
        printf("Não foi possivel ler o arquivo clientes.dat\n");
        printf("pressione <enter>\n");
        getchar();
        return;
    }
    char nome_lido[51];
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Clientes por nome                                ♡\n");
    printf("♡                                                                             ♡\n");
    ler_nome(nome_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    printf("Busca: %s\n",nome_lido);
    while (fread(cliente,sizeof(Cliente),1,arq_clientes)) {
        if (strstr(cliente->nome,nome_lido) != NULL){
            printf("\n");
            printf("\t\tCPF: %s\n",cliente->cpf);
            printf("\t\tNome: %s\n",cliente->nome);
            printf("\t\tData de nascimento: %s\n",cliente->nasc);
            printf("\t\tTelefone: %s\n",cliente->telef);
            printf("\t\tEmail: %s\n",cliente->email);
        }
    }
    fclose(arq_clientes);
    free(cliente);
    continuar_acao();
}

void quartos_por_tipo(void) {
    Quarto* quarto;
    quarto = (Quarto*)malloc(sizeof(*quarto));
    FILE *arq_quartos;
    arq_quartos = fopen("data/quartos.DAT", "rb");
    if (arq_quartos == NULL) {
        printf("Não foi possivel ler o arquivo quartos.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    int tipo_lido;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Quartos por tipo                                 ♡\n");
    printf("♡                                                                             ♡\n");
    printf("\n\n--- Tipos de Quarto Disponíveis ---\n");
    for (int i = 0; i < 4; i++) {
        printf("\t%d - %s\n", i + 1, NOME_TIPOS_QUARTO[i]);
    }
    tipo_lido = ler_tipo();
    tipo_lido--;
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    printf("Busca: %s\n",NOME_TIPOS_QUARTO[tipo_lido]);
    while (fread(quarto,sizeof(Quarto),1,arq_quartos)){
        if (quarto->tipo == (tipo_quarto)tipo_lido){
            printf("\n");
            printf("\t\tID: %d\n",quarto->id);
            printf("\t\tTipo: %s\n",NOME_TIPOS_QUARTO[quarto->tipo]);
            printf("\t\tDescricao: %s\n",quarto->descricao);
            printf("\t\tPreco/hora: %f\n",quarto->preco_hora);
            printf("\t\tPreco/diaria: %f\n",quarto->preco_diaria);
        }
    }
    fclose(arq_quartos);
    free(quarto);
    continuar_acao();
}

void produtos_por_nome(void) {
    Produto* produto;
    produto = (Produto*)malloc(sizeof(*produto));
    FILE *arq_produtos;
    arq_produtos = fopen("data/produtos.DAT", "rb");
    if (arq_produtos == NULL) {
        printf("Não foi possivel ler o arquivo produtos.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    char nome_lido[51];
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                               Produtos por nome                             ♡\n");
    printf("♡                                                                             ♡\n");
    ler_nome(nome_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    printf("Busca: %s\n",nome_lido);
    while (fread(produto,sizeof(Produto),1,arq_produtos)) {
        if (strstr(produto->nome,nome_lido) != NULL) {
            printf("\n");
            printf("\t\tID: %d\n",produto->id);
            printf("\t\tNome: %s\n",produto->nome);
            printf("\t\tDescricao: %s\n",produto->descricao);
            printf("\t\tPreco: %f\n",produto->preco);
            printf("\t\tQuantidade: %d\n",produto->quant);
        }
    }
    fclose(arq_produtos);
    free(produto);
    continuar_acao();
}

void funcionarios_por_cargo(void){
    Funcionario* funcionario;
    funcionario = (Funcionario*)malloc(sizeof(*funcionario));
    FILE *arq_funcionario;
    arq_funcionario = fopen("data/funcionarios.DAT", "rb");
    if (arq_funcionario == NULL) {
        printf("Não foi possivel ler o arquivo funcionarios.dat\n");
        printf("pressione <enter>\n");
        getchar();
        return;
    }
    char cargo_lido[20];
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                             Funcionarios por cargo                          ♡\n");
    printf("♡                                                                             ♡\n");
    ler_cargo(cargo_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    printf("Busca: %s\n",cargo_lido);
    while (fread(funcionario,sizeof(Funcionario),1,arq_funcionario)) {
        if (strstr(funcionario->cargo,cargo_lido) != NULL){
            printf("\n");
            printf("\t\tCPF: %s\n",funcionario->cpf);
            printf("\t\tNome: %s\n",funcionario->nome);
            printf("\t\tTelefone: %s\n",funcionario->telefone);
            printf("\t\tEmail: %s\n",funcionario->email);
            printf("\t\tCargo: %s\n",funcionario->cargo);
            printf("\t\tSalário: %f\n",funcionario->salario);
        }
    }
    fclose(arq_funcionario);
    free(funcionario);
    continuar_acao();
}

void hospedagens_por_cliente(void){
    Hospedagem* hospedagem;
    hospedagem = (Hospedagem*)malloc(sizeof(*hospedagem));
    FILE *arq_hospedagem;
    arq_hospedagem = fopen("data/hospedagem.DAT", "rb");
    if (arq_hospedagem == NULL) {
        printf("Não foi possivel ler o arquivo hospedagem.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    char nome_lido[51];
    char* nome_cliente;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                         Hospedagens por cliente                             ♡\n");
    printf("♡                                                                             ♡\n");
    ler_nome(nome_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    printf("Busca: %s\n",nome_lido);
    while (fread(hospedagem,sizeof(Hospedagem),1,arq_hospedagem)) {
        nome_cliente = get_nome_cliente(hospedagem->cpf);
        if (strstr(nome_cliente,nome_lido) != NULL){
            printf("\n");
            printf("\t\tCPF Cliente: %s\n",hospedagem->cpf);
            printf("\t\tNome Cliente: %s\n",nome_cliente);
            printf("\t\tID do Quarto: %d\n",hospedagem->id_quarto);
            printf("\t\tHoras: %d\n",hospedagem->horas);
        }
    }
    fclose(arq_hospedagem);
    free(hospedagem);
    continuar_acao();
}

void vendas_por_cliente(void) {
    Venda* venda;
    venda = (Venda*)malloc(sizeof(*venda));
    FILE *arq_vendas;
    arq_vendas = fopen("data/vendas.DAT", "rb");
    if (arq_vendas == NULL) {
        printf("Não foi possivel ler o arquivo vendas.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    system("clear||cls");
    mostrar_cabecalho();
    char nome_lido[51];
    char* nome_cliente;
    char* nome_funcionario;
    char* nome_produto;
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Vendas por cliente                               ♡\n");
    printf("♡                                                                             ♡\n");
    ler_nome(nome_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    printf("Busca: %s\n",nome_lido);
    while (fread(venda,sizeof(Venda),1,arq_vendas)) {
        nome_cliente = get_nome_cliente(venda->cpf_cliente);
        nome_funcionario = get_nome_funcionario(venda->cpf_funcionario);
        nome_produto = get_nome_produto(venda->id_produto);
        if (strstr(nome_cliente,nome_lido) != NULL){
            printf("\n");
            printf("\t\tCPF Cliente: %s\n",venda->cpf_cliente);
            printf("\t\tNome Cliente: %s\n",nome_cliente);
            printf("\t\tCPF Funcionario: %s\n",venda->cpf_funcionario);
            printf("\t\tNome Funcionario: %s\n",nome_funcionario);
            printf("\t\tID do Produto: %d\n",venda->id_produto);
            printf("\t\tNome Produto: %s\n",nome_produto);
            printf("\t\tQuantidade: %d\n",venda->quant);
        }
    }
    fclose(arq_vendas);
    free(venda);
    continuar_acao();
}

void vendas_por_funcionario(void) {
    Venda* venda;
    venda = (Venda*)malloc(sizeof(*venda));
    FILE *arq_vendas;
    arq_vendas = fopen("data/vendas.DAT", "rb");
    if (arq_vendas == NULL) {
        printf("Não foi possivel ler o arquivo vendas.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    system("clear||cls");
    mostrar_cabecalho();
    char nome_lido[51];
    char* nome_cliente;
    char* nome_funcionario;
    char* nome_produto;
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                          Vendas por funcionario                             ♡\n");
    printf("♡                                                                             ♡\n");
    ler_nome(nome_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    printf("Busca: %s\n",nome_lido);
    while (fread(venda,sizeof(Venda),1,arq_vendas)) {
        nome_cliente = get_nome_cliente(venda->cpf_cliente);
        nome_funcionario = get_nome_funcionario(venda->cpf_funcionario);
        nome_produto = get_nome_produto(venda->id_produto);
        if (strstr(nome_funcionario,nome_lido) != NULL){
            printf("\n");
            printf("\t\tCPF Cliente: %s\n",venda->cpf_cliente);
            printf("\t\tNome Cliente: %s\n",nome_cliente);
            printf("\t\tCPF Funcionario: %s\n",venda->cpf_funcionario);
            printf("\t\tNome Funcionario: %s\n",nome_funcionario);
            printf("\t\tID do Produto: %d\n",venda->id_produto);
            printf("\t\tNome Produto: %s\n",nome_produto);
            printf("\t\tQuantidade: %d\n",venda->quant);
        }
    }
    fclose(arq_vendas);
    free(venda);
    continuar_acao();
}

// ============================= RELATÓRIOS ORDENADOS =============================

typedef struct cliente_node {
    Cliente cliente;
    struct cliente_node* prox;
} ClienteNode;

void lista_geral_clientes_ordenado(void) {
    FILE *arq_clientes;
    Cliente cliente;
    ClienteNode* novo_node;
    ClienteNode* lista;
    ClienteNode* anter;
    ClienteNode* atual;
    int i = 1;
    
    arq_clientes = fopen("data/clientes.DAT", "rb");
    if (arq_clientes == NULL) {
        printf("Não foi possivel ler o arquivo clientes.dat\n");
        printf("Pressione <ENTER>\n");
        getchar();
        return;
    }

    lista = NULL;
    while (fread(&cliente, sizeof(Cliente), 1, arq_clientes)) {
        if (cliente.status) {
            novo_node = (ClienteNode*) malloc(sizeof(ClienteNode));
            novo_node->cliente = cliente;  // copia os dados do cliente
            
            if (lista == NULL) {
                // Primeiro elemento da lista
                lista = novo_node;
                novo_node->prox = NULL;
            } else if (strcmp(novo_node->cliente.nome, lista->cliente.nome) < 0) {
                // Insere no início
                novo_node->prox = lista;
                lista = novo_node;
            } else {
                // Insere no meio ou final
                anter = lista;
                atual = lista->prox;
                while ((atual != NULL) && strcmp(atual->cliente.nome, novo_node->cliente.nome) < 0) {
                    anter = atual;
                    atual = atual->prox;
                }
                anter->prox = novo_node;
                novo_node->prox = atual;
            }
        }
    }
    fclose(arq_clientes);

    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                   Lista Geral de Clientes (Ordem Alfabética)                ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    
    novo_node = lista;
    while (novo_node != NULL) {
        printf("\n");
        printf("\t\tCliente %d:\n", i);
        printf("\t\tCPF: %s\n", novo_node->cliente.cpf);
        printf("\t\tNome: %s\n", novo_node->cliente.nome);
        printf("\t\tData de nascimento: %s\n", novo_node->cliente.nasc);
        printf("\t\tTelefone: %s\n", novo_node->cliente.telef);
        printf("\t\tEmail: %s\n", novo_node->cliente.email);
        
        novo_node = novo_node->prox;
        i++;
    }
    novo_node = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(novo_node);
        novo_node = lista;
    }
    continuar_acao();
}

typedef struct funcionario_node {
    Funcionario funcionario;
    struct funcionario_node* prox;
} FuncionarioNode;

void lista_geral_funcionarios_ordenado(void) {
    FILE *arq_funcionarios;
    Funcionario funcionario;
    FuncionarioNode* novo_node;
    FuncionarioNode* lista;
    FuncionarioNode* anter;
    FuncionarioNode* atual;
    int i = 1;
    
    arq_funcionarios = fopen("data/funcionarios.DAT", "rb");
    if (arq_funcionarios == NULL) {
        printf("Não foi possivel ler o arquivo funcionarios.dat\n");
        printf("Pressione <ENTER>\n");
        getchar();
        return;
    }

    lista = NULL;
    while (fread(&funcionario, sizeof(Funcionario), 1, arq_funcionarios)) {
        if (funcionario.status) {
            novo_node = (FuncionarioNode*) malloc(sizeof(FuncionarioNode));
            novo_node->funcionario = funcionario;
            
            if (lista == NULL) {
                lista = novo_node;
                novo_node->prox = NULL;
            } else if (strcmp(novo_node->funcionario.nome, lista->funcionario.nome) < 0) {
                novo_node->prox = lista;
                lista = novo_node;
            } else {
                anter = lista;
                atual = lista->prox;
                while ((atual != NULL) && strcmp(atual->funcionario.nome, novo_node->funcionario.nome) < 0) {
                    anter = atual;
                    atual = atual->prox;
                }
                anter->prox = novo_node;
                novo_node->prox = atual;
            }
        }
    }
    fclose(arq_funcionarios);

    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                Lista Geral de Funcionários (Ordem Alfabética)              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    
    novo_node = lista;
    while (novo_node != NULL) {
        printf("\n");
        printf("\t\tFuncionário %d:\n", i);
        printf("\t\tCPF: %s\n", novo_node->funcionario.cpf);
        printf("\t\tNome: %s\n", novo_node->funcionario.nome);
        printf("\t\tTelefone: %s\n", novo_node->funcionario.telefone);
        printf("\t\tEmail: %s\n", novo_node->funcionario.email);
        printf("\t\tCargo: %s\n", novo_node->funcionario.cargo);
        printf("\t\tSalário: %.2f\n", novo_node->funcionario.salario);
        
        novo_node = novo_node->prox;
        i++;
    }

    novo_node = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(novo_node);
        novo_node = lista;
    }
    
    continuar_acao();
}

typedef struct produto_node {
    Produto produto;
    struct produto_node* prox;
} ProdutoNode;

void lista_geral_produtos_ordenado(void) {
    FILE *arq_produtos;
    Produto produto;
    ProdutoNode* novo_node;
    ProdutoNode* lista;
    ProdutoNode* anter;
    ProdutoNode* atual;
    int i = 1;
    
    arq_produtos = fopen("data/produtos.DAT", "rb");
    if (arq_produtos == NULL) {
        printf("Não foi possivel ler o arquivo produtos.dat\n");
        printf("Pressione <ENTER>\n");
        getchar();
        return;
    }

    lista = NULL;
    while (fread(&produto, sizeof(Produto), 1, arq_produtos)) {
        if (produto.status) {
            novo_node = (ProdutoNode*) malloc(sizeof(ProdutoNode));
            novo_node->produto = produto;
            
            if (lista == NULL) {
                lista = novo_node;
                novo_node->prox = NULL;
            } else if (strcmp(novo_node->produto.nome, lista->produto.nome) < 0) {
                novo_node->prox = lista;
                lista = novo_node;
            } else {
                anter = lista;
                atual = lista->prox;
                while ((atual != NULL) && strcmp(atual->produto.nome, novo_node->produto.nome) < 0) {
                    anter = atual;
                    atual = atual->prox;
                }
                anter->prox = novo_node;
                novo_node->prox = atual;
            }
        }
    }
    fclose(arq_produtos);

    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                  Lista Geral de Produtos (Ordem Alfabética)                 ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    
    novo_node = lista;
    while (novo_node != NULL) {
        printf("\n");
        printf("\t\tProduto %d:\n", i);
        printf("\t\tID: %d\n", novo_node->produto.id);
        printf("\t\tNome: %s\n", novo_node->produto.nome);
        printf("\t\tDescrição: %s\n", novo_node->produto.descricao);
        printf("\t\tPreço: %.2f\n", novo_node->produto.preco);
        printf("\t\tQuantidade: %d\n", novo_node->produto.quant);
        
        novo_node = novo_node->prox;
        i++;
    }

    novo_node = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(novo_node);
        novo_node = lista;
    }
    
    continuar_acao();
}

typedef struct quarto_node {
    Quarto quarto;
    struct quarto_node* prox;
} QuartoNode;

void lista_geral_quartos_ordenado(void){
    FILE *arq_quartos;
    Quarto quarto;
    QuartoNode* novo_node;
    QuartoNode* lista;
    QuartoNode* anter;
    QuartoNode* atual;

    arq_quartos = fopen("data/quartos.DAT", "rb");
    if (arq_quartos == NULL) {
        printf("Não foi possivel ler o arquivo quartos.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }

    lista = NULL;
    while (fread(&quarto, sizeof(Quarto), 1, arq_quartos)) {
        if (quarto.status) {
            novo_node = (QuartoNode*) malloc(sizeof(QuartoNode));
            novo_node->quarto = quarto;
            
            if (lista == NULL) {
                lista = novo_node;
                novo_node->prox = NULL;
            } else if (novo_node->quarto.id < lista->quarto.id) {
                novo_node->prox = lista;
                lista = novo_node;
            } else {
                anter = lista;
                atual = lista->prox;
                while ((atual != NULL) && (atual->quarto.id < novo_node->quarto.id)) {
                    anter = atual;
                    atual = atual->prox;
                }
                anter->prox = novo_node;
                novo_node->prox = atual;
            }
        }
    }
    fclose(arq_quartos);

    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                    Lista Geral de Quartos (Ordem Numerica)                  ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    novo_node = lista;
    while (novo_node != NULL) {
        printf("\n");
        printf("\t\tID: %d\n",novo_node->quarto.id);
        printf("\t\tTipo: %s\n",NOME_TIPOS_QUARTO[novo_node->quarto.tipo]);
        printf("\t\tDescricao: %s\n",novo_node->quarto.descricao);
        printf("\t\tPreco/hora: %f\n",novo_node->quarto.preco_hora);
        printf("\t\tPreco/diaria: %f\n",novo_node->quarto.preco_diaria);
        
        novo_node = novo_node->prox;
    }

    novo_node = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(novo_node);
        novo_node = lista;
    }
    
    continuar_acao();
}

typedef struct hospedagens_node {
    Hospedagem hospedagem;
    struct hospedagens_node* prox;
} HospedagemNode;

void lista_geral_hospedagens_ordenado(void){
    Hospedagem hospedagem;
    HospedagemNode* novo_node;
    HospedagemNode* lista;
    HospedagemNode* anter;
    HospedagemNode* atual;

    FILE *arq_hospedagem;
    arq_hospedagem = fopen("data/hospedagem.DAT", "rb");
    if (arq_hospedagem == NULL) {
        printf("Não foi possivel ler o arquivo hospedagem.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }

    lista = NULL;
    while (fread(&hospedagem, sizeof(Hospedagem), 1, arq_hospedagem)) {
        if (hospedagem.status) {
            novo_node = (HospedagemNode*) malloc(sizeof(HospedagemNode));
            novo_node->hospedagem = hospedagem; 
            
            if (lista == NULL) {
                lista = novo_node;
                novo_node->prox = NULL;
            } else if (strcmp(get_nome_cliente(novo_node->hospedagem.cpf), get_nome_cliente(lista->hospedagem.cpf)) < 0) {
                novo_node->prox = lista;
                lista = novo_node;
            } else {
                anter = lista;
                atual = lista->prox;
                while ((atual != NULL) && strcmp(get_nome_cliente(atual->hospedagem.cpf), get_nome_cliente(novo_node->hospedagem.cpf)) < 0) {
                    anter = atual;
                    atual = atual->prox;
                }
                anter->prox = novo_node;
                novo_node->prox = atual;
            }
        }
    }
    fclose(arq_hospedagem);
    char* nome_cliente;

    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                          Lista Geral de Hospedagens                         ♡\n");
    printf("♡                         Ordem Alfabetica de Clientes                        ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    novo_node = lista;
    while (novo_node != NULL) {
        nome_cliente = get_nome_cliente(novo_node->hospedagem.cpf);
        printf("\n");
        printf("\t\tCPF Cliente: %s\n",novo_node->hospedagem.cpf);
        printf("\t\tNome Cliente: %s\n",nome_cliente);
        printf("\t\tID do Quarto: %d\n",novo_node->hospedagem.id_quarto);
        printf("\t\tHoras: %d\n",novo_node->hospedagem.horas);

        novo_node = novo_node->prox;
    }

    novo_node = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(novo_node);
        novo_node = lista;
    }
    
    continuar_acao();
}

typedef struct vendas_node {
    Venda venda;
    struct vendas_node* prox;
} VendaNode;

void lista_geral_vendas_ordenado(void){
    Venda venda;
    VendaNode* novo_node;
    VendaNode* lista;
    VendaNode* anter;
    VendaNode* atual;

    FILE *arq_vendas;
    arq_vendas = fopen("data/vendas.DAT", "rb");
    if (arq_vendas == NULL) {
        printf("Não foi possivel ler o arquivo vendas.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }

    lista = NULL;
    while (fread(&venda, sizeof(Venda), 1, arq_vendas)) {
        if (venda.status) {
            novo_node = (VendaNode*) malloc(sizeof(VendaNode));
            novo_node->venda = venda; 
            
            if (lista == NULL) {
                lista = novo_node;
                novo_node->prox = NULL;
            } else if (strcmp(get_nome_cliente(novo_node->venda.cpf_cliente), get_nome_cliente(lista->venda.cpf_cliente)) < 0) {
                novo_node->prox = lista;
                lista = novo_node;
            } else {
                anter = lista;
                atual = lista->prox;
                while ((atual != NULL) && strcmp(get_nome_cliente(atual->venda.cpf_cliente), get_nome_cliente(novo_node->venda.cpf_cliente)) < 0) {
                    anter = atual;
                    atual = atual->prox;
                }
                anter->prox = novo_node;
                novo_node->prox = atual;
            }
        }
    }
    fclose(arq_vendas);
    char* nome_cliente;
    char* nome_funcionario;
    char* nome_produto;

    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                             Lista Geral de Vendas                           ♡\n");
    printf("♡                         Ordem Alfabetica de Clientes                        ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    novo_node = lista;
    while (novo_node != NULL) {
        nome_cliente = get_nome_cliente(novo_node->venda.cpf_cliente);
        nome_funcionario = get_nome_funcionario(novo_node->venda.cpf_funcionario);
        nome_produto = get_nome_produto(novo_node->venda.id_produto);
        printf("\n");
        printf("\t\tCPF Cliente: %s\n",novo_node->venda.cpf_cliente);
        printf("\t\tNome Cliente: %s\n",nome_cliente);
        printf("\t\tCPF Funcionario: %s\n",novo_node->venda.cpf_funcionario);
        printf("\t\tNome Funcionario: %s\n",nome_funcionario);
        printf("\t\tID do Produto: %d\n",novo_node->venda.id_produto);
        printf("\t\tNome Produto: %s\n",nome_produto);
        printf("\t\tQuantidade: %d\n",novo_node->venda.quant);
        novo_node = novo_node->prox;
    }

    novo_node = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(novo_node);
        novo_node = lista;
    }
    
    continuar_acao();
}