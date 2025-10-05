#ifndef QUARTOS_H
#define QUARTOS_H

typedef struct {
    int id;
    char tipo[32];
    char descricao[51];
    float preco_hora;
    float preco_diaria;
} Quarto;

void menu_quarto(void);
void cadastrar_quarto(void);
void exibir_quarto(void);
void alterar_quarto(void);
void excluir_quarto(void);

#endif