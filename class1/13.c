#include <stdio.h>

void calcularBinario12(int number){

        //faz shift right dos 31 bits possibeis 1 a 1 , depois faz um and entre o resultado e 1
        //caso seja 1 quer dizer que o bit encitra-se a 1 caso contrario é 0

        int test;

        for (int i = 11; i >= 0; i--)
        {
                test = number >> i;

                if (test & 1)
                        printf("1");
                else
                        printf("0");
        }

        printf("\n");
}
void calcularBinario64(long number){

        //faz shift right dos 31 bits possibeis 1 a 1 , depois faz um and entre o resultado e 1
        //caso seja 1 quer dizer que o bit encitra-se a 1 caso contrario é 0

        int test;

        for (int i = 63; i >= 0; i--)
        {
                test = number >> i;

                if (test & 1)
                        printf("1");
                else
                        printf("0");
        }

        printf("\n");
}
void calcularBinario65(long long number){

        //faz shift right dos 31 bits possibeis 1 a 1 , depois faz um and entre o resultado e 1
        //caso seja 1 quer dizer que o bit encitra-se a 1 caso contrario é 0

        int test;

        for (int i = 64; i >= 0; i--)
        {
                test = number >> i;

                if (test & 1)
                        printf("1");
                else
                        printf("0");
        }

        printf("\n");
}

int main()
{
        calcularBinario12(170);
        calcularBinario64(170);
        calcularBinario65(170);
        calcularBinario12(-170);
        calcularBinario64(-170);
        calcularBinario65(-170);


        return 0;
}
