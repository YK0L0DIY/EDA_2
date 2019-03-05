#include <stdio.h>
#include <string.h>

#define NAMESIZE 21

struct team {                                       // struct
    char name[NAMESIZE];                            // nome da equipa
    int vitorias,                                   // numero de vitorias
            empates,                                // numero de empates
            derotas,                                // numero de derrotas
            golosMarcados,                          // numero de golos marcados
            golosSofridos,                          // numero de golos sofredos
            pontos;                                 // pontos da equipa
};

// funcao para quando a equipa sofre um empate
void empate(int indice, int golos, struct team *equipas, int pontos) {
    equipas[indice].empates++;                      // incrementa o numero de empates
    equipas[indice].golosMarcados += golos;         // incrementa os golos marcados
    equipas[indice].golosSofridos += golos;         // incrementa os golos sofridos
    equipas[indice].pontos += pontos;               // incrementa o numero depontos (+1) neste caso
}

// funcao que recebe as equipa vencedora e equipa perdedora
void vitoria(int indiceV, int indiceP, int golosV, int golosP, struct team *equipa, int pontos) {
    equipa[indiceV].vitorias++;                     // incrementa o numero de vitorias a equipa vendecora
    equipa[indiceV].golosMarcados += golosV;        // incrementa o numero de golos marcados a equipa vendedora
    equipa[indiceV].golosSofridos += golosP;        // incrementa o numero de golos sofridos a equipa vencedora
    equipa[indiceV].pontos += pontos;               // incrementa os popntos da equipa vencedora

    equipa[indiceP].derotas++;                      // incrementa o numero de derrotas da equipa derotada
    equipa[indiceP].golosMarcados += golosP;        // incremneta o numero de golos marcados da equipa perdedora
    equipa[indiceP].golosSofridos += golosV;        // incrementa o numero de golos sofridos da equipa perdedora
}

// funcao que calcula o indici em que a equipa esta no array
int indice(char name[NAMESIZE], struct team *equipas, int nEquipas) {
    for (int i = 0; i < nEquipas; i++) {
        if (strcmp(equipas[i].name, name) == 0) {
            return i;
        }
    }
    return 0;
}

// determina o vencedor do torneio
int winner(struct team *equipas, int numE) {
    int winnerI = 0, pontosW = 0, existe = 0;

    for (int i = 0; i < numE; i++) {                // procura a equipa com mais pontos
        if (equipas[i].pontos > pontosW) {
            winnerI = i;
            pontosW = equipas[i].pontos;
            existe = 0;                             // como o maximo foi atualizado este ainda e unico
        } else if (equipas[i].pontos == pontosW) {  // caso ja exista
            existe = 1;
        }
    }

    return (existe == 0 ? winnerI: -1);

}

int main(void) {
    int pontosPorV = 3,                             // pontos por vitoria
            pontosPorE = 1,                         // pontos por empate
            numEquipas,                             // numero de equipas
            numJogos,                               // numero de jogos
            indiceE1,                               // indice de equipa 1
            indiceE2,                               // indice de equipa 2
            golosE1,                                // golos equipa 1
            golosE2;                                // golos equipa 2

    char name1[NAMESIZE],                           // nome equipa 1
            name2[NAMESIZE];                        // nome equipa 2

    scanf("%d %d", &numEquipas, &numJogos);         // recebe o numero de equipas e numero de jogos

    struct team equipas[numEquipas];                // cria um array de structs de equipas

    for (int i = 0; i < numEquipas; i++) {          // recebe o nome de cada equipa e inicializa as variaveis
        scanf("%s", equipas[i].name);
        equipas[i].golosSofridos = 0;
        equipas[i].golosMarcados = 0;
        equipas[i].vitorias = 0;
        equipas[i].derotas = 0;
        equipas[i].empates = 0;
        equipas[i].pontos = 0;
    }

    for (int i = 0; i < numJogos; i++) {                            // recebe os jogos reaizados
        scanf("%s %d - %s %d", name1, &golosE1, name2, &golosE2);
        indiceE1 = indice(name1, equipas, numEquipas);              // calcula o indice da equipa 1
        indiceE2 = indice(name2, equipas, numEquipas);              // calcula o indice da equipa 2
        if (golosE1 == golosE2) {                                   // verifica se e empate
            empate(indiceE1, golosE1, equipas, pontosPorE);         // chama a funcao de empate a equipa 1
            empate(indiceE2, golosE1, equipas, pontosPorE);         // chama a funcao de empate a equipa 2
        } else
            golosE1 > golosE2 ?                                     // verifica qual foi a equipa que ganhou
            vitoria(indiceE1, indiceE2, golosE1, golosE2, equipas, pontosPorV) :
            vitoria(indiceE2, indiceE1, golosE2, golosE1, equipas, pontosPorV);
    }


    int index = winner(equipas, numEquipas);                // calcula o incdico do vencedor caso este exista
    if (index == -1)                                        // caso nao exista vencedor
        printf("torneio sem vencedora\n");

    else                                                    // caso exista vencedor
        printf("a vencedora foi %s, com %d ponto(s)\n"
               "ganhou %d jogo(s), empatou %d jogo(s) e perdeu %d jogo(s)\n"
               "marcou %d golo(s) e sofreu %d golo(s)\n",
               equipas[index].name, equipas[index].pontos,
               equipas[index].vitorias, equipas[index].empates, equipas[index].derotas,
               equipas[index].golosMarcados, equipas[index].golosSofridos);

    return 0;
}