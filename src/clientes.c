#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "clientes.h"


void menu_cliente(void) {
    char op_cliente;
    do {
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                                Módulo Cliente                               ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      1 - Cadastrar cliente                                                  ♡\n");
        printf("♡      2 - Exibir dados do cliente                                            ♡\n");
        printf("♡      3 - Alterar dados do cliente                                           ♡\n");
        printf("♡      4 - Excluir cliente                                                    ♡\n");
        printf("♡      0 - Retornar ao menu principal                                         ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("\nEscolha sua opção: ");
        scanf(" %c", &op_cliente);
        getchar();

        switch(op_cliente) {
            case '1':
                cadastrar_cliente();
                break;
            case '2':
                exibir_cliente();
                break;
            case '3':
                alterar_cliente();
                break;
            case '4':
                excluir_cliente();
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
    } while (op_cliente != '0');
}


void cadastrar_cliente(void) {
    FILE *arq_clientes;
    arq_clientes = fopen("clientes.csv", "at");
    if (arq_clientes == NULL) {
        printf("nao consigo ler nada");
        printf("pressione <enter>");
        getchar();
        return;
    }
    char nome[51];
    char cpf[12];
    char nasc[11];
    char telef[12];
    char email[51];
    int tam;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                              Cadastrar Cliente                              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      CPF: ");
    scanf("%s",cpf);
    getchar();
    printf("♡      Nome: ");
    fgets(nome,51,stdin);
    tam = strlen(nome);
    nome[tam-1] = '\0';
    printf("♡      Data de nascimento: ");
    scanf("%s",nasc);
    getchar();
    printf("♡      Telefone (apenas números): ");
    scanf("%s",telef);
    getchar();
    printf("♡      E-mail: ");
    scanf("%s",email);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    fprintf(arq_clientes,"%s;",cpf);
    fprintf(arq_clientes,"%s;",nome);
    fprintf(arq_clientes,"%s;",nasc);
    fprintf(arq_clientes,"%s;",telef);
    fprintf(arq_clientes,"%s\n",email);
    fclose(arq_clientes);

    continuar_acao();
}


void exibir_cliente(void){
    char nome[51];
    char cpf[12];
    char cpf_lido[12];
    char nasc[11];
    char telef[12];
    char email[51];
    FILE *arq_clientes;
    arq_clientes = fopen("clientes.csv", "rt");
    if (arq_clientes == NULL) {
        printf("nao consigo ler nada");
        printf("pressione <enter>");
        getchar();
        return;
    }
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Exibir Dados do Cliente                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o CPF do cliente: ");
    scanf("%s",cpf_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fscanf(arq_clientes, "%11[^;];%50[^;];%10[^;];%11[^;];%50[^\n]\n",
        cpf,nome,nasc,telef,email)==5) {
        if (strcmp(cpf,cpf_lido)==0){
            printf("\t\t Cliente encontrado! >>>> \n");
            printf("\t\tCPF: %s\n",cpf);
            printf("\t\tNome: %s\n",nome);
            printf("\t\tData de nascimento: %s\n",nasc);
            printf("\t\tTelefone: %s\n",telef);
            printf("\t\tEmail: %s\n",email);
            printf("Pressione <ENTER> para continuar");
            getchar();
            fclose(arq_clientes);
            return;
        }
    }
    printf("\t\t Cliente NAO encontrado! >>>> \n");
    printf("Pressione <ENTER> para continuar");
    getchar();
    fclose(arq_clientes);
    return;
    continuar_acao();
}


void alterar_cliente(void){
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                           Alterar Dados do Cliente                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o CPF do cliente:                                              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    continuar_acao();
}


void excluir_cliente(void){
    FILE *arq_clientes;
    arq_clientes = fopen("clientes.csv", "rt");
    if (arq_clientes == NULL) {
        printf("Não foi possivel ler o arquivo");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    FILE *arq_temp;
    arq_temp = fopen("temp.csv", "at");
    if (arq_clientes == NULL) {
        printf("Não foi possivel ler o arquivo");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    char nome[51];
    char cpf[12];
    char cpf_lido[12];
    char nasc[11];
    char telef[12];
    char email[51];
    int encontrado;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                                Excluir Cliente                              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o CPF do cliente: ");
    scanf("%s",cpf_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fscanf(arq_clientes, "%11[^;];%50[^;];%10[^;];%11[^;];%50[^\n]\n",
        cpf,nome,nasc,telef,email)==5) {
        if (strcmp(cpf,cpf_lido)!=0){
            fprintf(arq_temp,"%s;",cpf);
            fprintf(arq_temp,"%s;",nome);
            fprintf(arq_temp,"%s;",nasc);
            fprintf(arq_temp,"%s;",telef);
            fprintf(arq_temp,"%s\n",email);
        } else {
            encontrado = 1;
        }
    }
    
    fclose(arq_clientes);
    fclose(arq_temp);

    if (encontrado) {
        remove("clientes.csv");
        rename("temp.csv","clientes.csv");
        printf("\t\t Cliente EXCLUIDO com sucesso! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    } else {
        printf("\t\t Cliente NAO encontrado! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    }

    continuar_acao();
}