#include <stdio.h>
#include <stdlib.h>

typedef struct contato {
    char nome[50];
    char numero[15];
} Contato;

void cadastrar_contato(Contato *contatos, int *n);
void buscar_contato(Contato *contatos, int n);
void listar_contatos(Contato *contatos, int n);