#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// the number is perfect if the sum of all of the dividors is equal to numbers
// so this funcion
// retun 1 if the nmber is perfect and 0 if the number is normal
int perfect(int number) {

    int sum = 0;
    float rest;
    for (int i = 1; i < number; i++) {
        rest = number % i;
        if (rest == 0) {
            sum += i;
        }
    }

    if (sum == number) {
        return 1;
    }
    return 0;
}

int main(void) {

    int number;
    char cont[] = "n";
    do {
        printf("\n%s", "Your number:");
        scanf("%d", &number);
        int perf = perfect(number);

        if (perf) {
            printf("%s\n", "Perfect number");
        } else {
            printf("%s\n", "Normal number");
        }

        printf("%s", "continue[y/n]:");
        scanf("%s", cont);

    } while (strcmp(cont, "n") != 0);
}
