#include <stdio.h>

int main(){
    int mat1[3][3], mat2[3][3];
    int i, j;

    printf("Digite os elementos da primeira matriz 3x3: \n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Digite os elementos da segunda matriz 3x3: \n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }
    
    printf("A soma das matrizes e: \n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d ", mat1[i][j] + mat2[i][j]);
        }
        printf("\n");
    }

    return 0;
}