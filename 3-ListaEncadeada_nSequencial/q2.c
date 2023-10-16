#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula, nota, curso;
} Aluno;

typedef struct Node *NewNode;

typedef struct Node {
    Aluno aluno;
    NewNode next;
} Node;

NewNode criaNo(Aluno aluno) {
    NewNode novoNo = (NewNode)malloc(sizeof(Node));
    novoNo->aluno = aluno;
    novoNo->next = NULL;
    return novoNo;
}

void addNo(Node **listaTurma, Aluno aluno) {
    NewNode novoNo = criaNo(aluno);
    if (*listaTurma == NULL) {
        *listaTurma = novoNo;
    } else {
        NewNode aux = *listaTurma;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = novoNo;
    }
}

int estaVazia(Node *lista) {
    return lista == NULL;
}

void imprimirAprovadosReprovados(Node *listaTurma) {

    if (estaVazia(listaTurma)) {
        printf("A lista está vazia.\n");
        return;
    }

    Node *aprovados = NULL;
    Node *reprovados = NULL;

    Node *atual = listaTurma;
    while (atual != NULL) {
        if (atual->aluno.nota >= 7.0) {
            addNo(&aprovados, atual->aluno);
        } else {
            addNo(&reprovados, atual->aluno);
        }
        atual = atual->next;
    }

    printf("Alunos Aprovados:\n");
    atual = aprovados;
    while (atual != NULL) {
        printf("Matricula: %d, Nota: %d, Curso: %d\n", atual->aluno.matricula, atual->aluno.nota, atual->aluno.curso);
        atual = atual->next;
    }

    printf("\nAlunos Reprovados:\n");
    atual = reprovados;
    while (atual != NULL) {
        printf("Matricula: %d, Nota: %d, Curso: %d\n", atual->aluno.matricula, atual->aluno.nota, atual->aluno.curso);
        atual = atual->next;
    }
}

int main() {
    Node *listaTurma = NULL;
    Aluno aluno1 = {1, 8, 1};
    Aluno aluno2 = {2, 5, 2};
    Aluno aluno3 = {3, 9, 3};

    addNo(&listaTurma, aluno1);
    addNo(&listaTurma, aluno2);
    addNo(&listaTurma, aluno3);

    imprimirAprovadosReprovados(listaTurma);

    return 0;
}
