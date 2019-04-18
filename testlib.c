#include <stdio.h>

#include "linkedlist.h"

typedef struct {
    char *name;
    int age;
} person;

void addperson(struct linkedlist *head, char *name, int age)
{
    person *p = malloc(sizeof(person));
    p->name = name;
    p->age = age;
    linkedlist_create(head, (void*)p);
}

int main(void)
{
    struct linkedlist mylist;
    struct linkedlist *temp;
    person me = {.name = "BJ", .age = 22};    

    linkedlist_init(&mylist);
    mylist.data = (void*)&me;

    addperson(&mylist, "Peter", 12);
    addperson(&mylist, "Jack", 8);
    addperson(&mylist, "Jill", 19);
    
    for (temp = &mylist; temp != NULL; temp = temp->next)
    {
        if (temp->data != NULL)
        {
            printf("Name, age: %s, %d\n", ((person*)temp->data)->name, ((person*)temp->data)->age);
        }
    }

    linkedlist_free(&mylist, 0);
    
    return 0;
}

