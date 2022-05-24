#include <iostream>

using namespace std;
constexpr int MAX_ELEMENT = 100;

template <class T>
class Stack
{
  private:
    int top;
    T *node;
  public:
    Stack();
    void push(T el);
    T pop();
    bool isempty();
    T stacktop();
};

template <class T>
Stack<T>::Stack()
{
  node = new T[MAX_ELEMENT];
  top = -1;
}

template <class T>
void Stack<T>::push(T el)
{
  node[++top] = el;
}

template <class T>
T Stack<T>::pop()
{
  if(isempty()) exit(1);
  return node[top--];
}

template <class T>
bool Stack<T>::isempty()
{
  if(top == -1) return true;
  return false;
}

template <class T>
T Stack<T>::stacktop()
{
  return node[top];
}

int main()
{
  Stack<int> istack;
  istack.push(10);
  cout<<istack.pop()<<endl;
}
