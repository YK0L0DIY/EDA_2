#include <stdio.h>
#include <string.h>

#define SIZE 1101

int lastPosition(char string[SIZE]) {            // calcula o tamanho da palavara encriptada
    for (int i = 0; i < SIZE; ++i) {           // percorre a palavra toda
        if (string[i] == 0) {                       // encontra o primeiro caracter nulo
            return i;                           // retorna o valor do caracter nulo
        }
    }
    return -1;                                  // caso nao encontre
}

void put(int *local,char caracter,char array[]){
    int sitio=*local;
//    if(array[sitio-1]==caracter){
//        return;
//    }
    array[*local]=caracter;
    (*local)++;
}

void correctLetter(int first, int last, int *toPut, char correct[], char string[SIZE]) {
    // coloco a letra no sitio correto
    // recursivamnete enviar para aqui caso existe um grupo dentro do grupo formado anteriormente
    // caso
    //printf("aqui %d\n",*toPut);
    int distace = last - first, colocou = 0;
    if (distace <= 2) {
        put(toPut,string[first],correct);

    } else {
        int x, i;
        for (x = first + 1; first < last; first++) {
            for (i = x + 1; i < last; i++) {
                if (string[x] == string[i]) {

                    printf("%c : %d %d\n", string[x], x, i);
                    correctLetter(x, i, toPut, correct, string);
                    x = i;
                    colocou = 1;
                }
            }
        }
        if (colocou == 0) {
            printf("aqui\n");
            correct[*toPut] = string[first];
            (*toPut)++;
        }
    }
}

void findLetter(int last, char correct[], char string[SIZE]) {

//    for (int i = 0; i <= last; i++) {
//        //printf("%s", correct);
//        correct[i] = string[i];
//    }
    int toPut = 0; // posicao da ultima letra a ser adicionada
    int position = 0, positionC;
    for (positionC = 0; position <= last; positionC++) {
        for (position = positionC + 1; position < last; position++) {
            if (string[positionC] == string[position]) {
                printf("%c : %d %d\n", string[positionC], positionC, position);
                correctLetter(positionC, position, &toPut, correct, string);
                positionC = position;
            }
        }
    }

    correct[toPut] = 0;

    // verifica a distancia das letras
    // se for menor de 2 entao nao pode existir repetidas

    // verifica se o o elemento e igual ao ja introduzido
    // caso sim ignora // testas // TODO


}

void convert(char string[SIZE]) {
    int size = lastPosition(string);              // tamanho da palavra encriptada
    char correctWord[size];                     // aloca espaco para a palvra correta que no pior dos casos o tamanho e igual ao recebido
    findLetter(size, correctWord, string);

    //printf("%s: size= %d\n", string,size);
    printf("%s\n", correctWord);
}

int main(void) {
    char encripted[SIZE];                               // palavra encriptada

    while (scanf("%[^\n]%*c", encripted) == 1) {        // verifica o input caso seja diferente de nulo
        convert(encripted);                             // converte o codigo para a palavra correta
    }
}