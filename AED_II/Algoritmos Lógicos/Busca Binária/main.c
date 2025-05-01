#include <stdio.h>

// Função para realizar a busca binária
int busca_binaria(int vetor[], int tamanho, int chave) {
    int inicio = 0, fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == chave) {
            return meio; // Retorna o índice onde a chave foi encontrada
        } else if (vetor[meio] < chave) {
            inicio = meio + 1; // Ajusta o início para a metade superior
        } else {
            fim = meio - 1; // Ajusta o fim para a metade inferior
        }
    }

    return -1; // Retorna -1 se a chave não for encontrada
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int chave;

    printf("Digite o número que deseja buscar: ");
    scanf("%d", &chave);

    int resultado = busca_binaria(vetor, tamanho, chave);

    if (resultado != -1) {
        printf("Número %d encontrado no índice %d.\n", chave, resultado);
    } else {
        printf("Número %d não encontrado no vetor.\n", chave);
    }

    return 0;
}