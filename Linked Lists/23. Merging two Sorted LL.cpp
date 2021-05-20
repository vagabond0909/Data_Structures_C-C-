#include<iostream>
#include<stdio.h>
#include<stdlib.h>>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;

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
void create1(int A[],int n)
{
	int i;
	struct Node *t, *last;
	
	second = (struct Node *)malloc(sizeof(struct Node));
	
	second -> data = A[0];
	second-> next = NULL;
	
	last = second;
	
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
	cout<<endl;
}

void merge(Node *p, Node *q)
{
	Node *last;
	
	if(first -> data < second -> data)
	{
		third = last = first;
		first = first -> next;
		last -> next = NULL;	
	}
	else
	{
		third = last =second;
		second = second -> next;
		last -> next = NULL;
	}
	
	while(first != NULL && second!= NULL)
	{
		if(first -> data < second -> data)
		{
			last -> next = first;
			last = first;
			first = first ->next;
			last -> next = NULL;
		}
		else
		{
			last -> next = second;
			last = second;
			second = second ->next;
			last -> next = NULL;
		}
	}
	if(first != NULL)
	{
		last -> next = first;
	}
	else
	{
		last -> next = second;
	}
}

int main()
{
	int A[] = {3,5,7,10,15};
	int B[] = {10,20,30,40,50};
	create(A,5);
	create1(B,5);
	
	Display(first);
	Display(second);
	
	merge(first, second);
	Display(third);
	return 0;
}
