#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef int TipoChave;

typedef struct{
    TipoChave chave;
}TipoItem;

typedef struct TipoCelula *Apontador;

struct TipoCelula{
    TipoItem Item;
    Apontador Prox;
};

typedef struct{
        Apontador Primeiro,Ultimo;
        int tamanho;
}TipoLista;

void Inicia(TipoLista *Lista){
    Lista->Primeiro = (Apontador) malloc(sizeof(struct  TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
    Lista->tamanho = 0;
}

// Implemente a Operação Vazia verifica se primeiro == ultimo
int Vazia(TipoLista *lista){
    return lista->Primeiro == lista->Ultimo;
}

//A inserção é feita à direita do ponteiro Último*/
void Insere(TipoItem x, TipoLista *Lista){
    Lista->Ultimo->Prox = (Apontador) malloc(sizeof( struct TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
    Lista->tamanho = Lista->tamanho + 1;
}

// Implemente a Operação Imprimir
void Imprimir(TipoLista *Lista){
    if(!Vazia(Lista)){
        Apontador aux = Lista->Primeiro->Prox;
        for(int i=1; aux!=NULL; i++){
            printf("%d- %d\n",i,aux->Item);
            aux = aux->Prox;
        }
    }else{
        printf("Lista Vazia\n");
    }
}



int main(int argc, char *argv[]) {
    TipoLista Lista;
    TipoItem item1, item2, item3;
    Inicia(&Lista);
    Imprimir(&Lista);
    item1.chave = 42;
    item2.chave = 73;
    item3.chave = 88;
    Insere(item1, &Lista);
    Insere(item2, &Lista);
    Insere(item3, &Lista);
    Imprimir(&Lista);
    return 0;
}