/*Dados um valor em real e a cotação do dólar, converta esse valor em dólares. */
#include <stdio.h>
int main(){
    float r,d,v;
    printf("Informe o valor em reais: ");
    scanf("%f",&r);
    printf("Informe o valor da cotacao em dolar: ");
    scanf("%f",&d);
    v = r/d;
    printf("O valor em dolar eh: %f$",v);
    return 0;
}