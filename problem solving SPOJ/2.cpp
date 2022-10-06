#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
 
bool checkprime (long int num)
{
    if (num <=1)
        return false;
    else if (num == 2)        
        return true;
    else if (num % 2 == 0)
        return false;
    else
    {
        bool prime = true;
        int divisor = 3;
      
        int upperLimit =sqrt(num) +1;
        
        while (divisor <= upperLimit)
        {
            if (num % divisor == 0)
                return false;
            divisor +=2;
        }
        return prime;
    }
}
     
 int main()
 {int a,b,i,n,j;
 scanf("%d",&n);
 
 for(i=0;i<n;i++)
 {   
  scanf(" %d %d",&a,&b);
  printf("\n");
  for(j=a;j<=b;j++)
  {            if(checkprime(j))
     printf("%d\n",j);
        
  }
 }
 return 0;
 }