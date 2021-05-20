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

int max(struct Node *p)
{
	int max = -32768;
	while(p)
	{
		if(p->data>max)
		{
			max = p->data;
		}
		p = p->next;
	}
	return max;
}

int main()
{
	int A[] = {3,5,20,7,60,10,15};
	int n = sizeof(A)/sizeof(A[0]);
	
	create(A,n);
	Display(first);
	cout<<"\n"<<max(first);
	return 0;
}
