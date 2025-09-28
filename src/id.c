#include <stdio.h>
#include <stdlib.h>
#include "id.h"

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