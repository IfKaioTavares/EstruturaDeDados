#include <stdarg.h>
#include <stdlib.h>

typedef struct Node *Apointer;

struct Node{
    int Data;
    Apointer Next; 
};
typedef struct{
    int Length;
    Apointer First, Last;
}List;

void Start(List *List){
    List->First = (Apointer)malloc(sizeof(struct Node));
    List->Last = List->First;
    List->First->Next = NULL;
    List->Length = 0;
}

void Add(List *List, int data){
    List->Last->Next = (Apointer)malloc(sizeof(struct Node));
    List->Last = List->Last->Next;
    List->Last->Data = data;
    List->Last->Next = NULL;
    List->Length++;
}

List addVetor( int vetor[], int tamanho){
    List listToReturn;
    Start(&listToReturn);
    if(tamanho==0 || tamanho==NULL){
        return listToReturn;
    }else{
        for(int i = 0; i < tamanho; i++){
            Add(&listToReturn, vetor[i]);
        }
    }
    return listToReturn;
}

void Imprimir(List *Lista){
    if(Lista->Length > 0){
        Apointer aux = Lista->First->Next;
        for(int i=1; aux!=NULL; i++){
            printf("%d- %d\n",i,aux->Data);
            aux = aux->Next;
        }
    }else{
        printf("Lista Vazia\n");
    }
    printf( "\n");
}

int main(){
    int vetor[] = {12, 34, 67, 89};
    List List1 = addVetor(vetor, 4);
    Imprimir(&List1);
    return 0;
}