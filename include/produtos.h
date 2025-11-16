#ifndef PRODUTOS_H
#define PRODUTOS_H
#define True 1
#define False 0

typedef struct {
    int id;
    char nome[51];
    char descricao[55];
    float preco;
    int quant;
    int status;
} Produto;

void menu_produto(void);
void cadastrar_produto(void);
void exibir_produto(void);
void alterar_produto(void);
void excluir_produto(void);

#endif