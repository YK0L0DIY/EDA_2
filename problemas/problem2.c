#include <stdio.h>

int main() {

    int nElementos = 0;

    //guarda o tamanho do array
    scanf("%d", &nElementos);

    int array[nElementos], //inicializa o array com n elementos
            first = 0, //posicao do primeiro elemento do array
            last = nElementos - 1, //posicao do ultimo elemento do array
            player = 0, // jogaror, caso seja 0 -> Alex caso seija 1 -> Bela
            alex = 0, // pontuacao do Alex
            bela = 0, // pontuacao da Bela
            menor = 1; // caso a jogada da bela seja escolher o menor (menor=1)

    // recebe o input do array
    for (int i = 0; i < nElementos; i++) {
        fscanf(stdin, "%d", &array[i]);
    }

    do {
        //teste para ver quem e o jogador
        if (player == 0) {
            //verifica qual dos elementos e o maior ""caso do Alex
            if (array[first] > array[last]) {
                alex += array[first];
                first++;
            } else {
                alex += array[last];
                last--;
            }
            player = 1; // troca o jogador

        } else {
            // verifica se o numero a escolher é o menor ou o maior ""caso da Bela
            if (menor) {
                //escolhe o menor elemento
                if (array[first] < array[last]) {
                    bela += array[first];
                    first++;
                } else {
                    bela += array[last];
                    last--;
                }
                menor = 0; // o proximo eleento a ser escolhido sera o maior
            } else {
                // escolhe o maior elemento
                if (array[first] > array[last]) {
                    bela += array[first];
                    first++;
                } else {
                    bela += array[last];
                    last--;
                }
                menor = 1; // o proximo elemento a ser escolhido sera o menor
            }
            player = 0; // troca o jogador
        }
    } while (first <= last);

    // da print do resultado
    if (alex > bela) {
        printf("Alex ganha com %d contra %d\n", alex, bela);
    } else if (alex < bela) {
        printf("Bela ganha com %d contra %d\n", bela, alex);
    } else {
        printf("Alex e Bela empatam a %d\n", alex);
    }

    return 0;
}