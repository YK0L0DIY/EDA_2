#include <stdio.h>

//recebe o numero para calcular o numero
//de algoritmos que este tem
int digits(int n) {
    if (n < 10) {
        return 1;
    } else {
        return digits(n / 10) + 1;
    }
}

int main(void) {
    int number, num;
    scanf("%d", &number);

    if (number >= 0)
        num = digits(number);

    else if (number < 0)
        num = digits(number * -1);

    printf("%d\n", num);

    return 0;
}
