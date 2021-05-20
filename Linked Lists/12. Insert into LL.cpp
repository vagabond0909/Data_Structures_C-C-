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

void Insert( struct Node *p, int pos, int x)
{
	struct Node *t;
	if(pos == 0)
	{
		t = new Node;
		t -> data = x;
		t->next = first;
		first = t;
	}
	else if(pos>0)
	{
		p = first;
		for(int i=0; i< (pos-1)&&p; i++)
		{
			p = p-> next;
		}
		if(p)
		{
			t= new Node;
			t->data = x;
			t -> next = p ->next;
			p -> next = t;
		}
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

int main()
{
	int A[] = {3,5,7,10,15};
	int n = sizeof(A)/sizeof(A[0]);
	int pos, x;
	cin>>pos>>x;
	
	create(A,n);
	Display(first);
	Insert( first, pos, x);
	Display(first);
	return 0;
}
