#include <stdio.h>

int main() {
    int vet1[5], vet2[5], i, j;

    printf("Digite 5 numeros para o primeiro vetor:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &vet1[i]);
    }

    printf("Digite 5 numeros para o segundo vetor:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &vet2[i]);
    }

    printf("Elementos comuns entre os dois vetores:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (vet1[i] == vet2[j]) {
                printf("%d ", vet1[i]);
                break; // Evita duplicar a exibição do mesmo número
            }
        }
    }

    printf("\n");
    return 0;
}