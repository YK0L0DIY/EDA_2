#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// representacao do grafo e das ligacoes que vai ter
struct grafo {
    short nElementos;
    int elementos[300];
};

// criar um novo grafo
struct grafo *newGrafo() {
    struct grafo *g = malloc(sizeof(struct grafo));
    g->nElementos = 0;
    memset(g->elementos, 0, 300 * sizeof(int));
    return g;
}

// funcao para o qsort retirada de "https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm"
int comparar(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

//  pesquisa binaria devolve o endereço da posicao do elemento case nao exista devolve -1
int recursiva(int elemento, int inicio, int fim, int v[]) {
    int meio = (inicio + fim) / 2;
    if (elemento == v[meio])
        return meio;
    else if (inicio == fim) {
        return -1;
    }
    return elemento < v[meio] ? recursiva(elemento, 0, meio - 1, v) : recursiva(elemento, meio + 1, fim, v);
}

int procura(int elemento, int nelementos, int v[nelementos]) {
    return recursiva(elemento, 0, nelementos, v);
}

// funcao para adicionar uma ligacao a um sensor
void addConection(struct grafo *g, int element) {
    g->elementos[g->nElementos] = element;                      // adiciona no fim da fila
    g->nElementos++;                                            // incrementa o numero de elementos
    qsort(g->elementos, g->nElementos, sizeof(int), comparar);  // faz sort dos elementos
}

// funcao para remover um aligacao de um sensor
void removeConection(struct grafo *g, int element) {
    short index = procura(element, g->nElementos, g->elementos);    // procura o inice da posicao do elemento no aray
    if (index != -1) {
        g->elementos[index] = g->elementos[g->nElementos];              // substitui pelo ultimo elemnto
        g->nElementos--;                                                // decrementa o numero de leemntos
        qsort(g->elementos, g->nElementos, sizeof(int), comparar);      // faz sort dos elementos
    }
}

// funcao que verifica se existe ligacao entre os sensores
int verificarConexao(struct grafo *g[], int de, int para) {
    printf("_%d %d_", de, para);
    short index = procura(para, g[de]->nElementos, g[de]->elementos);
    printf("%d\n", index);
    return index;
}

int main(void) {
    int nSenesores;
    scanf("%d", &nSenesores);

    struct grafo *grafos[nSenesores];
    memset(grafos, 0, sizeof(int) * nSenesores);
    int x, y, z, ex=0;
    char operacao;

    while ((scanf(" %c", &operacao) != EOF)) {
        scanf(" %d %d", &x, &y);
        if (operacao == '+') {                                  // caso a opcao seja adicionar uma conexao
            if (grafos[x] == 0) {                               // caso o grafo ainda nao tenha nenhuma coxao
                grafos[x] = newGrafo();                         // é craido um grafo vazio e o seu endereço e guardado na poscao x
                addConection(grafos[x], y);                     // é adicionada a nonexao no grafo
            } else {
                addConection(grafos[x], y);                     // caso este ja exista é adiciona a conexao
            }
        } else if (operacao == '-') {                           // caso a opca seja eleminar uma conexa
            removeConection(grafos[x], y);                      // remove-se o elemento pretendido
            if (grafos[x]->nElementos == 0) {                   // verifica se este possui mais ligacoes
                free(grafos[x]);                                // liberta o espcao ocupado caso este nao posua mais ligacoes
                grafos[x] = 0;                                  // incica que esse grafo nao possui conexoes
            }
        } else if (operacao == '?') {

            for (int i = 0; i < x; i++) {
                scanf(" %d", &z);
                printf("%d\n", z);
//                ex = verificarConexao(grafos, y, z);
                printf("%d", ex);
                y = z;
            }
        }
    }

//        print das ligacoes dos nos
//    for (int i = 0; i < nSenesores; i++) {
//        printf("%d: ", i);
//        if (grafos[i] != 0) {
//            for (int j = 0; j < grafos[i]->nElementos; j++) {
//                printf("%d", grafos[i]->elementos[j]);
//            }
//        }
//        printf(" %d\n",grafos[i]->nElementos);
//    }
//    verificarConexao(grafos,1,3);
//    printf("%d\n",procura(3,grafos[1]->nElementos,grafos[1]->elementos));
}
