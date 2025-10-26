#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacao.h"

void ler_string(char* buffer, int tamanho) {
    fgets(buffer, tamanho, stdin);
    
    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    } else {
        // se nao tinha '\n', o buffer de entrada pode ter lixo
        // limpa o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

// retorna 1 se for uma letra, 0 caso contrario
int eh_letra(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return True;
    } else {
        return False;
    }
}

// retorna 1 se for um numero, 0 caso contrario
int eh_digito(char c) {
    if (c >= '0' && c <= '9') {
        return True;
    } else {
        return False;
    }
}

// retorna 1 se o ano for bissexto, 0 caso contrario
int eh_bissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return True;
    } else {
        return False;
    }
}


// valida o nome.
// deve conter apenas letrase  espacos 
// nao pode estar vazio
// falta verificar acentos
int validar_nome(const char* nome) {
    int i = 0;

    // verifica se está vazio
    if (strlen(nome) == 0) {
        return False;
    }

    while (nome[i] != '\0') {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return False; 
        }
        i++;
    }
    return True;
}

// valida o cpf
// deve conter exatamente 11 numeros
// nao valida os digitos verificadores, so o formato
// falta verificacao completa de cpf
int validar_cpf(const char* cpf) {
    int i = 0;

    if (strlen(cpf) != 11) {
        return False; // tamanho incorreto
    }

    while (cpf[i] != '\0') {
        if (!eh_digito(cpf[i])) {
            return False; // nao eh digito
        }
        i++;
    }
    return True;
}

// valida id
// deve conter 4 digitos no maximo
int validar_id(const char* id) {
    int i = 0;

    if (strlen(id) > 4) {
        return False; // tamanho incorreto
    }

    while (id[i] != '\0') {
        if (!eh_digito(id[i])) {
            return False; // nao eh digito
        }
        i++;
    }
    return True;
}

// valida a data de nascimento DD/MM/AAAA
// formato, dias, meses e anos validos
int validar_data(const char* data) {
    int dia, mes, ano;
    
    // verifica o formato e extrai os numeros
    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3) {
        return False; // formato invalido (não é DD/MM/AAAA)
    }

    // verifica o comprimento (deve ser 10, ex: "01/01/2000")
    if (strlen(data) != 10) {
        return False;
    }

    // verifica os separadores
    if (data[2] != '/' || data[5] != '/') {
        return False;
    }

    // validacao basica do intervalo
    if (ano < 1900 || ano > 2025) return False; // intervalo de ano possivel
    if (mes < 1 || mes > 12) return False;
    if (dia < 1 || dia > 31) return False;

    // validacao de dias por mes
    if (mes == 2) {
        if (eh_bissexto(ano)) {
            if (dia > 29) return False;
        } else {
            if (dia > 28) return False;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) { // meses com 30 dias
        if (dia > 30) return False;
    }

    return True;
}


// valida o telefone
// deve conter apenas numeros, exemplo 80999887766
int validar_telefone(const char* telefone) {
    int i = 0;

    // verifica se esta vazio
    if (strlen(telefone) == 0) {
        return False;
    }

    // verifica tamanho
    if (strlen(telefone) != 11) {
        return False;
    }

    while (telefone[i] != '\0') {
        if (!eh_digito(telefone[i])) {
            return False; // nao eh um dígito
        }
        i++;
    }
    return True;
}


// valida o email
// verificacao simples de formato 
// deve ter um @ e um . depois do @
int validar_email(const char* email) {
    char* arroba = strchr(email, '@'); // procura o @
    
    // verifica se tem @
    if (arroba == NULL) {
        return False;
    }

    // se o @ for o primeiro caractere, eh invalido
    if (arroba == email) {
        return False;
    }

    // procura um . DEPOIS do @
    char* ponto = strchr(arroba, '.');

    // ve nao houver . depois do @
    // ou se o . estiver logo após o @, eh invalido
    if (ponto == NULL || ponto == arroba + 1) {
        return False;
    }
    
    // verifica se o . eh o ultimo caractere
    if (ponto[1] == '\0') {
        return False;
    }

    return True;
}

// valida descricao
// verifica o tamanho da string 
int validar_descricao(const char* descricao, int tamanho_max) {
    int len = strlen(descricao);

    // verifica se ta vazio
    if (len == 0) {
        return False;
    }
    
    // verifica se passou do tamanho maximo
    if (len > tamanho_max - 1) { // -1 por causa do '\0'
        return False;
    }
    
    return True;
}


// valida tipo
// verifica o tamanho da string 
int validar_tipo(const char* tipo, int tamanho_max) {
    int len = strlen(tipo);

    // verifica se ta vazio
    if (len == 0) {
        return False;
    }
    
    // verifica se passou do tamanho maximo
    if (len > tamanho_max - 1) { // -1 por causa do '\0'
        return False;
    }
    
    return True;
}

// valida preco
// recebe uma string que representa um float
int validar_preco(const char* preco_str) {
    int i = 0;
    int pontos_decimais = 0;
    float preco;

    // verifica se ta vazio
    if (strlen(preco_str) == 0) {
        return False;
    }

    // verifica se todos os caracteres sao digitos ou um ponto
    while (preco_str[i] != '\0') {
        if (preco_str[i] == '.') {
            pontos_decimais++;
        } else if (!eh_digito(preco_str[i])) {
            return False; // caracter invalido, nao eh digito nem '.'
        }
        
        if (pontos_decimais > 1) {
            return False; // mais de um ponto decimal, tipo 10.5.9
        }
        i++;
    }
    
    // converte a string para float
    preco = atof(preco_str);
    
    // verifica se o preco eh positivo
    if (preco <= 0.0) {
        return False;
    }
    
    return True;
}

// valida quantidade
// recebe uma string que representa um int
int validar_quantidade(const char* quant_str) {
    int i = 0;
    int quantidade;

    // verifica se esta vazio
    if (strlen(quant_str) == 0) {
        return False;
    }

    // verifica se todos os caracteres sao digitos
    while (quant_str[i] != '\0') {
        if (!eh_digito(quant_str[i])) {
            return False;
        }
        i++;
    }
    
    // converte a string para int
    quantidade = atoi(quant_str);

    // verifica se quantidade eh positiva
    if (quantidade < 0) {
        return False;
    }
     
    return True; 
}