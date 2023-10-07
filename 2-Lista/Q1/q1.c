//Dado um número real qualquer, informe qual é o seu dobro
#include <stdio.h>
#include <string.h>

int main(){
    float a;
    printf("Informe o valor de a: ");
    scanf("%f", &a);
    a=a * 2;
    printf("%f",a);
    return 0;
}