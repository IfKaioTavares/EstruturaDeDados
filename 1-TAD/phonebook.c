#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct contact{
    char name[50];
    char number[15];
}Contact;

typedef struct phoneBook{
    int capacity;
    int size;
    Contact* contacts;
}PhoneBook;

PhoneBook createPhoneBook(int capacity){
    PhoneBook newPhoneBook;
    newPhoneBook.capacity = capacity;
    newPhoneBook.size = 0;
    newPhoneBook.contacts = (Contact*)malloc(capacity * sizeof(Contact));
    return newPhoneBook;
}

void addContact(PhoneBook* phoneBook, char* name, char* number){
    if(phoneBook->size >= phoneBook->capacity){
        printf("A agenda já está cheia");
        return;
    }

    Contact newContact;
    strncpy(newContact.name, name, sizeof(newContact.name) - 1);
    strncpy(newContact.number, number, sizeof(newContact.number) -1);
    phoneBook->contacts[phoneBook->size] = newContact;
    phoneBook->size++;
}

void showContacts(PhoneBook* phoneBook){
    for (int i = 0; i < phoneBook->size; i++)
    {
        printf("%d- %s: %s\n", i +1, phoneBook->contacts[i].name, phoneBook->contacts[i].number);
    }
    
}

int main(){
    PhoneBook kaioPhoneBook = createPhoneBook(2);
    addContact(&kaioPhoneBook, "Raquel", "(xx)xxxxx-xxxx");
    addContact(&kaioPhoneBook, "Arielle", "(yy)yyyyy-yyyy");
    showContacts(&kaioPhoneBook);
    return 0;
}