#ifndef HOSPEDAGEM_H
#define HOSPEDAGEM_H
#define True 1
#define False 0

typedef struct {
    char cpf[12];
    int id_quarto;
    int horas;
    char data[11];
    int status;

} Hospedagem;

typedef struct hospedagens_node {
    Hospedagem hospedagem;
    struct hospedagens_node* prox;
} HospedagemNode;

void menu_hospedagem(void);
void cadastrar_hospedagem(void);
void exibir_hospedagem(void);
void alterar_hospedagem(void);
void excluir_hospedagem(void);

#endif
