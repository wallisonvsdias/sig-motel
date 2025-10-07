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
    Cliente cliente;
    FILE *arq_clientes;
    arq_clientes = fopen("clientes.csv", "at");
    if (arq_clientes == NULL) {
        printf("nao consigo ler nada");
        printf("pressione <enter>");
        getchar();
        return;
    }
    int tam;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                              Cadastrar Cliente                              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      CPF: ");
    scanf("%s",cliente.cpf);
    getchar();
    printf("♡      Nome: ");
    fgets(cliente.nome,51,stdin);
    tam = strlen(cliente.nome);
    cliente.nome[tam-1] = '\0';
    printf("♡      Data de nascimento: ");
    scanf("%s",cliente.nasc);
    getchar();
    printf("♡      Telefone (apenas números): ");
    scanf("%s",cliente.telef);
    getchar();
    printf("♡      E-mail: ");
    scanf("%s",cliente.email);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    fprintf(arq_clientes,"%s;",cliente.cpf);
    fprintf(arq_clientes,"%s;",cliente.nome);
    fprintf(arq_clientes,"%s;",cliente.nasc);
    fprintf(arq_clientes,"%s;",cliente.telef);
    fprintf(arq_clientes,"%s\n",cliente.email);
    fclose(arq_clientes);

    continuar_acao();
}


void exibir_cliente(void){
    Cliente cliente;
    char cpf_lido[12];
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
        cliente.cpf,cliente.nome,cliente.nasc,cliente.telef,cliente.email)==5) {
        if (strcmp(cliente.cpf,cpf_lido)==0){
            printf("\t\t Cliente encontrado! >>>> \n");
            printf("\t\tCPF: %s\n",cliente.cpf);
            printf("\t\tNome: %s\n",cliente.nome);
            printf("\t\tData de nascimento: %s\n",cliente.nasc);
            printf("\t\tTelefone: %s\n",cliente.telef);
            printf("\t\tEmail: %s\n",cliente.email);
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
    Cliente cliente;
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
    if (arq_temp == NULL) {
        printf("Não foi possivel ler o arquivo");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    int tam;
    char cpf_lido[12];
    int encontrado;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                           Alterar Dados do Cliente                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o CPF do cliente: ");
    scanf("%s",cpf_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fscanf(arq_clientes, "%11[^;];%50[^;];%10[^;];%11[^;];%50[^\n]\n",
        cliente.cpf,cliente.nome,cliente.nasc,cliente.telef,cliente.email)==5) {
        if (strcmp(cliente.cpf,cpf_lido)!=0){
            fprintf(arq_temp,"%s;",cliente.cpf);
            fprintf(arq_temp,"%s;",cliente.nome);
            fprintf(arq_temp,"%s;",cliente.nasc);
            fprintf(arq_temp,"%s;",cliente.telef);
            fprintf(arq_temp,"%s\n",cliente.email);
        } else {
            encontrado = 1;
        }
    }
    
    fclose(arq_clientes);

    if (encontrado) {
        Cliente novo_cliente;
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                            Novos dados de Cliente                           ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      CPF: ");
        scanf("%s",novo_cliente.cpf);
        getchar();
        printf("♡      Nome: ");
        fgets(novo_cliente.nome,51,stdin);
        tam = strlen(novo_cliente.nome);
        novo_cliente.nome[tam-1] = '\0';
        printf("♡      Data de nascimento: ");
        scanf("%s",novo_cliente.nasc);
        getchar();
        printf("♡      Telefone (apenas números): ");
        scanf("%s",novo_cliente.telef);
        getchar();
        printf("♡      E-mail: ");
        scanf("%s",novo_cliente.email);
        getchar();
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

        fprintf(arq_temp,"%s;",novo_cliente.cpf);
        fprintf(arq_temp,"%s;",novo_cliente.nome);
        fprintf(arq_temp,"%s;",novo_cliente.nasc);
        fprintf(arq_temp,"%s;",novo_cliente.telef);
        fprintf(arq_temp,"%s\n",novo_cliente.email);
        fclose(arq_temp);

        remove("clientes.csv");
        rename("temp.csv","clientes.csv");
        printf("\t\t Cliente ALTERADO com sucesso! >>>> \n");
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


void excluir_cliente(void){
    Cliente cliente;
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
    if (arq_temp == NULL) {
        printf("Não foi possivel ler o arquivo");
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
    printf("♡                                Excluir Cliente                              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o CPF do cliente: ");
    scanf("%s",cpf_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fscanf(arq_clientes, "%11[^;];%50[^;];%10[^;];%11[^;];%50[^\n]\n",
        cliente.cpf,cliente.nome,cliente.nasc,cliente.telef,cliente.email)==5) {
        if (strcmp(cliente.cpf,cpf_lido)!=0){
            fprintf(arq_temp,"%s;",cliente.cpf);
            fprintf(arq_temp,"%s;",cliente.nome);
            fprintf(arq_temp,"%s;",cliente.nasc);
            fprintf(arq_temp,"%s;",cliente.telef);
            fprintf(arq_temp,"%s\n",cliente.email);
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