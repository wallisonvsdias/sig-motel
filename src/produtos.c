#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "produtos.h"
#include "validacao.h"

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
                printf("\n");
                printf("Por favor, digite uma opção válida");
                getchar();
                break;
        }
    } while (op_produto != '0');
}


void cadastrar_produto(void) {
    Produto* produto;
    produto = (Produto*)malloc(sizeof(*produto));
    FILE *arq_produtos;
    arq_produtos = fopen("data/produtos.DAT", "ab");
    if (arq_produtos == NULL) {
        printf("Não foi possivel ler o arquivo produtos.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    char entrada_preco[20];
    char entrada_id[10];
    char entrada_quant[10];
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Cadastrar Produto                                ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      ID do produto\n");
    ler_id(entrada_id);
    produto->id = atoi(entrada_id);
    ler_nome(produto->nome);
    ler_descricao(produto->descricao);
    printf("♡      Preço: ");
    ler_preco(entrada_preco);
    produto->preco = atof(entrada_preco);
    ler_quantidade(entrada_quant);
    produto->quant = atoi(entrada_quant);
    printf("♡                                                                             ♡\n");
    printf("♡        Produto cadastrado com sucesso!                                      ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    fwrite(produto,sizeof(Produto),1,arq_produtos);
    fclose(arq_produtos);
    free(produto);

    continuar_acao();
}


void exibir_produto(void){
    Produto* produto;
    produto = (Produto*)malloc(sizeof(*produto));
    FILE *arq_produtos;
    arq_produtos = fopen("data/produtos.DAT", "rb");
    if (arq_produtos == NULL) {
        printf("Não foi possivel ler o arquivo produtos.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    int id;
    char entrada_id[10];
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                           Exibir Dados do Produto                           ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      ID do produto: \n");
    ler_id(entrada_id);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    id = atoi(entrada_id);
    while (fread(produto,sizeof(Produto),1,arq_produtos)) {
        if (produto->id == id){
            printf("\t\t Produto encontrado! >>>> \n");
            printf("\t\tNome: %s\n",produto->nome);
            printf("\t\tDescricao: %s\n",produto->descricao);
            printf("\t\tPreco: %f\n",produto->preco);
            printf("\t\tQuantidade: %d\n",produto->quant);
            fclose(arq_produtos);
            free(produto);
            continuar_acao();
            return;
        }
    }
    printf("\t\t Produto NAO encontrado! >>>> \n");
    fclose(arq_produtos);
    free(produto);
    continuar_acao();
    return;
}


void alterar_produto(void){
    Produto* produto;
    produto = (Produto*)malloc(sizeof(*produto));
    FILE *arq_produtos;
    arq_produtos = fopen("data/produtos.DAT", "rb");
    if (arq_produtos == NULL) {
        printf("Não foi possivel ler o arquivo produtos.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        free(produto);
        return;
    }
    FILE *arq_temp;
    arq_temp = fopen("data/temp.DAT", "ab");
    if (arq_temp == NULL) {
        printf("Não foi possivel ler o arquivo temp.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        fclose(arq_produtos);
        free(produto);
        return;
    }
    
    int id;
    char entrada_id[10];
    int encontrado = False;
    
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                           Alterar Dados do Produto                          ♡\n");
    printf("♡                                                                             ♡\n");
    ler_id(entrada_id);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    id = atoi(entrada_id);
    while (fread(produto, sizeof(Produto), 1, arq_produtos)) {
        if (produto->id != id) {
            fwrite(produto, sizeof(Produto), 1, arq_temp);
        } else {
            encontrado = True;
        }
    }
    fclose(arq_produtos);
    free(produto);

    if (encontrado) {
        Produto* novo_produto;
        novo_produto = (Produto*)malloc(sizeof(*novo_produto));
        char entrada_preco[20];
        char entrada_quant[10];
        
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                            Novos dados de Produto                           ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡      ID do produto\n");
        ler_id(entrada_id);
        novo_produto->id = atoi(entrada_id);
        ler_nome(novo_produto->nome);
        ler_descricao(novo_produto->descricao);
        printf("♡      Preço: ");
        ler_preco(entrada_preco);
        novo_produto->preco = atof(entrada_preco);
        ler_quantidade(entrada_quant);
        novo_produto->quant = atoi(entrada_quant);
        printf("♡                                                                             ♡\n");
        printf("♡        Produto cadastrado com sucesso!                                      ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

        fwrite(novo_produto, sizeof(Produto), 1, arq_temp);

        free(novo_produto);
        fclose(arq_temp);
        remove("data/produtos.DAT");
        rename("data/temp.DAT", "data/produtos.DAT");
        printf("\t\t Produto ALTERADO com sucesso! >>>> \n");
        continuar_acao();
        return;
    } else {
        fclose(arq_temp);
        remove("data/temp.DAT");
        printf("\t\t Produto NAO encontrado! >>>> \n");
        continuar_acao();
        return;
    }
}


void excluir_produto(void){
    Produto* produto;
    produto = (Produto*)malloc(sizeof(*produto));
    FILE *arq_produtos;
    arq_produtos = fopen("data/produtos.DAT", "rb");
    if (arq_produtos == NULL) {
        printf("Não foi possivel ler o arquivo produtos.DAT\n");
        printf("Pressione <ENTER> ...");
        getchar();
        free(produto);
        return;
    }
    FILE *arq_temp;
    arq_temp = fopen("data/temp.DAT", "ab");
    if (arq_temp == NULL) {
        printf("Não foi possivel criar arquivo temporário\n");
        printf("Pressione <ENTER> ...");
        getchar();
        fclose(arq_produtos);
        free(produto);
        return;
    }
    int id;
    char entrada_id[10];
    int encontrado = False;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                                Excluir Produto                              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      ID do produto: ");
    ler_id(entrada_id);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    
    id = atoi(entrada_id);
    while (fread(produto, sizeof(Produto), 1, arq_produtos)) {
        if (produto->id != id) {
            fwrite(produto, sizeof(Produto), 1, arq_temp);
        } else {
            encontrado = True;
        }
    }

    fclose(arq_produtos);
    fclose(arq_temp);
    free(produto);

    if (encontrado) {
        remove("data/produtos.DAT");
        rename("data/temp.DAT", "data/produtos.DAT");
        printf("\t\t Produto EXCLUIDO com sucesso! >>>> \n");
    } else {
        remove("data/temp.DAT");
        printf("\t\t Produto NAO encontrado! >>>> \n");
    }
    
    continuar_acao();
}