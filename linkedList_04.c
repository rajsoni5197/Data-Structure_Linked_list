//reversing a linked list 
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_03.c"

void reverseLinkedList()
{
    struct Node *current ,*prev ,*next;
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
