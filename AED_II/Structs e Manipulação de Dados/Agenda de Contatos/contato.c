#include "contato.h"
#include <string.h>

void cadastrar_contato(Contato *contatos, int *n) {
    char opcao, opcao2;

    printf("\nDeseja cadastrar um contato? (S/N): ");
    scanf(" %c", &opcao);

    if (opcao != 'S' && opcao != 's') {
        printf("Voltando ao menu...\n");
        return;
    }
    
    do {
        printf("\nInforme o nome do contato: ");
        scanf(" %[^\n]", contatos[*n].nome);
        printf("Informe o número do contato: ");
        scanf(" %[^\n]", contatos[*n].numero);
        
        (*n)++; // Incrementa o contador de contatos
        printf("\nContato cadastrado com sucesso!\n");

        printf("\nDeseja cadastrar outro contato? (S/N): ");
        scanf(" %c", &opcao2);
    } while (opcao2 == 'S' || opcao2 == 's');
}

void buscar_contato(Contato *contatos, int n) {
    char nome[50], opcao;
    int encontrado = 0;
    
    do {
        printf("Informe o nome do contato que deseja buscar: ");
        scanf(" %[^\n]", nome);

        for (int i = 0; i < n; i++) {
            if (strcmp(contatos[i].nome, nome) == 0) {
                printf("\nContato encontrado:\n");
                printf("Nome: %s\n", contatos[i].nome);
                printf("Número: %s\n", contatos[i].numero);
                encontrado = 1;
            }
        }

        if (!encontrado) {
            printf("Contato com nome %s não encontrado.\n", nome);
        }

        printf("\nDeseja buscar outro contato? (S/N): ");
        scanf(" %c", &opcao);
    } while (opcao == 'S' || opcao == 's');
}

void listar_contatos(Contato *contatos, int n) {
    printf("\nLista de contatos:\n");
    for (int i = 0; i < n; i++) {
        printf("\nNome: %s \nNúmero: %s\n", contatos[i].nome, contatos[i].numero);
    }
}