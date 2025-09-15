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
#include "clientes.h"
#include "funcionarios.h"
#include "quartos.h"
#include "hospedagem.h"
#include "produtos.h"
#include "vendas.h"
#include "relatorios.h"


// Assinatura das funções
void menu_principal(void);
void sobre(void);
void equipe(void);
void finalizacao(void);


// Programa principal
int main(void) {
    char op_menu;
    do {
        menu_principal();
        printf("Escolha sua opção: ");
        scanf("%c", &op_menu);
        getchar();

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
            case '0':
                sobre();
                equipe();   
                finalizacao();
                break;
            default:
                printf("Por favor, digite uma opção válida");
                break;
        }
    } while (op_menu != '0');


    menu_relatorio();

    return 0;
}

void menu_principal(void) {
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
    printf("♡           1 - Módulo Cliente                                                ♡\n");
    printf("♡           2 - Módulo Funcionário                                            ♡\n");
    printf("♡           3 - Módulo Quarto                                                 ♡\n");
    printf("♡           4 - Módulo Hospedagem                                             ♡\n");
    printf("♡           5 - Módulo Produto                                                ♡\n");
    printf("♡           6 - Módulo Venda                                                  ♡\n");
    printf("♡           7 - Módulo Relatórios                                             ♡\n");
    printf("♡           0 - Sair                                                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
}

void sobre(void) {
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
    printf("♡ Esse projeto faz parte da disciplina Programação (DCT1106), ministrada pelo ♡\n");
    printf("♡ professor Flavius Gorgônio. Nosso sistema auxilia os funcionários no        ♡\n");
    printf("♡ gerenciamento de motéis, contando com módulos de cliente, funcionário,      ♡\n");
    printf("♡ quarto, produto, hospedagem, venda, e os relatórios, incluíndo a listagem   ♡\n");
    printf("♡ de todos os módulos anteriores.                                             ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void equipe(void) {
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
    printf("♡ Esse projeto foi desenvolvido por:                                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ Wallison Dias                                                               ♡\n");
    printf("♡ E-mail: wallison.dias.711@ufrn.edu.br                                       ♡\n");
    printf("♡ GitHub: @wallisonvsdias                                                     ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ Isabelle Cavalcanti                                                         ♡\n");
    printf("♡ E-mail: isabelle.silva.712@ufrn.edu.br                                      ♡\n");
    printf("♡ GitHub: @Isabellecavalcant                                                  ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ Repositório: https://github.com/wallisonvsdias/sig-motel.git                ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ Sites usados para as artes em ASCII:                                        ♡\n");
    printf("♡ https://emojicombos.com/heart                                               ♡\n");
    printf("♡ https://www.asciiart.eu/text-to-ascii-art                                   ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("\n");
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}
