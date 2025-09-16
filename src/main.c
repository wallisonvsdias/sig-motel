//⠀⠀⠀⠀⠀⠀                                               ⠀⣠⣶⣶⣶⣦                                                         
//  ____ ___ ____       __  __       _       _ ⠀ ⠀⣠⣤⣤⣄⣀⣾⣿⠟⠛⠻⢿⣷
// / ___|_ _/ ___|     |  \/  | ___ | |_ ___| | ⢰⣿⡿⠛⠙⠻⣿⣿⠁⠀⠀⠀⢸⣿⡇
// \___ \| | |  _ _____| |\/| |/ _ \| __/ _ \ | ⢿⣿⣇⠀⠀⠀⠈⠏⠀⠀⠀⠀⣼⣿⠀
//  ___) | | |_| |_____| |  | | (_) | ||  __/ | ⠀⠻⣿⣷⣦⣤⣀⠀⠀⠀⠀⣾⡿⠃⠀
// |____/___\____|     |_|  |_|\___/ \__\___|_| ⠀⠀⠀⠀⠉⠉⠻⣿⣄⣴⣿⠟⠀⠀⠀
//                                              ⠀⠀⠀⠀⠀⠀⠀⣿⡿⠟⠁⠀⠀⠀⠀
//
// Universidade Federal do Rio Grande do Norte - UFRN
// Centro de Ensino Superior do Seridó - CERES
// Departamento de Computação e Tecnologia - DCT
// Disciplina DCT1106 -- Programação
// Projeto Sistema de Gestão para Motéis
// Desenvolvido por @wallisonvsdias e @Isabellecavalcant -- desde Ago, 2025


#include <stdio.h>
#include <stdlib.h>

#include "interface.h"
#include "clientes.h"
#include "funcionarios.h"
#include "quartos.h"
#include "hospedagem.h"
#include "produtos.h"
#include "vendas.h"
#include "relatorios.h"
#include "infos.h"
#include "final.h"


// Assinatura
void menu_principal(void);


// Função do menu principal
void menu_principal(void) {
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡           1 - Módulo Cliente                                                ♡\n");
    printf("♡           2 - Módulo Funcionário                                            ♡\n");
    printf("♡           3 - Módulo Quarto                                                 ♡\n");
    printf("♡           4 - Módulo Hospedagem                                             ♡\n");
    printf("♡           5 - Módulo Produto                                                ♡\n");
    printf("♡           6 - Módulo Venda                                                  ♡\n");
    printf("♡           7 - Módulo Relatórios                                             ♡\n");
    printf("♡           8 - Módulo Informações                                            ♡\n");
    printf("♡           0 - Sair                                                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
}


// Programa principal
int main(void) {
    char op_menu;
    do {
        menu_principal();
        printf("\nEscolha sua opção: ");
        scanf(" %c", &op_menu);

        switch(op_menu) {
            case '1':
                menu_cliente();
                break;
            case '2':
                menu_funcionario();
                break;
            case '3':
                menu_quarto();
                break;
            case '4':
                menu_hospedagem();
                break;
            case '5':
                menu_produto();
                break;
            case '6':
                menu_venda();
                break;
            case '7':
                menu_relatorio();
                break;
            case '8':
                sobre();
                equipe();
                break;
            case '0': 
                final();
                break;
            default:
                getchar();
                printf("\n");
                printf("Por favor, digite uma opção válida");
                getchar();
                break;
        }
    } while (op_menu != '0');

    return 0;
}