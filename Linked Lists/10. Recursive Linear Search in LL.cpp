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

Node* Rsearch(Node *p, int key)
{
	if(p == NULL)
	{
		return NULL;
	}
	
	if(key == p->data)
	{
		return p;
	}
	
	return Rsearch(p->next, key);
}


int main()
{
	int A[] = {3,5,7,10,15};
	int key;
	int n = sizeof(A)/sizeof(A[0]);
	cin>>key;
	create(A,n);
	Display(first);
	cout<<Rsearch(first,key);
	
	return 0;
}
