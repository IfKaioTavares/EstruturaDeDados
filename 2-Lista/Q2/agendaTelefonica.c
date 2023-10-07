#include <stdio.h>
#include <string.h>

typedef struct Contatos{
    char nome[20];
    char endereco[20];
    char telefone[15];
}Contato;

typedef struct AgendaTelefonica{
    int size;
    Contato C[3];
}Agenda;

Agenda createPhoneBook(){
    Agenda agenda;
    agenda.size = 0;
    return agenda;
}

void addContato(Agenda* agenda, Contato* newContato){
    agenda->C[agenda->size] = *newContato;
    agenda->size++;
}

void mostrarContatos(Agenda* agenda){
    for(int i=0; i < agenda->size; i++){
        printf("%d- %s: %s; %s\n", i +1, agenda->C[i].nome, agenda->C[i].telefone, agenda->C[i].endereco);
    }
}

int main(){
    Agenda newAgenda = createPhoneBook();
    Contato newContato;
    for(int i=0; i<3;i++){
        printf("Nome do contato: ");
        scanf("%s",newContato.nome);
        printf("Telefone: ");
        scanf("%s",newContato.telefone);
        printf("Endereco: ");
        scanf("%s",newContato.endereco);
        addContato(&newAgenda,&newContato);
    }
    mostrarContatos(&newAgenda);
    return 0;
}