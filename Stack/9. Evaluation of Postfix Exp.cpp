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

int Eval(char *postfix)
{
 int i=0;
 int x1,x2,r=0 ;

 for(i=0;postfix[i]!='\0';i++)
 {
 	if(isOperand(postfix[i]))
 	{
 		push(postfix[i]-'0');
 	}
 	else
 	{
 		x2=pop();
		x1=pop();
		
 		switch(postfix[i])
 		{
 			case '+':r=x1+x2; break;
 			case '-':r=x1-x2; break;
 			case '*':r=x1*x2; break;
 			case '/':r=x1/x2; break;
 		}
 		push(r);
 	}
 }
 return top->data;
}

int main()
{
	char *postfix = "234*+82/-";
	cout<<"Postfix exp: "<<postfix;
	cout<<"\n Result is: "<<Eval(postfix)<<endl;

	return 0;
}
