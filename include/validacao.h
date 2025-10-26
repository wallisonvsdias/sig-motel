#ifndef VALIDACAO_H
#define VALIDACAO_H
#define True 1
#define False 0

void ler_string(char* buffer, int tamanho);

int eh_letra(char c);
int eh_digito(char c);
int eh_bissexto(int ano);

int validar_cpf(const char* cpf);
int validar_nome(const char* nome);
int validar_data(const char* data);
int validar_telefone(const char* telefone);
int validar_email(const char* email);
int validar_descricao(const char* descricao, int tamanho_max);
int validar_tipo(const char* tipo, int tamanho_max);
int validar_preco(const char* preco_str);
int validar_quantidade(const char* quant_str);

#endif