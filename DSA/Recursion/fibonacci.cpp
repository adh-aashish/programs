#include <iostream>
using namespace std;

int fibo(int n)
{
  int temp;
  if(n==0)
    return 0;
  if(n==1)
    return 1;
  return (fibo(n-1)+fibo(n-2));
}

int fiboTail(int n, int a = 0, int b = 1)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fiboTail(n - 1, b, a + b);
}

int main()
{
  cout<<fibo(6)<<endl;
  cout<<fiboTail(6)<<endl;
}
