#include <stdio.h>

int main(){
    int x[10], i;
    printf("Digite 10 numeros inteiros: \n");
    for(i = 0; i < 10; i++){
        scanf("%d", &x[i]);
    }

    printf("Frequencia dos numeros:\n");
    for(i = 0; i < 10; i++){
        int j, cont = 0;
        for(j = 0; j < 10; j++){
            if(x[i] == x[j]){
                cont++;
            }
        }
        printf("%d: %d\n", x[i], cont);
    }

    return 0;
}