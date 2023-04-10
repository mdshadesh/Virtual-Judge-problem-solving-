#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 2;
const int MOD = 1e9 + 7;

int n, t[MAXN], a[MAXN];

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> t[i];
	for(int i = 0; i < n; ++i) cin >> a[i];
	int ans = (t[0] <= a[0] && t[n - 1] >= a[n - 1]);
	for(int i = 1; i < n - 1; ++i){
		if(t[i - 1] < t[i]){
			if(t[i] > a[i]) ans = 0;
		}
		else if(a[i + 1] < a[i]){
			if(a[i] > t[i]) ans = 0;
		} else {
			ans = (long long) ans * min(a[i], t[i]) % MOD;
		}
	}
	cout << ans;
	return 0;
}