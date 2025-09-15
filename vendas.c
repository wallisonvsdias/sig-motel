#include <stdio.h>
#include <stdlib.h>
#include "vendas.h"

void menu_venda(void) {
    char op_venda;
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
    printf("♡                                Módulo Venda                                 ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      1 - Cadastrar Venda                                                    ♡\n");
    printf("♡      2 - Exibir Dados da Venda                                              ♡\n");
    printf("♡      3 - Alterar Dados da Venda                                             ♡\n");
    printf("♡      4 - Excluir Venda                                                      ♡\n");
    printf("♡      0 - Retornar ao Menu Principal                                         ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    printf("Escolha sua opção: ");
    scanf("%c", &op_venda);
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
        default:
            printf("Por favor, digite uma opção válida");
            break;
    }
}


void cadastrar_venda(void) {
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
    printf("♡                              Cadastrar Venda                                ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      ID do cliente:                                                         ♡\n");
    printf("♡      ID da venda:                                                           ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void exibir_venda(void) {
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
    printf("♡                        Exibir Dados da Venda                                ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o ID da venda:                                                 ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void alterar_venda(void) {
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
    printf("♡                        Alterar Dados da Venda                               ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o ID da venda:                                                 ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void excluir_venda(void) {
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
    printf("♡                              Excluir Venda                                  ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o ID da venda:                                                 ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}