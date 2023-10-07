/*Dado o total de vendas de um vendedor, calcule a sua comissão. 
Suponha que a comissão do vendedor seja de 10% do total de vendas.*/ 
#include <stdio.h>
int main(){
    float x,y;
    printf("Informe o valor da venda: ");
    scanf("%f",&x);
    y = x * 0.1f;
    printf("O valor da comissao: %f",y);
    return 0;
}