#include <stdio.h>
#include <stdlib.h>  // <- necessário para a função abs()


#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
#define TAM_NAVIO 3

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

// Exibe tabuleiro com caracteres visuais
void exibirTabuleiro() {
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA)
                printf("~ ");
            else if (tabuleiro[i][j] == NAVIO)
                printf("# ");
            else if (tabuleiro[i][j] == HABILIDADE)
                printf("* ");
            else
                printf("? ");
        }
        printf("\n");
    }
}

// Posiciona navio horizontal
void posicionarHorizontal(int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
}

// Posiciona navio vertical
void posicionarVertical(int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
}

// Constrói matriz cone (ponta no topo)
void construirCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Constrói matriz cruz
void construirCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Constrói matriz octaedro (losango)
void construirOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Aplica matriz de habilidade ao tabuleiro no ponto de origem
void aplicarHabilidade(int origemLinha, int origemColuna, int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int tabLinha = origemLinha - meio + i;
            int tabColuna = origemColuna - meio + j;

            // Valida limites
            if (tabLinha >= 0 && tabLinha < TAM_TABULEIRO && tabColuna >= 0 && tabColuna < TAM_TABULEIRO) {
                if (matriz[i][j] == 1 && tabuleiro[tabLinha][tabColuna] != NAVIO)
                    tabuleiro[tabLinha][tabColuna] = HABILIDADE;
            }
        }
    }
}

int main() {
    // Posiciona navios fixos
    posicionarHorizontal(2, 1);
    posicionarVertical(5, 6);

    // Matrizes de habilidade
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // Constrói formas
    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // Aplica habilidades no tabuleiro
    aplicarHabilidade(4, 4, cone);       // cone centrado em (4,4)
    aplicarHabilidade(7, 7, cruz);       // cruz centrada em (7,7)
    aplicarHabilidade(2, 8, octaedro);   // octaedro centrado em (2,8)

    // Exibe resultado final
    exibirTabuleiro();

    return 0;
}
