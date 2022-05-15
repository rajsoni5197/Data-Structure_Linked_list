//function to print linked list recursively.
void printLinkedListRecursion(struct Node* p)
{
    if(p == NULL) return;
    printf("%d ",p->data);
    printLinkedListRecursion(p->next);
}
