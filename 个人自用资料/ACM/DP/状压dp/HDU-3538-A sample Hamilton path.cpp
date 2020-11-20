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
#define Inf 0x3f3f3f3f

const int maxn=1e5+5;
typedef long long ll;
using namespace std;
int Map[25][25];
int n,m;
ll dp[1<<21][20];
ll f[25];
int  main()
{

    while(~scanf("%d%d",&n,&m))
    {
    memset(f,0,sizeof(f));
    for(int t=0;t<=1<<n;t++)
    {
        for(int j=0;j<n;j++)
        {
            dp[t][j]=Inf;
        }
    }
    dp[1][0]=0;
    for(int t=0;t<n;t++)
    {
       for(int j=0;j<n;j++)
       {
           scanf("%d",&Map[t][j]);
       }
    }
    int x,y;
    for(int t=0;t<m;t++)
    {
        scanf("%d%d",&x,&y);
        f[y]|=(1<<x);
    }
    for(int t=0;t<=1<<n;t++)
    {
        for(int j=0;j<n;j++)
        {
            for (int k=0;k<n;k++)
            if (!(t & (1 << k)) && Map[j][k] != -1 && (t & f[k]) == f[k])
                dp[t|(1<<k)][k] = min(dp[t|(1<<k)][k],dp[t][j] + Map[j][k]);
        }
    }
    ll ans=Inf;
     for (int t=0;t<n;t++)
    {
        ll tmp=dp[(1<<n)-1][t];
        ans=min(ans,tmp);
    }
    if(ans==Inf)
    {
         puts("-1");
    }
    else
    {
         printf("%lld\n",ans);
    }
    }
    system("pause");
    return 0;
}