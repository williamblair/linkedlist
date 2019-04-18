## A simple linked list implementation in C

# Compile
Make should compile the library

Compile into your program by adding the flag `-llinkedlist`

# Usage

linkedlist_init(): sets all members of a linkedlist struct to NULL
linkedlist_create(): adds a new entry to the linkedlist starting with head, and sets is data entry
linkedlist_add(): adds an already initialized linkedlist entry to the list starting with head
linkedlist_free(): frees a list starting with head, including its `data` members if they aren't null. If freehead is non-zero it will try and free `head` as well.

