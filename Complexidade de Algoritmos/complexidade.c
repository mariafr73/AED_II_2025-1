#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_N 100

// 1. Função recursiva otimizada
int fibonacci_recursivo(int n) {
    if (n <= 1) return 1;
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

// 2. Variáveis para memoização
int memo[MAX_N];

void inicializar_memo() {
    memset(memo, 0, sizeof(memo));
}

// 3. Versão iterativa sem recursão
int fibonacci_iterativo(int n) {
    if (n <= 1) return 1;

    int a = 1, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// 4. Versão com fórmula fechada (Binet)
int fibonacci_binet(int n) {
    double phi = (1 + sqrt(5)) / 2;
    return (int)round(pow(phi, n + 1) / sqrt(5));
}

// 5. Função para medir o tempo médio de execução
double medir_tempo(int (*funcao)(int), int n, int repeticoes) {
    double total = 0;
    for (int i = 0; i < repeticoes; i++) {
        clock_t start = clock();
        funcao(n);
        clock_t end = clock();
        total += (double)(end - start) / CLOCKS_PER_SEC;
    }
    return total / repeticoes;
}

// 6. Gerar dados para análise
void gerar_dados_comparativos() {
    int repeticoes = 1000;
    int valores_n[] = {5, 10, 15, 20, 25, 30, 35, 40};
    int num_valores = sizeof(valores_n) / sizeof(valores_n[0]);

    printf("n,Recursivo,Iterativo,Formula\n");

    for (int i = 0; i < num_valores; i++) {
        int n = valores_n[i];
        double t_recursivo = 0, t_iterativo = 0, t_binet = 0;

        // Medir recursivo (limitado por desempenho)
        if (n <= 35) {
            t_recursivo = medir_tempo(fibonacci_recursivo, n, repeticoes);
        }

        // Medir iterativo
        t_iterativo = medir_tempo(fibonacci_iterativo, n, repeticoes);

        // Medir fórmula fechada (Binet)
        t_binet = medir_tempo(fibonacci_binet, n, repeticoes);

        printf("%d,%.6f,%.6f,%.6f\n", n, t_recursivo, t_iterativo, t_binet);
    }
}

// 7. Função principal
int main() {
    inicializar_memo();

    printf("=== Análise de Complexidade de Algoritmos ===\n");
    printf("=== Comparação entre versões recursiva, iterativa e fórmula fechada ===\n\n");

    printf("Gerando dados para os gráficos...\n");
    gerar_dados_comparativos();

    printf("\nDados gerados com sucesso!\n");
    printf("Copie a saída para um arquivo CSV e importe no Excel, Python ou R para gerar os gráficos.\n");

    return 0;
}