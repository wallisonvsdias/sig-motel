#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "hospedagem.h"
#include "validacao.h"


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
        getchar();
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

    FILE *arq_hospedagem = fopen("data/hospedagem.DAT", "ab");
    if (arq_hospedagem == NULL) {
        printf("Não foi possível abrir o arquivo hospedagem.DAT\n");
        free(hospedagem);
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    char entrada_id[10];
    char entrada_horas[10];
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                           Cadastrar Hospedagem                              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o CPF do cliente.                                              ♡\n");
    ler_cpf(hospedagem->cpf);
    printf("♡      Informe o ID do quarto.                                                ♡\n");
    ler_id(entrada_id);
    hospedagem->id_quarto = atoi(entrada_id);
    printf("♡      Informe a quantidade de horas.                                         ♡\n");
    ler_quantidade(entrada_horas);
    hospedagem->horas = atoi(entrada_horas);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    hospedagem->status = True; 
    // registra a data automaticamente
    pegar_data_atual(hospedagem->data);
    fwrite(hospedagem, sizeof(Hospedagem), 1, arq_hospedagem);
    fclose(arq_hospedagem);
    free(hospedagem);

    continuar_acao();
}

// Exibir também a data
void exibir_hospedagem(void) {
    Hospedagem* hospedagem; 
    hospedagem = (Hospedagem*) malloc(sizeof(*hospedagem));
    FILE *arq_hospedagem = fopen("data/hospedagem.DAT", "rb");
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
    printf("♡                       Exibir Dados da Hospedagem                            ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o CPF do cliente.                                              ♡\n");
    ler_cpf(cpf_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    while (fread(hospedagem, sizeof(Hospedagem), 1, arq_hospedagem)) {
        if (strcmp(hospedagem->cpf, cpf_lido) == 0 && hospedagem->status) {
            printf("\nHospedagem encontrada!\n");
            printf("CPF: %s\n", hospedagem->cpf);
            printf("ID do quarto: %d\n", hospedagem->id_quarto);
            printf("Horas: %d\n", hospedagem->horas);
            printf("Data do registro: %s\n", hospedagem->data);
            
            fclose(arq_hospedagem);
            free(hospedagem);
            continuar_acao();
            return;
        }
    }
    printf("\t\t Hospedagem NAO encontrado! >>>> \n");
    fclose(arq_hospedagem);
    free(hospedagem);
    continuar_acao();
    return;
}


void alterar_hospedagem(void) {
    Hospedagem* hospedagem;
    hospedagem = (Hospedagem*) malloc(sizeof(*hospedagem));
    FILE *arq_hospedagem = fopen("data/hospedagem.DAT", "r+b");
    if (arq_hospedagem == NULL) {
        printf("Não foi possível abrir o arquivo hospedagem.DAT\n");
        printf("Pressione <ENTER> ...");
        free(hospedagem);
        getchar();
        return;
    }
    FILE *arq_temp;
    arq_temp = fopen("data/temp.DAT", "ab");
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
    printf("♡      Informe o CPF do cliente.                                              ♡\n");
    ler_cpf(cpf_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    while (fread(hospedagem,sizeof(Hospedagem),1,arq_hospedagem)) {
        if (strcmp(hospedagem->cpf,cpf_lido) != 0 || hospedagem->status == False){
            fwrite(hospedagem,sizeof(Hospedagem),1,arq_temp);
        } else {
            encontrado = True;
        }
    }
    pegar_data_atual(hospedagem->data);
    fclose(arq_hospedagem);
    free(hospedagem);
    
    if (encontrado) {
        Hospedagem* nova_hospedagem;
        nova_hospedagem = (Hospedagem*)malloc(sizeof(*nova_hospedagem));

        system("clear||cls");
        char entrada_id[10];
        char entrada_horas[10];

        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                        Novos dados da Hospedagem                            ♡\n");
        printf("♡                                                                             ♡\n");
        ler_cpf(nova_hospedagem->cpf);
        ler_id(entrada_id); 
        nova_hospedagem->id_quarto = atoi(entrada_id);
        printf("♡      Quantidade de Horas:                                                   ♡\n");
        ler_quantidade(entrada_horas);
        nova_hospedagem->horas = atoi(entrada_horas);
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        nova_hospedagem->status = True;
        fwrite(nova_hospedagem,sizeof(Hospedagem),1,arq_temp);
        fclose(arq_temp);
        free(nova_hospedagem);

        remove("data/hospedahem.DAT");
        rename("data/temp.DAT","data/hospedagem.DAT");
        printf("\t\t Hospedagem ALTERADA com sucesso! >>>> \n");
        continuar_acao();
        return;
        }
    else {
        fclose(arq_temp);
        printf("\t\t Hospedagem NAO encontrado! >>>> \n");
        continuar_acao();
        return;
    }
}


void excluir_hospedagem(void) {
    Hospedagem* hospedagem;
    hospedagem = (Hospedagem*) malloc(sizeof(*hospedagem)); 
    FILE *arq_hospedagem = fopen("data/hospedagem.DAT", "r+b");
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
    printf("♡      Informe o CPF do cliente\n");
    ler_cpf(cpf_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(hospedagem,sizeof(Hospedagem),1,arq_hospedagem) && (!encontrado)) {
        if (strcmp(hospedagem->cpf,cpf_lido) == 0){
            if (hospedagem->status == False) {
                printf("\t\t Hospedagem NAO encontrado! >>>>\n");
                continuar_acao();
                return;
            }
            hospedagem ->status = False;
            fseek(arq_hospedagem,-(long)sizeof(Hospedagem),SEEK_CUR);
            fwrite(hospedagem, sizeof(Hospedagem), 1, arq_hospedagem);
            encontrado = True;
        }
    }
    

    fclose(arq_hospedagem);
    free(hospedagem);
    
    if (encontrado) {
        printf("\t\t Hospedagem EXCLUIDO com sucesso! >>>> \n");
        continuar_acao();
        return;
    } else {
        printf("\t\t Hospedagem NAO encontrado! >>>> \n");
        continuar_acao();
        return;
    }
    
}