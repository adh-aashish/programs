#include <iostream>

using namespace std;

void tower_of_hanoi(int n,char from_peg,char to_peg, char aux_peg);

int main()
{
  tower_of_hanoi(4,'A','C','B');
}

void tower_of_hanoi(int n, char from_peg, char to_peg, char aux_peg)
{
  if(n==1)
  {
    cout<<"Move disc 1 from "<<from_peg<<" to "<<to_peg<<endl;
    return;
  }
  tower_of_hanoi(n-1,from_peg,aux_peg,to_peg);//from A move n-1 discs to B using C
  cout<<"Move disc "<< n<<" from "<<from_peg<<" to "<<to_peg<<endl;//move the last remaining disc to C 
  tower_of_hanoi(n-1,aux_peg,to_peg,from_peg);//now move the n-1 discs to C from B using A
}


