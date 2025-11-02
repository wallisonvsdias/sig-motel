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
                getchar();
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
    arq_produtos = fopen("produtos.DAT", "ab");
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
    ler_id(entrada_id);
    produto->id = atof(entrada_id);
    ler_nome(produto->nome);
    ler_descricao(produto->descricao);
    printf("♡      Preço: ");
    ler_preco(entrada_preco);
    produto->preco = atof(entrada_preco);
    ler_quantidade(entrada_quant);
    produto->quant = atof(entrada_quant);
    printf("♡                                                                             ♡\n");
    printf("♡        Produto cadastrado com sucesso!                                        ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    produto->status = True;
    fwrite(produto,sizeof(Produto),1,arq_produtos);
    fclose(arq_produtos);
    free(produto);

    continuar_acao();
}


void exibir_produto(void){
    Produto* produto;
    produto = (Produto*)malloc(sizeof(*produto));
    FILE *arq_produtos;
    arq_produtos = fopen("produtos.DAT", "rb");
    if (arq_produtos == NULL) {
        printf("Não foi possivel ler o arquivo produtos.DAT");
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
    ler_id(id_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(produto,sizeof(Produto),1,arq_produtos)) {
        if (produto->id == id_lido && produto->status==True){
            printf("\t\t Produto encontrado! >>>> \n");
            printf("\t\tNome: %s\n",produto->nome);
            printf("\t\tDescricao: %s\n",produto->descricao);
            printf("\t\tPreco: %f\n",produto->preco);
            printf("\t\tQuantidade: %d\n",produto->quant);
            printf("Pressione <ENTER> para continuar");
            getchar();
            fclose(arq_produtos);
            free(produto);
            return;
        }
    }
    printf("\t\t Produto NAO encontrado! >>>> \n");
    printf("Pressione <ENTER> para continuar");
    getchar();
    fclose(arq_produtos);
    free(produto);
    return;
    continuar_acao();
}


void alterar_produto(void){
    Produto* produto;
    produto = (Produto*)malloc(sizeof(*produto));
    FILE *arq_produtos;
    arq_produtos = fopen("produtos.DAT", "rb");
    if (arq_produtos == NULL) {
        printf("Não foi possivel ler o arquivo produtos.DAT");
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
    int id_lido;
    int encontrado;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                           Alterar Dados do Produto                          ♡\n");
    printf("♡                                                                             ♡\n");
    ler_id(id_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(produto,sizeof(Produto),1,arq_produtos)) {
        if (produto->id != id_lido){
            fwrite(produto,sizeof(Produto),1,arq_temp);
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
        char entrada_id[10];
        char entrada_quant[10];
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                              Editar dados de Produto                        ♡\n");
        printf("♡                                                                             ♡\n");
        do {
        printf("♡      ID do produto: ");
        ler_string(entrada_id, 10);
        if (!validar_id(entrada_id)) {
            printf("♡      ID invalido! Insira apenas digitos\n");
            printf("♡      Pressione <ENTER>");
            getchar();
        }
        } while (!validar_id(entrada_id));
        novo_produto->id = atof(entrada_id);
        do {
            printf("♡      Nome: ");
            ler_string(novo_produto->nome,25);
            if (!validar_nome(novo_produto->nome)) {
                printf("♡      Nome invalido! Deve conter apenas letras e espacos\n");
                printf("♡      Pressione <ENTER>");
                getchar();
            }
        } while (!validar_nome(novo_produto->nome));
        do {
            printf("♡      Descrição: ");
            ler_string(novo_produto->descricao,55);
            if (!validar_descricao(novo_produto->descricao,55)) {
                printf("♡      Descricao invalida! Nao pode ser vazia\n");
                printf("♡      Pressione <ENTER>");
                getchar();
            }
        } while (!validar_descricao(novo_produto->descricao, 55));
        do {
            printf("♡      Preço: ");
            ler_string(entrada_preco,20);
            if (!validar_preco(entrada_preco)) {
                printf("♡      Preco invalido! Deve ser um numero positivo (use '.' para centavos).\n");
                printf("♡      Pressione <ENTER>");
                getchar();
            }
        } while (!validar_preco(entrada_preco));
        novo_produto->preco = atof(entrada_preco);
        do {
            printf("♡      Quantidade: ");
            ler_string(entrada_quant,10);
            if (!validar_preco(entrada_quant)) {
                printf("♡      Quantidade invalida! Insira apenas digitos.\n");
                printf("♡      Pressione <ENTER>");
                getchar();
            }
        } while (!validar_preco(entrada_quant));
        novo_produto->quant = atof(entrada_quant);
        printf("♡                                                                             ♡\n");
        printf("♡        Produto cadastrado com sucesso!                                        ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

        fwrite(novo_produto,sizeof(Produto),1,arq_temp);

        free(novo_produto);
        fclose(arq_temp);
        remove("produtos.DAT");
        rename("temp.DAT", "produtos.DAT");
        printf("\t\t Produto ALTERADO com sucesso! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    } else {
        fclose(arq_temp);
        remove("temp.DAT");
        printf("\t\t Produto NAO encontrado! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    }

    continuar_acao();
}


void excluir_produto(void){
    Produto* produto;
    produto = (Produto*)malloc(sizeof(*produto));
    FILE *arq_produtos;
    arq_produtos = fopen("produtos.DAT", "r+b");
    if (arq_produtos == NULL) {
        printf("Não foi possivel ler o arquivo produtos.DAT\n");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    int id_lido;
    int encontrado = False;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                                Excluir Produto                              ♡\n");
    printf("♡                                                                             ♡\n");
    ler_id(id_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(produto,sizeof(Produto),1,arq_produtos)) {
        if (produto->id == id_lido){
            produto->status = False;
            fseek(arq_produtos, -(long)sizeof(Produto),SEEK_CUR);
            fwrite(produto, sizeof(Produto),1,arq_produtos);
            encontrado = True;
        } 
    }

    fclose(arq_produtos);
    free(produto);

    if (encontrado) {
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