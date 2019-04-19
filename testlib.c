#include <stdio.h>
#include <string.h>

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
    struct linkedlist *jill_entry;
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
            if (strcmp("Jill", ((person*)temp->data)->name) == 0) {
                jill_entry = temp;
            }
        }
    }

    // remove some guys
    linkedlist_remove_index(&mylist, 1);
    linkedlist_remove_pointer(&mylist, jill_entry);

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

