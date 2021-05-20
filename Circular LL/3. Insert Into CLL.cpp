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

void Insert(Node *p, int index, int x)
{
	Node *t;
	int i;
	
	if(index<0 || index > Length(head))
	{
		return ;
	}
		if(index == 0)
		{
			t = new Node;
			t->data = x;
			if(head == NULL)
			{
				head = t;
				head -> next = head;
			}
			else
			{
				while(p->next != head)
				{
					p = p-> next;
				}
				p->next = t;
				t -> next = head;
				head = t;
			}
		}
		else
		{
			t = new Node;	
			t -> data =  x;
			for(i=1;i<index; i++) 
			{
				p = p -> next;
			}
			t -> next = p->next;
			p->next = t;	
		}	
}

int main ()
{
	int A[] ={2,3,4,5,6};
	
	create(A,5);
	
	Insert(head,0,10);
	RDisplay(head);	
	return 0;
}
