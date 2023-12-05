#ifndef Curso_H
#define Curso_H

typedef struct Curso{
    char nomeCurso[50];
    int cargaHoraria;
    struct Curso *proximo;
}Curso;
#endif