#include <iostream>

using namespace std;

template <typename T>
class Node
{
  public:
    T data;
    Node* link;
    Node* head;
  public:
    Node()
    {
      head = NULL;
    }

    ~Node()
    {
      Node<int>* temp = new Node<int>;
      Node<int>* temp1 = new Node<int>;
      temp = head;
      while(temp1->link != NULL)
      {
        temp = temp1;
        temp1 = temp->link;
        delete temp;
      }
      temp1 = temp1->link;
      delete temp1; 
      delete head;
    }

    void insertLast( T el)
    {
      Node<int>* temp = new Node<int>;

      //New Node
      Node<int>* newNode = new Node<int>;
      newNode->data = el;
      newNode->link = NULL;

      //check if it is the first node
      temp = head;
      if(temp == NULL)
      {
        head = newNode;
      }
      else
      {
        while(temp->link != NULL)
        {
          temp = temp->link;
        }
        temp->link=newNode;
      }
    }

    void insertAt(T refData, T el) //insert after the reference Data
    {
      Node* temp = new Node<int>;
      temp = head;
      while(temp->data != refData)
      {
        temp = temp->link;
      }
      Node* newNode = new Node<int>;
      newNode->data = el;
      newNode->link = temp->link;
      temp->link = newNode;
    }

    void insertBeg(T el)
    {
      Node<int>* newNode = new Node<int>;
      newNode->data = el;
      newNode->link = head;
      head = newNode;
    }

    void displayList()
    {
      Node<int>* temp = new Node<int>;
      temp = head;
      if(temp == NULL)
        return;
      while(temp->link != NULL)
      {
        std::cout << temp->data << " ";
        temp = temp->link;
      }
      std::cout << temp->data << std::endl;
    }

    void deleteBeg()
    {
      if(head == NULL)
        return;

      Node* temp = new Node<int>;
      temp = head->link;
      delete head;
      head = temp; 
    }

    void deleteLast()
    {
      if(head == NULL)
        return;
      Node* temp = new Node<int>;
      temp = head;
      while(temp->link->link != NULL)
      {
        temp = temp->link;
      }
      //temp is n-1th node
      Node* temp1 = new Node<int>;
      temp1 = temp->link;
      //temp1 is nth node
      
      temp->link = NULL;
      delete temp1;
    }

    void deleteAt(T refData)
    {
      Node* temp = new Node<int>;
      temp = head;

      while(temp->link->data != refData)
      {
        temp = temp->link;
      }
      //temp has n-1 node

      Node* temp1 = new Node<int>;
      temp1 = temp->link;
      //temp1 has nth node

      temp->link = temp1->link;//fix the link
      delete temp1;//free the memory
   }

   void reverse()
   {
     Node *curr,*prev,*next;
     curr = head;
     prev = NULL;

     while(curr != NULL)
     {
       next = curr->link;
       curr->link = prev;
       prev = curr;
       curr = next;
     }
       head = prev;
   }
};

int main()
{
  Node<int> l;
  l.insertBeg(1);
  l.insertLast(3);
  l.insertLast(4);
  l.insertLast(5);
  l.insertLast(6);
  l.insertAt(1,2);
  l.displayList();
  l.reverse();
  l.displayList();
}
