#include "bits/stdc++.h"
using namespace std;
//Singly Linked List Implementation using Class in C++;
// class node
// {
//     public:
//     int data;
//     node *next;
//     node (int value)
//     {
//         this->data = value;
//         this->next = NULL;
//     }
// };

// void insertAtTail(node **f1)
// {
//     int value;
//     cout<<"Enter the value : ";
//     cin>>value;
//     node *n = new node(value);

//     if(*f1 == NULL)
//     {
//         *f1 = n;
//         return;
//     }

//     node *temp = NULL;
//     temp = *f1;
//     while(temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = n;
// }

// void display(node* f1)
// {
//     if(f1 == NULL)
//     {
//         cout<<"Empty"<<endl;
//         return;
//     }

//     while(f1 != NULL)
//     {
//         cout<<f1->data<<" ";
//         f1 = f1->next;
//     }
// }

// int main()
// {
//     node *f = NULL;
//     insertAtTail(&f);
//     insertAtTail(&f);
//     insertAtTail(&f);
//     insertAtTail(&f);
//     insertAtTail(&f);
//     insertAtTail(&f);
//     insertAtTail(&f);

//     display(f);
//     return 0;
// }

//Singly Linked List Implementation using Structure in c++
// typedef struct node
// {
//     int data;
//     struct node *next;
// } nodetype;

// void insert(nodetype **l, nodetype **r)
// {
//     int value;
//     cout << "Enter the value : ";
//     cin >> value;

//     nodetype *p = NULL;
//     p = new nodetype();

//     if (p != NULL)
//     {
//         p->data = value;
//         if (*l == NULL && *r == NULL)
//         {
//             *l = *r = p;
//         }
//         else
//         {
//             (*r)->next = p;
//             *r = p;
//         }
//         (*r)->next = NULL;
//     }
// }

// void display(nodetype *f1)
// {
//     if (f1 == NULL)
//     {
//         cout << "Empty" << endl;
//         return;
//     }

//     while (f1 != NULL)
//     {
//         cout << f1->data << " ";
//         f1 = f1->next;
//     }
// }

// void deleteNode(nodetype **f1, nodetype **r1)
// {
//     int value;
//     cout << "Enter the value : ";
//     cin >> value;

//     if ((*f1)->data == value)
//     {
//         nodetype *todelete = *f1;
//         *f1 = (*f1)->next;
//         free(todelete);
//         return;
//     }

//     nodetype *p = NULL;
//     nodetype *temp = NULL;
//     p = (*f1)->next;
//     temp = *f1;
//     while (p != NULL)
//     {
//         if (p->data == value)
//         {
//             temp->next = p->next;
//             free(p);
//             return;
//         }
//         p = p->next;
//         temp = temp->next;
//     }
//     cout << "No value : " << value << " found!" << endl;
// }

// int main()
// {

//     nodetype *f = NULL, *r = NULL;
//     insert(&f, &r);
//     insert(&f, &r);
//     insert(&f, &r);
//     insert(&f, &r);
//     insert(&f, &r);
//     insert(&f, &r);
//     display(f);

//     deleteNode(&f,&r);
//     display(f);
//     return 0;
// }