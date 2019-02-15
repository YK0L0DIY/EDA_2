#include <stdio.h>

int primo(int n) {
    int div = 0;

    for (int i = 1; i <= j / 2; i++) {
        if (j % i == 0) {
            div++;
            if (div > 2) {
                return 0;
            }
        }
    }
    return 1;
}

int main(void) {

    for (int j = 555; j <= 777; j++) {
        if (primo(j))
            printf("%d\n", j);
    }
    return 0;


}
