#include <stdio.h>
#define MaxLength 100
#define VetorStart 0

typedef struct{
    int value;
}Data;

typedef int Pointer;

typedef struct {
    Data data[MaxLength];
    Pointer first, last;
}StaticList;

void StartList(StaticList *List){
    List->first = VetorStart;
    List->last = List->first;
};

int empetyList(StaticList *List){
    return List->first == List->last;
}

void addData(StaticList *List, Data data){
    if(List->last == MaxLength){
        printf("Lista cheia\n");
    }else{
        List->data[List->last] = data;
        List->last++;
    }
}

void showList(StaticList *List){
    if(empetyList(List)){
        printf("Lista vazia\n");
    }else{
        printf("List itens:\n");
        for(int i = VetorStart; i < List->last; i++){
            printf("%d: %d\n", i+1, List->data[i].value);
        }
    }
}

void addData_inPosition(StaticList *List, Data data, Pointer pos){
    if(List->last == MaxLength - 1){
        printf("Lista cheia\n");
    }else if (pos < 0 || pos > List->last )
    {
        printf("Posição invalida");
    }else{
        //Deslocar os itens da lista
        for(int i = List->last; i > pos; i--){
            List->data[i] = List->data[i-1];
        }
        List->data[pos] = data;
        List->last++;
    }
}

void checkOrder(StaticList *List){
    int increasing = 0;
    int decreasing = 0;
    for(int i = List->first + 1; i < List->last; i++){
        if(List->data[i - 1].value < List->data[i].value){
            increasing = 1;
        }
        if(List->data[i-1].value > List->data[i].value){
            decreasing = 1;
        }
    }

    if(increasing && decreasing){
        printf("Lista nao ordernada\n");
    }else if (increasing && !decreasing)
    {
        printf("Lista crescente\n");
    }else if (!increasing && decreasing)
    {
        printf("Lista decrescente\n");
    }else{
        printf("Lista com dados iguais\n");
    }
}

void compareLists(StaticList *List1, StaticList *List2){
    int validation = 0;
    for(int i = VetorStart; i<List1->last; i++){
        if(List1->data[i].value != List2->data[i].value){
            validation = 1;
        }
    }

    if(validation || (List1->last != List2->last)){
        printf("Listas diferentes");
    }else{
        printf("Listas iguais");
    }
}

void copyLists(StaticList *list1, StaticList *list2){
    for(int i=list1->first; i < list1->last; i++){
        addData(list2,list1->data[i]);
    }
}

void copyListsInverted(StaticList *list1, StaticList *list2){
    for(int i=list1->last; i > list1->first; i--){
        addData(list2,list1->data[i-1]);
    }
}

void interleaveData(StaticList *list1, StaticList *list2, StaticList *list3){
    int i = list1->first, j = list2->first;
    while (i < list1->last && j < list2->last){
        if(list1->data[i].value < list2->data[j].value){
            addData(list3,list1->data[i]);
            i++;
        }else{
            addData(list3,list2->data[j]);
            j++;
        }
    }

    while (i < list1->last)
    {
        addData(list3,list1->data[i]);
        i++;
    }

    while (j< list2->last)
    {
        addData(list3,list2->data[j]);
        j++;
    }
    
}
   

void deleteOcorrences(StaticList *List, Data data_to_delete){
    int i = List->first, j = List->first;
    while (i<List->last)
    {
        if(List->data[i].value != data_to_delete.value){
            List->data[j] = List->data[i];
            j++;
        }
        i++;
    }
    List->last = j;
}

int main(){
    StaticList List1;
    StaticList List2;
    StaticList List3;

    Data data1, data2, data3, data4, data5, data6, data7, data8, data9;
    StartList(&List1);
    StartList(&List2);
    StartList(&List3);
    data1.value = 1;
    data2.value = 4;
    data3.value = 6;
    data4.value = 9;
    data5.value = 10;

    data6.value = 2;
    data7.value = 5;
    data8.value = 9;
    data9.value = 11;
    addData(&List1, data1);
    addData(&List1, data2);
    addData(&List1, data3);
    addData(&List1, data4);
    addData(&List1, data5);

    addData(&List2, data6);
    addData(&List2, data7);
    addData(&List2, data8);
    addData(&List2, data9);
    showList(&List1);
    showList(&List2);

    interleaveData(&List1, &List2, &List3);
    showList(&List3);
    return 0;
}