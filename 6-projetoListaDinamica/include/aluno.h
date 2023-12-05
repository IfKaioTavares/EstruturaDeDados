#ifndef Aluno_H //Guard de inclusão
#define Aluno_H

struct Curso; //foward Declartion para a estrutura Curso
typedef struct Aluno
{
    int matricula;
    char nome[50];
    struct Curso *cursos;
}Aluno;

typedef struct NoAluno *Apontador;

struct NoAluno{
    Aluno Aluno;
    Apontador Prox;
};

typedef struct ListaAlunos{
    int tamanho;
    Apontador Primeiro,Ultimo;
}ListaAlunos;

#endif