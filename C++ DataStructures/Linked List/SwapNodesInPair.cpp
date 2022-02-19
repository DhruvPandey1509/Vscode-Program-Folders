#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;

} nodetype;

void insert(nodetype **last, int value)
{
    nodetype *p = NULL;
    p = (nodetype *)malloc(sizeof(nodetype));
    if (p != NULL)
    {
        p->data = value;
        if (*last == NULL)
        {
            *last = p;
        }
        else
        {
            (*last)->next = p;
            *last = p;
        }

        (*last)->next = NULL;
    }
}

void display(nodetype *f1)
{
    if (f1 == NULL)
    {
        printf("Empty\n");
        return;
    }

    while (f1 != NULL)
    {
        printf("%d ", f1->data);
        f1 = f1->next;
    }

    printf("\n");
}
void displayAlternate(nodetype *f1)
{
    while (f1 != NULL)
    {
        printf("%d ", f1->data);
        f1 = f1->next->next;
    }
    printf("\n");
}
void evenAfterOdd(nodetype **f)
{
    nodetype *odd = *f;
    nodetype *even = (*f)->next;
    nodetype *evenStart = even;

    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;
    if (odd->next != NULL)
    {
        even->next == NULL;
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
nodetype *swapPair(nodetype *head)
{
    if(!head || !(head->next))
    {
        return head;
    }

    nodetype *n1 = head, *n2 = head->next;
    while(n1->next != NULL && n2 != NULL)
    {
        swap(&(n1->data), &(n2->data));
        if(n2->next == NULL)
        {
            break;
        }
        n1 = n2->next;
        n2 = n1->next;
    }

    return head;
}
int main()
{
    nodetype *head = NULL, *last = NULL;
    insert(&last, 1);
    head = last;
    insert(&last, 2);
    insert(&last, 3);
    insert(&last, 4);
    display(head);
    head = swapPair(head);
    display(head);

    return 0;
}