#include <stdio.h>

void exibeVetor(int *lista, int tamanho){
    for(int i=0; i<tamanho; i++){
        printf("%d ", lista[i]);
    }
    printf("\n");
}
//q1
void insereItem(int *lista, int pos, int dado){
    lista[pos-1] = dado; 
}
//q2.1
void verificaOrdenacao(int *lista, int tamanho){
    int crescente = 0; 
    int decrescente = 0;
    for(int i=1; i < tamanho; i++){
        if(lista[i-1] > lista[i]){
            crescente = 1;
        }
        if(lista[i-1] < lista[i]){
            decrescente = 1;
        }
    }
    if(crescente == 1 && decrescente == 1){
        printf("Nao esta ordenado\n");
    }else if(crescente == 0 && decrescente == 1){
        printf("Lista em ordem crescente\n");
    } else if(crescente== 1 && decrescente ==0){
        printf("Lista em ordem descrecente\n");
    }
}
//q2.2
void verificaIgualdadeListas(int *lista1, int *lista2, int tam){
    for(int i = 0; i<tam; i++){
        if(lista1[i] != lista2[i]){
            printf("Listas nao sao igauis\n");
            return;
        }
    }
    printf("Listas iguais\n");
}
//q2.3
void copiaLista(int *lista1,int *lista2, int tam){
    for(int i = 0; i< tam; i++){
        lista2[i] = lista1[i];
    }
}
//q2.4
void inverteLista(int *lista1, int *lista2, int tam){
    for(int i = 0; i < tam; i++){
        lista2[i] = lista1[tam - i - 1];
    }
}
//q2.5
void intercalaListas(int *lista1, int *lista2, int *lista3, int tam1, int tam2) {
    int i = 0, j = 0, k = 0;

    while (i < tam1 && j < tam2) {
        lista3[k++] = lista1[i++];
        lista3[k++] = lista2[j++];
    }

    while (i < tam1) {
        lista3[k++] = lista1[i++];
    }

    while (j < tam2) {
        lista3[k++] = lista2[j++];
    }
}
//q2.6
void eliminarOcorrencias(int *lista, int tamanho, int elemento) {
    int aux = 0;
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] != elemento) {
            lista[aux++] = lista[i];
        }
    }
    
    for(int i = aux; i < tamanho; i++){
        lista[i] = -1;
    }
}

int main(){
    int lista1 [5] = {3,1,2,3,4};
    int lista2 [5] = {4,3,2,1,0};
    int lista3 [5] = {36, 8, 36, 41, 36};
    insereItem(lista1,1,0);
    printf("%d\n",lista1[0]);
    verificaOrdenacao(lista1,5);
    verificaOrdenacao(lista2,5);
    verificaOrdenacao(lista3,4);
    verificaIgualdadeListas(lista1,lista1,5);
    verificaIgualdadeListas(lista1,lista3,5);
    int lista2_[5];
    copiaLista(lista1,lista2_,5);
    exibeVetor(lista2_,5);
    inverteLista(lista1, lista2_, 5);
    exibeVetor(lista2_,5);
    int lista3_[10];
    intercalaListas(lista1,lista2,lista3_,5,5);
    exibeVetor(lista3_,10);
    eliminarOcorrencias(lista3, 5, 36);
    exibeVetor(lista3,5);
    return 0;
}