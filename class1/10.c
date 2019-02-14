#include <stdio.h>


int main(void){
  int resultado;
        for (int j =555; j<=777; j++) {
          resultado=0;
                for (int i = 1; i <= j / 2; i++) {
                        if (j % i == 0) {
                                resultado++;
                        }
                }

                if (resultado <= 2)
                        printf("%d\n", j);
        }
        return 0;


}
