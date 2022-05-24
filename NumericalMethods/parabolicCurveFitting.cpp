#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  int deg,n;
  double x[10],y[10];
  double mat[12][12] = {0,0};

  double ratio,sum=0;
  
  cout<<"Enter the degree of the equation:\t";
  cin>>deg;
  cout<<endl<<"Enter the number of the inputs:\t";
  cin>>n;

  for (int i=0; i<n;i++)
  {
    cout<<endl<<"x & y:\t";
    cin>>x[i]>>y[i];
  }

  for(int i=0; i<=deg;i++)
  {
    for(int j=0;j<=deg;j++)
    {
      sum=0;
      for(int k=0;k<n;k++)
      {
        sum+=  pow(x[k],i+j);
      }
      mat[i][j] = sum;
    }
  }

  for(int i=0;i<=deg;i++)
  {
    sum=0;
    for(int k=0;k<n;k++)
    {
      sum+= (pow(x[k],i)*y[k]);
      mat[i][deg+1] = sum;
    }
  }

  for(int j=0;j<(deg+1);j++)
  {
    if(fabs(mat[j][j])<=0.00005)
    {
      cout<<"Pivot Element is zero"<<endl;
      return 1;
    }
    for(int i=0;i<(deg+1);i++)
    {
      if(i!=j)
      {
        ratio = mat[i][j] / mat[j][j];
        for(int k=0;k<=(deg+1);k++)
        {
          mat[i][k] = mat[i][k] - ratio*mat[j][k];
        }
      }
    }
  }

  for(int i=0;i<(deg+1);i++)
  {
    cout<<"a["<<i+1<<"]"<<" = "<<mat[i][deg+1]/mat[i][i]<<endl;
  }

  return 0;
}
