#ifndef QUARTOS_H
#define QUARTOS_H
#define True 1
#define False 0

typedef struct {
    int id;
    char tipo[32];
    char descricao[51];
    float preco_hora;
    float preco_diaria;
    int status;
} Quarto;

void menu_quarto(void);
void cadastrar_quarto(void);
void exibir_quarto(void);
void alterar_quarto(void);
void excluir_quarto(void);

#endif