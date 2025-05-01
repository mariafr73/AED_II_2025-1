#include <stdio.h>

int main() {
    int matriz[4][4];
    int soma = 0;

    printf("Digite os elementos da matriz 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 4; i++) {
        soma += matriz[i][i]; // Soma dos elementos
    }

    printf("\nMatriz 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nA soma da diagonal principal é: %d\n", soma);

    return 0;
}