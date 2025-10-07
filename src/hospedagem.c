#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "hospedagem.h"


void menu_hospedagem(void) {
    char op_hospedagem;
    do {
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                               Módulo Hospedagem                             ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      1 - Cadastrar hospedagem                                               ♡\n");
        printf("♡      2 - Exibir dados da hospedagem                                         ♡\n");
        printf("♡      3 - Alterar dados do hospedagem                                        ♡\n");
        printf("♡      4 - Cancelar hospedagem                                                ♡\n");
        printf("♡      0 - Retornar ao menu principal                                         ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("\nEscolha sua opção: ");
        scanf(" %c", &op_hospedagem);
        
        switch(op_hospedagem) {
            case '1':
                cadastrar_hospedagem();
                break;
            case '2':
                exibir_hospedagem();
                break;
            case '3':
                alterar_hospedagem();
                break;
            case '4':
                excluir_hospedagem();
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
    } while (op_hospedagem != '0');
}


void cadastrar_hospedagem(void) {
   
    FILE *arq_hospedagem;
    arq_hospedagem = fopen("hospedagem.csv", "at");
    char cpf[12];
    char id_quarto[30];
    char horas[3];

    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                           Cadastrar Hospedagem                              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      CPF do cliente: ");
    scanf("%s", cpf);
    getchar();
    printf("♡      ID do quarto: ");
    scanf("%s", id_quarto);
    getchar();
    printf("♡      Quantidade de horas: ");
    scanf("%s", horas);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    fprintf(arq_hospedagem,"%s;",cpf);
    fprintf(arq_hospedagem,"%s;",id_quarto);
    fprintf(arq_hospedagem,"%s\n", horas);
    fclose(arq_hospedagem);

    continuar_acao();
}

// Exibir também a data
void exibir_hospedagem(void) {
    char cpf[12];
    char cpf_lido[12];
    char id_quarto[4];
    char horas[4];

    FILE *arq_hospedagem;
    arq_hospedagem = fopen("hospedagem.csv", "rt");
    if (arq_hospedagem == NULL) {
        printf("nao consigo ler nada");
        printf("pressione <enter>");
        getchar();
        return;
    }
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                        Exibir Dados da Hospedagem                           ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o CPF do cliente hospedado: ");
    scanf("%s", cpf_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    while (fscanf(arq_hospedagem, "%11[^;];%3[^;];%3[^\n]\n", cpf, id_quarto, horas) == 3) {
        if (strcmp(cpf, cpf_lido) == 0) {
            printf("\nHospedagem encontrado!\n");
            printf("CPF: %s\n", cpf);
            printf("ID do quarto: %s\n", id_quarto);
            printf("Horas: %s\n", horas);
            fclose(arq_hospedagem);
            getchar();
            return;
        }
    }
    fclose(arq_hospedagem);
    printf("\nHospedagem não encontrado.\n");
    getchar();
    continuar_acao();
}


void alterar_hospedagem(void) {
    Hospedagem hospedagem;
    FILE *arq_hospedagem;
        arq_hospedagem = fopen("hospedagem.csv", "rt");
    if (arq_hospedagem == NULL) {
        printf("Não foi possivel ler o arquivo de hospedagem");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    FILE *arq_temp;
    arq_temp = fopen("temp_hospedagem.csv", "wt");
    if (arq_temp == NULL) {
        printf("Não foi possivel criar arquivo temporário");
        fclose(arq_hospedagem);
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    char cpf_lido[12];
    int encontrado = 0;
    int tam;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                        Alterar Dados da Hospedagem                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o ID da hospedagem:                                            ♡\n");
    scanf("%s", cpf_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fscanf(arq_hospedagem, "%11[^;];%3[^;];%3[^\n]\n",
            hospedagem.cpf, hospedagem.id_quarto,hospedagem.horas)==6) {
        if (strcmp(hospedagem.cpf,cpf_lido)!=0){
            fprintf(arq_temp,"%s;",hospedagem.cpf);
            fprintf(arq_temp,"%s;",hospedagem.id_quarto);
            fprintf(arq_temp,"%s\n",hospedagem.horas);
        } else {
            encontrado = 1;
        }
    }
    
    fclose(arq_hospedagem);

    if (encontrado) {
        Hospedagem novo_hospedagem;
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                            Novos dados de Cliente                           ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      CPF: ");
        scanf("%s",novo_hospedagem.cpf);
        getchar();
        printf("♡      ID do Quarto: ");
        scanf("%s",novo_hospedagem.id_quarto);
        getchar();
        printf("♡      Horas: ");
        scanf("%s",novo_hospedagem.horas);
        getchar();
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

        fprintf(arq_temp,"%s;",novo_hospedagem.cpf);
        fprintf(arq_temp,"%s;",novo_hospedagem.id_quarto);
        fprintf(arq_temp,"%s\n",novo_hospedagem.horas);
        fclose(arq_temp);

        remove("hospedagem.csv");
        rename("temp.csv","hospedagem.csv");
        printf("\t\t Hospedagem ALTERADA com sucesso! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;

    } else {
        printf("\t\t Hospedagem NAO encontrado! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    }
    continuar_acao();
}


void excluir_hospedagem(void) {
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                              Excluir Hospedagem                             ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o ID da hospedagem:                                            ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    continuar_acao();
}