// inserting a node in a linked list at the nth position
#include <stdio.h>
#include <stdlib.h>


struct Node 
{
    int data;
    struct Node* next;
};
struct Node* head;

void insurt(int data, int position);
void printLinkedList();

int main()
{   
    int data , position;
    head = NULL; //empty list
   
    
    while(1)
    {
        printf("\n Hello User give us the data and position :\t");
        scanf("%d %d",&data , &position);
        printf("\n");
        if(!position)break;
        
        insurt(data , position);
        printf("\nhello\n");
        printLinkedList();
    }
}
void insurt(int x ,int p)
{
    int i;
    //first we want to create a node.
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));//here we created a pointer of type node 
                                                                  //To store the the address of the newly created node in the dinamic memory throuh malloc.
    (*temp1).data = x;
    temp1->next = NULL;//its temperory.
    
    //special case when we want to insurt node at beginning of the list p=1;
    if(p == 1)
    {
        temp1->next=head; //Set next of temp1 to Null if list is empty
        head = temp1; //now head will point to the newly created node temp1
        return;
    }

    //for any other case we will have to traverse the linked list
    //here for this we will find p-1 node 
    struct Node* temp2 = head; //currently pointing to the first node in the list 
    for(i=0 ; i<p-2 ; i++)  //we have to run the loop p-2 times to reach at p-1 node
    {
        temp2 = temp2->next;
    }
    //now temp2 is the pointer which is pointing to p-1 node.
    temp1->next = temp2->next; // we stored the address of p+1 node in our newly created node.
    temp2->next = temp1;       // now here we pointed the p-1nt node to our newly created node.

}
void printLinkedList()
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("\n  NodesAddress = %d NodeData = %d NextNodeAddress = %d \n",temp,temp->data,temp->next);
        temp = temp->next;
        
    }
}
