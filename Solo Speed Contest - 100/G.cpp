#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

#define ll long long
#define int ll

using namespace std;

const int N = 1e5 + 10;
int n,a[N];
map<int,int>r,op;

int C(int x,int y){
	int res1 = 1,res2 = 1;
	for(int i = 1; i <= x; i ++ ){
		res2 *= i;
	}
	for(int i = y - x + 1; i <= y; i ++ ){
		res1 *= i;
	}
	return res1/res2;
}

signed main()
{
	cin >> n;
	for(int i = 0; i < n; i ++ ) cin >> a[i],r[a[i]] ++ ;
	sort(a,a + n);
	
	int x1 = a[0],x2 = a[1],x3 = a[2];
	op[x1] ++ ,op[x2] ++ ,op[x3] ++ ;
	
	
	int res = 1;
	for(auto i:op){
		int goal = i.first,Size = i.second;
		res = res * C(Size,r[goal]);
	}
	cout << res << endl;
	return 0;
}
 	   	 	   	 	 			 		 	 		 	 	
