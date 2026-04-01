#include <stdio.h>

int main() {
    int tabuleiro[10][10];

    char linha[10] = {'A', 'B','C', 'D','E', 'F','G', 'H','I', 'J',};


    // preenche o tabuleiro com água (0)
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // posicionando os navios

    // vertical
    tabuleiro[6][3] = 3;
    tabuleiro[7][3] = 3;
    tabuleiro[8][3] = 3;
            
    // horizontal
    tabuleiro[1][6] = 3;
    tabuleiro[1][7] = 3;
    tabuleiro[1][8] = 3;


    // espaço inicial para alinhar com os números das linhas
    printf("   ");


    for (int letra = 0; letra < 10; letra++) {
        //imprimir o topo das letras
        printf("%c  ", linha[letra]);
    }

    printf("\n");

    //linha
    for(int i = 0; i < 10; i++) {

        // imprimir as linhas dos números de 1 a 10, com formatacao
        printf("%2d ",i + 1);

        // coluna
        for(int j = 0; j < 10; j++) {
            // imprime o valor 0 ou 3
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}