#ifndef Aluno_H //Guard de inclusão
#define Aluno_H

struct Curso; //foward Declartion para a estrutura Curso
typedef struct Aluno
{
    int matricula;
    char nome[50];
    struct Curso *cursos;
    struct Aluno *proximo;
}Aluno;

#endif