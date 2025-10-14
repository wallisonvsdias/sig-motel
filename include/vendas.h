#ifndef VENDAS_H
#define VENDAS_H
#define True 1
#define False 0

typedef struct{
    char cpf[12];
    char id_produto[4];
    char quant[4];
 } Venda;

void menu_venda(void);
void cadastrar_venda(void);
void exibir_venda(void);
void alterar_venda(void);
void excluir_venda(void);

#endif