#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se uma string é um palíndromo
int eh_palindromo(char str[]) {
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (inicio < fim) {
        // Ignora espaços e caracteres não alfanuméricos
        while (inicio < fim && !isalnum(str[inicio])) inicio++;
        while (inicio < fim && !isalnum(str[fim])) fim--;

        // Compara os caracteres (ignorando maiúsculas/minúsculas)
        if (tolower(str[inicio]) != tolower(str[fim])) {
            return 0; // Não é um palíndromo
        }

        inicio++;
        fim--;
    }

    return 1; // É um palíndromo
}

int main() {
    char str[100];

    printf("Digite uma string: ");
    scanf(" %[^\n]", str);

    if (eh_palindromo(str)) {
        printf("A palavra \"%s\" é um palíndromo.\n", str);
    } else {
        printf("A palavra \"%s\" não é um palíndromo.\n", str);
    }

    return 0;
}