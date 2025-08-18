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


// Assinatura das funções
void tela_menu_principal(void);
void tela_sobre(void);
void tela_equipe(void);

void tela_menu_cliente(void);
void tela_menu_funcionario(void);
void tela_menu_quarto(void);
void tela_menu_produto(void);
void tela_menu_hospedagem(void);
void tela_menu_venda(void);
void tela_menu_relatorio(void);


// Programa principal
int main(void) {
    tela_menu_principal();
    tela_sobre;
    tela_equipe;
    tela_menu_cliente;
    tela_menu_funcionario;
    tela_menu_quarto;
    tela_menu_produto;
    tela_menu_hospedagem;
    tela_menu_venda;
    tela_menu_relatorio;
    
    return 0;
}

void tela_menu_principal(void) {
    char op_menu;
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
    printf("|           1 - Módulo Clientes                                               |\n");
    printf("|           2 - Módulo Funcionários                                           |\n");
    printf("|           3 - Módulo Quartos                                                |\n");
    printf("|           4 - Módulo Hospedagem                                             |\n");
    printf("|           5 - Módulo Produtos                                               |\n");
    printf("|           6 - Módulo vendas                                                 |\n");
    printf("|           7 - Módulo Relatórios                                             |\n");
    printf("|           8 - Módulo Informações                                            |\n");
    printf("|           0 - Sair                                                          |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    printf("|Escolha sua opção:");
    scanf(" %c", &op_menu);
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}