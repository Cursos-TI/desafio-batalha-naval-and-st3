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
    int navio2[3] = {7, 7, 7};

    // Posicionamento dos Navios no Tabuleiro
    // Navio horizontal
    tabuleiroNaval[3][3] = navio1[0];
    tabuleiroNaval[3][4] = navio1[1];
    tabuleiroNaval[3][5] = navio1[2];

    // Navio vertical
    tabuleiroNaval[5][1] = navio2[0];
    tabuleiroNaval[6][1] = navio2[1];
    tabuleiroNaval[7][1] = navio2[2];


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabuleiroNaval[i][j]);
        }
        printf("\n");
    }

    return 0;
}
