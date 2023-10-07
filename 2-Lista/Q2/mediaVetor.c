#include <stdio.h>

int main(){
    int V[] = {1,2,3,4,5,6,7,8,9,10};
    int soma = 0;
    float media = 0;
    for(int i = 0; i < 10; i++){
        soma += V[i];
    }
    media = (float)soma/10;
    printf("Media:%0.2f", media);
    return 0;
} 