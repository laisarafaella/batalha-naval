#include <stdio.h>

int main() {
    int tabuleiro[10][10];

    int cruz[5][5];
    int cone[5][5];
    int octaedro[5][5];

    // meio
    int linhaCruz = 5, colunaCruz = 5;
    // cima / esquerda
    int linhaCone = 2, colunaCone = 2;
    // embaixo / direita
    int linhaOctaedro = 7, colunaOctaedro = 7;

    char linha[10] = {'A', 'B','C', 'D','E', 'F','G', 'H','I', 'J',};


    // preenche o tabuleiro com água (0)
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // posicionando os navios

    // vertical

    for (int i = 0; i < 3; i++) {
        tabuleiro[6 + i][3] = 3;
    }

    //tabuleiro[6][3] = 3;
    //tabuleiro[7][3] = 3;
    //tabuleiro[8][3] = 3;
            
    // horizontal

    for (int i = 0; i < 3; i++) {
        tabuleiro[1][6 + i] = 3;
    }

    //tabuleiro[1][6] = 3;
    //tabuleiro[1][7] = 3;
    //tabuleiro[1][8] = 3;

    
    // diagonal principal

    for (int k = 0; k < 3; k++) {
        tabuleiro[k][k] = 3;
    }

    //tabuleiro[0][0] = 3;
    //tabuleiro[1][1] = 3;
    //tabuleiro[2][2] = 3;

    // diagonal secundária
    for (int k = 0; k < 3; k++) {
        tabuleiro[2 + k][7 - k] = 3;
    }

    //tabuleiro[2][7] = 3;
    //tabuleiro[3][6] = 3;
    //tabuleiro[4][5] = 3;


    // habilidades

    // cone
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            // topo do cone - limita a metade superior
            // lado esquerdo cresce
            // lado direito cresce
            if (i <= 2 && j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // DEBUG - visulizar matriz cone
    /* for (int i = 0; i < 5; i++) {
         for (int j = 0; j < 5; j++) {
            printf("%d  ", cone[i][j]);
        }
        printf("\n");
     }*/

    // posicionar cone no tabuleiro

    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (cone[i][j] == 1) {
                // converte as coordenadas
                int linhas = linhaCone + (i - 2);
                int colunas = colunaCone + (j - 2);

                // verifica se está dentro do tabuleiro
                if (linhas >= 0 && linhas < 10 && colunas >= 0 && colunas < 10) {

                    // nao sobrescrever o navio
                    if (tabuleiro[linhas][colunas] == 0) {

                        tabuleiro[linhas][colunas] = 5;
                    }
                }
            }
        }
    }


    // cruz

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            // linha do meio
            // coluna do meio
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // DEBUG - visualizar matriz cruz
    /* for (int i = 0; i < 5; i++) {
         for (int j = 0; j < 5; j++) {
            printf("%d  ", cruz[i][j]);
        }
        printf("\n");
     }*/

    // posicionar a cruz no tabuleiro

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (cruz[i][j] == 1) {
                int linhas = linhaCruz + (i - 2);
                int colunas = colunaCruz + (j - 2);

                if (linhas >= 0 && linhas < 10 && colunas >= 0 && colunas < 10) {

                    if (tabuleiro[linhas][colunas] == 0) {
                        tabuleiro[linhas][colunas] = 5;
                    }
                }
            }
        }
    }



    // octaedro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            // parte de cima até o meio
            // vai expandindo

            // parte de baixo depois do meio
            //comeca a fechar
            if ((i <= 2 && j >= 2 - i && j <= 2 + i ) || (i > 2 && j >= i - 2 && j <= 6 - i)) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // DEBUG - visualizar matriz octaedro
    /* for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d  ", octaedro[i][j]);
        }
         printf("\n");
     }*/

    // posicionar octaedro no tabuleiro
    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < 5; j++) {

            if (octaedro[i][j] == 1) {
                int linhas = linhaOctaedro + (i - 2);
                int colunas = colunaOctaedro + (j - 2);

                if (linhas >= 0 && linhas < 10 && colunas >= 0 && colunas < 10) {

                    if (tabuleiro[linhas][colunas] == 0) {
                        tabuleiro[linhas][colunas] = 5;
                    }
                }
            }
        }
    }


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