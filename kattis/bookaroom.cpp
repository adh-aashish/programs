#include <bits/stdc++.h>
  
using namespace std;

int main()
{ 
  long long r,n, occ[100],emp;
  cin>>r>>n;
  int flag=1;
  for(int i=0; i<n; i++)
  {
    cin>> occ[i];
  }
  if(n!=r)
  {
    emp =1;
    while(flag==1)
    {
      flag =0;
      for(int j=0; j<n; j++)
      {
        if(emp ==  occ[j])
        {
          flag = 1;
          emp ++;
        }
      }
    }
    cout << emp <<endl;
  }
  else 
  {
    cout << "too late" <<endl;
  }
  return 0;
}
