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
    Funcionario* funcionario;
    funcionario = (Funcionario*) malloc(sizeof(*funcionario));
    FILE *arq_funcionario;
    arq_funcionario = fopen("funcionarios.DAT", "ab");
    if (arq_funcionario == NULL) {
        printf("Não foi possível abrir o arquivo funcionarios.dat\n");
        printf("Pressione <enter>\n");
        getchar();
        free(funcionario);
        return;
    }
    int tam;

    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                           Cadastrar Funcionário(a)                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      CPF: ");
    scanf("%s", funcionario->cpf);
    getchar();
    printf("♡      Nome: ");
    fgets(funcionario->nome, 51, stdin);
    tam = strlen(funcionario->nome);
    funcionario->nome[tam-1] = '\0';
    printf("♡      Telefone: ");
    scanf("%s", funcionario->telefone);
    getchar();
    printf("♡      E-mail: ");
    scanf("%s", funcionario->email);
    printf("♡      Cargo: ");
    scanf("%s", funcionario->cargo);
    getchar();
    printf("♡      Salário: ");
    scanf("%s", funcionario->salario);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    getchar();

    funcionario->status = True;
    fwrite(funcionario, sizeof(Funcionario), 1, arq_funcionario);
    fclose(arq_funcionario);
    free(funcionario);

    continuar_acao();
}


void exibir_funcionario(void) {
    Funcionario* funcionario;
    funcionario = (Funcionario*) malloc(sizeof(*funcionario));
    FILE *arq_funcionario;
    arq_funcionario = fopen("funcionarios.DAT", "ab");
    if (arq_funcionario == NULL) {
        printf("Não foi possível abrir o arquivo funcionarios.dat\n");
        printf("Pressione <enter>\n");
        getchar();
        free(funcionario);
        return;
    }
    char cpf_lido[12];

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
                  funcionario->cpf, funcionario->nome, funcionario->telefone, 
                  funcionario->email, funcionario->cargo, funcionario->salario) == 6) {
        if (strcmp(funcionario->cpf, cpf_lido) == 0) {
            printf("\nFuncionário encontrado!\n");
            printf("CPF: %s\n", funcionario->cpf);
            printf("Nome: %s\n", funcionario->nome);
            printf("Telefone: %s\n", funcionario->telefone);
            printf("Email: %s\n", funcionario->email);
            printf("Cargo: %s\n", funcionario->cargo);
            printf("Salário: %s\n", funcionario->salario);
            fclose(arq_funcionario);
            getchar();
            return;
        }
    }
    printf("\nFuncionário não encontrado.\n");
    getchar();
    fclose(arq_funcionario);
    free(funcionario);
    return;
    continuar_acao();

}


void alterar_funcionario(void) {
Funcionario* funcionario = (Funcionario*) malloc(sizeof(*funcionario));
    if (funcionario == NULL) {
        printf("Erro ao alocar memória.\n");
        getchar();
        return;
    }

    FILE *arq_funcionarios = fopen("funcionarios.DAT", "rb");
    if (arq_funcionarios == NULL) {
        printf("Não foi possível abrir o arquivo funcionarios.DAT\n");
        printf("Pressione <ENTER> ...");
        getchar();
        free(funcionario);
        return;
    }

    FILE *arq_temp = fopen("temp.DAT", "wb");
    if (arq_temp == NULL) {
        printf("Não foi possível criar o arquivo temporário temp.DAT\n");
        printf("Pressione <ENTER> ...");
        getchar();
        fclose(arq_funcionarios);
        free(funcionario);
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
    while (fread(funcionario, sizeof(Funcionario), 1, arq_funcionarios)) {
        if (strcmp(funcionario->cpf, cpf_lido) != 0) {
            fwrite(funcionario, sizeof(Funcionario), 1, arq_temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arq_funcionarios);
    free(funcionario);

    if (encontrado) {
        Funcionario* novo_funcionario = (Funcionario*) malloc(sizeof(*novo_funcionario));
        if (novo_funcionario == NULL) {
            printf("Erro ao alocar memória.\n");
            fclose(arq_temp);
            return;
        }

        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                       Novos dados do(a) Funcionários                        ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      CPF: ");
        scanf("%s",novo_funcionario->cpf);
        getchar();
        printf("♡      Nome: ");
        fgets(novo_funcionario->nome,51,stdin);
        tam = strlen(novo_funcionario->nome);
        novo_funcionario->nome[tam-1] = '\0';
        printf("♡      Telefone: ");
        scanf("%s",novo_funcionario->telefone);
        getchar();
        printf("♡      E-mail: ");
        scanf("%s",novo_funcionario->email);
        getchar();
        printf("♡      Cargo: ");
        scanf("%s",novo_funcionario->cargo);
        getchar();
                printf("♡      Salário: ");
        scanf("%s",novo_funcionario->salario);
        getchar();
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

        novo_funcionario->status = 1; 
        fwrite(novo_funcionario, sizeof(Funcionario), 1, arq_temp);
        fclose(arq_temp);
        free(novo_funcionario);

        remove("funcionarios.DAT");
        rename("temp.DAT", "funcionarios.DAT");

        printf("\t\t Funcionário ALTERADO com sucesso! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;

    } else {
        fclose(arq_temp);
        remove("temp.DAT");
        printf("\t\t Funcionário NAO encontrado! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
    }
    continuar_acao();
}

void excluir_funcionario(void) {
    Funcionario* funcionario;
    funcionario = (Funcionario*)malloc(sizeof(*funcionario));
    FILE *arq_funcionarios;
    arq_funcionarios = fopen("funcionarios.DAT", "r+b");
    if (arq_funcionarios == NULL) {
        printf("Não foi possivel ler o arquivo funcionarios.csv\n");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    char cpf_lido[12];
    int encontrado = 0;
    
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
    
    while (fread(funcionario, sizeof(Funcionario), 1, arq_funcionarios) == 1 && !encontrado) {
        if (strcmp(funcionario->cpf, cpf_lido) == 0) {
            funcionario->status = 0;  // marca como inativo
            fseek(arq_funcionarios, -(long)sizeof(Funcionario), SEEK_CUR);
            fwrite(funcionario, sizeof(Funcionario), 1, arq_funcionarios);
            encontrado = 1;
        }
    }

    fclose(arq_funcionarios);
    free(funcionario);

    if (encontrado) {
        printf("\t\t Funcionário(a) EXCLUÍDO(A) com sucesso! >>>> \n");
    } else {
        printf("\t\t Funcionário(a) NÃO encontrado(a)! >>>> \n");
    }
    
    printf("♡ Pressione <ENTER> para continuar...");
    getchar();
}