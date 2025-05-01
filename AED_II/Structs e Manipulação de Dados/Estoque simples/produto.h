#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct produto {
    char nome[50];
    int codigo;
    int quantidade;
    float preco;
} Produto;

void cadastrar_produto(Produto *produtos, int *n);
void buscar_produto(Produto *produtos, int n);
void listar_produtos(Produto *produtos, int n);

#endif