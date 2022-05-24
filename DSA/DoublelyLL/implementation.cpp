#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
  Node* prev;
};

struct Node* head = NULL;

Node* getNode(int el)
{
  Node* newNode = new Node();
  newNode->data = el;
  newNode->next = NULL;
  newNode->prev= NULL;
  return newNode;
}

void insertBeg(int el)
{
  if(head == NULL)
  {
    Node* newNode = getNode(el);
    head = newNode;
    return;
  }
  Node* newNode = getNode(el);
  head->prev = newNode;
  newNode->next = head;
  head = newNode;
}

void insertLast(int el)
{
  if(head == NULL)
  {
    struct Node* newNode = getNode(el);
    head = newNode;
    return;
  }
  struct Node* temp = head;
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  struct Node* newNode = getNode(el);
  temp->next = newNode;
  newNode->prev = temp;
}

void insertAfter(int el, int pos)
{
  struct Node*temp = head;
  for(int i=0;i<pos-1;i++)
  {
    if(temp == NULL)
    {
      cout<<"Index Out of Bound\n";
      return;
    }
    temp = temp->next;
  }
  struct Node* newNode = getNode(el);
  newNode->next = temp->next;
  newNode->prev = temp;
  if(temp->next != NULL)
   temp->next->prev = newNode;
  temp->next = newNode;
}

void insertBefore(int el, int pos)
{
  struct Node*temp = head;
  if(pos==1)
  {
    insertBeg(el);
    return;
  }
  for(int i=0;i<pos-2;i++)
  {
    if(temp == NULL)
    {
      cout<<"Index Out of Bound\n";
      return;
    }
    temp = temp->next;
  }
  struct Node* newNode = getNode(el);
  newNode->next = temp->next;
  newNode->prev = temp;
  if(temp->next != NULL)
    temp->next->prev = newNode;
  temp->next = newNode;
}

void deleteAfter(int pos)
{
  struct Node*temp = head;
  for(int i=0;i<pos-1;i++)
  {
    if(temp == NULL)
    {
      cout<<"Index Out of Bound\n";
      return;
    }
    temp = temp->next;
  }
  
  struct Node*temp1 = temp->next;
  temp->next = temp->next->next;
  if(temp->next != NULL)
    temp->next->prev = temp;
  delete temp1;
}

void deleteBeg()
{
  if(head==NULL)
  {
    cout<<"List is empty\n";
    return;
  }
  struct Node* temp = head;
  head = temp->next;
  head->prev = NULL;
  delete temp;
}

void deleteBefore(int pos)
{
  struct Node*temp = head;
  if(pos==1)
  {
    cout<<"Invalid Index"<<endl;
    return;
  }
  if(pos==2)
  {
    deleteBeg();
    return;
  }
  for(int i=0;i<pos-2;i++)
  {
    if(temp == NULL)
    {
      cout<<"Invalid Index\n";
      return;
    }
    temp = temp->next;
  }
  
  struct Node*temp1 = temp;
  temp = temp->prev;
  temp->next = temp->next->next;
  if(temp->next != NULL)
    temp->next->prev = temp;
  delete temp1;
}


void deleteLast()
{
  if(head==NULL)
  {
    cout<<"List is empty\n";
    return;
  }
  struct Node* temp = head;
  while(temp->next->next!=NULL)
  {
    temp = temp->next;
  }
  struct Node*temp1 = temp->next;
  temp->next = NULL;
  delete temp1;
}

void display()
{
  Node* temp = head;
  while(temp != NULL)
  {
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

void revDisplay()
{
  Node* temp = head;
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  while(temp != NULL)
  {
    cout<<temp->data<<" ";
    temp = temp->prev;
  }
  cout<<endl;
}

int main()
{
  insertBeg(10);
  insertLast(30);
  insertLast(50);
  insertLast(60);
  insertAfter(20,1);
  insertBefore(40,4);

  cout<<"After Insert Operations:\n";

  display();
  revDisplay();

  cout<<"\nDelete First and Last element:\n";

  deleteBeg();
  deleteLast();

  display();
  revDisplay();

  cout<<"\nDelete After and Before operations:\n";

  deleteAfter(2);
  deleteBefore(3);

  display();
  revDisplay();

}

