//Dadas as medidas de uma sala em metros (comprimento e largura), informe a sua área em metros quadrados. 
#include <stdio.h>

int main(){
    float x,y,a;
    printf("Informe o valor do comprimento: ");
    scanf("%f",&x);
    printf("Informe o valor da largura: ");
    scanf("%f",&y);
    a = x * y;
    printf("O valor da metragem eh:%f m^2",a);
    return 0;
}