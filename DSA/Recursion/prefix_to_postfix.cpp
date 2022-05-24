//TODO: 1)FUNCTION TO FIND THE HIGHEST LENGTH PREFIX AND RETURNS THE POSTION
//      2)CONVERT CONVERT FUNCTION THAT CALLS ITSELF RECURSIVELY
#include <iostream>
#include <cstring>
#include <string.h> 

constexpr int MAX_LENGHT = 20;

using namespace std;

void convert(char prefix[], char postfix[]);
void find(char operand1[], char operand2[], char prefix[]);
void substr(char *src, int m, int n,char str[]);

int main()
{
  char prefix[MAX_LENGHT] = "+a*bc";
  char postfix[MAX_LENGHT];
  convert(prefix,postfix);
  cout<<"the equivalent postfix is: \t"<< postfix<<endl;
}

void convert(char prefix[], char postfix[])
{
  char op[2];
  char ch;
  char operand1[MAX_LENGHT], operand2[MAX_LENGHT];
  char temp[MAX_LENGHT];
  int length = strlen(prefix);
  ch = prefix[0];
  substr(prefix,1,length-1,temp);
  strcpy(prefix,temp);
  if(isalpha(prefix[0]))
  {
    strcat(postfix,&ch);
    return;
  }
  else{
    convert(prefix,postfix);
    convert(prefix,postfix);
    strcat(postfix,&ch);
  }















/*   int length; */
/*   char op[MAX_LENGHT], operand2[MAX_LENGHT], operand1[MAX_LENGHT]; */
/*   char temp[MAX_LENGHT]; */
/*   if((length = strlen(prefix)) == 1) */
/*   { */
/*     if(!isalpha(prefix[0])) */
/*     { */
/*       cout<<"Invalid Prefix"<<endl; */
/*       exit(1); */
/*     } */
/*     if(isalpha(prefix[0])) */
/*     { */
/*       postfix[0] = prefix[0]; */
/*       postfix[1] = '\0'; */
/*  */
/*     } */
/*     return; */
/*   } */
/*   op[0] = prefix[0]; */
/*   op[1] = '\0'; */
/*   find(operand1,operand2,prefix); */
/*   if(!isalpha(operand1[0])) */
/*   { */
/*     strcpy(temp,operand1); */
/*     convert(temp,operand1); */
/*   } */
/*   if(!isalpha(operand2[0])) */
/*   { */
/*     strcpy(temp,operand2); */
/*     convert(temp,operand2); */
/*   } */
/*   strcat(postfix,operand1); */
/*   strcat(postfix,operand2); */
/*   strcat(postfix,op); */
}
/*  */
/* void find(char operand1[], char operand2[], char prefix[]) */
/* { */
/*   int i =2,j=0; */
/*   int length = strlen(prefix); */
/*   if(!isalpha(prefix[1])) */
/*   { */
/*     operand1[j] = prefix[1]; */
/*     while(isalpha(prefix[i])) */
/*     { */
/*       i++; */
/*       j++; */
/*       operand1[j] = prefix[i]; */
/*     } */
/*     j=0; */
/*     while(i<length-1) */
/*     { */
/*       operand2[j] = prefix[i]; */
/*       i++; */
/*       j++; */
/*     } */
/*   } */
/*   else */
/*   { */
/*   } */
/*  */
/*  */
/*  */
/*  */






  /* int i=0; */
  /* if(!isalpha(prefix[0])) */
  /* { */
  /*   operand1[0]=prefix[0]; */
  /*   i++; */
  /*   while(isalpha(*(prefix+i) && i<strlen(prefix))) */
  /*   { */
  /*     operand1[i] = *(prefix+i); */
  /*     i++; */
  /*     cout<<"here"; */
  /*   } */
  /*   operand1[i]='\0'; */
  /*   int j=0; */
  /*   while(i<(strlen(prefix)-1)) */
  /*   { */
  /*     operand2[j] = *(prefix+i); */
  /*     i++; */
  /*     j++; */
  /*   } */
  /*   operand2[j] = '\0'; */
  /* } */
/* } */

void substr(char src[], int m, int n,char str[])
{
    // get the length of the destination string
    int len = n - m;
 
    // allocate (len + 1) chars for destination (+1 for extra null character)
    char *dest = (char*)malloc(sizeof(char) * (len + 1));
 
    // extracts characters between m'th and n'th index from source string
    // and copy them into the destination string
    for (int i = m; i < n && (*(src + i) != '\0'); i++)
    {
        *dest = *(src + i);
        dest++;
    }
 
    // null-terminate the destination string
    *dest = '\0';
 
    // return the destination string
    strcpy(str,dest);
}
