#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "info.h"


void menu_info(void) {
    char op_info;
        do {
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                              Módulo Informações                             ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      1 - Sobre o projeto                                                    ♡\n");
        printf("♡      2 - Equipe                                                             ♡\n");
        printf("♡      0 - Retornar ao menu principal                                         ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("\nEscolha sua opção: ");
        scanf(" %c", &op_info);

        switch(op_info) {
            case '1':
                sobre();
                break;
            case '2':
                equipe();
                break;
            case '0':
                break;
            default:
                getchar();
                printf("\n");
                printf("Por favor, digite uma opção válida");
                getchar();
                break;
        }
    } while (op_info != '0');
}


// Informações sobre o projeto
void sobre(void) {
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ Esse projeto faz parte da disciplina Programação (DCT1106), ministrada pelo ♡\n");
    printf("♡ professor Flavius Gorgônio. Nosso sistema auxilia os funcionários no        ♡\n");
    printf("♡ gerenciamento de motéis, contando com módulos de cliente, funcionário,      ♡\n");
    printf("♡ quarto, produto, hospedagem, venda, e os relatórios, incluíndo a listagem   ♡\n");
    printf("♡ de todos os módulos anteriores.                                             ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    getchar();
    continuar_acao();
}


// Informações sobre a equipe
void equipe(void) {
    system("clear||cls");
    mostrar_cabecalho();
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
    getchar();
    continuar_acao();
}