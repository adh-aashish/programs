#include <iostream>
using namespace std;

class CirculaLL
{
  private:
    int data;
    CirculaLL* next;
    CirculaLL* head;
  public:
    CirculaLL()
    {
      head = NULL;
    }
    void insertAt(int el,int n)
    {
      CirculaLL* newNode = new CirculaLL;
      CirculaLL* temp; 
      if(n==1)
      {
        temp = head;
        if(head == NULL)
        {
          newNode->data = el;
          newNode->next = newNode;
          head = newNode;
          return;
        }
        newNode->next = temp->next;
        do
        {
          temp = temp->next;
        }while(temp->next != head); //traverse to the last node
        head = newNode;
        newNode->data = el;

        temp -> next = head;
      }
      else
      {
        temp = head;
        for(int i=0;i<n-2;i++)
        {
          temp = temp->next;
        }
        newNode->data = el;
        newNode->next= temp->next;
        temp->next = newNode;
      }
    }

    void insertBeg(int el)
    {
      CirculaLL* newNode = new CirculaLL;
      CirculaLL* temp;
      temp = head;
      do
      {
        temp = temp->next;
      }while(temp->next != head); //traverse to the last node


      newNode->data = el;
      newNode->next = head;
      head = newNode;

      temp->next = head;
    }

    void deleteAt(int n)
    {
      CirculaLL*temp,*temp1;
      temp = head;
      if(n==1)
      {
        if(head==NULL) return;
        temp1 = head;
        head = temp -> next;//new head
        do
        {
          temp = temp->next;
        }while(temp->next != temp1); //traverse to the last node
        delete temp1;
        temp -> next = head;
        return;
      }
      for(int i=0;i<n-2;i++)
      {
        temp = temp->next;
      }
      temp1 = temp->next;
      temp->next = temp->next->next;
      delete temp1;
    }

    void display()
    {
      CirculaLL* temp = head;
      do
      {
        cout<<temp->data<<" ";
        temp = temp->next;
      }while(temp!=head);
      cout<<endl;
    }
};

int main()
{
  CirculaLL c;
  c.insertAt(10,1);
  c.insertAt(20,2);
  c.insertAt(30,3);
  c.insertAt(40,4);
  c.insertAt(5,1);
  c.insertBeg(0);
  c.display();
  c.deleteAt(1);
  c.deleteAt(3);
  c.display();
}

