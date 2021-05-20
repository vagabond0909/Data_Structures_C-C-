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

int outPre(char x)
{
	if(x =='+' || x == '-')
	{
		return 1;
	}
	else if(x=='*' || x=='/')
	{
		return 3;
	}
	else if(x=='^')
	return 6;
	else if(x=='(')
	return 7;
	else if(x==')')
	return 0;
	
	return -1;
}

int inPre(char x)
{
	if(x=='+' || x=='-')
	{
		return 2;
	}
	else if(x=='*' || x=='/')
	{
		return 4;
	}
	else if(x=='^')
	{
		return 5;
	}
	else if(x==')')
	{
		return 0;
	}
	
	return -1;
}


int isOperand(char x)
{
	if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


char *Convert(char *infix)
{
	 char* postfix = new char [strlen(infix) + 1];
 
    stack<char> stk;
 
    int i = 0;
    int j = 0;
 
    while (infix[i] != '\0'){
        if (isOperand(infix[i])){
            postfix[j++] = infix[i++];
        } else {
            if (stk.empty() || outPre(infix[i]) > inPre(stk.top())){
                stk.push(infix[i++]);
            } else if (outPre(infix[i]) == inPre(stk.top())){
                stk.pop();
            }
            else {
                postfix[j++] = stk.top();
                stk.pop();
            }
        }
    }
 
    while (! stk.empty() && stk.top() != ')'){
        postfix[j++] = stk.top();
        stk.pop();
    }
 
    postfix[j] = '\0';
 
    return postfix;
}




int main()
{
	char *infix= "((a+b)*c)-d^e^f";
	push('#');
	cout<<infix<<endl;
	char *postfix=Convert(infix);
	
	cout<<"\n"<<postfix<<endl;

	return 0;
}
