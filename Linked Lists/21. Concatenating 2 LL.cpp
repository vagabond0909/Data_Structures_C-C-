#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
}*first= NULL, *second = NULL;

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
	second -> next = NULL;
	
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

void concatinate(Node *p, Node *q)
{
	p = first;
	q = second;
	while(p->next)
	{
		p = p->next;
	}
	p->next = second;
	second = NULL;
}


int main()
{
	int A[] = {3, 5, 7, 10, 15};
	int B[] = {9, 5, 4, 1, 12};
	int n = sizeof(A)/sizeof(A[0]);
	int m = sizeof(B)/sizeof(B[0]);
	
	create(A,n);
	Display(first);
	cout<<endl;
	create1(B,m);
	Display(second);
	cout<<"\nAfter Concatination: "<<endl;
	concatinate(first, second);
	Display(first);
	return 0;
}
