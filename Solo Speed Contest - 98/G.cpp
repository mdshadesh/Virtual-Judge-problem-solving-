#include <cstdio>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
 
int main(){
	const int MAXA = 8002;
	const int MOD = 1e9 + 7;
	int N, K, tmp, sum = 0;
	scanf("%d %d", &N, &K);
	vector<int> A(MAXA), dp(MAXA);
	dp[0] = 1;
 
	for (int i = 0; i < N; ++i){
		scanf("%d", &tmp);
		A[tmp]++;
	}
	for (int i = 1; i < MAXA; ++i){
		for (int j = i; j > 0; --j){
			dp[j] = (dp[j] + static_cast<int64_t>(dp[j - 1]) * A[i]) % MOD;
		}
	}
        for (int i = 0; i <= K && i < MAXA; ++i){
		sum = (sum + dp[i]) % MOD;
	}
	printf("%d\n", sum);
	return 0;
}