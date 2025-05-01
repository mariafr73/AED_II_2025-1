#include "produto.h"

void cadastrar_produto(Produto *produtos, int *n) {
    char opcao, opcao2;

    printf("\nDeseja cadastrar um produto? (S/N): ");
    scanf(" %c", &opcao);

    if (opcao != 'S' && opcao != 's') {
        printf("Voltando ao menu...\n");
        return;
    }
    
    do {
        printf("\nInforme o nome do produto: ");
        scanf(" %[^\n]", produtos[*n].nome);
        printf("Informe o código do produto: ");
        scanf("%d", &produtos[*n].codigo);
        printf("Informe a quantidade do produto: ");
        scanf("%d", &produtos[*n].quantidade);
        printf("Informe o preço do produto: ");
        scanf("%f", &produtos[*n].preco);
        
        (*n)++; // Incrementa o contador de produtos
        printf("\nProduto cadastrado com sucesso!\n");

        printf("\nDeseja cadastrar outro produto? (S/N): ");
        scanf(" %c", &opcao2);
    } while (opcao2 == 'S' || opcao2 == 's');
}

void buscar_produto(Produto *produtos, int n) {
    int codigo, encontrado = 0;
    char opcao;
    
    do {
        printf("Informe o código do produto que deseja buscar: ");
        scanf("%d", &codigo);

        for (int i = 0; i < n; i++) {
            if (produtos[i].codigo == codigo) {
                printf("\nProduto encontrado:\n");
                printf("Nome: %s\n", produtos[i].nome);
                printf("Código: %d\n", produtos[i].codigo);
                printf("Quantidade: %d\n", produtos[i].quantidade);
                printf("Preço: %.2f\n", produtos[i].preco);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Produto com código %d não encontrado.\n", codigo);
        }

        printf("\nDeseja buscar outro produto? (S/N): ");
        scanf(" %c", &opcao);
    } while (opcao == 'S' || opcao == 's');
}

void listar_produtos(Produto *produtos, int n) {
    if (n == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\nLista de produtos:\n");
    for (int i = 0; i < n; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Código: %d\n", produtos[i].codigo);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("Preço: %.2f\n", produtos[i].preco);
        printf("\n");
    }
}