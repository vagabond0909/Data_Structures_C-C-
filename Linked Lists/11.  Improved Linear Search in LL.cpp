#include<iostream>
#include<stdio.h>
#include<stdlib.h>>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
}*first = NULL;

void create(int A[],int n)
{
	int i;
	struct Node *t, *last;
	
	first = (struct Node *)malloc(sizeof(struct Node));
	
	first -> data = A[0];
	first -> next = NULL;
	
	last = first;
	
	for(i=1;i<n;i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		
		t->data = A[i];
		t -> next = NULL;
		last -> next = t;
		last = t; 
	}
}
void Display(struct Node *p)
{
	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p = p->next;
	}
	cout<<"NULL"<<endl;
}

Node* Search(Node *p, int key)
{
	Node *q = NULL;

	while(p)
	{
		if(key  == p->data)
		{
			q->next = p->next;
			p->next = first;
			first = q;
			
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}


int main()
{
	int A[] = {3,5,7,10,15};
	int key;
	int n = sizeof(A)/sizeof(A[0]);
	cin>>key;
	create(A,n);
	Display(first);
	cout<<Search(first,key);
	
	return 0;
}
