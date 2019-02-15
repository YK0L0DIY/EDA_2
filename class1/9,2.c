#include <stdio.h>

//recebe o numero de elementos a calcular
void fib(int n) {
    int first = 0, second = 1, next;

    if (n >= 0)
        printf("%d\n", first);
    if (n >= 1)
        printf("%d\n", second);
    if (n > 1) {
        for (int i = 2; i <= n; i++) {
            next = first + second;
            first = second;
            second = next;
            printf("%d\n", next);
        }
    }
}

int main(void) {
    int elementos;
    scanf("%d", &elementos);
    fib(elementos);

    return 0;
}
