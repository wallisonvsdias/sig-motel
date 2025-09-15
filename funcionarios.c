#include <stdio.h>
#include <stdlib.h>
#include "funcionarios.h"

void menu_funcionario(void) {
    char op_funcionario;
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
    printf("♡                             Módulo Funcionário                              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      1 - Cadastrar Funcioário(a)                                            ♡\n");
    printf("♡      2 - Exibir Dados do Funcionário(a)                                     ♡\n");
    printf("♡      3 - Alterar Dados do FUncionário(a)                                    ♡\n");
    printf("♡      4 - Excluir Funcionário                                                ♡\n");
    printf("♡      0 - Retornar ao Menu Principal                                         ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    printf("Escolha sua opção: ");
    scanf("%c", &op_funcionario);
    getchar();
    
    switch(op_funcionario) {
        case '1':
            cadastrar_funcionario();
            break;
        case '2':
            exibir_funcionario();
            break;
        case '3':
            alterar_funcionario();
            break;
        case '4':
            excluir_funcionario();
            break;
        default:
            printf("Por favor, digite uma opção válida");
            break;
    }
}


void cadastrar_funcionario(void) {
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
    printf("♡                           Cadastrar Funcionário(a)                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Nome:                                                                  ♡\n");
    printf("♡      Cpf:                                                                   ♡\n");
    printf("♡      Telefone:                                                              ♡\n");
    printf("♡      E-mail:                                                                ♡\n");
    printf("♡      Cargo:                                                                 ♡\n");
    printf("♡      Salário:                                                               ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void exibir_funcionario(void) {
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
    printf("♡                        Exibir Dados do Funcionário(a)                       ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡     Informe o cpf do funcionário:                                           ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void alterar_funcionario(void) {
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
    printf("♡                       Alterar Dados do Funcionário(a)                       ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡     Informe o cpf do funcionário:                                           ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void excluir_funcionario(void){
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
    printf("♡                             Excluir Funcionário(a)                             ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o cpf do funcionário:                                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}