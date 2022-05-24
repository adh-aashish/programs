#include <bits/stdc++.h>
  
using namespace std;


int main()
{
  long long x,n,p[100],extra=0;

  cin >> x >> n;

  for(int i=0; i<n; i++)
  {
    cin >> p[i];
    if(p[i] <= x)
    {
      extra+= x - p[i];
    }
    else
    {
      extra = extra - (p[i] - x);
    }
  }
  cout << extra + x<<endl;
  return 0;
}
