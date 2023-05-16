#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int cnt = 1;
	int mx = 0;

	for(int i = 0;i <s.size();i++)
    {
        if(s[i] == s[i+1]){
            cnt++;
        }
        if(s[i] != s[i+1]){
            if(mx <= cnt){
                mx = cnt;
            }
            cnt = 1;
            continue;}
    }
    cout << mx << endl;
	return 0;
}
