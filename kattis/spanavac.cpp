#include <bits/stdc++.h>
  
using namespace std;


int main()
{
  long long h, m, tempM;
  cin >> h >> m;

  m= m - 45;

  if(m<0) 
  {
    m = m + 60;
    h = h -1;
  }

  if(h<0)
  {
    h = 23;
  }

  cout << h <<" "<< m << endl;


  return 0;
}
