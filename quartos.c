#include <stdio.h>
#include <stdlib.h>
#include "quartos.h"


void menu_quarto(void) {
    char op_quarto;
    system("clear||cls");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("|           Universidade Federal do Rio Grande do Norte - UFRN                |\n");
    printf("|               Centro de Ensino Superior do Seridó - CERES                   |\n");
    printf("|                     Disciplina DCT1106 -- Programação                       |\n");
    printf("|                   Projeto Sistema de Gestão para Motéis                     |\n");
    printf("|  Desenvolvido por @wallisonvsdias e @Isabellecavalcant -- desde Ago, 2025   |\n");
    printf("|                                                                             |\n");
    printf("|                                   SIG-Motel                                 |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("|                                                                             |\n");
    printf("|                                Módulo Quarto                                |\n");
    printf("|                                                                             |\n");
    printf("|      1 - Cadastrar Quarto                                                   |\n");
    printf("|      2 - Exibir Dados do Quarto                                             |\n");
    printf("|      3 - Alterar Dados do Quarto                                            |\n");
    printf("|      4 - Excluir QUarto                                                     |\n");
    printf("|      0 - Retornar ao Menu Principal                                         |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    printf("Escolha sua opção: ");
    scanf("%c", &op_quarto);
    getchar();
    
    switch(op_quarto) {
        case '1':
            cadastrar_quarto();
            break;
        case '2':
            exibir_quarto();
            break;
        case '3':
            alterar_quarto();
            break;
        case '4':
            excluir_quarto();
            break;
        default:
            printf("Por favor, digite uma opção válida");
            break;
    }
}


void cadastrar_quarto(void) {
    system("clear||cls");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("|           Universidade Federal do Rio Grande do Norte - UFRN                |\n");
    printf("|               Centro de Ensino Superior do Seridó - CERES                   |\n");
    printf("|                     Disciplina DCT1106 -- Programação                       |\n");
    printf("|                   Projeto Sistema de Gestão para Motéis                     |\n");
    printf("|  Desenvolvido por @wallisonvsdias e @Isabellecavalcant -- desde Ago, 2025   |\n");
    printf("|                                                                             |\n");
    printf("|                                   SIG-Motel                                 |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("|                                                                             |\n");
    printf("|                               Cadastrar Quarto                              |\n");
    printf("|                                                                             |\n");
    printf("|      Nome:                                                                  |\n");
    printf("|      ID:                                                                    |\n");
    printf("|      Valor:                                                                 |\n");
    printf("|      Descrição:                                                             |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void exibir_quarto(void){
        system("clear||cls");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("|           Universidade Federal do Rio Grande do Norte - UFRN                |\n");
    printf("|               Centro de Ensino Superior do Seridó - CERES                   |\n");
    printf("|                     Disciplina DCT1106 -- Programação                       |\n");
    printf("|                   Projeto Sistema de Gestão para Motéis                     |\n");
    printf("|  Desenvolvido por @wallisonvsdias e @Isabellecavalcant -- desde Ago, 2025   |\n");
    printf("|                                                                             |\n");
    printf("|                                   SIG-Motel                                 |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("|                                                                             |\n");
    printf("|                            Exibir Dados do Quarto                           |\n");
    printf("|                                                                             |\n");
    printf("|      Informe o ID do quarto:                                                |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void alterar_quarto(void) {
    system("clear||cls");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("|           Universidade Federal do Rio Grande do Norte - UFRN                |\n");
    printf("|               Centro de Ensino Superior do Seridó - CERES                   |\n");
    printf("|                     Disciplina DCT1106 -- Programação                       |\n");
    printf("|                   Projeto Sistema de Gestão para Motéis                     |\n");
    printf("|  Desenvolvido por @wallisonvsdias e @Isabellecavalcant -- desde Ago, 2025   |\n");
    printf("|                                                                             |\n");
    printf("|                                   SIG-Motel                                 |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("|                                                                             |\n");
    printf("|                            Alterar Dados do Quarto                          |\n");
    printf("|                                                                             |\n");
    printf("|     Informe o ID do quarto:                                                 |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void excluir_quarto(void) {
    system("clear||cls");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("|           Universidade Federal do Rio Grande do Norte - UFRN                |\n");
    printf("|               Centro de Ensino Superior do Seridó - CERES                   |\n");
    printf("|                     Disciplina DCT1106 -- Programação                       |\n");
    printf("|                   Projeto Sistema de Gestão para Motéis                     |\n");
    printf("|  Desenvolvido por @wallisonvsdias e @Isabellecavalcant -- desde Ago, 2025   |\n");
    printf("|                                                                             |\n");
    printf("|                                   SIG-Motel                                 |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("|                                                                             |\n");
    printf("|                                 Excluir Quarto                              |\n");
    printf("|                                                                             |\n");
    printf("|     Informe o ID do quarto:                                                 |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}