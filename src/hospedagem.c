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
    if (!hospedagem) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    FILE *arq_hospedagem = fopen("hospedagem.DAT", "ab");
    if (arq_hospedagem == NULL) {
        printf("Não foi possível abrir o arquivo hospedagem.DAT\n");
        free(hospedagem);
        printf("Pressione <ENTER> ...");
        getchar();
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

    hospedagem->status = True; 
    fwrite(hospedagem, sizeof(Hospedagem), 1, arq_hospedagem);

    fclose(arq_hospedagem);
    free(hospedagem);

    continuar_acao();
}

// Exibir também a data
void exibir_hospedagem(void) {
    Hospedagem* hospedagem; 
    hospedagem = (Hospedagem*) malloc(sizeof(*hospedagem));
    FILE *arq_hospedagem = fopen("hospedagem.DAT", "rb");
    if (arq_hospedagem == NULL) {
        printf("Não foi possível abrir o arquivo hospedagem.DAT\n");
        free(hospedagem);
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    char cpf_lido[12];
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                       Exibir Dados da Hospedagem                             ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o CPF do cliente hospedado: ");
    scanf("%s", cpf_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    while (fread(hospedagem, sizeof(Hospedagem), 1, arq_hospedagem)) {
        if (strcmp(hospedagem->cpf, cpf_lido) == 0 && hospedagem->status == True) {
            printf("\nHospedagem encontrada!\n");
            printf("CPF: %s\n", hospedagem->cpf);
            printf("ID do quarto: %s\n", hospedagem->id_quarto);
            printf("Horas: %s\n", hospedagem->horas);
            getchar();
            fclose(arq_hospedagem);
            free(hospedagem);
            return;
        }
    }
    printf("\t\t Hospedagem NAO encontrado! >>>> \n");
    printf("Pressione <ENTER> para continuar");
    getchar();
    fclose(arq_hospedagem);
    free(hospedagem);
    return;
    continuar_acao();
}


void alterar_hospedagem(void) {
    Hospedagem* hospedagem;
    hospedagem = (Hospedagem*) malloc(sizeof(*hospedagem));
    FILE *arq_hospedagem = fopen("hospedagem.DAT", "r+b");
    if (arq_hospedagem == NULL) {
        printf("Não foi possível abrir o arquivo hospedagem.DAT\n");
        printf("Pressione <ENTER> ...");
        free(hospedagem);
        getchar();
        return;
    }
    FILE *arq_temp;
    arq_temp = fopen("temp.DAT", "ab");
    if (arq_temp == NULL) {
        printf("Não foi possivel ler o arquivo temp.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }

    char cpf_lido[12];
    int encontrado;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                        Alterar Dados da Hospedagem                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o CPF da hospedagem: ");
    scanf("%s", cpf_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    while (fread(hospedagem,sizeof(Hospedagem),1,arq_hospedagem)) {
        if (strcmp(hospedagem->cpf,cpf_lido) != 0){
            fwrite(hospedagem,sizeof(Hospedagem),1,arq_temp);
        } else {
            encontrado = True;
        }
    }
    fclose(arq_hospedagem);
    free(hospedagem);
    
    if (encontrado) {
        Hospedagem* nova_hospedagem;
        nova_hospedagem = (Hospedagem*)malloc(sizeof(*nova_hospedagem));
            system("clear||cls");
            mostrar_cabecalho();
            printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
            printf("♡                                                                             ♡\n");
            printf("♡                        Novos dados da Hospedagem                            ♡\n");
            printf("♡                                                                             ♡\n");
            printf("♡      CPF: ");
            scanf("%s", nova_hospedagem->cpf);
            getchar();
            printf("♡      ID do Quarto: ");
            scanf("%s", nova_hospedagem->id_quarto);
            getchar();
            printf("♡      Horas: ");
            scanf("%s", nova_hospedagem->horas);
            printf("♡                                                                             ♡\n");
            printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
            getchar();
            nova_hospedagem->status = True;
            fwrite(nova_hospedagem,sizeof(Hospedagem),1,arq_temp);
            fclose(arq_temp);
            free(nova_hospedagem);
            remove("hospedahem.DAT");
            rename("temp.DAT","hospedagem.DAT");
            printf("\t\t Hospedagem ALTERADA com sucesso! >>>> \n");
            printf("Pressione <ENTER> para continuar");
            getchar();
            return;
        }
    else {
        printf("\t\t Hospedagem NAO encontrado! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    }
    continuar_acao();
}


void excluir_hospedagem(void) {
    Hospedagem* hospedagem;
    hospedagem = (Hospedagem*) malloc(sizeof(*hospedagem)); 
    FILE *arq_hospedagem = fopen("hospedagem.DAT", "r+b");
    if (!arq_hospedagem) {
        printf("Não foi possível abrir o arquivo hospedagem.DAT\n");
        free(hospedagem);
        getchar();
        return;
    }

    char cpf_lido[12];
    int encontrado = False;

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
    while (fread(hospedagem,sizeof(Hospedagem),1,arq_hospedagem) && (!encontrado)) {
        if (strcmp(hospedagem->cpf,cpf_lido) == 0){
            hospedagem ->status = False;
            fseek(arq_hospedagem,-(long)sizeof(Hospedagem),SEEK_CUR);
            fwrite(hospedagem, sizeof(Hospedagem), 1, arq_hospedagem);
            encontrado = True;
        }
    }
    

    fclose(arq_hospedagem);
    free(hospedagem);
    
    if (encontrado) {
        printf("\t\t Hospedahem EXCLUIDO com sucesso! >>>> \n");
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