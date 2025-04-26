#include <stdio.h>
#include <stdlib.h>

// Definições de cores ANSI
#define VERMELHO "\e[31m"
#define AZUL "\e[34m"
#define VERDE "\e[32m"
#define RESET "\e[0m"

// Função para calcular a potência usando apenas multiplicações
int potencia(int base, int expoente) {
    int resultado = 1;

    // Caso o expoente seja negativo
    if (expoente < 0) {
        printf(VERMELHO "Erro: expoente negativo não suportado." RESET "\n");
        return -1; // Indica erro
    }

    // Calcula a potência
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }

    return resultado;
}

int main() {
    char entrada[100];
    int base, expoente;

    while (1) {
        // Solicita a base ao usuário
        printf("Digite a base (ou 's' para sair): ");
        scanf(" %[^\n]", entrada);

        // Verifica se o usuário deseja sair
        if (entrada[0] == 's' || entrada[0] == 'S') {
            printf(AZUL "Saindo do programa." RESET "\n");
            break;
        }

        // Tenta converter a entrada para um número inteiro
        if (sscanf(entrada, "%d", &base) != 1) {
            printf(VERMELHO "Erro: entrada inválida. Por favor, insira um número inteiro." RESET "\n");
            continue;
        }

        // Solicita o expoente ao usuário
        printf("Digite o expoente (ou 's' para sair): ");
        scanf(" %[^\n]", entrada);

        // Verifica se o usuário deseja sair
        if (entrada[0] == 's' || entrada[0] == 'S') {
            printf(AZUL "Saindo do programa." RESET "\n");
            break;
        }

        // Tenta converter a entrada para um número inteiro
        if (sscanf(entrada, "%d", &expoente) != 1) {
            printf(VERMELHO "Erro: entrada inválida. Por favor, insira um número inteiro." RESET "\n");
            continue;
        }

        // Calcula e exibe o resultado
        int resultado = potencia(base, expoente);
        if (resultado != -1) {
            printf(VERDE "%d elevado a %d é %d" RESET "\n", base, expoente, resultado);
        }
    }

    return 0;
}