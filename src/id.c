#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "id.h"

int gerador_id(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        return 1;
    }
    
    int ultimo_id_lido = 0;
    char linha[1024];
    
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        int id_extraido;
        if (sscanf(linha, "%d;", &id_extraido) == 1) {
            ultimo_id_lido = id_extraido;
        }
    }
    
    fclose(arquivo);
    
    return ultimo_id_lido + 1;
}