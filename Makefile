# VARIÁVEIS
# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Pastas
SRC = src
BUILD = build


# LISTAGEM
# Arquivos .c dentro de src/
SRCS = $(wildcard $(SRC)/*.c $(SRC)/*/*.c)

# Arquivos .o correspondentes dos .c, em build/
OBJS = $(patsubst $(SRC)/%.c,$(BUILD)/%.o,$(SRCS))


# REGRA PADRÃO
all: sig-motel

sig-motel: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^


# COMPILAÇÃO
$(BUILD)/%.o: $(SRC)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


# LIMPEZA
.PHONY: clean
clean:
	rm -f *.o sig-motel