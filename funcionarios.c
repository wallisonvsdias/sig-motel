#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "funcionarios.h"


void menu_funcionario(void) {
    char op_funcionario;
    do {
        system("clear||cls");
        cabecalho();
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

        printf("Escolha sua opção: ");
        scanf(" %c", &op_funcionario);
        
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
            case '0':
                break;
            default:
                getchar();
                printf("\nPor favor, digite uma opção válida\n");
                getchar();
                break;
        }
    } while (op_funcionario != '0');
}


void cadastrar_funcionario(void) {
    system("clear||cls");
    cabecalho();
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
    getchar();
    printf("\nPressione ENTER para voltar ao menu...\n");
    getchar();
}


void exibir_funcionario(void) {
    system("clear||cls");
    cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                        Exibir Dados do Funcionário(a)                       ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡     Informe o cpf do funcionário:                                           ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    getchar();
    printf("\nPressione ENTER para voltar ao menu...\n");
    getchar();
}


void alterar_funcionario(void) {
    system("clear||cls");
    cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                       Alterar Dados do Funcionário(a)                       ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡     Informe o cpf do funcionário:                                           ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    getchar();
    printf("\nPressione ENTER para voltar ao menu...\n");
    getchar();
}


void excluir_funcionario(void){
    system("clear||cls");
    cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Excluir Funcionário(a)                           ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o cpf do funcionário:                                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    getchar();
    printf("\nPressione ENTER para voltar ao menu...\n");
    getchar();
}