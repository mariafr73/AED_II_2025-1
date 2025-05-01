#include <stdio.h>
#include "produto.h"

int main() {
    Produto produtos[100];
    int n = 0, opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar produto\n");
        printf("2. Buscar produto\n");
        printf("3. Listar produtos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_produto(produtos, &n);
                break;
            case 2:
                buscar_produto(produtos, n);
                break;
            case 3:
                listar_produtos(produtos, n);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}