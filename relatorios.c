#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"

void menu_relatorio(void) {
    char op_relatorio;
    system("clear||cls");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡           Universidade Federal do Rio Grande do Norte - UFRN                ♡\n");
    printf("♡               Centro de Ensino Superior do Seridó - CERES                   ♡\n");
    printf("♡                     Disciplina DCT1106 -- Programação                       ♡\n");
    printf("♡                   Projeto Sistema de Gestão para Motéis                     ♡\n");
    printf("♡  Desenvolvido por @wallisonvsdias e @Isabellecavalcant -- desde Ago, 2025   ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                                   SIG-Motel                                 ♡\n");
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
    printf("♡      0  - Retornar ao Menu Principal                                        ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    printf("♡Escolha sua opção:");
    scanf("%c", &op_relatorio);
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}