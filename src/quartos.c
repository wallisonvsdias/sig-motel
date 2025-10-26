#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"
#include "quartos.h"
#include "validacao.h"

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
    Quarto* quarto;
    quarto = (Quarto*)malloc(sizeof(*quarto));
    FILE *arq_quartos;
    arq_quartos = fopen("quartos.DAT", "ab");
    if (arq_quartos == NULL) {
        printf("Não foi possivel ler o arquivo quartos.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    char entrada_preco[20];
    char entrada_id[10];
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                               Cadastrar Quarto                              ♡\n");
    printf("♡                                                                             ♡\n");
    do {
        printf("♡      ID do quarto: ");
        ler_string(entrada_id, 10);
        if (!validar_id(entrada_id)) {
            printf("♡      ID invalido! Insira apenas digitos\n");
            printf("♡      Pressione <ENTER>");
            getchar();
        }
    } while (!validar_id(entrada_id));
    quarto->id = atof(entrada_id);
    do {
        printf("♡      Tipo: ");
        ler_string(quarto->tipo, 32);
        if (!validar_tipo(quarto->tipo, 32)) {
            printf("♡      Tipo invalido! Nao pode ser vazio\n");
            printf("♡      Pressione <ENTER>");
            getchar();
        }
    } while (!validar_tipo(quarto->tipo,32));
    do {
        printf("♡      Descrição: ");
        ler_string(quarto->descricao,51);
        if (!validar_descricao(quarto->descricao,51)) {
            printf("♡      Descricao invalida! Nao pode ser vazia\n");
            printf("♡      Pressione <ENTER>");
            getchar();
        }
    } while (!validar_descricao(quarto->descricao, 51));
    do {
        printf("♡      Preço/hora: ");
        ler_string(entrada_preco,20);
        if (!validar_preco(entrada_preco)) {
            printf("♡      Preco invalido! Deve ser um numero positivo (use '.' para centavos).\n");
        }
    } while (!validar_preco(entrada_preco));
    quarto->preco_hora = atof(entrada_preco);
    do {
        printf("♡      Preço/diária: ");
        ler_string(entrada_preco,20);
        if (!validar_preco(entrada_preco)) {
            printf("♡      Preco invalido! Deve ser um numero positivo (use '.' para centavos).\n");
        }
    } while (!validar_preco(entrada_preco));
    quarto->preco_diaria = atof(entrada_preco);
    printf("♡                                                                             ♡\n");
    printf("♡        Quarto cadastrado com sucesso!                                       ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

    quarto->status = True;
    fwrite(quarto,sizeof(Quarto),1,arq_quartos);
    fclose(arq_quartos);
    free(quarto);

    continuar_acao();

}

// Exibir também o status
void exibir_quarto(void){
    Quarto* quarto;
    quarto = (Quarto*)malloc(sizeof(*quarto));
    FILE *arq_quartos;
    arq_quartos = fopen("quartos.DAT", "rb");
    if (arq_quartos == NULL) {
        printf("Não foi possivel ler o arquivo quartos.DAT");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    int id_lido;
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
    while (fread(quarto,sizeof(Quarto),1,arq_quartos)) {
        if (quarto->id == id_lido && quarto->status==True){
            printf("\t\t Quarto encontrado! >>>> \n");
            printf("\t\tTipo: %s\n",quarto->tipo);
            printf("\t\tDescricao: %s\n",quarto->descricao);
            printf("\t\tPreco/hora: %f\n",quarto->preco_hora);
            printf("\t\tPreco/diaria: %f\n",quarto->preco_diaria);
            printf("Pressione <ENTER> para continuar");
            getchar();
            fclose(arq_quartos);
            free(quarto);
            return;
        }
    }
    printf("\t\t Quarto NAO encontrado! >>>> \n");
    printf("Pressione <ENTER> para continuar");
    getchar();
    fclose(arq_quartos);
    free(quarto);
    return;
    continuar_acao();
}


void alterar_quarto(void) {
    Quarto* quarto;
    quarto = (Quarto*)malloc(sizeof(*quarto));
    FILE *arq_quartos;
    arq_quartos = fopen("quartos.DAT", "rb");
    if (arq_quartos == NULL) {
        printf("Não foi possivel ler o arquivo quartos.DAT\n");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    FILE *arq_temp;
    arq_temp = fopen("temp.DAT", "ab");
    if (arq_temp == NULL) {
        printf("Não foi possivel ler o arquivo temp.DAT\n");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    int id_lido;
    int encontrado;
    char entrada_preco[20];
    char entrada_id[10];
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Alterar Dados do Quarto                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡     Informe o ID do quarto: ");
    scanf("%d",&id_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(quarto,sizeof(Quarto),1,arq_quartos)) {
        if (quarto->id != id_lido){
            fwrite(quarto,sizeof(Quarto),1,arq_temp);
        } else {
            encontrado = True;
        }
    }

    fclose(arq_quartos);
    free(quarto);

    if (encontrado) {
        Quarto* novo_quarto;
        novo_quarto = (Quarto*)malloc(sizeof(*novo_quarto));
        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                              Editar dados de Quarto                         ♡\n");
        printf("♡                                                                             ♡\n");
        do {
            printf("♡      ID do quarto: ");
            ler_string(entrada_id, 10);
            if (!validar_id(entrada_id)) {
                printf("♡      ID invalido! Insira apenas digitos\n");
                printf("♡      Pressione <ENTER>");
                getchar();
            }
        } while (!validar_id(entrada_id));
        novo_quarto->id = atof(entrada_id);
        do {
            printf("♡      Tipo: ");
            ler_string(novo_quarto->tipo, 32);
            if (!validar_tipo(novo_quarto->tipo, 32)) {
                printf("♡      Tipo invalido! Nao pode ser vazio\n");
                printf("♡      Pressione <ENTER>");
                getchar();
            }
        } while (!validar_tipo(novo_quarto->tipo,32));
        do {
            printf("♡      Descrição: ");
            ler_string(novo_quarto->descricao,51);
            if (!validar_descricao(novo_quarto->descricao,51)) {
                printf("♡      Descricao invalida! Nao pode ser vazia\n");
                printf("♡      Pressione <ENTER>");
                getchar();
            }
        } while (!validar_descricao(novo_quarto->descricao, 51));
        do {
            printf("♡      Preço/hora: ");
            ler_string(entrada_preco,20);
            if (!validar_preco(entrada_preco)) {
                printf("♡      Preco invalido! Deve ser um numero positivo (use '.' para centavos).\n");
            }
        } while (!validar_preco(entrada_preco));
        novo_quarto->preco_hora = atof(entrada_preco);
        do {
            printf("♡      Preço/diária: ");
            ler_string(entrada_preco,20);
            if (!validar_preco(entrada_preco)) {
                printf("♡      Preco invalido! Deve ser um numero positivo (use '.' para centavos).\n");
            }
        } while (!validar_preco(entrada_preco));
        novo_quarto->preco_diaria = atof(entrada_preco);
        printf("♡                                                                             ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");

        fwrite(novo_quarto,sizeof(Quarto),1,arq_temp);

        free(novo_quarto);
        fclose(arq_temp);
        remove("quartos.DAT");
        rename("temp.DAT","quartos.DAT");
        printf("\t\t Quarto ALTERADO com sucesso! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    } else {
        fclose(arq_temp);
        remove("temp.DAT");
        printf("\t\t Quarto NAO encontrado! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    }

    continuar_acao();
}


void excluir_quarto(void) {
    Quarto* quarto;
    quarto = (Quarto*)malloc(sizeof(*quarto));
    FILE *arq_quartos;
    arq_quartos = fopen("quartos.DAT", "r+b");
    if (arq_quartos == NULL) {
        printf("Não foi possivel ler o arquivo quartos.DAT\n");
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
    printf("♡                                 Excluir Quarto                              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡     Informe o ID do quarto: ");
    scanf("%d",&id_lido);
    getchar();
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    while (fread(quarto,sizeof(Quarto),1,arq_quartos)) {
        if (quarto->id == id_lido){
            quarto->status = False;
            fseek(arq_quartos,-(long)sizeof(Quarto),SEEK_CUR);
            fwrite(quarto, sizeof(Quarto), 1, arq_quartos);
            encontrado = True;
        }
    }

    fclose(arq_quartos);
    free(quarto);

    if (encontrado) {
        printf("\t\t Quarto EXCLUIDO com sucesso! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    } else {
        printf("\t\t Quarto NAO encontrado! >>>> \n");
        printf("Pressione <ENTER> para continuar");
        getchar();
        return;
    }

    continuar_acao();

}
