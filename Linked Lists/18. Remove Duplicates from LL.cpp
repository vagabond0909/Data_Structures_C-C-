#include<bits/stdc++.h>
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

void removeDuplicate(Node *p)
{
	Node *q;
	p = first;
	q = first->next;
	while(q)
	{
		if(p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p -> next = q -> next;
			delete q;
			q = p -> next;
		}
	}
	
}
int main()
{
	int A[] = {3,5,5,8,8,8};
	int n = sizeof(A)/sizeof(A[0]);
	int x;
	
	create(A,n);
	Display(first);
	cout<<"\nAfter Removing Duplicates LL is: "<<endl;
	removeDuplicate(first);
	Display(first);
	return 0;
}
