#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "produtos.h"
#include "id.h"

void menu_produto(void) {
    char op_produto;
    do {
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                               Módulo Produto                                ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      1 - Cadastrar produto                                                  ♡\n");
        printf("♡      2 - Exibir dados do produto                                            ♡\n");
        printf("♡      3 - Alterar dados do produto                                           ♡\n");
        printf("♡      4 - Excluir produto                                                    ♡\n");
        printf("♡      0 - Retornar ao menu principal                                         ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("\nEscolha sua opção: ");
        scanf(" %c", &op_produto);
        getchar();
        
        switch(op_produto) {
            case '1':
                cadastrar_produto();
                break;
            case '2':
                exibir_produto();
                break;
            case '3':
                alterar_produto();
                break;
            case '4':
                excluir_produto();
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
    } while (op_produto != '0');
}


void cadastrar_produto(void) {
    FILE *arq_produtos;
    arq_produtos = fopen("produtos.csv", "at");
    if (arq_produtos == NULL) {
        printf("Não foi possivel ler o arquivo");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    int id = gerador_id("produtos.csv");
    int tam;
    char nome[25];
    char descricao[55];
    float preco;
    int quant;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Cadastrar Produto                                ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Nome: ");
    fgets(nome,25,stdin);
    tam = strlen(nome);
    nome[tam-1] = '\0';
    printf("♡      Descrição: ");
    fgets(descricao,55,stdin);
    tam = strlen(descricao);
    descricao[tam-1] = '\0';
    printf("♡      Preço: ");
    scanf("%f",&preco);
    getchar();
    printf("♡      Quantidade: ");
    scanf("%d",&quant);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡        Produto cadastrado com sucesso!                                        ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    fprintf(arq_produtos,"%d;",id);
    fprintf(arq_produtos,"%s;",nome);
    fprintf(arq_produtos,"%s;",descricao);
    fprintf(arq_produtos,"%f;",preco);
    fprintf(arq_produtos,"%d\n",quant);
    fclose(arq_produtos);

    continuar_acao();
}


void exibir_produto(void){
    FILE *arq_produtos;
    arq_produtos = fopen("produtos.csv", "rt");
    if (arq_produtos == NULL) {
        printf("Não foi possivel ler o arquivo");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    int id;
    int id_lido;
    char nome[25];
    char descricao[55];
    float preco;
    int quant;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                           Exibir Dados do Produto                           ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o ID do produto:                                               ♡\n");
    scanf("%d",&id_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fscanf(arq_produtos, "%d;%24[^;];%54[^;];%f;%d\n",
        &id,nome,descricao,&preco,&quant)==5) {
        if (id == id_lido){
            printf("\t\t Produto encontrado! >>>> \n");
            printf("\t\tNome: %s\n",nome);
            printf("\t\tDescricao: %s\n",descricao);
            printf("\t\tPreco: %f\n",preco);
            printf("\t\tQuantidade: %d\n",quant);
            printf("Pressione <ENTER> para continuar");
            getchar();
            fclose(arq_produtos);
            return;
        }
    }
    printf("\t\t Produto NAO encontrado! >>>> \n");
    printf("Pressione <ENTER> para continuar");
    getchar();
    fclose(arq_produtos);
    return;
    continuar_acao();
}


void alterar_produto(void){
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                           Alterar Dados do Produto                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o ID do produto:                                               ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    continuar_acao();
}


void excluir_produto(void){
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                                Excluir Produto                              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o ID do produto:                                               ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    continuar_acao();
}