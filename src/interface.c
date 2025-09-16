#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void mostrar_cabecalho(void) {
    system("clear||cls");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡           Universidade Federal do Rio Grande do Norte - UFRN                ♡\n");
    printf("♡               Centro de Ensino Superior do Seridó - CERES                   ♡\n");
    printf("♡                     Disciplina DCT1106 -- Programação                       ♡\n");
    printf("♡                   Projeto Sistema de Gestão para Motéis                     ♡\n");
    printf("♡  Desenvolvido por @wallisonvsdias e @Isabellecavalcant -- desde Ago, 2025   ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                                   SIG-Motel                                 ♡\n");
}


void continuar_acao(void) {
    printf("\n");
    printf("Pressione [Enter] para continuar a ação");
    getchar();
}