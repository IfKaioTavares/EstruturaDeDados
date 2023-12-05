CC = gcc
CFLAGS = -Wall -Iinclude

SRC_FILES = src/models/aluno.c src/models/curso.c src/main.c

TARGET = meu_programa.exe

$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	del /Q $(TARGET)