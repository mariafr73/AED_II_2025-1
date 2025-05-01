#include "contato.h"

int main(){
    Contato contatos[100];
    int n = 0;
    char opcao;

    do {
        printf("Menu: \n");
        printf("1. Cadastrar contato\n");
        printf("2. Buscar contato\n");
        printf("3. Listar contatos\n");
        printf("4. Sair\n");
        printf("\nEscolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                cadastrar_contato(contatos, &n);
                break;
            case '2':
                buscar_contato(contatos, n);
                break;
            case '3':
                listar_contatos(contatos, n);
                break;
            case '4':
                printf("Saindo da agenda...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != '4');

    return 0;
}