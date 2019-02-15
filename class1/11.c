#include <stdio.h>

void calcularBinario(int number){

        //faz shift right dos 31 bits possibeis 1 a 1 , depois faz um and entre o resultado e 1
        //caso seja 1 quer dizer que o bit encitra-se a 1 caso contrario é 0

        if(number<0) {
                printf("-");
                calcularBinario(number* -1);
        }else{
                int test;
                int block=1;

                for (int i = 31; i >= 0; i--)
                {
                        test = number >> i;

                        if (test & 1) {
                                printf("1");
                                block=0;
                        }
                        else{
                                if (!block) {
                                        printf("0");
                                }

                        }
                }
                printf("\n");
        }

}

int main()
{
        calcularBinario(170);
        calcularBinario(-170);


        return 0;
}
