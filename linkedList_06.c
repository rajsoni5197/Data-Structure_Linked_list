//function to reverse the linked list through recursion .
void ReversedLinkedListRecursion(struct Node* p)
{
    if(p->next == NULL)
    {
        head = p;
        return;
    }
    ReversedLinkedListRecursion(p->next);
    struct Node* t = p->next;
    t->next=p;
    p->next = NULL;
    return;
}
