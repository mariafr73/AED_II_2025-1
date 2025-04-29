#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define VERMELHO "\e[31m"
#define VERDE "\e[32m"
#define RESET "\e[0m"

// Função para verificar se um número é primo
bool ehPrimo(int n) {
    if (n < 2) {
        return false; // Números menores que 2 não são primos
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Função para verificar se a string contém apenas numeros
bool ehNumeroValido(const char *str) {
    char *ptr;
    strtol(str, &ptr, 10);
    return *ptr == '\0';
}

// Função para verificar entrada válida
int lerNumero(const char *mensagem) {
    char entrada[100];
    int numero;

    while (true) {
        printf("%s", mensagem);
        scanf(" %[^\n]", entrada);

        if (ehNumeroValido(entrada)) {
            numero = atoi(entrada); // Converte a string para inteiro
            return numero;
        } else {
            printf(VERMELHO "Erro: entrada inválida. Por favor, insira um número inteiro." RESET "\n");
        }
    }
}

int main() {
    int x, y;

    // Solicitar ao usuário os limites do intervalo com validação
    x = lerNumero("Digite o início do intervalo: ");
    y = lerNumero("Digite o fim do intervalo: ");

    // Lista os números primos no intervalo
    printf("Números primos entre %d e %d: \n", x, y);
    for (int i = x; i <= y; i++) {
        if (ehPrimo(i)) {
            printf(VERDE "%d "RESET , i);
        }
    }
    printf("\n");

    return 0;
}