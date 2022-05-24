#include <iostream>
using namespace std;

int fact(int n)
{
  if(n==1)
  {
    return 1;
  }
  return (n*fact(n-1));
}

int factTail(int n, int result=1)
{
  if(n==0) return result;
  return (factTail(n-1,n*result));
}


int main()
{
  cout<<fact(6)<<endl;
  cout<<factTail(6)<<endl;
}
