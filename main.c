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
void tela_cadastrar_cliente(void);
void tela_exibir_cliente(void);
void tela_alterar_dados_cliente(void);
void tela_excluir_cliente(void);

void tela_menu_funcionario(void);
void tela_cadastrar_funcionario(void);
void tela_exibir_funcionario(void);
void tela_alterar_dados_funcionario(void);
void tela_excluir_funcionario(void);

void tela_menu_quarto(void);
void tela_cadastrar_quarto(void);
void tela_exibir_quarto(void);
void tela_alterar_dados_quarto(void);
void tela_excluir_quarto(void);

void tela_menu_hospedagem(void);
void tela_cadastrar_hospedagem(void);
void tela_exibir_hospedagem(void);
void tela_alterar_hospedagem(void);
void tela_excluir_hospedagem(void);


void tela_menu_produto(void);
void tela_cadastrar_produto(void);
void tela_exibir_produto(void);
// void tela_alterar_produto(void);
// void tela_excluir_produto(void);


void tela_menu_venda(void);
void tela_menu_relatorio(void);
void tela_finalizacao(void);


// Programa principal
int main(void) {
    tela_menu_principal();

    tela_menu_cliente();
    tela_cadastrar_cliente();
    tela_exibir_cliente();
    tela_alterar_dados_cliente();
    tela_excluir_cliente();

    tela_menu_funcionario();
    tela_cadastrar_funcionario();
    tela_exibir_funcionario();
    tela_alterar_dados_funcionario();
    tela_excluir_funcionario();

    tela_menu_quarto();
    tela_cadastrar_quarto();
    tela_alterar_dados_quarto();
    tela_excluir_quarto();
    
    tela_menu_hospedagem();
    tela_cadastrar_hospedagem();
    tela_exibir_hospedagem();
    tela_alterar_hospedagem();
    tela_excluir_hospedagem();


    tela_menu_produto();
    tela_cadastrar_produto();
    tela_exibir_produto();
    // tela_alterar_produto();
    // tela_excluir_produto();


    tela_menu_venda();
    tela_menu_relatorio();

    tela_sobre();
    tela_equipe();
    tela_finalizacao();
    
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
    printf("|           1 - Módulo Cliente                                                |\n");
    printf("|           2 - Módulo Funcionário                                            |\n");
    printf("|           3 - Módulo Quarto                                                 |\n");
    printf("|           4 - Módulo Hospedagem                                             |\n");
    printf("|           5 - Módulo Produto                                                |\n");
    printf("|           6 - Módulo Venda                                                  |\n");
    printf("|           7 - Módulo Relatórios                                             |\n");
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


void tela_sobre(void) {
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
    printf("| Esse projeto faz parte da disciplina Programação (DCT1106), ministrada pelo |\n");
    printf("| professor Flavius Gorgônio. Nosso sistema auxilia os funcionários no        |\n");
    printf("| gerenciamento de motéis, contando com módulos de cliente, funcionário,      |\n");
    printf("| quarto, produto, hospedagem, venda, e os relatórios, incluíndo a listagem   |\n");
    printf("| de todos os módulos anteriores.                                             |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_equipe(void) {
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
    printf("| Esse projeto foi desenvolvido por:                                          |\n");
    printf("|                                                                             |\n");
    printf("| Wallison Dias                                                               |\n");
    printf("| E-mail: wallison.dias.711@ufrn.edu.br                                       |\n");
    printf("| GitHub: @wallisonvsdias                                                     |\n");
    printf("|                                                                             |\n");
    printf("| Isabelle Cavalcanti                                                         |\n");
    printf("| E-mail: isabelle.silva.712@ufrn.edu.br                                      |\n");
    printf("| GitHub: @Isabellecavalcant                                                  |\n");
    printf("|                                                                             |\n");
    printf("| Repositório: https://github.com/wallisonvsdias/sig-motel.git                |\n");
    printf("|                                                                             |\n");
    printf("| Sites usados para as artes em ASCII:                                        |\n");
    printf("| https://emojicombos.com/heart                                               |\n");
    printf("| https://www.asciiart.eu/text-to-ascii-art                                   |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_menu_cliente(void) {
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
    printf("|Escolha sua opção:");
    scanf(" %c", &op_cliente);
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_cadastrar_cliente(void) {
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


void tela_exibir_cliente(void){
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


void tela_alterar_dados_cliente(void){
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


void tela_excluir_cliente(void){
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


void tela_menu_funcionario(void) {
    char op_funcionario;
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
    printf("|                             Módulo Funcionário                              |\n");
    printf("|                                                                             |\n");
    printf("|      1 - Cadastrar Funcioário(a)                                            |\n");
    printf("|      2 - Exibir Dados do Funcionário(a)                                     |\n");
    printf("|      3 - Alterar Dados do FUncionário(a)                                    |\n");
    printf("|      4 - Excluir Funcionário                                                |\n");
    printf("|      0 - Retornar ao Menu Principal                                         |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    printf("|Escolha sua opção:");
    scanf(" %c", &op_funcionario);
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_cadastrar_funcionario(void) {
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
    printf("|                           Cadastrar Funcionário(a)                          |\n");
    printf("|                                                                             |\n");
    printf("|      Nome:                                                                  |\n");
    printf("|      Cpf:                                                                   |\n");
    printf("|      Telefone:                                                              |\n");
    printf("|      E-mail:                                                                |\n");
    printf("|      Cargo:                                                                 |\n");
    printf("|      Salário:                                                               |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_exibir_funcionario(void) {
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
    printf("|                        Exibir Dados do Funcionário(a)                       |\n");
    printf("|                                                                             |\n");
    printf("|     Informe o cpf do funcionário:                                           |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_alterar_dados_funcionario(void) {
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
    printf("|                       Alterar Dados do Funcionário(a)                       |\n");
    printf("|                                                                             |\n");
    printf("|     Informe o cpf do funcionário:                                           |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_excluir_funcionario(void){
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
    printf("|                             Excluir Funcionário(a)                             |\n");
    printf("|                                                                             |\n");
    printf("|      Informe o cpf do funcionário:                                          |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_menu_quarto(void) {
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
    printf("|Escolha sua opção:");
    scanf(" %c", &op_quarto);
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_cadastrar_quarto(void) {
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


void tela_exibir_quarto(void){
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


void tela_alterar_dados_quarto(void) {
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
    printf("|     Informe o ID do quarto:                                           |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_excluir_quarto(void) {
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


void tela_menu_hospedagem(void) {
    char op_hospedagem;
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
    printf("|                               Módulo Hospedagem                             |\n");
    printf("|                                                                             |\n");
    printf("|      1 - Cadastrar Hospedagem                                               |\n");
    printf("|      2 - Exibir Dados da Hospedagem                                         |\n");
    printf("|      3 - Alterar Dados do Hospagem                                          |\n");
    printf("|      4 - Cancelar Hospedagem                                                |\n");
    printf("|      0 - Retornar ao Menu Principal                                         |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    printf("|Escolha sua opção:");
    scanf(" %c", &op_hospedagem);
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_cadastrar_hospedagem(void) {
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
    printf("|                           Cadastrar Hospedagem                              |\n");
    printf("|                                                                             |\n");
    printf("|      ID do cliente:                                                         |\n");
    printf("|      ID do quarto:                                                          |\n");
    printf("|      Quantidade de dias:                                                    |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_exibir_hospedagem(void) {
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
    printf("|                        Exibir Dados da Hospedagem                           |\n");
    printf("|                                                                             |\n");
    printf("|      Informe o ID da hospedagem:                                            |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_alterar_hospedagem(void) {
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
    printf("|                        Alterar Dados da Hospedagem                          |\n");
    printf("|                                                                             |\n");
    printf("|      Informe o ID da hospedagem:                                            |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_excluir_hospedagem(void) {
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
    printf("|                              Excluir Hospedagem                             |\n");
    printf("|                                                                             |\n");
    printf("|      Informe o ID da hospedagem:                                            |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_menu_produto(void) {
    char op_produto;
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
    printf("|                               Módulo Produto                                |\n");
    printf("|                                                                             |\n");
    printf("|      1 - Cadastrar Produto                                                  |\n");
    printf("|      2 - Exibir Dados do Produto                                            |\n");
    printf("|      3 - Alterar Dados do Produto                                           |\n");
    printf("|      4 - Excluir Produto                                                    |\n");
    printf("|      0 - Retornar ao Menu Principal                                         |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    printf("|Escolha sua opção:");
    scanf(" %c", &op_produto);
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_cadastrar_produto(void) {
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
    printf("|                            Cadastrar Produto                                |\n");
    printf("|                                                                             |\n");
    printf("|      Nome:                                                                  |\n");
    printf("|      Valor:                                                                 |\n");
    printf("|      Quantidade:                                                            |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_exibir_produto(void){
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
    printf("|                           Exibir Dados do Produto                           |\n");
    printf("|                                                                             |\n");
    printf("|      Informe o ID do produto:                                               |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_menu_venda(void) {
    char op_venda;
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
    printf("|                                Módulo Venda                                 |\n");
    printf("|                                                                             |\n");
    printf("|      1 - Cadastrar Venda                                                    |\n");
    printf("|      2 - Exibir Dados da Venda                                              |\n");
    printf("|      3 - Alterar Dados da Venda                                             |\n");
    printf("|      4 - Excluir Venda                                                      |\n");
    printf("|      0 - Retornar ao Menu Principal                                         |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    printf("|Escolha sua opção:");
    scanf(" %c", &op_venda);
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_menu_relatorio(void) {
    char op_relatorio;
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
    printf("|                              Módulo Relatório                               |\n");
    printf("|                                                                             |\n");
    printf("|      1  - Lista geral de clientes                                           |\n");
    printf("|      2  - Lista geral de funcionários                                       |\n");
    printf("|      3  - Lista geral de quartos                                            |\n");
    printf("|      4  - Lista geral de hospedagens                                        |\n");
    printf("|      5  - Lista geral de produtos                                           |\n");
    printf("|      6  - Lista geral de vendas                                             |\n");
    printf("|      7  - Lista de hospedagens por cliente                                  |\n");
    printf("|      8  - Lista de hospedagens por funcionário                              |\n");
    printf("|      9  - Lista de hospedagens por quarto                                   |\n");
    printf("|     10  - Lista de hospedagens por período                                  |\n");
    printf("|     11  - Lista de vendas por cliente                                       |\n");
    printf("|     12  - Lista de vendas por funcionário                                   |\n");
    printf("|     13  - Lista de vendas por produto                                       |\n");
    printf("|     14  - Lista de vendas por hospedagem                                    |\n");
    printf("|     15  - Lista de vendas por período                                       |\n");
    printf("|     16  - Lista de gastos totais por cliente                                |\n");
    printf("|      0  - Retornar ao Menu Principal                                        |\n");
    printf("|                                                                             |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    printf("|Escolha sua opção:");
    scanf(" %c", &op_relatorio);
    getchar();
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}


void tela_finalizacao(void) {
    system("clear||cls");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("|                            SISTEMA ENCERRADO                                |\n");
    printf("|                                                                             |\n");
    printf("|                 Obrigado por utilizar o SIG-Motel!                          |\n");
    printf("|                                                                             |\n");
    printf("| Este sistema auxilia no gerenciamento de clientes, funcionários, quartos,   |\n");
    printf("| produtos, hospedagens, vendas e relatórios, garantindo organização e        |\n");
    printf("| eficiência na administração do motéis.                                      |\n");
    printf("|                                                                             |\n");
    printf("|                             Até a próxima!                                  |\n");
    printf("♡--------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------------˖⁺‧₊˚♡˚₊‧⁺˖--------♡\n");
    printf("\n");
    printf("Pressione ENTER para sair...");
    getchar();
}