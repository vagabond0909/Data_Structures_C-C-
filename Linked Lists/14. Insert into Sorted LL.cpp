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
	if(p!=NULL)
	{
		cout<<p->data<<"->";
		Display(p->next);
	}
}

void insertLast(int x)
{ 
	Node *last;
	Node *t = new Node;
	t -> data = x;
	t -> next = NULL;
	
	if(first == NULL)	
	{
		first = last = t;	
	}	
	else
	{
		last -> next = t;
		last = t;
	}
}

void SortedInsert(Node *p, int x)
{
	Node *q = NULL;
	
	while(p && (p->data<x))
	{
		q=p;
		p=p->next;
	}
	
	Node *t = new Node;
	t -> data = x;
	
	t->next = q->next;
	q->next = t;
}

int main()
{
	int A[] = {3,5,7,10,15};
	int n = sizeof(A)/sizeof(A[0]);
	int x;
	
	create(A,n);
	Display(first);
	cout<<"\nEnter Number: ";
	cin>>x;
	SortedInsert(first,x);
	Display(first);
	return 0;
}
