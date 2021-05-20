#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
}*top=NULL;

void push(int x)
{
	struct Node *t;
	t = new Node;
	if(t==NULL)
	{
		cout<<"Stack is FULL!"<<endl;
	}
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}

int pop()
{
	Node *t;
	int x =-1;
	if(top == NULL)
	{
		cout<<"STACK IS EMPTY"<<endl;
	}
	else
	{
		t = top;
		top=top -> next;
		x = t->data;
		delete(t);
	}
	return x;
}

void Display()
{
	struct Node *p;
	p = top;;
	while(p!=NULL)
	{
		cout<<p->data<<" | ";
		p = p->next;
	}
	cout<<endl;
}

int stackTop()
{
	if(top!=NULL)
	{
		return top->data;
	}
	else
	{
		return -1;
	}
}
int isEmpty()
{
	if(top!=NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

isFull()
{
	Node *t  = new Node;
	int r=t?1:0;
	delete(t);
	return r;
}
int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	
	Display();
	
	cout<<pop()<<endl;
	
	Display();
	
	cout<<"STACK TOP: "<<stackTop()<<endl;
	cout<<"IS EMPTY: "<<isEmpty()<<endl;
	
	cout<<"IS FULL: "<<isFull()<<endl;
	return 0;
}
