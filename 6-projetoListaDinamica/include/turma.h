#ifndef Turma_H
#define Turma_H

struct Aluno;
struct Professor;

typedef struct Turma{
    int identificador;
    struct Aluno *alunos;
    struct Professor *professor;
    struct Turma *proximo;
}Turma;
#endif