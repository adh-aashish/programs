#include <bits/stdc++.h>
  
using namespace std;


int main()
{
  string pattern;
  cin>>pattern;
  int res=1;
  for(int i=0; i<pattern.size(); i++)
  {
    if(pattern[i]=='A')
    {
      if(res ==1) 
      {
        res = 2;
      }
      else if(res == 2)
      {
        res = 1;
      }
    }
    if(pattern[i]=='B')
    {
      if(res ==2) 
      {
        res = 3;
      }
      else if(res == 3)
      {
        res = 2;
      }
    }

    if(pattern[i]=='C')
    {
      if(res ==3) 
      {
        res = 1;
      }
      else if(res == 1)
      {
        res = 3;
      }
    }
  }

  cout<< res << endl;

  return 0;
}
