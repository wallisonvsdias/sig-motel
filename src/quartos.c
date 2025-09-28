#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"
#include "quartos.h"

int gerador_id(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        printf("Pressione <ENTER> ...");
        getchar();
        return -1;
    }
    
    int id = 0;
    char linha[1024];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        id++;
    }
    
    fclose(arquivo);
    return id+1;
}

void menu_quarto(void) {
    char op_quarto;
    do {
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                                Módulo Quarto                                ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      1 - Cadastrar quarto                                                   ♡\n");
        printf("♡      2 - Exibir dados do quarto                                             ♡\n");
        printf("♡      3 - Alterar dados do quarto                                            ♡\n");
        printf("♡      4 - Excluir quarto                                                     ♡\n");
        printf("♡      0 - Retornar ao menu principal                                         ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("\nEscolha sua opção: ");
        scanf(" %c", &op_quarto);
        getchar();
        switch(op_quarto) {
            case '1':
                cadastrar_quarto();
                break;
            case '2':
                exibir_quarto();
                break;
            case '3':
                alterar_quarto();
                break;
            case '4':
                excluir_quarto();
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
    } while (op_quarto != '0');
}


void cadastrar_quarto(void) {
    FILE *arq_quartos;
    arq_quartos = fopen("quartos.csv", "at");
    if (arq_quartos == NULL) {
        printf("Não foi possivel ler o arquivo");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    int id = gerador_id("quartos.csv");
    char tipo[32];
    char descricao[51];
    float preco_hora;
    float preco_diaria;
    int tam;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                               Cadastrar Quarto                              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Tipo: ");
    fgets(tipo,51,stdin);
    tam = strlen(tipo);
    tipo[tam-1] = '\0';
    printf("♡      Descrição: ");
    fgets(descricao,51,stdin);
    tam = strlen(descricao);
    descricao[tam-1] = '\0';
    printf("♡      Preço/hora: ");
    scanf("%f",&preco_hora);
    getchar();
    printf("♡      Preço/diária: ");
    scanf("%f",&preco_diaria);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡        Quarto cadastrado com sucesso!                                       ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    fprintf(arq_quartos,"%d;",id);
    fprintf(arq_quartos,"%s;",tipo);
    fprintf(arq_quartos,"%s;",descricao);
    fprintf(arq_quartos,"%f;",preco_hora);
    fprintf(arq_quartos,"%f\n",preco_diaria);
    fclose(arq_quartos);

    continuar_acao();

}

// Exibir também o status
void exibir_quarto(void){
    FILE *arq_quartos;
    arq_quartos = fopen("quartos.csv", "rt");
    if (arq_quartos == NULL) {
        printf("Não foi possivel ler o arquivo");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    int id;
    int id_lido;
    char tipo[32];
    char descricao[51];
    float preco_hora;
    float preco_diaria;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Exibir Dados do Quarto                           ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o ID do quarto: ");
    scanf("%d",&id_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (!feof(arq_quartos)) {
        fscanf(arq_quartos, "%d[^;]", &id);
        fgetc(arq_quartos);
        fscanf(arq_quartos, "%[^;]", tipo);
        fgetc(arq_quartos);
        fscanf(arq_quartos, "%[^;]", descricao);
        fgetc(arq_quartos);
        fscanf(arq_quartos, "%f[^;]", &preco_hora);
        fgetc(arq_quartos);
        fscanf(arq_quartos, "%f[^\n]", &preco_diaria);
        fgetc(arq_quartos);
        if (id == id_lido){
            printf("\t\t Quarto encontrado! >>>> \n");
            printf("\t\tTipo: %s\n",tipo);
            printf("\t\tDescricao: %s\n",descricao);
            printf("\t\tPreco/hora: %f\n",preco_hora);
            printf("\t\tPreco/diaria: %f\n",preco_diaria);
            printf("Pressione <ENTER> para continuar");
            getchar();
            fclose(arq_quartos);
            return;
        }
    }
    printf("\t\t Quarto NAO encontrado! >>>> \n");
    printf("Pressione <ENTER> para continuar");
    getchar();
    fclose(arq_quartos);
    return;
    continuar_acao();
}


void alterar_quarto(void) {
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Alterar Dados do Quarto                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡     Informe o ID do quarto:                                                 ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    continuar_acao();
}


void excluir_quarto(void) {
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                                 Excluir Quarto                              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡     Informe o ID do quarto:                                                 ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    continuar_acao();
}