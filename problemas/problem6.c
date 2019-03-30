#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 300000

struct conexao {
    int sensor;                                                 // sensor a qual esta ligado
    struct conexao *next;                                       // proxima coenxao
};

struct conexao *newConect(int element) {                        // funcao para criar uma nova coenxao
    struct conexao *c = malloc(sizeof(struct conexao));
    c->sensor = element;
    return c;
}

void addConect(struct conexao *conexao[], int x, int y) {       // funcao para adiconar uma conexao de x para y
    struct conexao *c = newConect(y);                           // cria a conexao
    if (conexao[x] == 0) {                                      // verifica se esse elemento ja possuia coenxoes
        c->next = NULL;                                         // se nao entao esse passa a ser a sua coenxao
        conexao[x] = c;
    } else {
        c->next = conexao[x];                                   // caso exista a uma coencao esse passa a ser a proxima da que se pretende introduzir
        conexao[x] = c;
    }
}

void removeConect(struct conexao *conexao[], int x, int y) {    // funcoa para remover a coencap de x para y
    struct conexao *temp = conexao[x], *anterior;               // variaveis de controlo
    if (temp->sensor == y) {                                    // verifica se a conexao que pretende remover e a primera da lista
        if (temp->next != NULL) {                               // caso seja e nao for a unica
            conexao[x] = temp->next;                            // a proxima assa a ser a primeria
        } else {
            conexao[x] = 0;                                     // caso seja a unica nao ira existir mais nenhuma
        }
    } else {
        while (temp != NULL && temp->sensor != y) {             // percore toda a lista a procura do elemento
            anterior = temp;
            temp = temp->next;
        }
        anterior->next = temp->next;                            // remove o elemento
    }
    free(temp);                                                 // liberta o epaço utilizado pela struct

}

void findConect(struct conexao *conexao[], int x, int y) {      // funcao para veririfcar se existe cenxao
    int z, conect=0, primeiro=y;                                // z- proximo sensor,conect- numero de conexoes feitas,priemro-primeiro sensor
    struct conexao *temp;                                       // temporario para guardar o enedereço
    for (int i = 0; i < x; i++) {                               // percore todos os elementos da linha
        scanf(" %d", &z);                                       // le o rpoximo sensor
        temp = conexao[y];                                      // vai ao sensro a qal pretende encotrar se tem ligacao
        while (temp != NULL) {                                  // percore a lista toda
            if (temp->sensor == z) {                            // se encontrar o elemto
                conect++;                                       // onrementa o numero de elemntos que tem conexao
                break;
            }
            temp = temp->next;                                  // increnmneta o proximo elemento
        }
        y = z;                                                  // o elemento passa a ser o anterior a ser verificado
    }
    if (conect == x) {                                          // verifica se o numero de conexoes existentes é igual ao numero de pedidos
        printf("yes [%d..%d]\n", primeiro, z);
    } else {                                                    // se nao for diz que nao existe conexoes
        printf("no [%d..%d]\n", primeiro, z);
    }
}

int main(void) {
    int nSenesores;                                             // recebe o numer de sensores que exitirao
    scanf("%d", &nSenesores);

    struct conexao *conexao[TAMANHO] = {0};                     // inicializa o arrya de ponteiros com o maximo de sensores possiveis
    int x, y;                                                   // parareceber o input
    char operacao;                                              // opercao que vem do input

    while ((scanf(" %c", &operacao) != EOF)) {                  // corre ate do final do ficheiro
        scanf(" %d %d", &x, &y);                                // recebe o input de dados
        if (operacao == '+') addConect(conexao, x, y);          // caso seija adicionar coenxao
        else if (operacao == '-') removeConect(conexao, x, y);  // caso seja remover conexao
        else if (operacao == '?') findConect(conexao, x, y);    // cajo seja verificar conexao
    }
}