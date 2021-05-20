#include<bits/stdc++.h>

using namespace std;

struct Node
{
	char data;
	struct Node *next;
}*top=NULL;

void push(char x)
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

char pop()
{
	Node *t;
	char x =-1;
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
	char r=t?1:0;
	delete(t);
	return r;
}

int isBalanced(char *exp)
{
	int i;
	
	for(int i=0; exp[i]!='\0';i++)
	{
		if(exp[i]=='(')
		{
			push(exp[i]);
		}
		else if(exp[i]==')')
		{
			if(top==NULL)
			{
				return false;
			}
			pop();
		}
	}
	if(top==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}


int main()
{
	char *exp = "((a+b) * (c-d)";
	cout<<exp<<endl;
	cout<<isBalanced(exp)<<endl;
	return 0;
}
