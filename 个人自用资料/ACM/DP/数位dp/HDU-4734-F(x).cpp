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

ll dp[25][5005];
int a[25];
int AA;
ll dfs(int pos,int pre,int limit)
{
    if(pos==-1)
    {
        return pre>=0;
    }
    if(pre<0)
    {
        return 0;
    }
    if(!limit&&dp[pos][pre]!=-1)
    {
        return dp[pos][pre];
    }
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int t=0;t<=up;t++)
    {
        ans+=dfs(pos-1,pre-t*(pow(2,pos)),limit&&t==a[pos]);
    }
    if(!limit)
    {
        dp[pos][pre]=ans;
    }
    return ans;
}

ll solve(ll x)
{
    int len=0;
    while(x)
    {
        a[len++]=x%10;
        x/=10;
    }
    return dfs(len-1,AA,1);
}

int main()
{
    int T;
    cin>>T;
    ll A,B;
    int cnt=1;
    memset(dp,-1,sizeof(dp));
    while(T--)
    {
        scanf("%lld%lld",&A,&B);
        AA=0;
        int cc=1;
        while(A)
        {
            AA+=((A%10)*cc);
            A/=10;
            cc*=2;
        }
        printf("Case #%d: %lld\n",cnt++,solve(B));
        
    }
    system("pause");
    return 0;
}