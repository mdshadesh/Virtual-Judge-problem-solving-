#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	long t;
	cin>>t;
	while(t--)
	{
	    long n,m,k,ans=0;
	    cin>>n>>m>>k;
	    long a[n];
	    map<int,int> m1;
	    for(long i=0;i<n;i++)
	    {
	        cin>>a[i];
	        m1[a[i]]++;
	    }
	    for(long i=0;i<k;i++)
	    {
	        if(m1.find(i)!=m1.end())
	        {
	            ans++;
	        }
	    }
	    if(n-m1[k]>=m and m>=k and ans==k)
	        cout<<"yes"<<endl;
	    else
	        cout<<"no"<<endl;
	}
	return 0;
}