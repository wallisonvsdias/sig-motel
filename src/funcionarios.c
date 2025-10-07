#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "funcionarios.h"


void menu_funcionario(void) {    
    char op_funcionario;
    do {
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                           Módulo Funcionário(a)                             ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      1 - Cadastrar funcioário(a)                                            ♡\n");
        printf("♡      2 - Exibir dados do funcionário(a)                                     ♡\n");
        printf("♡      3 - Alterar dados do funcionário(a)                                    ♡\n");
        printf("♡      4 - Excluir funcionário(a)                                             ♡\n");
        printf("♡      0 - Retornar ao menu principal                                         ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("\nEscolha sua opção: ");
        scanf(" %c", &op_funcionario);
        
        switch(op_funcionario) {
            case '1':
                cadastrar_funcionario();
                break;
            case '2':
                exibir_funcionario();
                break;
            case '3':
                alterar_funcionario();
                break;
            case '4':
                excluir_funcionario();
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
    } while (op_funcionario != '0');
}


void cadastrar_funcionario(void) {
    FILE *arq_funcionario;
    arq_funcionario= fopen("funcionarios.csv","at");
    char cpf[12];
    char nome[51];
    char telefone[12];
    char email[53];
    char cargo[20];
    char salario[9];
    int tam;

    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                           Cadastrar Funcionário(a)                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      CPF: ");
    scanf("%s", cpf);
    getchar();
    printf("♡      Nome: ");
    fgets(nome, 51, stdin);
    tam = strlen(nome);
    nome[tam-1] = '\0';
    printf("♡      Telefone: ");
    scanf("%s", telefone);
    getchar();
    printf("♡      E-mail: ");
    scanf("%s", email);
    printf("♡      Cargo: ");
    scanf("%s", cargo);
    getchar();
    printf("♡      Salário: ");
    scanf("%s", salario);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    fprintf(arq_funcionario, "%s;", cpf);
    fprintf(arq_funcionario, "%s;", nome);
    fprintf(arq_funcionario, "%s;", telefone);
    fprintf(arq_funcionario, "%s;", email);
    fprintf(arq_funcionario, "%s;", cargo);
    fprintf(arq_funcionario, "%s\n", salario);
    fclose(arq_funcionario);

    continuar_acao();
}


void exibir_funcionario(void) {
    char cpf[12];
    char cpf_lido[12];
    char nome[51];
    char cargo[11];
    char salario[9];
    char telefone[12];
    char email[51];

    FILE *arq_funcionario;
    arq_funcionario = fopen("funcionarios.csv", "rt");
    if (arq_funcionario == NULL) {
        printf("nao consigo ler nada");
        printf("pressione <enter>");
        getchar();
        return;
    }
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                        Exibir Dados do Funcionário(a)                       ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡     Informe o CPF do(a) funcionário(a): ");
    scanf("%s", cpf_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

   while (fscanf(arq_funcionario, "%11[^;];%50[^;];%11[^;];%52[^;];%19[^;];%8[^\n]\n",
                  cpf, nome, telefone, email, cargo, salario) == 6) {
        if (strcmp(cpf, cpf_lido) == 0) {
            printf("\nFuncionário encontrado!\n");
            printf("CPF: %s\n", cpf);
            printf("Nome: %s\n", nome);
            printf("Telefone: %s\n", telefone);
            printf("Email: %s\n", email);
            printf("Cargo: %s\n", cargo);
            printf("Salário: %s\n", salario);
            fclose(arq_funcionario);
            getchar();
            return;
        }
    }
    fclose(arq_funcionario);
    printf("\nFuncionário não encontrado.\n");
    getchar();
    continuar_acao();

}


void alterar_funcionario(void) {
    Funcionario funcionario;
    FILE *arq_funcionarios;
        arq_funcionarios = fopen("funcionarios.csv", "rt");
    if (arq_funcionarios == NULL) {
        printf("Não foi possivel ler o arquivo de funcionários");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    FILE *arq_temp;
    arq_temp = fopen("temp_func.csv", "wt");
    if (arq_temp == NULL) {
        printf("Não foi possivel criar arquivo temporário");
        fclose(arq_funcionarios);
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
    printf("♡                       Alterar Dados do Funcionário(a)                       ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡     Informe o CPF do(a) funcionário(a): ");
    scanf("%s", cpf_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fscanf(arq_funcionarios, "%11[^;];%50[^;];%11[^;];%52[^;];%19[^;];%8[^\n]\n",
            funcionario.cpf,funcionario.nome,funcionario.telefone,funcionario.email,funcionario.cargo,
            funcionario.salario)==6) {
        if (strcmp(funcionario.cpf,cpf_lido)!=0){
            fprintf(arq_temp,"%s;",funcionario.cpf);
            fprintf(arq_temp,"%s;",funcionario.nome);
            fprintf(arq_temp,"%s;",funcionario.telefone);
            fprintf(arq_temp,"%s;",funcionario.email);
            fprintf(arq_temp,"%s;",funcionario.cargo);
            fprintf(arq_temp,"%s\n",funcionario.salario);
        } else {
            encontrado = 1;
        }
    }
    
    fclose(arq_funcionarios);

    if (encontrado) {
        Funcionario novo_funcionario;
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                       Novos dados do(a) Funcionários                        ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      CPF: ");
        scanf("%s",novo_funcionario.cpf);
        getchar();
        printf("♡      Nome: ");
        fgets(novo_funcionario.nome,51,stdin);
        tam = strlen(novo_funcionario.nome);
        novo_funcionario.nome[tam-1] = '\0';
        printf("♡      Telefone: ");
        scanf("%s",novo_funcionario.telefone);
        getchar();
        printf("♡      E-mail: ");
        scanf("%s",novo_funcionario.email);
        getchar();
        printf("♡      Cargo: ");
        scanf("%s",novo_funcionario.cargo);
        getchar();
                printf("♡      Salário: ");
        scanf("%s",novo_funcionario.salario);
        getchar();
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

        fprintf(arq_temp,"%s;",novo_funcionario.cpf);
        fprintf(arq_temp,"%s;",novo_funcionario.nome);
        fprintf(arq_temp,"%s;",novo_funcionario.telefone);
        fprintf(arq_temp,"%s;",novo_funcionario.email);
        fprintf(arq_temp,"%s;",novo_funcionario.cargo);
        fprintf(arq_temp,"%s\n",novo_funcionario.salario);
        fclose(arq_temp);

        remove("funcionarios.csv");
        rename("temp.csv","funcionario.csv");
        printf("\t\t Funcionário ALTERADO com sucesso! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;

    } else {
        printf("\t\t Funcionário NAO encontrado! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    }
    continuar_acao();
}

void excluir_funcionario(void) {
    Funcionario funcionario;
    FILE *arq_funcionarios;
    char cpf_lido[12];
    int encontrado = 0;
    
    arq_funcionarios = fopen("funcionarios.csv", "rt");
    if (arq_funcionarios == NULL) {
        printf("Não foi possivel ler o arquivo funcionarios.csv\n");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    
    FILE *arq_temp;
    arq_temp = fopen("temp.csv", "wt"); 
    if (arq_temp == NULL) {
        printf("Não foi possivel criar o arquivo temp.csv\n");
        fclose(arq_funcionarios);
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Excluir Funcionário(a)                           ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o CPF do(a) funcionário(a): ");
    scanf("%s", cpf_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    
    while (fscanf(arq_funcionarios, "%11[^;];%50[^;];%11[^;];%50[^;];%19[^;];%8[^\n]\n",
        funcionario.cpf, funcionario.nome, funcionario.telefone, funcionario.email, 
        funcionario.cargo, funcionario.salario) == 6) {
        
        if (strcmp(funcionario.cpf, cpf_lido) != 0) {
            fprintf(arq_temp, "%s;%s;%s;%s;%s;%s\n",
                funcionario.cpf, funcionario.nome, funcionario.telefone, 
                funcionario.email, funcionario.cargo, funcionario.salario);
        } else {
            encontrado = 1;
            printf("\n♡ Funcionário(a) encontrado(a): %s\n", funcionario.nome);
            printf("♡ Cargo: %s\n", funcionario.cargo);
        }
    }
    
    fclose(arq_funcionarios);
    fclose(arq_temp);
    
    if (encontrado) {
        remove("funcionarios.csv");
        rename("temp.csv", "funcionarios.csv");
        printf("\n♡ Funcionário(a) EXCLUÍDO(A) com sucesso! ♡\n");
    } else {
        remove("temp.csv");
        printf("\n♡ Funcionário(a) NÃO encontrado(a)! ♡\n");
    }
    
    printf("♡ Pressione <ENTER> para continuar...");
    getchar();
}