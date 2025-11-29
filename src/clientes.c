#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "clientes.h"
#include "validacao.h"


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
    Cliente* cliente;
    cliente = (Cliente*)malloc(sizeof(*cliente));
    FILE *arq_clientes;
    arq_clientes = fopen("data/clientes.DAT", "ab");
    if (arq_clientes == NULL) {
        printf("Não foi possivel ler o arquivo clientes.dat\n");
        printf("pressione <enter>\n");
        getchar();
        return;
    }
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                              Cadastrar Cliente                              ♡\n");
    printf("♡                                                                             ♡\n");
    ler_cpf(cliente->cpf);
    ler_nome(cliente->nome);
    ler_data(cliente->nasc);
    ler_telefone(cliente->telef);
    ler_email(cliente->email);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    cliente->status = True;
    fwrite(cliente,sizeof(Cliente),1,arq_clientes);
    fclose(arq_clientes);
    free(cliente);

    continuar_acao();
}


void exibir_cliente(void){
    Cliente* cliente;
    cliente = (Cliente*)malloc(sizeof(*cliente));
    FILE *arq_clientes;
    arq_clientes = fopen("data/clientes.DAT", "rb");
    if (arq_clientes == NULL) {
        printf("Não foi possivel ler o arquivo clientes.dat\n");
        printf("pressione <enter>\n");
        getchar();
        return;
    }
    char cpf_lido[12];
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Exibir Dados do Cliente                          ♡\n");
    printf("♡                                                                             ♡\n");
    ler_cpf(cpf_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(cliente,sizeof(Cliente),1,arq_clientes)) {
        if (strcmp(cliente->cpf,cpf_lido) == 0  && cliente->status){
            printf("\t\t Cliente encontrado! >>>> \n");
            printf("\t\tCPF: %s\n",cliente->cpf);
            printf("\t\tNome: %s\n",cliente->nome);
            printf("\t\tData de nascimento: %s\n",cliente->nasc);
            printf("\t\tTelefone: %s\n",cliente->telef);
            printf("\t\tEmail: %s\n",cliente->email);
            printf("Pressione <ENTER> para continuar");
            getchar();
            fclose(arq_clientes);
            free(cliente);
            return;
        }
    }
    printf("\t\t Cliente NAO encontrado! >>>> \n");
    printf("Pressione <ENTER> para continuar");
    getchar();
    fclose(arq_clientes);
    free(cliente);
    return;
    continuar_acao();
}


void alterar_cliente(void){
    Cliente* cliente;
    cliente = (Cliente*)malloc(sizeof(*cliente));
    FILE *arq_clientes;
    arq_clientes = fopen("data/clientes.DAT", "rb");
    if (arq_clientes == NULL) {
        printf("Não foi possivel ler o arquivo clientes.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    FILE *arq_temp;
    arq_temp = fopen("data/temp.DAT", "wb");
    if (arq_temp == NULL) {
        printf("Não foi possivel ler o arquivo temp.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    char cpf_lido[12];
    int encontrado = False;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                           Alterar Dados do Cliente                          ♡\n");
    printf("♡                                                                             ♡\n");
    ler_cpf(cpf_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(cliente, sizeof(Cliente), 1, arq_clientes)) {
        if (strcmp(cliente->cpf, cpf_lido) != 0) {
            fwrite(cliente, sizeof(Cliente), 1, arq_temp);
        } else {
            encontrado = True;
        }
    }
    fclose(arq_clientes);
    free(cliente);

    if (encontrado) {
        Cliente* novo_cliente;
        novo_cliente = (Cliente*)malloc(sizeof(*novo_cliente));
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                            Novos dados de Cliente                           ♡\n");
        printf("♡                                                                             ♡\n");
        ler_cpf(novo_cliente->cpf);
        ler_nome(novo_cliente->nome);
        ler_data(novo_cliente->nasc);
        ler_telefone(novo_cliente->telef);
        ler_email(novo_cliente->email);
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        
        novo_cliente->status = True;
        fwrite(novo_cliente,sizeof(Cliente),1,arq_temp);
        fclose(arq_temp);
        free(novo_cliente);

        remove("data/clientes.DAT");
        rename("data/temp.DAT", "data/clientes.DAT");
        printf("\t\t Cliente ALTERADO com sucesso! >>>> \n");
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
    Cliente* cliente;
    cliente = (Cliente*)malloc(sizeof(*cliente));
    FILE *arq_clientes;
    arq_clientes = fopen("data/clientes.DAT", "r+b");
    if (arq_clientes == NULL) {
        printf("Não foi possivel ler o arquivo clientes.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    char cpf_lido[12];
    int encontrado = False;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                                Excluir Cliente                              ♡\n");
    printf("♡                                                                             ♡\n");
    ler_cpf(cpf_lido);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(cliente,sizeof(Cliente),1,arq_clientes) && (!encontrado)) {
        if (strcmp(cliente->cpf,cpf_lido) == 0){
            cliente->status = False;
            fseek(arq_clientes,-(long)sizeof(Cliente),SEEK_CUR);
            fwrite(cliente, sizeof(Cliente), 1, arq_clientes);
            encontrado = True;
        }
    }
    
    fclose(arq_clientes);
    free(cliente);

    if (encontrado) {
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