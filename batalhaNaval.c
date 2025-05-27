#include <stdio.h>

int main() {
    
    // Declaração do Tabuleiro e dos Navios
    int tabuleiroNaval[10][10] = {

    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

    };
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int navio3[3] = {3, 3, 3}; // Navio diagonal
    int navio4[3] = {3, 3, 3}; // Navio diagonal

    // Posicionamento dos Navios no Tabuleiro
    // Navio horizontal
    tabuleiroNaval[3][3] = navio1[0];
    tabuleiroNaval[3][4] = navio1[1];
    tabuleiroNaval[3][5] = navio1[2];

    // Navio vertical
    tabuleiroNaval[5][1] = navio2[0];
    tabuleiroNaval[6][1] = navio2[1];
    tabuleiroNaval[7][1] = navio2[2];

    // Navios Diagonais
    for (int x = 0; x < 3; x++) {
        tabuleiroNaval[5 + x][x + 3] = navio3[x];
    }

    for (int y = 0; y < 3; y++) {
        tabuleiroNaval[6 + y][9 - y] = navio4[y];
    }

    // Exibição do Tabuleiro
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabuleiroNaval[i][j]);
        }
        printf("\n");
    }

    return 0;
}
