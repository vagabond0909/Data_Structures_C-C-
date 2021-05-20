#include<bits/stdc++.h>

using namespace std;

struct Node{
	
	int data;
	struct Node *next;
	
}*head;

void create(int A[], int n)
{
	int i;
	struct Node *t,*last;
	head = new Node;
	
	head -> data = A[0];
	head -> next = head;
	last = head;
	for(int i=1;i<n;i++)
	{
		t = new Node;
		t->data = A[i];
		t -> next = last -> next;
		last ->next = t;
		last = t;
	}		
}

void RDisplay(Node *h)
{
	static int flag = 0;
	
	if(h != head || flag ==0)
	{
		flag = 1;
		cout<<h->data<<" ";
		RDisplay(h->next);
	}
}

int Length(Node *p)
{
	int len = 0;
	do
	{
		len++;
		p = p->next;
		}	while(p!=head);
		
	return len;
}

int Delete(Node *p, int index)
{
	Node *q;
	int i,x;
	
	if(index<0 || index> Length(head))
	return -1;
	
	if(index == 1)
	{
		while(p -> next != head)
		{
			p = p->next;
		}
		x = head -> data;
		if(head == p)
		{
			free(head);
			head = NULL;
		}
		else
		{
			p -> next = head->next;
			free(head);
			head = p -> next;
		}
	}
	else
	{
		for(i = 0; i<index-2; i++)
		{
			p = p->next;
		}
		q = p -> next;
		p -> next = q -> next;
		x = q -> data;
		free(q);
	}
	
	return x;
}
int main ()
{
	int A[] ={2,3,4,5,6};
	
	create(A,5);
	Delete(head,1);
	RDisplay(head);	
	return 0;
}
