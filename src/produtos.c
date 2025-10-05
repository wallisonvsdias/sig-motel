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
    Produto produto;
    FILE *arq_produtos;
    arq_produtos = fopen("produtos.csv", "at");
    if (arq_produtos == NULL) {
        printf("Não foi possivel ler o arquivo");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    produto.id = gerador_id("produtos.csv");
    int tam;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Cadastrar Produto                                ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Nome: ");
    fgets(produto.nome,25,stdin);
    tam = strlen(produto.nome);
    produto.nome[tam-1] = '\0';
    printf("♡      Descrição: ");
    fgets(produto.descricao,55,stdin);
    tam = strlen(produto.descricao);
    produto.descricao[tam-1] = '\0';
    printf("♡      Preço: ");
    scanf("%f",&produto.preco);
    getchar();
    printf("♡      Quantidade: ");
    scanf("%d",&produto.quant);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡        Produto cadastrado com sucesso!                                        ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    fprintf(arq_produtos,"%d;",produto.id);
    fprintf(arq_produtos,"%s;",produto.nome);
    fprintf(arq_produtos,"%s;",produto.descricao);
    fprintf(arq_produtos,"%f;",produto.preco);
    fprintf(arq_produtos,"%d\n",produto.quant);
    fclose(arq_produtos);

    continuar_acao();
}


void exibir_produto(void){
    Produto produto;
    FILE *arq_produtos;
    arq_produtos = fopen("produtos.csv", "rt");
    if (arq_produtos == NULL) {
        printf("Não foi possivel ler o arquivo");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    int id_lido;
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
        &produto.id,produto.nome,produto.descricao,&produto.preco,&produto.quant)==5) {
        if (produto.id == id_lido){
            printf("\t\t Produto encontrado! >>>> \n");
            printf("\t\tNome: %s\n",produto.nome);
            printf("\t\tDescricao: %s\n",produto.descricao);
            printf("\t\tPreco: %f\n",produto.preco);
            printf("\t\tQuantidade: %d\n",produto.quant);
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
    Produto produto;
    FILE *arq_produtos;
    arq_produtos = fopen("produtos.csv", "rt");
    if (arq_produtos == NULL) {
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
    int id_lido;
    int tam;
    int encontrado;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                           Alterar Dados do Produto                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o ID do produto: ");
    scanf("%d",&id_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fscanf(arq_produtos, "%d;%24[^;];%54[^;];%f;%d\n",
        &produto.id,produto.nome,produto.descricao,&produto.preco,&produto.quant)==5) {
        if (produto.id != id_lido){
            fprintf(arq_temp,"%d;",produto.id);
            fprintf(arq_temp,"%s;",produto.nome);
            fprintf(arq_temp,"%s;",produto.descricao);
            fprintf(arq_temp,"%f;",produto.preco);
            fprintf(arq_temp,"%d\n",produto.quant);
        } else {
            encontrado = 1;
            Produto novo_produto;
            system("clear||cls");
            mostrar_cabecalho();
            printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
            printf("♡                                                                             ♡\n");
            printf("♡                         Editar dados de Produto                             ♡\n");
            printf("♡                                                                             ♡\n");
            printf("♡      Nome: ");
            fgets(novo_produto.nome,25,stdin);
            tam = strlen(novo_produto.nome);
            novo_produto.nome[tam-1] = '\0';
            printf("♡      Descrição: ");
            fgets(novo_produto.descricao,55,stdin);
            tam = strlen(novo_produto.descricao);
            novo_produto.descricao[tam-1] = '\0';
            printf("♡      Preço: ");
            scanf("%f",&novo_produto.preco);
            getchar();
            printf("♡      Quantidade: ");
            scanf("%d",&novo_produto.quant);
            getchar();
            printf("♡                                                                             ♡\n");
            printf("♡                                                                             ♡\n");
            printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

            fprintf(arq_temp,"%d;",produto.id);
            fprintf(arq_temp,"%s;",novo_produto.nome);
            fprintf(arq_temp,"%s;",novo_produto.descricao);
            fprintf(arq_temp,"%f;",novo_produto.preco);
            fprintf(arq_temp,"%d\n",novo_produto.quant);
        }
    }

    fclose(arq_temp);
    fclose(arq_produtos);

    if (encontrado) {
        remove("produtos.csv");
        rename("temp.csv","produtos.csv");
        printf("\t\t Produto ALTERADO com sucesso! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    } else {
        printf("\t\t Produto NAO encontrado! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
    return;
    }
    
    continuar_acao();
}


void excluir_produto(void){
    Produto produto;
    FILE *arq_produtos;
    arq_produtos = fopen("produtos.csv", "rt");
    if (arq_produtos == NULL) {
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
    int id_lido;
    int encontrado;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                                Excluir Produto                              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      Informe o ID do produto: ");
    scanf("%d",&id_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fscanf(arq_produtos, "%d;%24[^;];%54[^;];%f;%d\n",
        &produto.id,produto.nome,produto.descricao,&produto.preco,&produto.quant)==5) {
        if (produto.id != id_lido){
            fprintf(arq_temp,"%d;",produto.id);
            fprintf(arq_temp,"%s;",produto.nome);
            fprintf(arq_temp,"%s;",produto.descricao);
            fprintf(arq_temp,"%f;",produto.preco);
            fprintf(arq_temp,"%d\n",produto.quant);
        } else {
            encontrado = 1;
        }
    }

    fclose(arq_produtos);
    fclose(arq_temp);

    if (encontrado) {
        remove("produtos.csv");
        rename("temp.csv","produtos.csv");
        printf("\t\t Produto EXCLUIDO com sucesso! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    } else {
        printf("\t\t Produto NAO encontrado! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    }

    continuar_acao();
}