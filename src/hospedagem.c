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
    Hospedagem* hospedagem = (Hospedagem*) malloc(sizeof(*hospedagem));
    FILE *arq_hospedagem = fopen("hospedagem.DAT", "ab");
    if (arq_hospedagem == NULL) {
        printf("Não foi possível abrir o arquivo hospedagem.DAT\n");
        printf("Pressione <ENTER> ...");
        free(hospedagem);
        return;
    }
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                           Cadastrar Hospedagem                              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      CPF do cliente: ");
    scanf("%s", hospedagem->cpf);
    getchar();
    printf("♡      ID do quarto: ");
    scanf("%s", hospedagem->id_quarto);
    getchar();
    printf("♡      Quantidade de horas: ");
    scanf("%s", hospedagem->horas);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    hospedagem->status = 1; // ativo
    fwrite(hospedagem, sizeof(Hospedagem), 1, arq_hospedagem);

    fclose(arq_hospedagem);
    free(hospedagem);

    continuar_acao();
}

// Exibir também a data
void exibir_hospedagem(void) {
    Hospedagem* hospedagem = (Hospedagem*) malloc(sizeof(*hospedagem));
    FILE *arq_hospedagem = fopen("hospedagem.DAT", "rb");
    if (arq_hospedagem == NULL) {
        printf("Não foi possível abrir o arquivo hospedagem.DAT\n");
        printf("Pressione <ENTER> ...");
        free(hospedagem);
        return;
    }

    char cpf_lido[12];
    int encontrado = 0;
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

    while (fread(hospedagem, sizeof(Hospedagem), 1, arq_hospedagem) == 1) {
        if (strcmp(hospedagem->cpf, cpf_lido) == 0 && hospedagem->status == 1) {
            printf("\nHospedagem encontrada!\n");
            printf("CPF: %s\n", hospedagem->cpf);
            printf("ID do quarto: %s\n", hospedagem->id_quarto);
            printf("Horas: %s\n", hospedagem->horas);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nHospedagem não encontrada.\n");
    }

    fclose(arq_hospedagem);
    free(hospedagem);
    printf("Pressione <ENTER> para continuar...");
    getchar();
}


void alterar_hospedagem(void) {
    Hospedagem* hospedagem = (Hospedagem*) malloc(sizeof(*hospedagem));
    FILE *arq_hospedagem = fopen("hospedagem.DAT", "rb");
    if (arq_hospedagem == NULL) {
        printf("Não foi possível abrir o arquivo hospedagem.DAT\n");
        printf("Pressione <ENTER> ...");
        free(hospedagem);
        return;
    }

    FILE *arq_temp = fopen("temp_hospedagem.DAT", "ab");
    if (arq_temp == NULL) {
        printf("Não foi possível criar o arquivo temporário\n");
        fclose(arq_hospedagem);
        free(hospedagem);
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
    while (fread(hospedagem, sizeof(Hospedagem), 1, arq_hospedagem) == 1) {
        if (strcmp(hospedagem->cpf, cpf_lido) != 0 || hospedagem->status == 0) {
            fwrite(hospedagem, sizeof(Hospedagem), 1, arq_temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arq_hospedagem);
    free(hospedagem);


    if (encontrado) {
        Hospedagem* novo_hospedagem = (Hospedagem*) malloc(sizeof(*novo_hospedagem));
        if (novo_hospedagem == NULL) {
            printf("Erro ao alocar memória.\n");
            fclose(arq_temp);
            getchar();
            return;
        }

        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                         Novos dados da Hospedagem                           ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      CPF: ");
        scanf("%s",novo_hospedagem->cpf);
        getchar();
        printf("♡      ID do Quarto: ");
        scanf("%s",novo_hospedagem->id_quarto);
        getchar();
        printf("♡      Horas: ");
        scanf("%s",novo_hospedagem->horas);
        getchar();
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

        printf("♡                                                                             ♡\n");
        novo_hospedagem->status = 1;
        fwrite(novo_hospedagem, sizeof(Hospedagem), 1, arq_temp);

        fclose(arq_temp);
        free(novo_hospedagem);

        remove("hospedagem.DAT");
        rename("temp_hospedagem.DAT", "hospedagem.DAT");

        printf("\t\t Hospedagem ALTERADA com sucesso! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;

    } else {
        fclose(arq_temp);
        remove("temp_hospedagem.DAT");
        printf("\t\t Hospedagem NAO encontrada! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    }
    continuar_acao();
}


void excluir_hospedagem(void) {
    Hospedagem* hospedagem = (Hospedagem*) malloc(sizeof(*hospedagem)); 
    FILE *arq_hospedagem = fopen("hospedagem.DAT", "r+b");
    if (!arq_hospedagem) {
        printf("Não foi possível abrir o arquivo hospedagem.DAT\n");
        free(hospedagem);
        getchar();
        return;
    }

    char cpf_lido[12];
    int encontrado = 0;

    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                              Excluir Hospedagem                             ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o ID da hospedagem: ");
    scanf("%s", cpf_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(hospedagem, sizeof(Hospedagem), 1, arq_hospedagem)) {
        if (strcmp(hospedagem->cpf, cpf_lido) == 0 && hospedagem->status == 1) {
            hospedagem->status = 0; // exclusão lógica
            fseek(arq_hospedagem, -((long) sizeof(Hospedagem)), SEEK_CUR);
            fwrite(hospedagem, sizeof(Hospedagem), 1, arq_hospedagem);
            encontrado = 1;
            break;
        }
    }

    fclose(arq_hospedagem);
    free(hospedagem);
    
    if (encontrado) {
        printf("\n♡ Hospedagem EXCLUÍDA com sucesso! ♡\n");
    } else {
        printf("\n♡ Hospedagem NÃO encontrada! ♡\n");
    }

    printf("Pressione <ENTER> para continuar...");
    continuar_acao();
}