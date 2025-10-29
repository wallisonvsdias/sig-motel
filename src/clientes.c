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
    arq_clientes = fopen("clientes.DAT", "ab");
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
    do {
        printf("♡      CPF (apenas 11 numeros): ");
        ler_string(cliente->cpf,12);
        if (!validar_cpf(cliente->cpf)) {
            printf("♡      CPF invalido! Deve conter 11 numeros\n");
            printf("♡      Pressione <ENTER>");
            getchar();
        }
    } while (!validar_cpf(cliente->cpf));
    do {
        printf("♡      Nome: ");
        ler_string(cliente->nome,51);
        if (!validar_nome(cliente->nome)) {
            printf("♡      Nome invalido! Deve conter apenas letras e espacos\n");
            printf("♡      Pressione <ENTER>");
            getchar();
        }
    } while (!validar_nome(cliente->nome));
    do {
        printf("♡      Data de nascimento: ");
        ler_string(cliente->nasc,11);
        if (!validar_data(cliente->nasc)) {
            printf("♡      Data de nascimento invalida! Use o formato DD/MM/AAAA\n");
            printf("♡      Pressione <ENTER>");
            getchar();
        }
    } while (!validar_data(cliente->nasc));
    do {
        printf("♡      Telefone (apenas números): ");
        ler_string(cliente->telef,12);
        if (!validar_telefone(cliente->telef)) {
            printf("♡      Telefone invalido! Use apenas numeros e deve conter 11 digitos\n");
            printf("♡      Pressione <ENTER>");
            getchar();
        }
    } while (!validar_telefone(cliente->telef));
    do {
        printf("♡      Email:");
        ler_string(cliente->email,51);
        if (!validar_email(cliente->email)) {
            printf("♡      Email invalido! Formato esperado: joao@teste.com\n");
            printf("♡      Pressione <ENTER>");
            getchar();
        }
    } while (!validar_email(cliente->email));
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
    arq_clientes = fopen("clientes.DAT", "rb");
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
    do {
        printf("♡      Informe o CPF do cliente: ");
        ler_string(cpf_lido,12);
        if (!validar_cpf(cpf_lido)) {
            printf("♡      CPF invalido! Deve conter 11 numeros\n");
            printf("♡      Pressione <ENTER>");
            getchar();
        }
    } while (!validar_cpf(cpf_lido));
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(cliente,sizeof(Cliente),1,arq_clientes)) {
        if (strcmp(cliente->cpf,cpf_lido) == 0  && cliente->status==True){
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
    arq_clientes = fopen("clientes.DAT", "rb");
    if (arq_clientes == NULL) {
        printf("Não foi possivel ler o arquivo clientes.DAT");
        printf("Pressione <ENTER> ...");
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
    printf("♡                           Alterar Dados do Cliente                          ♡\n");
    printf("♡                                                                             ♡\n");
    do {
        printf("♡      Informe o CPF do cliente: ");
        ler_string(cpf_lido,12);
        if (!validar_cpf(cpf_lido)) {
            printf("♡      CPF invalido! Deve conter 11 numeros\n");
            printf("♡      Pressione <ENTER>");
            getchar();
        }
    } while (!validar_cpf(cpf_lido));
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(cliente,sizeof(Cliente),1,arq_clientes)) {
        if (strcmp(cliente->cpf,cpf_lido) != 0){
            fwrite(cliente,sizeof(Cliente),1,arq_temp);
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
        do {
            printf("♡      CPF (apenas 11 numeros): ");
            ler_string(novo_cliente->cpf,12);
            if (!validar_cpf(novo_cliente->cpf)) {
                printf("♡      CPF invalido! Deve conter 11 numeros\n");
                printf("♡      Pressione <ENTER>");
                getchar();
            }
        } while (!validar_cpf(novo_cliente->cpf));
        do {
            printf("♡      Nome: ");
            ler_string(novo_cliente->nome,51);
            if (!validar_nome(novo_cliente->nome)) {
                printf("♡      Nome invalido! Deve conter apenas letras e espacos\n");
                printf("♡      Pressione <ENTER>");
                getchar();
            }
        } while (!validar_nome(novo_cliente->nome));
        do {
            printf("♡      Data de nascimento: ");
            ler_string(novo_cliente->nasc,11);
            if (!validar_data(novo_cliente->nasc)) {
                printf("♡      Data de nascimento invalida! Use o formato DD/MM/AAAA\n");
                printf("♡      Pressione <ENTER>");
                getchar();
            }
        } while (!validar_data(novo_cliente->nasc));
        do {
            printf("♡      Telefone (apenas números): ");
            ler_string(novo_cliente->telef,12);
            if (!validar_telefone(novo_cliente->telef)) {
                printf("♡      Telefone invalido! Use apenas numeros e deve conter 11 digitos\n");
                printf("♡      Pressione <ENTER>");
                getchar();
            }
        } while (!validar_telefone(novo_cliente->telef));
        do {
            printf("♡      Email:");
            ler_string(novo_cliente->email,51);
            if (!validar_email(novo_cliente->email)) {
                printf("♡      Email invalido! Formato esperado: joao@teste.com\n");
                printf("♡      Pressione <ENTER>");
                getchar();
            }
        } while (!validar_email(novo_cliente->email));
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        novo_cliente->status = True;
        fwrite(novo_cliente,sizeof(Cliente),1,arq_temp);
        fclose(arq_temp);
        free(novo_cliente);
        remove("clientes.DAT");
        rename("temp.DAT","clientes.DAT");
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
    Cliente* cliente;
    cliente = (Cliente*)malloc(sizeof(*cliente));
    FILE *arq_clientes;
    arq_clientes = fopen("clientes.DAT", "r+b");
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
    do {
        printf("♡      Informe o CPF do cliente: ");
        ler_string(cpf_lido,12);
        if (!validar_cpf(cpf_lido)) {
            printf("♡      CPF invalido! Deve conter 11 numeros\n");
            printf("♡      Pressione <ENTER>");
            getchar();
        }
    } while (!validar_cpf(cpf_lido));
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