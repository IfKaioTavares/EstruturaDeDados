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

void ConcatenateLists(List *List1, List *List2){
    Apointer aux = List2->First->Next;
    while (aux!=NULL)
    {
        Add(List1, aux->Data);
        aux = aux->Next;
    }
    
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
    List List1;
    List List2;
    Start(&List1);
    Start(&List2);
    Add(&List1,1);
    Add(&List1,2);
    Add(&List1,3);
    Add(&List2,4);
    Add(&List2,5);
    Imprimir(&List1);
    Imprimir(&List2);
    ConcatenateLists(&List1, &List2);
    Imprimir(&List1);
    return 0;
}