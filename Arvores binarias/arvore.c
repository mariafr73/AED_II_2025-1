#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura básica da árvore binária
typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

// Estrutura para árvore de alunos
typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerdo;
    struct Aluno* direito;
} Aluno;

// Funções básicas para árvore de inteiros
No* criarNo(int c) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->dado = c;
        novoNo->esquerdo = NULL;
        novoNo->direito = NULL;
    }
    return novoNo;
}

void removerArvore(No* T) {
    if (T != NULL) {
        removerArvore(T->esquerdo);
        removerArvore(T->direito);
        free(T);
    }
}

No* buscar(No* T, int c) {
    if (T == NULL) {
        return NULL;
    }
    if (T->dado == c) {
        return T;
    }
    if (c < T->dado) {
        return buscar(T->esquerdo, c);
    } else {
        return buscar(T->direito, c);
    }
}

No* inserir(No* T, int c) {
    if (T == NULL) {
        return criarNo(c);
    }
    if (c < T->dado) {
        T->esquerdo = inserir(T->esquerdo, c);
    } else if (c > T->dado) {
        T->direito = inserir(T->direito, c);
    }
    return T;
}

// Percursos para árvore de inteiros
void inOrdem(No* T) {
    if (T != NULL) {
        inOrdem(T->esquerdo);
        printf("%d ", T->dado);
        inOrdem(T->direito);
    }
}

void preOrdem(No* T) {
    if (T != NULL) {
        printf("%d ", T->dado);
        preOrdem(T->esquerdo);
        preOrdem(T->direito);
    }
}

void posOrdem(No* T) {
    if (T != NULL) {
        posOrdem(T->esquerdo);
        posOrdem(T->direito);
        printf("%d ", T->dado);
    }
}

// Operações avançadas para inteiros
int altura(No* T) {
    if (T == NULL) {
        return -1;
    } else {
        int alturaEsq = altura(T->esquerdo);
        int alturaDir = altura(T->direito);
        return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
    }
}

int profundidade(No* T, int c, int nivel) {
    if (T == NULL) {
        return -1;
    }
    if (T->dado == c) {
        return nivel;
    }
    int profEsq = profundidade(T->esquerdo, c, nivel + 1);
    if (profEsq != -1) {
        return profEsq;
    }
    return profundidade(T->direito, c, nivel + 1);
}

int soma(No* T) {
    if (T == NULL) {
        return 0;
    }
    return T->dado + soma(T->esquerdo) + soma(T->direito);
}

int nivel(No* T, int c) {
    return profundidade(T, c, 0);
}

int contarNos(No* T) {
    if (T == NULL) {
        return 0;
    }
    return 1 + contarNos(T->esquerdo) + contarNos(T->direito);
}

int contarFolhas(No* T) {
    if (T == NULL) {
        return 0;
    }
    if (T->esquerdo == NULL && T->direito == NULL) {
        return 1;
    }
    return contarFolhas(T->esquerdo) + contarFolhas(T->direito);
}

// Funções para árvore de alunos
Aluno* criarAluno(const char* nome, int matricula, float nota) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    if (novoAluno != NULL) {
        strncpy(novoAluno->nome, nome, 49);
        novoAluno->nome[49] = '\0';
        novoAluno->matricula = matricula;
        novoAluno->nota = nota;
        novoAluno->esquerdo = NULL;
        novoAluno->direito = NULL;
    }
    return novoAluno;
}

Aluno* inserirAluno(Aluno* T, const char* nome, int matricula, float nota) {
    if (T == NULL) {
        return criarAluno(nome, matricula, nota);
    }
    int cmp = strcmp(nome, T->nome);
    if (cmp < 0) {
        T->esquerdo = inserirAluno(T->esquerdo, nome, matricula, nota);
    } else if (cmp > 0) {
        T->direito = inserirAluno(T->direito, nome, matricula, nota);
    }
    return T;
}

Aluno* buscarAlunoPorNome(Aluno* T, const char* nome) {
    if (T == NULL) {
        return NULL;
    }
    int cmp = strcmp(nome, T->nome);
    if (cmp == 0) {
        return T;
    } else if (cmp < 0) {
        return buscarAlunoPorNome(T->esquerdo, nome);
    } else {
        return buscarAlunoPorNome(T->direito, nome);
    }
}

// Percursos para árvore de alunos
void inOrdemAlunos(Aluno* T) {
    if (T != NULL) {
        inOrdemAlunos(T->esquerdo);
        printf("\n Nome: %s\n Matrícula: %d\n Nota: %.2f\n", T->nome, T->matricula, T->nota);
        inOrdemAlunos(T->direito);
    }
}

void preOrdemAlunos(Aluno* T) {
    if (T != NULL) {
        printf("\n Nome: %s\n Matrícula: %d\n Nota: %.2f\n", T->nome, T->matricula, T->nota);
        preOrdemAlunos(T->esquerdo);
        preOrdemAlunos(T->direito);
    }
}

void posOrdemAlunos(Aluno* T) {
    if (T != NULL) {
        posOrdemAlunos(T->esquerdo);
        posOrdemAlunos(T->direito);
        printf("\n Nome: %s\n Matrícula: %d\n Nota: %.2f\n", T->nome, T->matricula, T->nota);
    }
}

// Operações avançadas para alunos
int alturaAlunos(Aluno* T) {
    if (T == NULL) {
        return -1;
    } else {
        int alturaEsq = alturaAlunos(T->esquerdo);
        int alturaDir = alturaAlunos(T->direito);
        return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
    }
}

int contarAlunos(Aluno* T) {
    if (T == NULL) {
        return 0;
    }
    return 1 + contarAlunos(T->esquerdo) + contarAlunos(T->direito);
}

int contarFolhasAlunos(Aluno* T) {
    if (T == NULL) {
        return 0;
    }
    if (T->esquerdo == NULL && T->direito == NULL) {
        return 1;
    }
    return contarFolhasAlunos(T->esquerdo) + contarFolhasAlunos(T->direito);
}

void calcularMediaAux(Aluno* T, float* soma, int* contador) {
    if (T != NULL) {
        *soma += T->nota;
        (*contador)++;
        calcularMediaAux(T->esquerdo, soma, contador);
        calcularMediaAux(T->direito, soma, contador);
    }
}

float calcularMedia(Aluno* T) {
    float soma = 0;
    int contador = 0;
    calcularMediaAux(T, &soma, &contador);
    return contador > 0 ? soma / contador : 0;
}

// Função principal
int main() {
    printf("\n=== ÁRVORE DE INTEIROS ===\n");
    
    No* arvore = NULL;
    
    // Inserção de valores na árvore de inteiros
    arvore = inserir(arvore, 50);
    inserir(arvore, 30);
    inserir(arvore, 70);
    inserir(arvore, 20);
    inserir(arvore, 40);
    inserir(arvore, 60);
    inserir(arvore, 80);
    
    // Percursos
    printf("\nIn-ordem: ");
    inOrdem(arvore);
    printf("\nPré-ordem: ");
    preOrdem(arvore);
    printf("\nPós-ordem: ");
    posOrdem(arvore);
    
    // Estatísticas
    printf("\n\nAltura: %d", altura(arvore));
    printf("\nNúmero de nós: %d", contarNos(arvore));
    printf("\nNúmero de folhas: %d", contarFolhas(arvore));
    printf("\nSoma dos valores: %d", soma(arvore));
    
    // Busca
    int valor = 40;
    No* encontrado = buscar(arvore, valor);
    if (encontrado) {
        printf("\n\nValor %d encontrado no nível %d", valor, nivel(arvore, valor));
    } else {
        printf("\n\nValor %d não encontrado", valor);
    }
    
    // Liberar memória
    removerArvore(arvore);
    
    printf("\n\n=== ÁRVORE DE ALUNOS ===\n");
    Aluno* arvoreAlunos = NULL;
    
    // Inserção de alunos
    arvoreAlunos = inserirAluno(arvoreAlunos, "João", 1001, 8.5);
    inserirAluno(arvoreAlunos, "Maria", 1002, 9.0);
    inserirAluno(arvoreAlunos, "Pedro", 1003, 7.5);
    inserirAluno(arvoreAlunos, "Ana", 1004, 8.0);
    inserirAluno(arvoreAlunos, "Carlos", 1005, 6.5);
    
    // Percursos
    printf("\nIn-ordem:\n");
    inOrdemAlunos(arvoreAlunos);
    
    printf("\nPré-ordem:\n");
    preOrdemAlunos(arvoreAlunos);
    
    printf("\nPós-ordem:\n");
    posOrdemAlunos(arvoreAlunos);
    
    // Estatísticas
    printf("\nAltura: %d", alturaAlunos(arvoreAlunos));
    printf("\nNúmero de alunos: %d", contarAlunos(arvoreAlunos));
    printf("\nNúmero de folhas: %d", contarFolhasAlunos(arvoreAlunos));
    
    // Busca por nome
    const char* nomeBusca = "Maria";
    Aluno* alunoEncontrado = buscarAlunoPorNome(arvoreAlunos, nomeBusca);
    printf("\n\nBusca por '%s': \n", nomeBusca);
    if (alunoEncontrado) {
        printf(" Nome: %s\n Matrícula: %d\n Nota: %.2f\n", 
               alunoEncontrado->nome, alunoEncontrado->matricula, alunoEncontrado->nota);
    } else {
        printf("Aluno não encontrado.\n");
    }
    
    // Cálculo da média
    printf("\nMédia das notas: %.2f\n", calcularMedia(arvoreAlunos));
    
    return 0;
}