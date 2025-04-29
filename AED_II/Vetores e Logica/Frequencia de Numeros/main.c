#include <stdio.h>

int main(){
    int x[10], i;
    int ja_contado[10] = {0}; // Array para marcar números já processados
    
    printf("Digite 10 numeros inteiros: \n");
    for(i = 0; i < 10; i++){
        scanf("%d", &x[i]);
    }

    printf("Frequencia dos numeros:\n");
    for(i = 0; i < 10; i++){
        if (ja_contado[i]) {
            continue; // Pula números já processados
        }

        int j, cont = 0;
        for(j = 0; j < 10; j++){
            if(x[i] == x[j]){
                cont++;
                ja_contado[j] = 1; // Marca o número como processado
            }
        }
        printf("%d: %d\n", x[i], cont);
    }

    return 0;
}