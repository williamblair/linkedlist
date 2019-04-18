/* linkedlist.c */

#include "linkedlist.h"

int linkedlist_init(struct linkedlist *entry)
{
    /* Can't init a NULL entry */
    if (entry == NULL) {
        fprintf(stderr, "linkedlist: entry is null\n");
        return -1;
    }

    /* Set datamembers as null */
    entry->prev = NULL;
    entry->next = NULL;
    entry->data = NULL;
}

int linkedlist_create(struct linkedlist *head, void *data)
{
    /* Allocate memory for an entry */
    struct linkedlist *entry = malloc(sizeof(struct linkedlist));
    if (entry == NULL) {
        fprintf(stderr, "linkedlist: faile to allocate entry\n");
        return -1;
    }

    /* Init the entry */
    linkedlist_init(entry);

    /* Set the data member */
    entry->data = data;

    /* Add it to the list */
    linkedlist_add(head, entry);

    return 0;
}

int linkedlist_add(struct linkedlist *head, struct linkedlist *entry)
{
    struct linkedlist *last;

    /* Make sure we have a valid entry */
    if (entry == NULL) {
        fprintf(stderr, "linkedlist: entry is null\n");
        return -1;
    }
    
    /* If head is null we'll assume this is the first entry */
    if (head == NULL) {
        entry->prev = NULL;
        entry->next = NULL;
        entry->data = NULL;

        return 0;
    }

    /* Get the current end of the list */
    last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    /* Add the entry to the end of the new list */
    last->next = entry;
    entry->prev = last;
    entry->next = NULL;

    return 0;
}

int linkedlist_free(struct linkedlist *head, int freehead)
{
    struct linkedlist *temp = head;

    if (temp == NULL) {
        fprintf(stderr, "linkedlist: head is null\n");
        return -1;
    }

    /* If we don't want to free the head pointer then
     * move immediately to the next entry */
    if (!freehead) {
        head = head->next;
        if (head == NULL) {
            return 0;
        }
    }

    /* Free each entry and its data if added */
    do
    {
        temp = head->next;
        if (head->data != NULL) {
            free(head->data);
            head->data = NULL;
        }
        free (head);
        head = temp;
    } while (head != NULL);

    return 0;
}

#ifdef LINKEDLIST_TEST
struct mydata {
    int num1;
    int num2;
};

void addentry(struct linkedlist *head, int num1, int num2)
{
    /* Test adding a guy */
    struct mydata *testdata = malloc(sizeof(struct mydata));
    testdata->num1 = num1;
    testdata->num2 = num2;
    linkedlist_create(head, (void*)testdata);
}

int main(void)
{
    struct linkedlist *iter;
    struct mydata *mydata_p;
    struct linkedlist head;

    /* Init */
    linkedlist_init(&head);

    /* Test adding some bruhs */
    addentry(&head, 1,2);
    addentry(&head, 3,4);
    addentry(&head, 5,6);
    addentry(&head, 7,8);
    addentry(&head, 9,10);

    /* Print out the list*/
    for (iter = &head; iter != NULL; iter = iter->next)
    {
        if (iter->data != NULL) {
            mydata_p = (struct mydata*)iter->data;
            printf("Data: %d, %d\n", mydata_p->num1, mydata_p->num2);
        } else {
            printf("NULL data member, skipping\n");
        }
    }

    /* Test freeing the list */
    linkedlist_free(&head, 0);

    return 0;
}
#endif // LINKEDLIST_TEST



