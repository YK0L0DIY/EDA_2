#include <stdio.h>
#include <stdlib.h>

//to clean the terminal
void clrscr()
{
        system("@cls||clear");
}

float addiction(float a,float b){

        return a+b;
}
float subraction(float a,float b){
        return a-b;
}
float division(float a,float b){
        return a/b;
}
float multiplication(float a,float b){
        return a*b;
}

void calc(int operation){
        //ask for the numbers
        float num1,num2;
        printf("%s", "First number:");
        scanf("%f", &num1);
        printf("%s", "Second number:");
        scanf("%f", &num2);

        float result;
        //execute the right function
        switch (operation) {
        case 1:
                result=addiction(num1,num2);
                break;
        case 2:
                result=subraction(num1,num2);
                break;
        case 3:
                result=division(num1,num2);
                break;
        case 4:
                result=multiplication(num1,num2);
                break;

        }
        printf("\nThe result is: %f\n", result);
}

int main(void){
        while (1) {
                printf("\n%s\n", "1) Addiction");
                printf("%s\n", "2) Subraction");
                printf("%s\n", "3) Division");
                printf("%s\n", "4) Multiplication");
                printf("%s\n", "0) Exit" );
                printf("\n%s", "Input >");

                //ask for the calcul to use
                int input;
                scanf("%d", &input);
                clrscr();

                //exist the program in case of 0
                if (input==0) {
                        break;
                }

                if(input < 5 && input > 0) {
                        calc(input);
                }else{
                        printf("%s\n", "Invalid operation");
                }

        }

}
