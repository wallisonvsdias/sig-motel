#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"

void menu_cliente(void) {
    char op_cliente;
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
    printf("|                                Módulo Cliente                               |\n");
    printf("|                                                                             |\n");
    printf("|      1 - Cadastrar Cliente                                                  |\n");
    printf("|      2 - Exibir Dados do Cliente                                            |\n");
    printf("|      3 - Alterar Dados do Cliente                                           |\n");
    printf("|      4 - Excluir Cliente                                                    |\n");
    printf("|      0 - Retornar ao Menu Principal                                         |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    printf("Escolha sua opção: ");
    scanf("%c", &op_cliente);
    getchar();
    switch(op_cliente) {
        case '1':
            cadastrar_cliente();
            break;
        case '2':
            exibir_cliente();
            break;
        case '3':
            alterar_cliente();
            break;
        case '4':
            excluir_cliente();
            break;
        default:
            printf("Por favor, digite uma opção válida");
            break;
    }
}


void cadastrar_cliente(void) {
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
    printf("|                              Cadastrar Cliente                              |\n");
    printf("|                                                                             |\n");
    printf("|      Nome:                                                                  |\n");
    printf("|      Cpf:                                                                   |\n");
    printf("|      Telefone:                                                              |\n");
    printf("|      E-mail:                                                                |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    
    getchar();
}


void exibir_cliente(void){
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
    printf("|                            Exibir Dados do Cliente                          |\n");
    printf("|                                                                             |\n");
    printf("|      Informe o cpf do cliente:                                              |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void alterar_cliente(void){
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
    printf("|                           Alterar Dados do Cliente                          |\n");
    printf("|                                                                             |\n");
    printf("|      Informe o cpf do cliente:                                              |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void excluir_cliente(void){
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
    printf("|                                Excluir Cliente                              |\n");
    printf("|                                                                             |\n");
    printf("|      Informe o cpf do cliente:                                              |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}