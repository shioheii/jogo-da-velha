#include<stdio.h>

// Bruno Shiohei Kinoshita do Nascimento - 176475 - NB

char verificaSeAlguemGanhou(char jogo[3][3]) {
    for (int i = 0; i < 3; i++) {
        // Verifica por linha
        if (jogo[i][0] == jogo[i][1] && jogo[i][1] == jogo[i][2] && jogo[i][0] != '\0') return jogo[i][0];

        // Verifica por coluna
        if (jogo[0][i] == jogo[1][i] && jogo[1][i] == jogo[2][i] && jogo[0][i] != '\0') return jogo[0][i];
    }

    // Verifica as diagonais
    if (jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2] && jogo[0][0] != '\0') return jogo[0][0];
    if (jogo[0][2] == jogo[1][1] && jogo[1][1] == jogo[2][0] && jogo[0][2] != '\0') return jogo[0][2];

    return ' ';
}

int main(){
    char jogoDaVelha[3][3];
    int jogador = 1;

    for (int rodadas = 0; rodadas < 9; rodadas++) {
        int x, y;

        int repeteCoordenadas = 1;
        while (repeteCoordenadas) {
            printf("Jogador %d digite a linha: ", jogador ? 1 : 2);
            scanf("%d", &x);
            x--;
            printf("Jogador %d digite a coluna: ", jogador ? 1 : 2);
            scanf("%d", &y);
            y--;

            // Se a posição não estiver ocupada, sai do laço
            if (jogoDaVelha[x][y] == '\0') break;
               
            printf("\n** INFORME UM LUGAR VAZIO **\n\n");
        }

        jogoDaVelha[x][y] = jogador ? 'X' : 'O';
        jogador = !jogador;

        // Mostra o jogo da velha no console
        printf("\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (j == 0) printf(" ");
                printf("%c", jogoDaVelha[i][j] != '\0' ? jogoDaVelha[i][j] : ' ');
                if (j != 2) printf(" | ");
            }
            printf("\n");
            if (i != 2) printf("---+---+---\n");
        }
        printf("\n");

        // Verifica se algum jogador ganhou a partir da quinta rodada 
        if (rodadas >= 4) {
            char vencedor = verificaSeAlguemGanhou(jogoDaVelha);
            if (vencedor != ' ') {
                printf("** O JOGADOR %d [%c] GANHOU **", vencedor == 'X' ? 1 : 2, vencedor);
                return 0;
            }
        }
    }
    printf("** DEU VELHA **");
    return 0;
}
