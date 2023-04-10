#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ans;
ll func(ll x,ll par,ll *arr,vector<vector<ll>> &adj,vector<ll> &dp,vector<ll> &dp1){
	ll val=arr[x];
	for(auto it: adj[x]){
		if(it==par) continue;
		ll temp=func(it,x,arr,adj,dp,dp1);
		val=__gcd(val,temp);
		dp[x]+=temp;
	}
    return dp1[x]=val;
}
void solve(ll x,ll par,vector<vector<ll>> &adj,vector<ll> &dp,ll val,vector<ll> &dp1){
	ans=max(ans,val+dp[x]);
	for(auto it: adj[x]){
		if(it==par) continue;
		solve(it,x,adj,dp,val+dp[x]-dp1[it],dp1);
	}
}
int main() {
	ll t; cin>>t;
	while(t--){
	  ans=0;
	  ll n; cin>>n;
	  ll arr[n+2];
	  for(ll i=1;i<=n;i++) cin>>arr[i];
	  vector<vector<ll>> adj(n+2);
	  for(ll i=0;i<n-1;i++){
		ll a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	  }
	  vector<ll> dp(n+2,0);
	  vector<ll> dp1(n+2,0);
	  func(1,-1,arr,adj,dp,dp1);
	  solve(1,-1,adj,dp,0,dp1);
	  cout<<ans<<endl;
	}
	return 0;
}