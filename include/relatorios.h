#ifndef RELATORIOS_H
#define RELATORIOS_H

void menu_relatorio(void);

// Menus de relatórios
void menu_relatorio_clientes(void);
void menu_relatorio_funcionarios(void);
void menu_relatorio_quartos(void);
void menu_relatorio_hospedagens(void);
void menu_relatorio_produtos(void);
void menu_relatorio_vendas(void);

// Relatórios gerais
void lista_geral_clientes(void);
void lista_geral_funcionarios(void);
void lista_geral_quartos(void);
void lista_geral_hospedagens(void);
void lista_geral_produtos(void);
void lista_geral_vendas(void);

// Relatórios específicos
void clientes_por_nome(void);
void quartos_por_tipo(void);
void produtos_por_nome(void);
void funcionarios_por_cargo(void);
void hospedagens_por_cliente(void);
void vendas_por_cliente(void);
void vendas_por_funcionario(void);

// Relatórios ordem alfabética
void lista_geral_clientes_ordenado(void);
void lista_geral_funcionarios_ordenado(void);
void lista_geral_produtos_ordenado(void);
void lista_geral_quartos_ordenado(void);
void lista_geral_hospedagens_ordenado(void);
void lista_geral_vendas_ordenado(void);

// Relatórios desativados
void lista_clientes_desativados(void);
void lista_funcionarios_desativados(void);
void lista_quartos_desativados(void);

#endif