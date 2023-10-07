/*Dados um salário e um percentual de reajuste, calcule o salário reajustado. Considere
que o percentual de reajuste é dado por um número real entre 0 e 1. Por exemplo, se o
reajuste for de 15%, o usuário deve digitar o número 0.15.*/
#include <stdio.h>
int main(){
    float a,b,v;
    printf("Informe o valor do salario: ");
    scanf("%f",&a);
    printf("Informe o valor do percentual do reajuste: ");
    scanf("%f",&b);
    v = (a * b) + a;
    printf("Salario reajustrado: %f",v);
    return 0;
}