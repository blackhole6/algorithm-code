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
int a[15];
int dp[25][2];

ll dfs(int pos,int pre,int status,int limit)
{
    if(pos==-1)
    {
        return 1;
    }
    if(!limit&&dp[pos][status]!=-1)
    {
        return dp[pos][status];
    }
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int t=0;t<=up;t++)
    {
          if(pre==6&&t==2||t==4)continue;
          ans+=dfs(pos-1,t,t==6?1:0,limit&&a[pos]==t);
    }
    if(!limit)
    {
        dp[pos][status]=ans;
    }
    return ans;
}
ll solve(int x)
{
    int len=0;
    while(x)
    {
        a[len++]=x%10;
        x/=10;
    }
    return dfs(len -1,0, 0,1);
}
int main()
{
    int m,n;
    while(~scanf("%d%d",&m,&n))
    {
        if(n==0&&m==0)
        {
            break;
        }
        memset(dp,-1,sizeof(dp));
        
        printf("%lld\n",solve(n)-solve(m-1));
    }
    system("pause");
    return 0;
}