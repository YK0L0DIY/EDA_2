#include <stdio.h>

//the function shuld be before main???

int veryfy(int num1, int num2) {
    if (num1 == num2) {
        return 1;
    } else {
        return 0;
    }
}


int main(void) {

    int a = 12, b = 13;
    int equal = veryfy(a, b);
    printf("%d\n", equal);

    return 0;
}
