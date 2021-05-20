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

bool checkSorted(Node *p)
{
	int x = -32678;
	p =first;
	while(p)
	{
		if(p->data < x)
		{
			return false;
		}
		
		x = p->data;
		p = p->next;
	}
	return true;
}
int main()
{
	int A[] = {3,5,4,10,15};
	int n = sizeof(A)/sizeof(A[0]);
	int x;
	
	create(A,n);
	Display(first);
	cout<<"\nIs Given LL is Sorted: "<<endl;
	cout<<checkSorted(first)<<endl;
	return 0;
}
