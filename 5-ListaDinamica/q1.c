#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int matricula;
    char nome[80];
    float media;
}Aluno;

typedef struct No *Apontador;

struct No{
    Aluno Aluno;
    Apontador Prox;
};

typedef struct{
    int Tamanho;
    Apontador Primeiro,Ultimo;
}Lista;

void Inicia(Lista *lista){
    lista->Primeiro = (Apontador)malloc(sizeof(struct No));
    lista->Ultimo = lista->Primeiro;
    lista->Primeiro->Prox = NULL;
    lista->Tamanho = 0;
}

void Insere(Lista *Lista, Aluno aluno){
    if(Lista->Tamanho == 0){
        Lista->Ultimo->Prox = (Apontador)malloc(sizeof(struct No));
        Lista->Ultimo = Lista->Ultimo->Prox;
        Lista->Ultimo->Aluno = aluno;
        Lista->Ultimo->Prox = NULL;
        Lista->Tamanho = Lista->Tamanho + 1;
    }else{
        Apontador aux = Lista->Primeiro->Prox;
        Apontador auxAnterior = Lista->Primeiro;
        while(aux != NULL && aux->Aluno.matricula < aluno.matricula){
            aux = aux->Prox;
            auxAnterior = auxAnterior->Prox;
        }
        auxAnterior->Prox = (Apontador)malloc(sizeof(struct No));
        auxAnterior->Prox->Aluno = aluno;
        auxAnterior->Prox->Prox = aux;
        Lista->Tamanho = Lista->Tamanho +1;    
    }
}

int main() {
    Lista listaAlunos;
    Inicia(&listaAlunos);

    Aluno aluno1 = {456, "Alice", 9.5};
    Aluno aluno2 = {458, "Bob", 8.0};
    Aluno aluno3 = {457, "Charlie", 7.5};
    Aluno aluno4 = {234, "David", 8.8};

    Insere(&listaAlunos, aluno1);
    Insere(&listaAlunos, aluno2);
    Insere(&listaAlunos, aluno3);
    Insere(&listaAlunos, aluno4);

    printf("Lista de Alunos:\n");
    Apontador aux = listaAlunos.Primeiro->Prox; // Começa do primeiro nó válido
    while (aux != NULL) {
        printf("Matrícula: %d, Nome: %s, Média: %.2f\n", aux->Aluno.matricula, aux->Aluno.nome, aux->Aluno.media);
        aux = aux->Prox;
    }

    return 0;
}
