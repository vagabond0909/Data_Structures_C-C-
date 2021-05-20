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

void reverseLL(Node *p)
{
	p =first;
	int A[count(first)];
	
	int i =0;
	while(p)
	{
		A[i] = p -> data;
		p = p -> next;
		i++;
	}
	p = first,i--;
	while(p)
	{
		p->data = A[i--];
		p = p -> next;
	}
}

int main()
{
	int A[] = {3,5,7,10,15};
	int n = sizeof(A)/sizeof(A[0]);
	int x;
	
	create(A,n);
	Display(first);
	reverseLL(first);
	cout<<endl;
	Display(first);
	return 0;
}
