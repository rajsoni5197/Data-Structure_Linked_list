//here is how we insert a newNode at start or at end of a doubly linked list.
//also it has function to print the doubly linked list in a pictorial manner.
//inserting Node at the tail or end of the linked list.
#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head;

struct Node *getNewNode(int x);
void insurtNodeatEndOfDDL();
void printDDL(struct Node *h);
void insertAtStart(int x);

int main()
{
    int x, soe;
    head = NULL; //empty ddl
    while (1)
    {
        printf("where do you want to insert the newNode start->0 and end->1\t");
        scanf("%d", &soe);
        printf("give us the value of the node to be inserted\t");
        scanf("%d", &x);
        printf("\n");
        if (x < 0)
            break;
        if (!soe)
        {
            insertAtStart(x);
        }
        else{insurtNodeatEndOfDDL(x);}
        
        printDDL(head);
    }
}
void insertAtStart(int x)
{
    struct Node *newNode = getNewNode(x);
    if (!head)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insurtNodeatEndOfDDL(int data)
{
    struct Node *newNode = getNewNode(data);
    struct Node *temp = head;
    if (!head)
    {
        head = newNode;
        return;
    }
    while (temp->next)
    {
        temp = temp->next; //traversing to the end node in case list is not empty.
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void printDDL(struct Node *h)
{
    while (h)
    {
        printf("|%d\t| %d\t| %d\t| <- %d\n", h->prev, h->data, h->next, h);
        h = h->next;
    }
    return;
}
struct Node *getNewNode(int x)
{
    struct Node *newNodePointer = (struct Node *)malloc(sizeof(struct Node));
    newNodePointer->data = x;
    newNodePointer->next = NULL;
    newNodePointer->prev = NULL;
    return newNodePointer;
}
