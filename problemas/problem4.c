#include<stdio.h>
#include<string.h>

#define SIZE 1101
#define SIZEHASH 123

void verify(char caracter,char array[]){                // funcao que verifica se o caracter ja foi iserida na hastable antes consoante o seu ascii
    if (array[(int)caracter]==caracter){                // caso esta ja foi inserida antes quer dizer fecha o grupo
        printf("%c",caracter);                          // da print desse caracter
        memset(array,' ', SIZEHASH);                    // rescreve o array de modo a ficar vasio para receer os proximos caracters
    } else{
        array[(int)caracter]=caracter;                  // caso o caracter ainda nao exista na has este e adicionado na sua posicao
    }
}

void convert(char string[SIZE]) {
    int i=0;                                            // variavel inicializada para o ciclo
    char myHash[SIZEHASH]={0};                          // cria um arrai que servi-ra como hastable com as possibilidades de ascii todas
    while (string[i]!=0){                               // percorre a string
        verify(string[i],myHash);                       // faz a verificacao do caracter
        i++;                                            // incremneta a varivel do ciclo
    }
    printf("\n");                                       // print de um paragrafo apos cada linha desencriptada
}

int main(void) {
    char encripted[SIZE];                               // palavra encriptada

    while (scanf("%[^\n]%*c", encripted) == 1) {        // verifica o input caso seja diferente de nulo
        convert(encripted);                             // converte o codigo para a palavra correta
    }
    return 0;
}