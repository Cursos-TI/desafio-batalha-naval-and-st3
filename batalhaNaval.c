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
    for (int i = 0; i < 3; i++) {
        int x = 3;
        if (i >= 0 && i <= 10 && x >= 0 && x < 10) {
            tabuleiroNaval[x][3 + i] = navio1[i];
        } else{
            printf("Erro: Índice fora dos limites do tabuleiro.\n");
            return -1;
        }
    }
    
    // Navio vertical
    for (int i = 0; i < 3; i++) {
        int y = 1;
        if (i >= 0 && i <= 10 && y >= 0 && y < 10) {
            tabuleiroNaval[5 + i][y] = navio2[i]; 
        } else{
            printf("Erro: Índice fora dos limites do tabuleiro.\n");
            return -1;
        }
    }

    // Navios Diagonais
    for (int k = 0; k < 3; k++) {
        int x = 6 + k;
        int y = 7 + k;
        if (x >= 0 && x < 10 && y >= 0 && y < 10) {
            tabuleiroNaval[x][y] = navio3[k];
        } else{
            printf("Erro: Índice fora dos limites do tabuleiro.\n");
            return -1;
        }
    }

    
    for (int k = 0; k < 3; k++) {
        int x = 5 + k;
        int y = 3 + k;
        if (x >= 0 && x < 10 && y >= 0 && y < 10) {
            tabuleiroNaval[x][8 - y] = navio4[k];
        } else{
            printf("Erro: Índice fora dos limites do tabuleiro.\n");
            return -1;
        }
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
