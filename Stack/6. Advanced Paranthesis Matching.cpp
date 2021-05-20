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


int empty()
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
	//create map
	
	map<char, char> mapping;
	mapping['}']='{';
	mapping[')']='(';
	mapping[']']='[';
	
	//create map iterator
	map<char, char>::iterator itr;
	
	//create stack 
	stack<char> stk; 
	
	for(int i=0; exp[i]!='\0';i++)
	{
		if(exp[i]=='{'||exp[i]=='['||exp[i]=='(')
		{
			push(exp[i]);
		}
		else if(exp[i]=='}'||exp[i]==']'||exp[i]==')')
		{
			if(top==NULL)
			{
				return false;
			}
			else
			{
				char temp = stk.top();
				itr = mapping.find(exp[i]);
				
				if(temp == itr->second)
				{
					//itr->first is key; itr->second is value
					stk.pop();
				}
				else
				{
					return false;
				}
			}
		}
	}
	return stk.empty() ? true: false;
	
}


int main()
{
	char *exp = "{([a+b]*[c-d])/e}";
	cout<<exp<<endl;
	cout<<isBalanced(exp)<<endl;
	return 0;
}
