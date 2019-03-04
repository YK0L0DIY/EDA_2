#include <stdio.h>
#include <string.h>

#define NAMESIZE 21

struct team {
    char name[NAMESIZE];
    int vitorias,
            empates,
            derotas,
            golosMarcados,
            golosSofridos,
            pontos;
};

void empate(int indice, int golos, struct team *equipas, int pontos) {
    equipas[indice].empates++;
    equipas[indice].golosMarcados += golos;
    equipas[indice].golosSofridos += golos;
    equipas[indice].pontos += pontos;
}

void vitoria(int indiceV, int indiceP, int golosV, int golosP, struct team *equipa, int pontos) {
    equipa[indiceV].vitorias++;
    equipa[indiceV].golosMarcados += golosV;
    equipa[indiceV].golosSofridos += golosP;
    equipa[indiceV].pontos += pontos;

    equipa[indiceP].derotas++;
    equipa[indiceP].golosMarcados += golosP;
    equipa[indiceP].golosSofridos += golosV;
}

int indice(char name[NAMESIZE], struct team *equipas, int nEquipas) {
    for (int i = 0; i < nEquipas; i++) {
        if (strcmp(equipas[i].name, name) == 0) {
            return i;
        }
    }
    return 0;
}

int winner(struct team *equipas, int numE) {
    int winnerI = 0, pontosW = 0;
    for (int i = 0; i < numE; i++) { //procura a equipa com mais pontos
        if (equipas[i].pontos >= pontosW) {
            winnerI = i;
            pontosW = equipas[i].pontos;
        }
    }
    for (int i = 0; i < numE; i++) { //verifica se é a unica com o mesmo numero de pontos
        if (equipas[i].pontos == pontosW && winnerI != i) {
            return -1;
        }
    }
    return winnerI;
}

int main(void) {
    int pontosPorV = 3,
            pontosPorE = 1,
            numEquipas,
            numJogos,
            indiceE1,
            indiceE2,
            golosE1,
            golosE2;

    char name1[NAMESIZE],
            name2[NAMESIZE];

    scanf("%d %d", &numEquipas, &numJogos);

    struct team equipas[numEquipas];

    for (int i = 0; i < numEquipas; i++) {
        scanf("%s", equipas[i].name);
        equipas[i].golosSofridos = 0;
        equipas[i].golosMarcados = 0;
        equipas[i].vitorias = 0;
        equipas[i].derotas = 0;
        equipas[i].empates = 0;
        equipas[i].pontos = 0;
    }

    for (int i = 0; i < numJogos; i++) {
        scanf("%s %d - %s %d", name1, &golosE1, name2, &golosE2);
        indiceE1 = indice(name1, equipas, numEquipas);
        indiceE2 = indice(name2, equipas, numEquipas);
        if (golosE1 == golosE2) {
            empate(indiceE1, golosE1, equipas, pontosPorE);
            empate(indiceE2, golosE1, equipas, pontosPorE);
        } else
            golosE1 > golosE2 ?
            vitoria(indiceE1, indiceE2, golosE1, golosE2, equipas, pontosPorV) :
            vitoria(indiceE2, indiceE1, golosE2, golosE1, equipas, pontosPorV);
    }


    int index = winner(equipas, numEquipas);
    if (index == -1)
        printf("torneio sem vencedora\n");

    else
        printf("a vencedora foi %s, com %d ponto(s)\n"
               "ganhou %d jogo(s), empatou %d jogo(s) e perdeu %d jogo(s)\n"
               "marcou %d golo(s) e sofreu %d golo(s)\n",
               equipas[index].name, equipas[index].pontos,
               equipas[index].vitorias, equipas[index].empates, equipas[index].derotas,
               equipas[index].golosMarcados, equipas[index].golosSofridos);

    return 0;
}