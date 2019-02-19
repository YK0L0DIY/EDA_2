#include <stdio.h>

#define SIZE 50000

int recursiva(int elemento, int inicio, int fim,int v[]) {
    int meio = (inicio + fim) / 2;

    if (elemento == v[meio])
        return meio;

    return elemento < v[meio] ? recursiva(elemento, 0, meio - 1, v)
                             : recursiva(elemento, meio + 1, fim, v);

}

int procura(int elemento, int nelementos, int v[nelementos]) {
    return recursiva(elemento, 0, nelementos-1, v);
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

    printf("Terminei!");

    return 0;
}