#ifndef VENDAS_H
#define VENDAS_H
#define True 1
#define False 0

typedef struct{
    char cpf[12];
    int id_produto;
    int quant;
    int status;
 } Venda;

void menu_venda(void);
void cadastrar_venda(void);
void exibir_venda(void);
void alterar_venda(void);
void excluir_venda(void);

#endif