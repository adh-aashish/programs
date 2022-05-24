//infix_to_postfix.cpp
//This program creates a postfix expression from infix expression using Stack

#include <iostream>
#include <cstring>

//Implementation of Stack
using namespace std;
constexpr int  MAX_STACK = 100;

bool isEmpty(struct Stack *s);
bool isFull(struct Stack *s);
void push(struct Stack *s, char p);
char pop(struct Stack *s);
bool checkValidity(char exp[]);
char stacktop(struct Stack *s);

//Implementation of postfix 
void postfix(struct Stack *s, char infix[]);
bool isOperand(char c);
bool prcd(char a, char b);

struct Stack
{
  int top;
  char item[MAX_STACK];
};

int main()
{
  struct Stack s;
  s.top = -1;
  char exp[] = "(a+b)*(c-d)";
  postfix(&s,exp);
}

bool prcd(char a, char b)
{
  if(a=='$' && (b=='/' || b=='*' || b=='+' || b=='-'))
  {
    return true;
  }

  if(a=='*' && (b=='+' || b=='-'))
  {
    return true;
  }

  if(a=='/' && (b=='*' || b=='+' || b=='-'))
  {
    return true;
  }

  if(a=='+' && b=='-')
  {
    return true;
  }


  if(b=='(')
  {
    return false;
  }

  if(a=='(')
  {
    return false;
  }

  if(b==')')
  {
    return true;
  }

  if(a=='('&& b==')')
  {
    return false;
  }

  if(a==b)
  {
    return false;
  }
  return false;
}

void postfix(struct Stack *s, char infix[])
{
  char pfix[25];
  int i =0,outpos=0;
  char sym,topsym;
  for(int pos=0;(sym = infix[pos])!='\0';pos++)
  {
    if(isOperand(sym))
    {
      pfix[outpos++] = sym;
    }
    else
    {
       while(prcd(stacktop(s),sym))
      {
        //this loop is only run when new symbol read 
        //has less precedence than stacktop
        topsym = pop(s);
        if(topsym != '(')
        {
          pfix[outpos++]= topsym;
        }
      }
      if(sym != ')')
      {
        push(s,sym);
      }
    }
  }
  while(!isEmpty(s))
  {
    topsym = pop(s);
    if(topsym != '(')
    {
      pfix[outpos++]= topsym;
    }
  }
  cout <<"the postfix is"<< pfix <<endl;
}

void push(struct Stack *s, char p)
{
  if(!isFull(s))
  {
    s->item[++(s->top)] = p;
  }
  else
  {
    printf("The stack is full.");
  }
}

char pop(struct Stack *s)
{
  if(!isEmpty(s))
  {
   return s->item[(s->top)--];
  }
  else
  {
    return '@';
  }
}

bool isEmpty(struct Stack *s)
{
  return (s->top == -1);
}

bool isFull(struct Stack *s)
{
  return (s->top == MAX_STACK-1);
}

char stacktop(struct Stack *s)
{
  return(s->item[s->top]);
}

bool isOperand(char c)
{
  switch (c)
  {
    case '+': return false;
    case '-': return false;
    case '/': return false;
    case '*': return false;
    case '$': return false;
    case '(': return false;
    case ')': return false;
    default: return true;
  }
}
