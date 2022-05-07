// inserting a node at the begning of the linked list
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* link;
};
struct Node* head;

void insurt(int a);
void printLinkedList();

int main()
{
    head = NULL; // empty list
    //test what is the size of head which is the pointer of the node vs struct node;
    printf("\n%d %d\n",sizeof(head),sizeof(struct Node));//4 8 because head is a pointer of type node and not node where as struct node is a structure of node itself ;

    int n , i , x;
    printf("Give us the no of elements \t");
    scanf("%d", &n);
    for(i = 0 ; i < n ; i++)
    {
        printf("\n Give us the %d element \t" ,i+1);
        scanf("%d", &x);
        insurt(x);
       

    }
     printLinkedList();
}
void insurt(int a)
{
    //creates a node block in memory using malloc function
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    (*temp).data = a;
    temp->link = NULL;
    if(head != NULL)
    {
        temp->link = head;
    }
    head = temp; 
}
void printLinkedList()
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("\n  NodesAddress = %d NodeData = %d NextNodeAddress = %d \n",temp,temp->data,temp->link);
        temp = temp->link;
        
    }
}
