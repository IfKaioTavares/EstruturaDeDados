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
    if(l->tamanho < 1){
        return NULL;
    }
    Lista *listaSeparada = (Lista*)malloc(sizeof(Lista));
    Inicia(listaSeparada);
    Apontador aux = l->Primeito->Prox;
    Apontador auxAnterior = l->Primeito;
    while(aux != NULL && aux->Dado != n){
        aux = aux->Prox;
        auxAnterior = auxAnterior->Prox;
    }
    if (aux == NULL) {
        return NULL;
    }

    listaSeparada->Primeito->Prox = aux->Prox;
    listaSeparada->Ultimo = l->Ultimo;
    l->Ultimo = aux;
    l->Ultimo->Prox = NULL;
    Apontador aux2 = listaSeparada->Primeito->Prox;
    while (aux2!=NULL){
        listaSeparada->tamanho++;
        aux2 = aux2->Prox;
    }
    l->tamanho -= listaSeparada->tamanho;
    return listaSeparada;
}

void Imprimir(Lista *Lista){
    if(Lista->tamanho>0){
        Apontador aux = Lista->Primeito->Prox;
        for(int i=1; aux!=NULL; i++){
            printf("%d- %d\n",i,aux->Dado);
            aux = aux->Prox;
        }
    }else{
        printf("Lista Vazia\n");
    }
}

int main(){
    Lista lista1;
    Lista *lista2;
    Inicia(&lista1);
    Insere(&lista1,3);
    Insere(&lista1,17);
    Insere(&lista1,5);
    Insere(&lista1,12);
    Insere(&lista1,1);
    lista2 = separa(&lista1, 5);
    Imprimir(&lista1);
    Imprimir(lista2);
    printf("\n%d %d", lista1.Ultimo->Dado, lista2->Ultimo->Dado);
    return 0;

}