#include <stdio.h>
#include <stdlib.h>


typedef struct employees
{
   int id;
   char name[50];
   float wage;
}Employees;



Employees* RegisterEmployee(){
   Employees* registeredEmployee = (Employees*)malloc(sizeof(Employees));
   
   if(registeredEmployee == NULL){
      fprintf(stderr, "Erro na alocação de memória");
      exit(1);
   }

   printf("Id do funcionario: ");
   scanf("%d", &registeredEmployee->id);
   printf("Nome do funcionario: ");
   scanf(" %49[^\n]", registeredEmployee->name);
   printf("Salario do funcionario: ");
   scanf("%f", &registeredEmployee->wage);

   return registeredEmployee;
}

int main(){
   Employees* employee1 = RegisterEmployee();
   printf("%d, %s, %f", employee1->id, employee1->name, employee1->wage);
   return 0;
}