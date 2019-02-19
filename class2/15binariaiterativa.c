#include <stdio.h>

#define SIZE 50000

int procura(int elemento, int nelementos, int v[nelementos]) {

    int inicio = 0;
    int fim = nelementos - 1;
    int meio;
    while (1) {
        meio = (inicio + fim) / 2;
        if (elemento == v[meio]) return meio;
        if (elemento < v[meio]) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

}

int main(void) {
    int array[SIZE];
    int p, num;

    //coloca os elementos pretendidos no array
    for (int i = 1; i <= SIZE; i++) {
        array[i - 1] = i * 2;
    }

    //procurar
    for (int i = 1; i <= SIZE; ++i) {

        num = i * 2;
        p = procura(num, SIZE, array);

        if (p == -1)
            printf("Não encontrou %d\n", num);
        else if (array[p] != 2 * i)
            printf("Encontrou %d na posição errada: %d\n", num, p);
    }

    printf("Terminei!\n");

    return 0;
}