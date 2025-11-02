#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "relatorios.h"
#include "clientes.h"


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