#include <stdio.h>

// Função para inverter os dígitos de um número
int inverterNumero(int numero) {
    int invertido = 0, digito;

    while (numero != 0) {
        digito = numero % 10; // Obtém o último dígito
        invertido = invertido * 10 + digito; // Adiciona o dígito ao número invertido
        numero /= 10; // Remove o último dígito do número original
    }

    return invertido;
}

int main() {
    int numero, resultado;

    // Solicitar ao usuário um número
    printf("Digite um número: ");
    scanf("%d", &numero);

    // Calcular e exibir o número invertido
    resultado = inverterNumero(numero);
    printf("O número invertido é: %d\n", resultado);

    return 0;
}