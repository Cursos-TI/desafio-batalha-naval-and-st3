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

    // Habilidades
    int habilidadeCone[7][7] = {
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };
    int habilidadeOctaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    int habilidadeCruz[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

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

    // Exibição do tabuleiro com as habilidades
    printf("Escolha uma das habilidades:\n");
    printf("1 - Cone\n");
    printf("2 - Cruz\n");
    printf("3 - Octaedro\n");

    int control;
    scanf("%d", &control);


    switch (control) {
        case 1:
            printf("Você escolheu a habilidade Cone.\n");

            // Iteração da habilidade Cone
            for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 7; j++) {
                    if (i >= 0 && i < 10 && j + 2 >= 0 && j + 2 < 10) {
                        if (tabuleiroNaval[i][j + 2] == 0) {
                            if (tabuleiroNaval[i][j + 2] != habilidadeCone[i][j]) {
                                tabuleiroNaval[i][j + 2] = habilidadeCone[i][j];
                            }
                        }
                        if (tabuleiroNaval[i][j + 2] == 3 && habilidadeCone[i][j] == 1) {
                            tabuleiroNaval[i][j + 2] = 5;
                        }
                    } else {
                        printf("Erro: Índice fora dos limites do tabuleiro.\n");
                        return -1;
                    }
                }
            }
            // Exibição do Tabuleiro com Cone
            printf("\nTabuleiro com Habilidade Cone:\n");
            printf("\n");

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    printf(" %d ", tabuleiroNaval[i][j]);
                }
                printf("\n");
            }

            break;
        case 2:
            printf("Você escolheu a habilidade Cruz.\n");

            // Iteração com Cruz
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (i + 3 >= 0 && i + 3 < 10 && j + 3 >= 0 && j + 3 < 10) {
                        if (tabuleiroNaval[3 + i][j + 3] == 0) {
                            if (tabuleiroNaval[3 + i][j + 3] != habilidadeCruz[i][j]) {
                                tabuleiroNaval[3 + i][j + 3] = habilidadeCruz[i][j];
                            }
                        }
                        if (tabuleiroNaval[3 + i][j + 3] == 3 && habilidadeCruz[i][j] == 1) {
                            tabuleiroNaval[3 + i][j + 3] = 5;
                        }
                    } else {
                        printf("Erro: Índice fora dos limites do tabuleiro.\n");
                        return -1;
                    }
                }
            }

            // Exibição do Tabuleiro com Cruz
            printf("\nTabuleiro com Habilidade Cruz:\n");
            printf("\n");

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    printf(" %d ", tabuleiroNaval[i][j]);
                }
                printf("\n");
            }

            break;
        case 3:
            printf("Você escolheu a habilidade Octaedro.\n");

            // Iteração com octaedro
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (i + 3 >= 0 && i + 3 < 10 && j + 3 >= 0 && j + 3 < 10) {
                            if (tabuleiroNaval[3 + i][j + 3] == 0) {
                                if (tabuleiroNaval[3 + i][j + 3] != habilidadeOctaedro[i][j]) {
                                    tabuleiroNaval[3 + i][j + 3] = habilidadeOctaedro[i][j];
                                }
                            }
                            if (tabuleiroNaval[3 + i][j + 3] == 3 && habilidadeOctaedro[i][j] == 1) {
                                tabuleiroNaval[3 + i][j + 3] = 5;
                            }
                        } else {
                            printf("Erro: Índice fora dos limites do tabuleiro.\n");
                            return -1;
                        }
                    }
                }

                printf("\nTabuleiro com Habilidade Octaedro:\n");
                printf("\n");

                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        printf(" %d ", tabuleiroNaval[i][j]);
                    }
                    printf("\n");
                }

            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            return -1;
    }

    return 0;
}
