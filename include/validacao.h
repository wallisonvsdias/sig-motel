#ifndef VALIDACAO_H
#define VALIDACAO_H
#define True 1
#define False 0

void ler_string(char* buffer, int tamanho);

int eh_letra(char c);
int eh_digito(char c);
int eh_bissexto(int ano);

int validar_cpf(char* cpf);
int validar_nome(char* nome);
int validar_data(char* data);
int validar_telefone(char* telefone);
int validar_email(char* email);
int validar_id(char* id_str);
int validar_descricao(char* descricao, int tamanho_max);
int validar_tipo(char* tipo, int tamanho_max);
int validar_preco(char* preco_str);
int validar_quantidade(char* quant_str);

void ler_nome(char* nome);
void ler_cpf(char* cpf);
void ler_data(char* data);
void ler_telefone(char* telefone);
void ler_email(char* email);

#endif