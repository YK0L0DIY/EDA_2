#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int perfect(int number){
        int sum=0;
        // for(int i=0; i<number; i++) {
        //         if (number%i==0) {
        //                 sum+=i;
        //         }
        //         printf("%d\n", sum);
        // }
        return 0;


}


int main(){
        int number;
        char cont[]="n";
        do {
                printf("\n%s","Your number:" );
                scanf("%d", &number);

                if (perfect(number)) {
                        printf("%s\n", "Perfect number");
                }else{
                        printf("%s\n", "Normal number");
                }

                printf("%s", "continue[y/n]:");
                scanf("%s", cont);

        } while (strcmp(cont,"n")!=0);
}
