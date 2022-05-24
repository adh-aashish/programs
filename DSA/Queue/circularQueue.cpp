#include <iostream>

using namespace std;

constexpr int MAX_SIZE = 5;

template<typename T>
class Queue
{
  private:
    int rear,front;
    T arr[MAX_SIZE];
  public:
    Queue()
    {
      rear = -1;
      front = -1;
    }

    void enqueue(T el)
    {
      if(front == -1 && rear ==-1)
      {
        front = 0;
        rear = 0;
      }
      else if((rear == MAX_SIZE-1 && front == 0) || (rear == front-1))
      {
        std::cout << "Overflow" << std::endl;
        return;
      }
      else if(rear==MAX_SIZE-1 && front!=0)
      {
        rear = 0;
      }
      else
      {
        rear++;
      }
      std::cout << "\t\trear : "<<rear<< std::endl;
      std::cout << "\t\tfront : "<<front<< std::endl;
      arr[rear] = el;
      std::cout << el  <<" is entered"<< std::endl;
    }

    T dequeue()
    {
      if((front==-1 && rear==-1))
      {
        std::cout << "Underflow" << std::endl;
        return -99999;
      }
      T temp = arr[front];
      if(front == rear)
      {
        front =-1;
        rear = -1;
      }
      else if(front==MAX_SIZE-1)
      {
        front = 0;
      }
      else
      {
        front++;
      }
      return temp; 
    }
};

int main()
{
  Queue<int> q;
  /* q.dequeue(); */
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  std::cout << q.dequeue() << std::endl;
  q.enqueue(7);
  std::cout << q.dequeue() << std::endl;
  q.enqueue(8);
  q.enqueue(9);
  std::cout << q.dequeue() << std::endl;
  std::cout << q.dequeue() << std::endl;
  std::cout << q.dequeue() << std::endl;
  std::cout << q.dequeue() << std::endl;
  std::cout << q.dequeue() << std::endl;
  std::cout << q.dequeue() << std::endl;
}
