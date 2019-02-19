#include <stdio.h>

#define SIZE 50000

//n- numero a procurar
//s- tamanho
//v[s] - endereço do array com s elementos
int procura(int n, int s, int v[s]) {
    for (int i = 0; i < s; i++) {
        if (n == v[i]) {
            return i;
        }
    }
    return -1;
}


int main(void) {
    int array[SIZE];
    int p, num;

    //coloca os elementos pretendidos no array
    for (int i = 1; i <= SIZE; i++) {
        array[i-1] = i * 2;
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