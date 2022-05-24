#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node* link;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int el)
{
  struct Node* newNode = new Node();
  newNode->data = el;
  newNode->link = NULL;
  if(rear == NULL)
  {
    front = newNode;
    rear = newNode;
    return;
  }
  rear->link = newNode;
  rear = newNode;
}

int dequeue()
{
  if(front == NULL)
  {
    cout<<"Underflow"<<endl;
    exit(1);
    return -999;
  }
  struct Node* temp = front;
  int el = front->data;
  front = front->link;
  if(front == NULL)
  {
    rear = NULL;
  }
  delete temp;
  return el;
}

void display()
{
  struct Node* temp = front;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp = temp->link;
  }
  cout<<endl;
}

int main()
{
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  cout<<dequeue();
  cout<<dequeue();
  cout<<dequeue();
  cout<<dequeue()<<endl;
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  display();
}
