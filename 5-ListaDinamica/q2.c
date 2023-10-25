#include <stdio.h>
#include <stdlib.h>

typedef struct No *Apontador;

struct No{
    int Dado;
    Apontador Prox;
};

typedef struct{
    int tamanho;
    Apontador Primeito, Ultimo;
}Lista;

void Inicia(Lista *Lista){
    Lista->Primeito = (Apontador)malloc(sizeof(struct No));
    Lista->Ultimo = Lista->Primeito;
    Lista->Primeito->Prox = NULL;
    Lista->tamanho = 0;
}

void Insere(Lista *Lista, int dado){
    Lista->Ultimo->Prox = (Apontador)malloc(sizeof(struct No));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Dado = dado;
    Lista->Ultimo->Prox = NULL;
    Lista->tamanho = Lista->tamanho + 1;
}

Lista* separa (Lista* l, int n){
    Lista *listaSeparada;
    Inicia(listaSeparada);
    return listaSeparada;
}

int main(){
    Lista lista1;
    Lista *lista2;
    //lista1 = separa(&lista1, 3);

}