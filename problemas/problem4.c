#include <stdio.h>
#include <string.h>

#define SIZE 1101

int lastPosition(char string[SIZE]){            // calcula o tamanho da palavara encriptada
    for (int i = 0; i < SIZE ; ++i) {           // percorre a palavra toda
        if(string[i]==0){                       // encontra o primeiro caracter nulo
            return i;                           // retorna o valor do caracter nulo
        }
    }
    return -1;                                  // caso nao encontre
}

void correctLetter(int first,int last,char correct[], char string[SIZE]){ // coloco a letra no sitio correto
    // recursivamnete enviar para aqui caso existe um grupo dentro do grupo formado anteriormente
    // caso
}

void findLetter(int last, int lastCorrect, char correct[],char string[SIZE]){
    // verifica a distancia das letras
    // se for menor de 2 entao nao pode existir repetidas

    // verifica se o o elemento e igual ao ja introduzido
    // caso sim ignora // testas // TODO


}

void convert(char string[SIZE]) {
    int size=lastPosition(string);              // tamanho da palavra encriptada
    char correctWord[size];                     // aloca espaco para a palvra correta que no pior dos casos o tamanho e igual ao recebido

    //printf("%s: size= %d\n", string,size);
    printf("%s", correctWord);
}

int main(void) {
    char encripted[SIZE];                               // palavra encriptada

    while (scanf("%[^\n]%*c", encripted) == 1) {        // verifica o input caso seja diferente de nulo
        convert(encripted);                             // converte o codigo para a palavra correta
    }
}