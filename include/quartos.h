#ifndef QUARTOS_H
#define QUARTOS_H
#define True 1
#define False 0

typedef enum {
    QUARTO_SIMPLES,     // 0
    QUARTO_MASTER,      // 1
    SUITE,              // 2
    SUITE_PRESIDENCIAL, // 3
} tipo_quarto;

extern const char* NOME_TIPOS_QUARTO[];

typedef struct {
    int id;
    tipo_quarto tipo;
    char descricao[51];
    float preco_hora;
    float preco_diaria;
    int status;
} Quarto;

typedef struct quarto_node {
    Quarto quarto;
    struct quarto_node* prox;
} QuartoNode;

void menu_quarto(void);
void cadastrar_quarto(void);
void exibir_quarto(void);
void alterar_quarto(void);
void excluir_quarto(void);

#endif