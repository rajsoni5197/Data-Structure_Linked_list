//here we will learn how to delete a node from a linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void insurt(int x, int position);
void printLinkedList();
void deleteNode(int position);

int main()
{
    int data, position;
    char iod;
    head = NULL; //empty list

    while (1)
    {
        printf("hello\n");
        printf("\nwhat do you want to do Insert (I) or Delete(D)\t");
        scanf("%c", &iod);
        if (iod == 'I' || iod == 'i')
        {
            printf("\n Hello User give us the data and position :\t");
            scanf("%d %d", &data, &position);
            printf("\n");
            if (!position)
                break;

            insurt(data, position);
            printf("\nhello\n");
            printLinkedList();
        }
        if (iod == 'D' || iod == 'd')
        {
            printf("give us the position of the node which you want to delete \t ");
            scanf("%d", &position);
            if (!position)
                break;
            deleteNode(position);
            printLinkedList();
        }
    }
}
void deleteNode(int p)
{
    int i;
    struct Node *temp1 = head;
    struct Node *temp2; //-> this is a pointer which will point to nth node of the list.

    if (p == 1)
    {
        head = head->next;
        free(temp1); //now at this place temp1 is pointing to the first node.
        return;
    }
    //now we have to tracerse the linked list to go to the n-1th node.
    //for this we will have to run a loop n-2 times .
    for (i = 0; i < p - 2; i++)
    {
        temp1 = temp1->next;
    } // at the end of the loop temp1 is pointing to (n-1)th node.

    temp2 = temp1->next; //now temp2 is pointing to nth node of the list.

    //now we will brake the link of n-1th node from nth node and link
    //n-1 th node to n+1 node.
    temp1->next = temp2->next; //nth node is out from the linked list but not from memory.

    //now we have to free the memory of nth node from the heap.
    free(temp2); //free that much space from memory to which temp2 is pointing here its n node
}
void insurt(int x, int p)
{
    int i;
    //first we want to create a node.
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node)); //here we created a pointer of type node
                                                                     //To store the the address of the newly created node in the dinamic memory throuh malloc.
    (*temp1).data = x;
    temp1->next = NULL; //its temperory.

    //special case when we want to insurt node at beginning of the list p=1;
    if (p == 1)
    {
        temp1->next = head; //Set next of temp1 to Null if list is empty
        head = temp1;       //now head will point to the newly created node temp1
        return;
    }

    //for any other case we will have to traverse the linked list
    //here for this we will find p-1 node
    struct Node *temp2 = head;  //currently pointing to the first node in the list
    for (i = 0; i < p - 2; i++) //we have to run the loop p-2 times to reach at p-1 node
    {
        temp2 = temp2->next;
    }
    //now temp2 is the pointer which is pointing to p-1 node.
    temp1->next = temp2->next; // we stored the address of p+1 node in our newly created node.
    temp2->next = temp1;       // now here we pointed the p-1nt node to our newly created node.
}

void printLinkedList()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("\n  NodesAddress = %d NodeData = %d NextNodeAddress = %d \n", temp, temp->data, temp->next);
        temp = temp->next;
    }
}
