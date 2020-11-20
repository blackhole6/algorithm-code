#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>

const int maxn=1e5+5;
typedef long long ll;
using namespace std;
int a[25],dp[25][25];
ll dfs(int len, int sum ,bool limit)
{
    if(len==-1)
    {
        return sum<=3;
    }
    if(!limit&&dp[len][sum]!=-1)
    {
        return dp[len][sum];
    }
    int up;
    if(limit)
    {
        up=a[len];
    }
    else
    {
        up=9;
    }
    ll ans=0;
    for(int t=0;t<=up;t++)
    {
        ans+=dfs(len-1,sum+(t!=0),limit && t==a[len]);
    }
 
    if(!limit) dp[len][sum]=ans;
    return ans;
}
ll cal(ll x)
{
    int len=0;
    while(x)
    {
        a[len++]=x%10;
        x/=10;
    }
    return dfs(len-1,0,1);
}
int main()
{
    int T;
    ll L,R;
    cin>>T;
    while(T--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%lld%lld",&L,&R);
        printf("%lld\n",cal(R)-cal(L-1));
    }
    system("pause");
    return 0;
}