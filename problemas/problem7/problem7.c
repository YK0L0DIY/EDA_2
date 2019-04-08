#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANHOSTRINGS 56
#define NOMEFILE "db"

struct person {                                                 // estorota da pessoa
    int id,                                                     // id unico
            tel1, tel2,                                         // telemovel 1 e 2
            existe,                                             // flag para verificacao se tal existe an base de dados
            rendimento;                                         // rendimento
    char ori[TAMANHOSTRINGS],                                   // array para guardar a informacao sobre a orientaao politica
            habitos[TAMANHOSTRINGS];                            // array para guardar a informacao sobre os habitos
};

void go_to(int id, FILE *file) {                                // funcao para colocar o apontador na posicao pretendida
    fseek(file, (id * sizeof(struct person)), SEEK_SET);        // para fazer leitura
}

void write(struct person *p, FILE *file) {                      // funcao para escerver a estrotura no ficheiro
    fwrite(p, sizeof(struct person), 1, file);
}

void notExist(int id) {                                         // funcao para dar print caso nao exista o id pretendido
    printf("+ SUJEITO %06d desconhecido\n", id);
}

void addInfo(FILE *file) {                                      // funcao que e corrida caso o comando seja adicionar informacao
    struct person *p = malloc(sizeof(struct person));           // crai-se uma pessoa
    p->existe = 1;                                              // coloca-se a indicacao de que esta existe
    scanf(" %d", &p->id);                                       // recebe informcao do stardart input
    scanf(" %d %d", &p->tel1, &p->tel2);
    scanf(" %d", &p->rendimento);
    scanf(" %[^\n]c", p->ori);
    scanf(" %[^\n]c", p->habitos);
    go_to(p->id,file);                                          // coloca o apontador do ficherio para a posicao para onde uqer escrever
    write(p, file);                                             // escerve a estrutura no ficheiro
    free(p);                                                    // liberta o espaco coupado pela estrutura
}

void removeInfo(FILE *file) {                                   // funao para remover elemnto caso este exista
    int id;                                                     // para receber o id da pessoa que se pretede remover
    scanf(" %d", &id);                                          // recebe o input do id
    go_to(id, file);                                            // coloca o apontador para a posicoa coreta consoante o id
    struct person *p = malloc(sizeof(struct person));           // cria uma pessoa nova
    if (fread(p, sizeof(struct person), 1, file) == 1 && p->existe == 1) {  // verifica se esta a ler dentro do ficheiro e se sim , se essa pessoa existe
        p->existe = 0;                                          // indica que essa nao vai existir
        go_to(id, file);                                        // volta a ir para a posicao correta para ler a pessoa
        write(p, file);                                         // reescreve a pessoa
    } else
        notExist(id);                                           // caso va ler fora do ficheiro ou essa pesso anao exista da print que a pessoa com esse id nao existe
    free(p);                                                    // liberta o espaço ocupado pela pessoa
}

void getInfo(FILE *file) {                                      // funcao para verificar a informacao da pessoa
    int id;                                                     // para rewceber o id da pessoa a ser verificado
    scanf(" %d", &id);                                          // recebe o input do id da pessoa
    struct person p;                                            // criase uma estrotura de pessoa para recceber a informacao da base de dados
    go_to(id, file);                                            // coloca o ponteiro na osicao correta
    if (fread(&p, sizeof(struct person), 1, file) == 1 && p.existe == 1) {  // verifica se esta a ler dentro do fichiero e a pessoa petendida existe
        printf("+ SUJEITO %06d\n%d %d\n%d\n%s\n%s\n", p.id, p.tel1, p.tel2, p.rendimento, p.ori, p.habitos);    // print da informcao sobre a pessoa
        return;
    }
    notExist(id);                                               // caso conrario se for ler fora do ficheiro ou a pessoa nao existir da pritn que nao existe
}

int main(void) {
    char option;                                                // para recevber a opcao pretendida
    FILE *file;
    file = fopen(NOMEFILE, "r+");                               // are o ficheiro
    if (file == NULL) {                                         // caso ele nao exista
        file = fopen(NOMEFILE, "w+");                           // criase um fichiero novo
    }
    while (scanf("%c", &option) != EOF) {                       // corre ate ao final do ficheiro de input
        switch (option) {                                       // verifica-se as opcoes pretendidas
            case '+':
                addInfo(file);
                break;
            case '-':
                removeInfo(file);
                break;
            case '?':
                getInfo(file);
                break;
            default:
                break;
        }
    }
    fclose(file);                                               // fecha o ficheiro
}