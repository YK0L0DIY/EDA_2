#include<stdio.h>
#include<string.h>

#define SIZE 1101
#define SIZEHASH 127

void verify(char caracter,char array[]){
    if (array[(int)caracter]==caracter){
        printf("%c",caracter);
        memset(array,' ', SIZEHASH);
    } else{
        array[(int)caracter]=caracter;
    }
}

void convert(char string[SIZE]) {
    int i=0;
    char myHash[SIZEHASH]={0};
    while (string[i]!=0){
        verify(string[i],myHash);
        i++;
    }
    printf("\n");
}

int main(void) {
    char encripted[SIZE];                               // palavra encriptada

    while (scanf("%[^\n]%*c", encripted) == 1) {        // verifica o input caso seja diferente de nulo
        convert(encripted);                             // converte o codigo para a palavra correta
    }
    return 0;
}