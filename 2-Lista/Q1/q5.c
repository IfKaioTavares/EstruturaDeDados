/*Dados o valor da compra e o percentual de desconto, calcule o valor a ser pago. 
Considere que o percentual de desconto é um número real entre 0 e 1.*/
#include <stdio.h>
int main(){
    float a,b,v;
    printf("Informe o valor da compra: ");
    scanf("%f",&a);
    printf("Informe o valor do percentual do desconto: ");
    scanf("%f",&b);
    v = a - (a*b);
    printf("Valor da compra com desconto: %f",v);
    return 0;
}