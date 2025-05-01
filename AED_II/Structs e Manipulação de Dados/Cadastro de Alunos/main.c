#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERMELHO "\e[31m"
#define VERDE "\e[32m"
#define AMARELO "\e[33m"
#define RESET "\e[0m"

typedef struct aluno {
    char nome[50];
    int matricula;
    float media;
} Aluno;

void preenche_aluno(Aluno *aluno) {
    float n1, n2, n3;
    printf("Nome: \t");
    scanf(" %[^\n]", aluno->nome);
    printf("Matricula: \t");
    scanf("%d", &aluno->matricula);
    printf("Informe as 3 notas: \n");
    printf("Nota 1: \t");
    scanf("%f", &n1);
    printf("Nota 2: \t");
    scanf("%f", &n2);
    printf("Nota 3: \t");
    scanf("%f", &n3);
    aluno->media = (n1 + n2 + n3) / 3;
    printf("Media: %.2f\n", aluno->media);
}

void aluno_aprovado(Aluno *aluno) {
    if (aluno->media >= 7.0) {
        printf(VERDE "Aprovado\n" RESET);
    } else if (aluno->media >= 5.0) {
        printf(AMARELO "Recuperacao\n" RESET);
    } else {
        printf(VERMELHO "Reprovado\n" RESET);
    }
}

void imprime_aluno(Aluno *aluno) {
    printf("Nome: %s\n", aluno->nome);
    printf("Matricula: %d\n", aluno->matricula);
    printf("Media: %.2f\n", aluno->media);
    aluno_aprovado(aluno);
}

int main() {
    int n;

    printf("Informe o numero de alunos: ");
    scanf("%d", &n);
    Aluno alunos[n];
    for (int i = 0; i < n; i++) {
        printf("\nInforme os dados do aluno %d:\n", i + 1);
        preenche_aluno(&alunos[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("\nDados do aluno %d:\n", i + 1);
        imprime_aluno(&alunos[i]);
    }
    printf("\n");

    return 0;
}