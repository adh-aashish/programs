#include <bits/stdc++.h>
  
using namespace std;


int main()
{
  long long x,y;
  cin >> x >> y;

  if(x>0 && y>0)
  {
    cout << "1" << endl;
  }
  else if (x>0 && y<0)
  {
    cout << "4" << endl;
  }
  else if (x<0 && y<0)
  {
    cout << "3" << endl;
  }
  else if (x<0 && y>0)
  {
    cout << "2" << endl;
  }

  return 0;
}
