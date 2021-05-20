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

int count(struct Node *p)
{
	int c = 0;
	
	while(p!=NULL)
	{
		c++;
		p = p -> next;
	}
	
	return c;
}

int Rcount(struct Node *p)
{
	if(p==0)
	{
		return 0;
	}
	else
	{
		return Rcount(p->next)+1;
	}
}
int main()
{
	int A[] = {3,5,7,10,15};
	int n = sizeof(A)/sizeof(A[0]);
	
	create(A,n);
	Display(first);
	
	cout<<"NULL"<<endl;
	int cnt = count(first);
	
	cout<<"NULL"<<endl;
	int Rcnt = Rcount(first);
	
	cout<<cnt<<endl;
	cout<<Rcnt<<endl;
	return 0;
}
