/* linkedlist.h */

#include <stdio.h>
#include <stdlib.h>

#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

struct linkedlist {
    struct linkedlist *prev;
    struct linkedlist *next;

    void *data;
};

int linkedlist_init(struct linkedlist *entry);
int linkedlist_create(struct linkedlist *head, void *data);
int linkedlist_add(struct linkedlist *head, struct linkedlist *entry);
int linkedlist_remove_index(struct linkedlist *head, int index);
int linkedlist_remove_pointer(struct linkedlist *head, struct linkedlist *entry);
int linkedlist_free(struct linkedlist *head, int freehead);

#endif

