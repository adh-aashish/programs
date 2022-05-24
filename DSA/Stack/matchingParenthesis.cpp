//matchingParenthis.cpp
//this program uses stack to check validity of parenthesis in an expression

#include <iostream>
#include <cstring>

using namespace std;

constexpr int  MAX_STACK = 100;

bool isEmpty(struct Stack *s);
bool isFull(struct Stack *s);
void push(struct Stack *s, char p);
char pop(struct Stack *s);
bool checkValidity(char exp[]);

//implementing Stack in C
struct Stack
{
  int top;
  char item[MAX_STACK];
};

int main()
{
  char exp[] = "}]";
  if(checkValidity(exp))
  {
    cout<<"matchingParenthesis"<<endl;
  }
  else
  {
    cout<<"No matchingParenthesis"<<endl;
  }
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

bool checkValidity(char exp[])
{
  //initilaizing an empty stack
  struct Stack p;
  p.top = -1;
  int i =0;
  char t;
  while(*(exp+i) != '\0')
  {
    if (exp[i] == '{' || exp[i] =='[') 
    {
      push(&p, exp[i]);
    }

    if (exp[i] == '}' || exp[i] ==']') 
    {
      t = pop(&p);
      if((t == '{' && exp[i] == ']') || (t == '[' && exp[i] == '}') || t == '@') 
      {
        return false;
      }
    }
    i++;
  }
  return true;
}

