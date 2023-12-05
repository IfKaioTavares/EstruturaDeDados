#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "curso.h"

void iniciaListaAlunos(ListaAlunos *lista){
  lista->Primeiro = (Apontador)malloc(sizeof(struct NoAluno));
  lista->Ultimo = lista->Primeiro;
  lista->Primeiro->Prox = NULL;
  lista->tamanho = 0;
}

int listaAlunoVazia(ListaAlunos *lista){
    return lista->tamanho == 0;
}

void cadastrarAluno(ListaAlunos *lista, int matricula, char nome[]){
    if(listaAlunoVazia(lista)){
        return NULL;
    }
}