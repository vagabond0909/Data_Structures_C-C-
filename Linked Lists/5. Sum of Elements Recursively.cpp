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

int sum = 0;
int AddR(struct Node *p)
{
	if(p==NULL)
	{
		return 0;
	}
	else
	{
		return AddR(p->next) + p -> data;
	}
}

int main()
{
	int A[] = {3,5,7,10,15};
	int n = sizeof(A)/sizeof(A[0]);
	
	create(A,n);
	Display(first);
	cout<<"\n"<<AddR(first);
	return 0;
}
