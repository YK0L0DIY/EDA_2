#include <stdio.h>

//nao e possivel calcular o factorial de 20 nem 21 pois da overflow visto que o int so pode ter 32 bits

int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main(void) {
    int number;
    printf("Factorial of:");
    scanf("%d", &number);
    int fact = factorial(number);
    printf("%d\n", fact);
}
