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
      front = 0;
    }
    void enqueue(T el)
    {
      if(rear == MAX_SIZE-1)
      {
        std::cout << "Overflow" << std::endl;
      }
      else
      {
        arr[++rear] = el;
      }
    }

    T dequeue()
    {
      if(rear<front)
      {
        std::cout << "Underflow" << std::endl;
        return -99999;
      }
      else
      {
        return arr[front++];
      }
    }
};



int main()
{
  Queue<int> q;
  q.dequeue();
  q.enqueue(15);
  q.enqueue(25);
  q.enqueue(35);
  q.enqueue(45);
  q.enqueue(55);
  q.dequeue();
  q.enqueue(55);
  /* q.enqueue(65); */
  /* std::cout << q.dequeue() << std::endl; */
  /* q.enqueue(25); */
  /* std::cout << q.dequeue() << std::endl; */
  /* std::cout << q.dequeue() << std::endl; */
  /* std::cout << q.dequeue() << std::endl; */
  /* std::cout << q.dequeue() << std::endl; */
  /* std::cout << q.dequeue() << std::endl; */
  /* std::cout << q.dequeue() << std::endl; */
  /* std::cout << q.dequeue() << std::endl; */
}
