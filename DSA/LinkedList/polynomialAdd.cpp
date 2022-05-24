#include <iostream>
using namespace std;

struct Node
{
  int coeff;
  int pow;
  Node* link;
};

void createNode(struct Node** poly, int c,int p)
{
  struct Node* newNode = new Node();
  newNode->coeff = c;
  newNode->pow = p;
  newNode->link = NULL;
  if(*(poly)==NULL)
  {
    *(poly) = newNode;
    return;
  }
  struct Node* temp = *poly;
  while(temp->link !=NULL)
  {
    temp = temp->link;
  }
  temp->link = newNode;
}

void getExpression(struct Node** poly)
{
  int n,c,p;
  cout<<"Enter the number of terms:\t";
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cout<<"Coefficient:\t";
    cin>>c;
    cout<<"Power:\t";
    cin>>p;
    createNode(poly,c,p);
  }
}

void display(struct Node** poly)
{
  struct Node* temp = *poly;
  while(temp->link!=NULL)
  {
    cout<<temp->coeff<<"x^"<<temp->pow<<" + ";
    temp=temp->link;
  }
  cout<<temp->coeff<<"x^"<<temp->pow<<endl;
}

void polyAdd(struct Node**poly,struct Node* poly1,struct Node* poly2)
{
  while(poly1!=NULL && poly2!=NULL)
  {
    if(poly1->pow == poly2->pow)
    {
      createNode(poly,(poly1->coeff + poly2->coeff),poly1->pow);
      poly1=poly1->link;
      poly2=poly2->link;
    }
    else if(poly1->pow > poly2->pow)
    {
      createNode(poly,poly1->coeff,poly1->pow);
      poly1=poly1->link;
    }
    else
    {
      createNode(poly,poly2->coeff,poly2->pow);
      poly2=poly2->link;
    }
  }
  while(poly1!=NULL)
  {
    createNode(poly,poly1->coeff,poly1->pow);
    poly1 = poly1->link;
  }
  while(poly2!=NULL)
  {
    createNode(poly,poly2->coeff,poly2->pow);
    poly2 = poly2->link;
  }
}

int main()
{
  struct Node* poly1=NULL,*poly2=NULL,*poly=NULL;
  cout<<"For Expression 1\n";
  getExpression(&poly1);
  cout<<"For Expression 2\n";
  getExpression(&poly2);
  cout<<endl<<"Expression 1: ";
  display(&poly1);
  cout<<"Expression 2: ";
  display(&poly2);

  cout<<"Additon: ";
  polyAdd(&poly,poly1,poly2);
  display(&poly);
}
