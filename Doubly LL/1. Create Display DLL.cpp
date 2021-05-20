#include<bits/stdc++.h>

using namespace std;

struct Node
{
	Node *prev;
	Node *next;
	int data;
} *first =NULL;

void create(int A[], int n)
{
	Node *t, *last;
	int i;
	
	first = new Node;
	first -> data = A[0];
	first -> prev = first -> next = NULL;
	last = first;
	
	for(i=1;i<n;i++)
	{
		t = new Node;
		t->data = A[i];
		t -> next = last -> next;
		t->prev = last;
		last -> next = t;
		last = t;
		
	}	
}

void Display(Node *p)
{
	while(p)
	{
		cout<<p -> data<<" ";
		p = p->next;
	}
	cout<<endl;
}

int Length(Node *p)
{
	int len = 0;
	while(p)
	{
		len++;
		p = p->next;
	}
	return len;
}
int main()
{
	int A[] = { 10, 20 , 30 , 40 , 50 };
	
	create(A,5);
	
	cout<<"DLL IS: "<<endl;
	Display(first);
	
	cout<<"Length of DLL is: "<<Length(first)<<endl;
	
	return 0;
}
