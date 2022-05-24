#include <bits/stdc++.h>
  
using namespace std;


int main()
{
  string jon, doc;
  getline(cin, jon);
  getline(cin, doc);

  if(jon.size() >= doc.size())
  {
    cout << "go"<< endl;
  } else {
    cout<< "no" << endl;
  }

  return 0;
}
