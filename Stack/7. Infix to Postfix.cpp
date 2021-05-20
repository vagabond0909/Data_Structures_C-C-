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

int pre(char x)
{
	if(x =='+' || x == '-')
	{
		return 1;
	}
	else if(x=='*' || x=='/')
	{
		return 2;
	}
	return 0;
}


int isOperand(char x)
{
	if(x=='+' || x=='-' || x=='*' || x=='/')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


char *InToPost(char *infix)
{
	int i=0, j=0;
	char *postfix;
	
	long int len = strlen(infix);
	
	postfix = (char *)malloc((len+2) *sizeof(char));
	
	while(infix[i]!='\0')
	{
		if(isOperand(infix[i]))
		{
			postfix[j++] = infix[i++];
		}
		else
		{
			if(pre(infix[i])>pre(top->data))
			{
				push(infix[i++]);
			}
			else
			{
				postfix[j++]=pop();
			}
		}
	}
	
	while(top!=NULL)
	{
		postfix[j++]=pop();
	}
	postfix[j]='\0';
	
	return postfix;
}




int main()
{
	char *infix= "a+b*c-d/e";
	push('#');
	cout<<infix<<endl;
	char *postfix=InToPost(infix);
	
	cout<<"\n"<<postfix<<endl;

	return 0;
}
