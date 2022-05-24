//binary_search.cpp
//This program uses binary search to return positon of the matching item 
//from a list

#include <iostream>

using namespace std;

//returns the position of the index of matching search result
int binary_search(int arr[], int len, int val)
{
  int low=0;              //lowest index
  int high=len-1;         //highest index
  int mid,guess;
  while(true)
  {
    mid = (low+high)/2;
    guess = arr[mid];
    if (guess == val)
    {
      return mid;
    }
    if(guess > val)
    {
      high = mid -  1;    //highest index is mid index now 
    }
    if (guess < val)
    {
      low = mid + 1;      //lowest index is mid index now 
    }
    else{
      return -9999;
    }
  }
}

int main()
{
  int arr[]={1,2,3,4,5,6,7,8,13,34,45,67,78,89,99};
  int length = sizeof(arr)/sizeof(arr[0]);
  cout <<"its position index on array is:"<< binary_search(arr,length,99);
}





/* ===================First Try=========================== */

/* int binary_search(int arr[], int len, int val) */
/* { */
/*   int pos=len/2; */
/*   while(true) */
/*   { */
       /* cout << count++<<endl; */
/*     if (val==arr[pos]) */
/*       return pos; */
/*     else if(val>arr[pos]) */
/*     { */
/*       pos=pos+((len-pos)/2); */
/*     } */
/*     else */
/*     { */
/*       pos=pos-(pos/2); */
/*     } */
/*   } */
/* } */
/*  */

/* ================================================================ */
