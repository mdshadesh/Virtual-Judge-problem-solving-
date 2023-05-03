#include<bits/stdc++.h>
using namespace std;

const int maxn = 5005;
const int mod = 1e9+7;
int dp[maxn][maxn];
char a[maxn],b[maxn];
int updata(int x,int y)
{
    return (x+y)%mod;
}
int main()
{
    scanf("%s%s",a+1,b+1);
    int len1 = strlen(a+1),len2 = strlen(b+1);
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=updata(dp[i][j],dp[i-1][j-1]+1);
            dp[i][j]=updata(dp[i][j],dp[i][j-1]);
        }
    }
    long long ans = 0;
    for(int i=1;i<=len1;i++)
        ans=updata(ans,dp[i][len2]);
    printf("%d\n",ans);
}
