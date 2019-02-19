#include <stdio.h>

int main(void) {
    int numero, num1, num2;
    float real, x, y;

    scanf("%d", &numero);
    printf("%d\n", numero);

    scanf("%d + %d =", &num1, &num2);
    printf("%d\n", num1 + num2);

    scanf("%f", &real);
    printf("%f\n", real);

    scanf(" (%f, %f)", &x, &y);
    printf("(%.3f, %.3f)\n", x, y);

    return 0;

}