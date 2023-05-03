#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    if(s[0]!='1' || s[1]!='1' || s[n]!='1')
	    {
	        cout<<"NO"<<endl;
	    }
	    else
	    {
	        cout<<"YES"<<endl;
	        cout<<0<<" ";
	        for(int i=1;i<n;i++)
	        {
	            if(s[i]=='0')
	            {
	                cout<<i<<" ";
	            }
	        }
	        for(int i=1;i<n;i++)
	        {
	            if(s[i]=='1')
	            {
	                cout<<i<<" ";
	            }
	        }
	        cout<<endl;
	    }
	    
	}
	return 0;
}