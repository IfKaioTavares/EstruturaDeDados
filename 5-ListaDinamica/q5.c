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


void swapNode(List *List, int pos1, int pos2){
    if(List->Length <= 1){
        printf("A lista deve conter pelo menos dois elementos");
    }else if(pos1 == pos2 || pos1 < 1 || pos2 < 1 || pos1 > List->Length || pos2 > List->Length){
        printf("Posicao invalida");
    }else{
        Apointer previous1 = List->First;
        Apointer previous2 = List->First;

        for(int i = 1; i < pos1; i++){
            previous1 = previous1->Next;
        }

        for(int i = 1; i < pos2; i++){
            previous2 = previous2->Next;
        }

        Apointer actualNode1 = previous1->Next;
        Apointer actualNode2 = previous2->Next;

        previous1->Next = actualNode2;
        previous2->Next = actualNode1;

        Apointer aux = actualNode2->Next;
        actualNode2->Next = actualNode1->Next;
        actualNode1->Next = aux;

        Apointer auxToLast = List->First;
        while(auxToLast->Next!=NULL){
            auxToLast = auxToLast->Next;
        }
        List->Last = auxToLast;
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
    Start(&List1);
    Add(&List1, 7);
    Add(&List1, 12);
    Add(&List1, 8);
    Add(&List1, 25);
    Add(&List1, 21);
    Add(&List1, 30);
    Imprimir(&List1);
    swapNode(&List1, 6, 1);
    Imprimir(&List1);
    swapNode(&List1,1,4);
    Imprimir(&List1);
    printf("%d %d", List1.First->Next->Data, List1.Last->Data);
    return 0;
}