#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO 765

struct no {                                                         // no que ira conter a informacao do ipv4
    int a, b, c, ipv;
    struct no *next;

};

struct no *newNo(int a, int b, int c, int ipv) {                    // funcao que cria um novo no e devolve o seu endereço
    struct no *no = malloc(sizeof(struct no));
    if (no != NULL) {
        no->a = a;
        no->b = b;
        no->c = c;
        no->ipv = ipv;
    }
    return no;
}

int main(void) {
    int ipvNumbers;
    scanf("%d",&ipvNumbers);                                        // le o input que contem o numero de ipv4 que sarao introduzidos
    int a, b, c, d, ipv, def = -1, position;                        // inicializa um array com de endereços de nos vazio
    struct no *table[TAMANHO] = {0}, *temp;

    for (int i = 0; i < ipvNumbers; i++) {                          // ciclo para receber todos os ipvs
        scanf("%d.%d.%d.0 %d", &a, &b, &c, &ipv);                   // recebe o nput e gurda nas respetivas variaveis
        position = a + b + c;                                       // calcula a posicao em que estara no array
        if (table[position] == 0) {                                 // se a osicao esta vazia
            table[position] = newNo(a, b, c,ipv);                   // cria um no de ipv e guarda o endereço na posicao destinada
        } else {                                                    // caso este nao esteja vazio
            temp = table[position];                                 // coloca o endereço que ja se encontrava numa variavel de controlo
            struct no *element = newNo(a, b, c, ipv);               // cria um novo no de ipv
            element->next = temp;                                   // coloca o anterior como proximo elemento do no
            table[position] = element;                              // coloca o endereço na posicao pretemdda do array
        }

        if (a == 0 && b == 0 &&c == 0) {                            // caso receba o ipv 0.0.0.0 este e identificado como defoult
            def = ipv;                                              // guarda o ipv
        }
    }
    while (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != EOF) {           // recebe o input ate ao final do ficheiro
        _Bool printed = false;                                       // variavel que seja usada para verificar se foi devolvida uma route ou nao
        position = a + b + c;                                       // calcula a posicao

        if (table[position] == 0) {                                 // caso nao exista nada nessa posicao devole o defoutl ou no route
            def >= 0 ? printf("%d\n", def) : printf("no route\n");
        } else {                                                    // caso exista elementos nessa posicao
            temp = table[position];                                 // a variavel de controlo ira ter o endereço do elemento

            if (temp->a == a && temp->b == b && temp->c == c) {     // verifica se e esse o elemento pretendido
                printf("%d\n", temp->ipv);                          // caso seja e feito o print do ipv
                printed = true;                                     // informa-se que foi impresso
            } else {                                                // caso nao seja esse elemento o pretendido
                while (temp->next != NULL) {                        // ira correr um ciclo dentro dos elementos daquela posicao ate nao existir mais nenhum ou ter encontrado o correto
                    temp = temp->next;                              // o de controlo passa a se o proximo elemento
                    if (temp->a == a && temp->b == b && temp->c == c) {     // verifica se e esse o pretendido
                        printf("%d\n", temp->ipv);                  // caso seja da print do ipv
                        printed = true;                             // informa-se que foi impresso
                        break;                                      // termina o ciclo
                    }
                }
            }
            if (!printed) {                                         // caso nao tenha sido impresso nenhum valor
                def >= 0 ? printf("%d\n", def) : printf("no route\n");  // verifica-se a edistencia de dfoult e da-se o print
            }
        }
    }
    return 0;
}