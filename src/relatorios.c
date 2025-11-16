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
    char op_relatorio;
    do {
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                              Módulo Relatório                               ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      1  - Lista geral de clientes                                           ♡\n");
        printf("♡      2  - Lista geral de funcionários                                       ♡\n");
        printf("♡      3  - Lista geral de quartos                                            ♡\n");
        printf("♡      4  - Lista geral de hospedagens                                        ♡\n");
        printf("♡      5  - Lista geral de produtos                                           ♡\n");
        printf("♡      6  - Lista geral de vendas                                             ♡\n");
        printf("♡      7  - Lista Clientes por nome                                           ♡\n");
        printf("♡      8  - Lista quartos por tipo                                           ♡\n");
        printf("♡      0  - Retornar ao Menu Principal                                        ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("\n");
        printf("Escolha sua opção: ");
        scanf(" %2s", &op_relatorio);
        getchar();
        
        switch (op_relatorio) {
        case '1':
            lista_geral_clientes();
            break;
        case '2':
            lista_geral_funcionarios();
            break;
        case '3':
            lista_geral_quartos();
            break;
        case '4':
            lista_geral_hospedagens();
            break;
        case '5':
            lista_geral_produtos();
            break;
        case '6':
            lista_geral_vendas();
            break;
        case '7':
            clientes_por_nome();
            break;
        case '8':
            quartos_por_tipo();
            break;
        default:
            break;
        }
    } while (op_relatorio != '0');

}

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
            printf("\t\tTipo: %s\n",quarto->tipo);
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
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                         Lista Geral de Hospedagens                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(hospedagem,sizeof(Hospedagem),1,arq_hospedagem)) {
        if (hospedagem->status){
            printf("\n");
            printf("\t\tCPF Cliente: %s\n",hospedagem->cpf);
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
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Lista Geral de Vendas                            ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(venda,sizeof(Venda),1,arq_vendas)) {
        if (venda->status){
            printf("\n");
            printf("\t\tCPF Cliente: %s\n",venda->cpf);
            printf("\t\tID do Produto: %d\n",venda->id_produto);
            printf("\t\tQuantidade: %d\n",venda->quant);
        }
    }
    fclose(arq_vendas);
    free(venda);
    continuar_acao();
}

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
    char tipo_lido[32];
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Quartos por tipo                                 ♡\n");
    printf("♡                                                                             ♡\n");
    ler_tipo(tipo_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    printf("Busca: %s\n",tipo_lido);
    while (fread(quarto,sizeof(Quarto),1,arq_quartos)){
        if (strstr(quarto->tipo,tipo_lido) != NULL){
            printf("\n");
            printf("\t\tID: %d\n",quarto->id);
            printf("\t\tTipo: %s\n",quarto->tipo);
            printf("\t\tDescricao: %s\n",quarto->descricao);
            printf("\t\tPreco/hora: %f\n",quarto->preco_hora);
            printf("\t\tPreco/diaria: %f\n",quarto->preco_diaria);
        }
    }
    fclose(arq_quartos);
    free(quarto);
    continuar_acao();
}