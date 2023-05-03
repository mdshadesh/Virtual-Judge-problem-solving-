#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define syncfalse ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int N = 1e5+5;
ll n, h;
struct node{
    ll val, id;
    bool operator<(const node&a){
        return val < a.val;
    }
}a[N];

int main(){
    syncfalse
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    cin>>n>>h;
    if (n==2){
        cout << "0\n2 2\n";
        return 0;
    }
    for(int i = 1; i <= n; ++i){cin>>a[i].val;a[i].id=i;}
    sort(a+1, a+1+n);
    ll ans1 = (a[n].val+a[n-1].val)-(a[1].val+a[2].val);
    ll mind = min(a[2].val+a[3].val, a[1].val+a[2].val+h);
    ll maxd = max(a[1].val+h+a[n].val, a[n].val+a[n-1].val);
    ll ans2 = maxd-mind;
    if (ans1>ans2){
        int tar = a[1].id;
        cout << ans2 << "\n";
        for (int i = 1; i <= n; ++i){
            if (i==tar)cout << "1 ";
            else cout << "2 ";
        }
    }else{
        cout << ans1 << "\n";
        for (int i = 1; i <= n; ++i){
            cout << "2 ";
        }
    }

    return 0;
}
