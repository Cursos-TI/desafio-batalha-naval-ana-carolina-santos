#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define OCUPADO 3
#define AGUA 0

int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

// Verifica se a posição está livre
int estaLivre(int linha, int coluna) {
    return tabuleiro[linha][coluna] == AGUA;
}

// Posiciona navio horizontal
int posicionarHorizontal(int linha, int coluna) {
    if (coluna + TAM_NAVIO > TAM_TABULEIRO)
        return 0;

    // Checa sobreposição
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (!estaLivre(linha, coluna + i))
            return 0;
    }

    // Marca navio no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = OCUPADO;
    }
    return 1;
}

// Posiciona navio vertical
int posicionarVertical(int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO)
        return 0;

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (!estaLivre(linha + i, coluna))
            return 0;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = OCUPADO;
    }
    return 1;
}

// Posiciona navio diagonal descendente ↘
int posicionarDiagonalDesc(int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna + TAM_NAVIO > TAM_TABULEIRO)
        return 0;

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (!estaLivre(linha + i, coluna + i))
            return 0;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = OCUPADO;
    }
    return 1;
}

// Posiciona navio diagonal ascendente ↗
int posicionarDiagonalAsc(int linha, int coluna) {
    if (linha - (TAM_NAVIO - 1) < 0 || coluna + TAM_NAVIO > TAM_TABULEIRO)
        return 0;

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (!estaLivre(linha - i, coluna + i))
            return 0;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha - i][coluna + i] = OCUPADO;
    }
    return 1;
}

// Exibe o tabuleiro no console
void exibirTabuleiro() {
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Definindo as coordenadas diretamente
    if (!posicionarHorizontal(2, 1))
        printf("Erro ao posicionar navio horizontal!\n");

    if (!posicionarVertical(5, 6))
        printf("Erro ao posicionar navio vertical!\n");

    if (!posicionarDiagonalDesc(0, 0))
        printf("Erro ao posicionar navio diagonal descendente!\n");

    if (!posicionarDiagonalAsc(9, 0))
        printf("Erro ao posicionar navio diagonal ascendente!\n");

    // Exibe o tabuleiro final
    exibirTabuleiro();

    return 0;
}