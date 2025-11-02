#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "relatorios.h"
#include "clientes.h"
#include "quartos.h"
#include "produtos.h"

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
        printf("♡      7  - Lista de hospedagens por cliente                                  ♡\n");
        printf("♡      8  - Lista de hospedagens por funcionário                              ♡\n");
        printf("♡      9  - Lista de hospedagens por quarto                                   ♡\n");
        printf("♡     10  - Lista de hospedagens por período                                  ♡\n");
        printf("♡     11  - Lista de vendas por cliente                                       ♡\n");
        printf("♡     12  - Lista de vendas por funcionário                                   ♡\n");
        printf("♡     13  - Lista de vendas por produto                                       ♡\n");
        printf("♡     14  - Lista de vendas por período                                       ♡\n");
        printf("♡     15  - Lista de gastos totais por cliente                                ♡\n");
        printf("♡     16  - Lista de lucros totais                                            ♡\n");
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
        case '3':
            lista_geral_quartos();
            break;
        case '5':
            lista_geral_produtos();
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
    arq_clientes = fopen("clientes.DAT", "rb");
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

void lista_geral_quartos(void) {
    Quarto* quarto;
    quarto = (Quarto*)malloc(sizeof(*quarto));
    FILE *arq_quartos;
    arq_quartos = fopen("quartos.DAT", "rb");
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


void lista_geral_produtos(void){
    Produto* produto;
    produto = (Produto*)malloc(sizeof(*produto));
    FILE *arq_produtos;
    arq_produtos = fopen("produtos.DAT", "rb");
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