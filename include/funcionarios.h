#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H
#define True 1
#define False 0

typedef struct {
    char nome[51];
    char cpf[12];
    char telefone[12];
    char email[53];
    char cargo[20];
    float salario;
    int status;
} Funcionario;

void menu_funcionario(void);
void cadastrar_funcionario(void);
void exibir_funcionario(void);
void alterar_funcionario(void);
void excluir_funcionario(void);

#endif
