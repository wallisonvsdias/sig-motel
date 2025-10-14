#ifndef HOSPEDAGEM_H
#define HOSPEDAGEM_H
#define True 1
#define False 0

typedef struct {
    char cpf[12];
    char id_quarto[30];
    char horas[3];
} Hospedagem;

void menu_hospedagem(void);
void cadastrar_hospedagem(void);
void exibir_hospedagem(void);
void alterar_hospedagem(void);
void excluir_hospedagem(void);

#endif
