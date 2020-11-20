#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>

const int maxn=1e5+5; 
using namespace std;
typedef long long ll;

int a[20];
ll dp[20][2];
ll dfs(int pos, int pre, int state, bool limit)
{
    if(pos==-1) return 1;
    if(!limit && dp[pos][state]!=-1) return dp[pos][state];
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;i++)
    {
        if(pre == 4 && i == 9) continue;
        ans+=dfs(pos-1, i, i == 4 ? 1 : 0, limit && i==a[pos]);
    }
    if(!limit) dp[pos][state]=ans;
    return ans;
}
ll solve(ll x)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos - 1, 0, 0, true);
}
int main()
{
    ll ri;
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%lld",&ri);
        memset(dp, -1, sizeof(dp));
        ll ans=ri;
        ans=solve(ri)-solve(0);
        printf("%lld\n",ri-ans);
    }
    return 0;
}