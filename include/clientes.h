#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct {
    char nome[51];
    char cpf[12];
    char nasc[11];
    char telef[12];
    char email[51];
} Cliente;

void menu_cliente(void);
void cadastrar_cliente(void);
void exibir_cliente(void);
void alterar_cliente(void);
void excluir_cliente(void);

#endif