#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Coordenadas iniciais (linha, coluna)
    int linha_navio_horizontal = 2;
    int coluna_navio_horizontal = 4;

    int linha_navio_vertical = 5;
    int coluna_navio_vertical = 7;

    // Validando horizontal dentro do limite
    if (coluna_navio_horizontal + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = 3;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites!\n");
        return 1;
    }

    // Validando vertical dentro do limite e sem sobreposição
    int sobreposicao = 0;
    if (linha_navio_vertical + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] == 3) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = 3;
            }
        } else {
            printf("Erro: navios sobrepostos!\n");
            return 1;
        }
    } else {
        printf("Erro: navio vertical fora dos limites!\n");
        return 1;
    }

    // Exibindo o tabuleiro
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}