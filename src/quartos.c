#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"
#include "quartos.h"
#include "validacao.h"

const char* NOME_TIPOS_QUARTO[] = {
    "Quarto Simples",
    "Quarto Master",
    "Suite",
    "Suite Presidencial"
};

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
    arq_quartos = fopen("data/quartos.DAT", "ab");
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
    printf("♡      ID do quarto\n");
    ler_id(entrada_id);
    quarto->id = atoi(entrada_id);
    printf("\n\n--- Tipos de Quarto Disponíveis ---\n");
    for (int i = 0; i < 4; i++) {
        printf("\t%d - %s\n", i + 1, NOME_TIPOS_QUARTO[i]);
    }
    int tipo = ler_tipo();
    quarto->tipo = tipo-1;
    printf("♡      Descrição: ");
    ler_descricao(quarto->descricao);
    printf("♡      Preço/hora: ");
    ler_preco(entrada_preco);
    quarto->preco_hora = atof(entrada_preco);
    printf("♡      Preço/diária: ");
    ler_preco(entrada_preco);
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

void exibir_quarto(void){
    Quarto* quarto;
    quarto = (Quarto*)malloc(sizeof(*quarto));
    FILE *arq_quartos;
    arq_quartos = fopen("data/quartos.DAT", "rb");
    if (arq_quartos == NULL) {
        printf("Não foi possivel ler o arquivo quartos.DAT");
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
    printf("♡                            Exibir Dados do Quarto                           ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      ID do quarto\n");
    ler_id(entrada_id);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    id = atoi(entrada_id);
    while (fread(quarto,sizeof(Quarto),1,arq_quartos)) {
        if (quarto->id == id && quarto->status){
            printf("\t\t Quarto encontrado! >>>> \n");
            printf("\t\tTipo: %s\n",NOME_TIPOS_QUARTO[quarto->tipo]);
            printf("\t\tDescricao: %s\n",quarto->descricao);
            printf("\t\tPreco/hora: %f\n",quarto->preco_hora);
            printf("\t\tPreco/diaria: %f\n",quarto->preco_diaria);

            fclose(arq_quartos);
            free(quarto);
            continuar_acao();
            return;
        }
    }
    printf("\t\t Quarto NAO encontrado! >>>> \n");
    fclose(arq_quartos);
    free(quarto);
    continuar_acao();
    return;
}


void alterar_quarto(void) {
    Quarto* quarto;
    quarto = (Quarto*)malloc(sizeof(*quarto));
    FILE *arq_quartos;
    arq_quartos = fopen("data/quartos.DAT", "rb");
    if (arq_quartos == NULL) {
        printf("Não foi possivel ler o arquivo quartos.DAT\n");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }

    FILE *arq_temp;
    arq_temp = fopen("data/temp.DAT", "wb");
    if (arq_temp == NULL) {
        printf("Não foi possivel ler o arquivo temp.DAT\n");
        printf("Pressione <ENTER> ...");
        getchar();
        fclose(arq_quartos);
        return;
    }

    int id;
    int encontrado = False;
    char entrada_id[10];

    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                            Alterar Dados do Quarto                          ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      ID do quarto: \n");
    ler_id(entrada_id);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    id = atoi(entrada_id);
    while (fread(quarto, sizeof(Quarto), 1, arq_quartos)) {
        if (quarto->id != id || quarto->status == False){
            fwrite(quarto, sizeof(Quarto), 1, arq_temp);
        } else {
            encontrado = True;
        }
    }
    fclose(arq_quartos);
    free(quarto);

    if (encontrado) {
        Quarto* novo_quarto;
        char entrada_preco[20];
        novo_quarto = (Quarto*)malloc(sizeof(*novo_quarto));

        system("clear||cls");
        mostrar_cabecalho();
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡                              Novos dados do Quarto                          ♡\n");
        printf("♡                                                                             ♡\n");

        printf("♡      ID do quarto\n");
        ler_id(entrada_id);
        novo_quarto->id = atoi(entrada_id);
        printf("\n\n--- Tipos de Quarto Disponíveis ---\n");
        for (int i = 0; i < 4; i++) {
            printf("\t%d - %s\n", i + 1, NOME_TIPOS_QUARTO[i]);
        }
        int tipo = ler_tipo();
        novo_quarto->tipo = tipo - 1;
        printf("♡      Descricao: ");
        ler_descricao(novo_quarto->descricao);
        printf("♡      Preço/hora: ");
        ler_preco(entrada_preco);
        novo_quarto->preco_hora = atof(entrada_preco);
        printf("♡      Preço/diária: ");
        ler_preco(entrada_preco);
        novo_quarto->preco_diaria = atof(entrada_preco);
        printf("♡                                                                             ♡\n");
        printf("♡                                                                             ♡\n");
        printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
        fwrite(novo_quarto, sizeof(Quarto), 1, arq_temp);
        free(novo_quarto);
        fclose(arq_temp);

        remove("data/quartos.DAT");
        rename("data/temp.DAT", "data/quartos.DAT");

        printf("\t\t Quarto ALTERADO com sucesso! >>>> \n");
        continuar_acao();
        return;

    } else {
        fclose(arq_temp);
        remove("data/temp.DAT");

        printf("\t\t Quarto NAO encontrado! >>>> \n");
        continuar_acao();
        return;
    }
}



void excluir_quarto(void) {
    Quarto* quarto;
    quarto = (Quarto*)malloc(sizeof(*quarto));
    FILE *arq_quartos;
    arq_quartos = fopen("data/quartos.DAT", "r+b");
    if (arq_quartos == NULL) {
        printf("Não foi possivel ler o arquivo quartos.DAT\n");
        printf("Pressione <ENTER> ...");
        getchar();
        return;
    }
    int id;
    char entrada_id[10];
    int encontrado = False;
    system("clear||cls");
    mostrar_cabecalho();
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡                                 Excluir Quarto                              ♡\n");
    printf("♡                                                                             ♡\n");
    printf("♡      ID do quarto: \n");
    ler_id(entrada_id);
    printf("♡                                                                             ♡\n");
    printf("♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡\n");
    id = atoi(entrada_id);
    while (fread(quarto,sizeof(Quarto),1,arq_quartos)) {
        if (quarto->id == id){
            if (quarto->status == False) {
                printf("\t\t Quarto NAO encontrado! >>>> \n");
                continuar_acao();
                return;
            }
            
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
        continuar_acao();
        return;
    } else {
        printf("\t\t Quarto NAO encontrado! >>>> \n");
        continuar_acao();
        return;
    }

}
