#ifndef Professor_H
#define Professor_H

struct Turma;
typedef struct Professor{
    char nome[50];
    char disciplina[50];
    struct Turma *turmas;
    struct Profesor *proximo;
}Professor;
#endif
