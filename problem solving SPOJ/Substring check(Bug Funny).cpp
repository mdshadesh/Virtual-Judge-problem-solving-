
#include <iostream>
using namespace std;
int main()
{
  int arr1[10]={1,1,1,0,1,1,1,0,1,1};
  int arr2[5]={1,0,0,1,1};
  int i,j=0,k;
  for(i=0;i<5;i=i+1)
  {
    k=0;
    for(j=i;j<i+5;j=j+1)
    {
      if(arr1[j]==arr2[k])
      {
        k=k+1;
        if(k==5)
        {
          cout<<"1";
        }
      }else
      {
        cout<<"0";
        i=5;
        break;
      }
    }
  }
}