#include <stdio.h>

void maior(int array[], int *inicio, int *fim, int *pontuacao){
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
        if (player == 1)                            // testa se o jogador e o Alex
            maior(array, &first, &last, &alexP);    // caso seija o alex executa a funcao maior (este escolhe sempre o maiior numeor)
        else if (player == -1 && menorJ == 1) {     // verifica se e a bela e a sua jogada e escolher o menor
            menor(array, &first, &last, &belaP);    // corre a funcao de escolher o menor
            menorJ *= -1;                           // coloca -1 na proxima jogada da bela para escolher o maior
        } else {
            maior(array, &first, &last, &belaP);    // corre a funcao de escolher o maior a bela caso seja esta
            menorJ *= -1;                           // coloca 1 na proxima jogada da bela para esta escolher o menor
        }
        player *= -1;                               // muda de jogador
    }

    // da print do resultado
    if (alexP > belaP) {
        printf("Alex ganha com %d contra %d\n", alexP, belaP);
    } else if (alexP < belaP) {
        printf("Bela ganha com %d contra %d\n", belaP, alexP);
    } else {
        printf("Alex e Bela empatam a %d\n", alexP);
    }

    return 0;
}