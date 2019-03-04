#include <stdio.h>

void maior(int array[], int *inicio, int *fim, int *pontuacao) {
    if (array[*inicio] > array[*fim]) {                         // verifica qual dos numeros do array e o maior
        *pontuacao += array[*inicio];                           // incremnata a pontuacao com o elemento do inicio caso seija maior
        (*inicio)++;                                            // incremnata a posicao do elemento inicial
    } else {
        *pontuacao += array[*fim];                              // incremnata a pontuacao com o elemento do fim caso seija maior
        (*fim)--;                                               // decrementa a posicao final do array
    }
}

void menor(int array[], int *inicio, int *fim, int *pontuacao) {
    if (array[*inicio] < array[*fim]) {                         // verifica qual dos numeros do array e a menor
        *pontuacao += array[*inicio];                           // incremnata a pontuacao com o elemento do inicio caso seija menor
        (*inicio)++;                                            // incremnata a posicao do elemento inicial
    } else {
        *pontuacao += array[*fim];                              // incremnata a pontuacao com o elemento do fim caso seija menor
        (*fim)--;                                               // decrementa a posicao final do array
    }
}

int main(void) {
    int nElementos;
    scanf("%d", &nElementos);           // guarda o tamanho do array

    int array[nElementos],              // inicializa o array com n elementos
            first = 0,                  // posicao do primeiro elemento do array
            last = nElementos - 1,      // posicao do ultimo elemento do array
            player = 1,                 // jogaror, caso seja 1 -> Alex caso seija -1 -> Bela
            alexP = 0,                  // pontuacao do Alex
            belaP = 0,                  // pontuacao da Bela
            menorJ = 1;                 // caso a jogada da bela seja escolher o menor ou maior


    for (int i = 0; i < nElementos; i++) {
        scanf("%d", &array[i]);         // recebe o input do array
    }

    for (int i = 0; i < nElementos; i++) {
        // testa se o jogador e o Alex ou a bela
        if (player == 1)
            // caso seija o alex executa a funcao maior (este escolhe sempre o maiior numeor)
            maior(array, &first, &last, &alexP);
        else {
            // verifica o tipo de jogada que a bela deve de realizar
            // corre uma das hipoteces
            // inverte o modo de jogar da bela na proxima jogada
            menorJ == 1 ? menor(array, &first, &last, &belaP) : maior(array, &first, &last, &belaP);
            menorJ *= -1;
        }
        // inverte o jogador
        player *= -1;
    }

    // da print do resultado
    if (alexP == belaP) {
        printf("Alex e Bela empatam a %d\n", alexP);
    } else {
        alexP < belaP ?
        printf("Bela ganha com %d contra %d\n", belaP, alexP) :
        printf("Alex ganha com %d contra %d\n", alexP, belaP);
    }

    return 0;
}