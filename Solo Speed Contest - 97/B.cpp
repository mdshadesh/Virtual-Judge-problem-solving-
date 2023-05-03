#include<bits/stdc++.h>
using namespace std;

int main(){
int cap,n,t,k,ts=1;
cin >> t;
while(t--)
{
    cin >> n;
    cin >> k;
    cin >> cap;
    int cnt=0,ara[n+10];
    for(int i=0; i<n; i++)
        cin >> ara[i];
    if(k==1)
    for(int i=0; i<n; i++){if(ara[i]==cap)cnt++;}
    else if(k==2)
    {
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
                if(ara[i]+ara[j]==cap)cnt++;
        }
    }
    else if(k==3)
    {
          for(int i=0; i<n-2; i++)
        {
            for(int j=i+1; j<n-1; j++)
                for(int k=j+1; k<n; k++)
                if(ara[i]+ara[j]+ara[k]==cap)cnt++;
        }
    }
    printf("Case %d: ",ts++);
    cout << cnt << endl;
}
}