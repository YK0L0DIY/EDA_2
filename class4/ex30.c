#include <stdio.h>
#include <string.h>

#define NOME "memoria"
#define SIZEMEM 10

FILE *abrir() {
    FILE *file = fopen(NOME, "r+");
    if (file == NULL) {
        int zero = 0;
        file = fopen(NOME, "w+");
        for (int i = 0; i < SIZEMEM; i++) {
            fwrite(&zero, sizeof(zero), 1, file);
        }
    }
    return file;
}

void escreve(FILE *file, int position, int value) {
    fseek(file, ((position - 1) * sizeof(int)), SEEK_SET);
    fwrite(&value, sizeof(value), 1, file);
}

int le(FILE *file, int position) {
    int place;
    fseek(file, ((position - 1) * sizeof(int)), SEEK_SET);
    fread(&place, sizeof(int), 1, file);
    return place;
}

void fechar(FILE *file) {
    fclose(file);
}

int main(void) {
    FILE *file = abrir();
    char option;

    do {
        int posicao, valorAnterior, valor;
        printf("-> ");
        scanf(" %c", &option);
        switch (option) {
            case '?':
                scanf(" %d", &posicao);
                printf("%d\n", le(file, posicao));
                break;

            case '+':
                scanf(" %d %d", &posicao, &valor);
                valorAnterior = le(file, posicao);
                escreve(file, posicao, (valorAnterior + valor));
                break;

            case 'r':
                scanf(" %d", &posicao);
                escreve(file, posicao, 0);
                break;
        }
    } while (option != 'q');
    return 0;
}