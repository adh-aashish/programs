#include <iostream>

using namespace std;
constexpr int MAX_SIZE = 5;

template <typename T>
class Deque
{
  private:
    int front, rear;
    T arr[MAX_SIZE];

  public:
    Deque()
    {
      front = -1;
      rear = -1;
    }
    
    void insertBeg(T el)
    {
      if((front==0 && rear==MAX_SIZE-1) || rear == front-1)
      {
        std::cout << "Overflow" << std::endl;
        return;
      }
      else if(front==-1 && rear==-1)
      {
        front =0;
        rear=0;
      }
      else if(front==0)
      {
        front = MAX_SIZE-1;
      }
      else 
      {
        front--;
      }
      arr[front] = el;
    }

    void insertLast(T el)
    {
      if((front==0 && rear==MAX_SIZE-1) || front == rear+1)//can be replace by if front == (rear+1)%MAX_SIZE
      {
        std::cout << "Overflow" << std::endl;
        return;
      }
      else if(front==-1 && rear==-1)
      {
        front =0;
        rear=0;
      }
      else if(rear==MAX_SIZE-1 && front!=0)
      {
        rear = 0;
      }
      else
      {
        rear++;
      }
      arr[rear] = el;
    }

    T deleteBeg()
    {
      if(front<0)
      {
        std::cout << "Underflow" << std::endl;
        return -9999;
      }
      T temp = arr[front];
      if (front==rear)
      {
        front =-1;
        rear = -1;
      }
      else if(front == MAX_SIZE-1)
      {
        front = 0;
      }
      else
      {
        front++;
      }
      return temp;
    }

    T deleteLast()
    {
      if(front<0)
      {
        std::cout << "Underflow" << std::endl;
        return -9999;
      }
      T temp = arr[rear];
      if (front==rear)
      {
        front =-1;
        rear = -1;
      }
      else if(rear==0 /*&& front!=0*/)
      {
        rear = MAX_SIZE-1;
      }
      else
      {
        rear--;
      }
      return temp;
    }

    void display()
    {
      int i = front;
      while(i!=rear)
      {
        std::cout << arr[i] << "\t";
        i = (i+1)%MAX_SIZE;
      }
      std::cout<< arr[rear]<< std::endl;
    }
};

int main()
{
  Deque<int> dq;
  dq.insertBeg(2);
  dq.insertBeg(5);
  dq.insertLast(6);
  dq.insertLast(7);
  dq.insertBeg(9);
  dq.deleteBeg();
  dq.insertBeg(10);
  dq.deleteLast();
  dq.insertLast(6);
  dq.display();

}
