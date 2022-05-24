//recursive_expression.cpp
//this program checks if the expression is valid or not.
//it is recursive because it calls itself
//the definition of expression are:
// expression = term + term or term
// term = factor * factor or factor
// factor = letter or (expression enclosed in parenthesis)

#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

bool expr(char str[],int* length, int*ppos);
bool term(char str[],int* length, int*ppos);
bool factor(char str[],int* length, int*ppos);
char getsym(char str[],int* length, int*ppos);

int main()
{
  char str[] = "(a+b)*(c)";
  int pos=0;
  /* cout<<"Enter the expression:\t"<<endl; */
  /* cin>>str; */
  int len = strlen(str);
  if(expr(str,&len,&pos) && pos>=len)
    cout<<"Valid Expression\n";
  else
    cout<<"Invalid Expression\n";
}

char getsym(char str[],int* length, int*ppos)
{
  char c;
  if(*ppos < *length)
    c = str[*ppos];
  else
    c =' ';
  (*ppos)++;
  return c;
}

bool expr(char str[],int* length, int*ppos)
{
  if(!term(str,length,ppos))
    return false;

  if(getsym(str,length,ppos) != '+')
  {
    (*ppos)--;
    return true;
  }

  return (term(str,length,ppos));
}

bool term(char str[],int* length, int*ppos)
{
  if(!factor(str,length,ppos))
    return false;

  if(getsym(str,length,ppos) != '*')
  {
    (*ppos)--;
    return true;
  }
  return (factor(str,length,ppos));
}


bool factor(char str[],int* length, int*ppos)
{

  char c;
  if((c = getsym(str,length,ppos)) != '(')
  {
    return (isalpha(c));
  }
  return (expr(str,length,ppos) && getsym(str,length,ppos) == ')');
}
