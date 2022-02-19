#include"bits/stdc++.h"
using namespace std;

class Node
{
	public:
	Node* next;
	int data;

	Node(int value)
	{
		data = value;
		next = NULL;
	}
};

void insertAtHead(Node* &head, int val)
{
	Node* n = new Node(val);
	n->next = head;
	head = n;
	return;
}

void insertAtTail(Node* &head, int val)
{
	Node* n = new Node(val);
	if(head == NULL)
	{
		head = n;
		return;
	}

	Node* temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = n;
}
void display(Node* head)
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
	}
	cout<<endl;
    return;
}
void deleteAtBegin(Node* &head)
{
	Node* temp = head;
	head = head->next;

	delete(temp);
}

void deleteAtEnd(Node* &head)
{
	if(head == NULL)
	{
		cout<<"Not Possible"<<endl;
	    return;
	}
	else if(head->next != NULL)
	{
		delete head;
		head = NULL;
		return;
	}
	Node* temp = head;
	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}
	delete temp->next;
	temp->next = NULL;

	return;
}
void deleteAtValue(Node* &head, int val)
{
    
	Node* temp = head;

	while(temp->next->next->data != val)
	{
		temp = temp->next;
	}
	Node* todelete = temp->next;
	temp->next = temp->next->next;

	delete todelete;
}

void deleteAtPosition(Node* &head, int pos)
{
	if(head == NULL)
	{
		cout<<"Empty List"<<endl;
	}
	Node* temp = head;
	if(temp->next = NULL)
	{
		cout<<"Not possible"<<endl;
	}
	if(pos == 0)
	{
		head = temp->next;
		free(temp);
		return;
	}
	int count = 0;
	while(count < pos-1)
    {
      temp = temp->next;
	}
	Node* todelete = temp->next;
	temp->next = temp->next->next;

	delete todelete;
}

Node* reverse(Node* &head)
{
	Node* prev = NULL;
	Node* curr = head;
	Node* next = head->next;

	while(curr != prev)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}
Node* reverseRecurssive(Node* &head)
{
	if(head == NULL || head->next == NULL)
	{
		return head;
	}

	Node* newhead = reverseRecurssive(head->next);
	head->next->next = head;
	head->next = NULL;
	return newhead;
}
Node* reversekNode(Node* &head, int k)
{
	Node* prev = NULL;
	Node* curr = head;
	Node* next;
	int count = 0;

	while(curr != NULL && count < k)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
    if(next != NULL)
	{
		head->next = reversekNode(next, k);
	}

	return prev;  
}

int main()
{
       
  	

	return 0;
}