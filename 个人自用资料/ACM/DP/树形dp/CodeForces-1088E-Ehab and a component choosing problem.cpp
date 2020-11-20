#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>

const int maxn=3e5+5;
typedef long long ll;
using namespace std;
struct edge
{
   int u,v;
   int nxt;
}Edge[maxn<<2];

int head[maxn];
int cnt;
ll cc;
ll ans;
ll a[maxn],dp[maxn];
void Add(int u,int v)
{
    Edge[cnt].u=u;
    Edge[cnt].v=v;
    Edge[cnt].nxt=head[u];
    head[u]=cnt++;
}
void dfs(int u,int pre)
{
    dp[u]=a[u];
    for(int t=head[u];t!=-1;t=Edge[t].nxt)
    {
        int to=Edge[t].v;
        if(to==pre)
        {
            continue;
        }
    
         dfs(to,u);
         if(dp[to]>0)
        dp[u]+=dp[to];
    }
    ans=max(dp[u],ans);
}
void dfs1(int u,int pre)
{
    dp[u]=a[u];
    
    for(int t=head[u];t!=-1;t=Edge[t].nxt)
    {
        int to=Edge[t].v;
        if(to==pre)
        {
            continue;
        }
        dfs1(to,u);
        if(dp[to]>0)
        dp[u]+=dp[to];
    }
    if(dp[u]==ans)
    {
        dp[u]=0;
        cc++;
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        cnt=0;
        ans=-0x3f3f3f3f;
        cc=0;
        memset(head,-1,sizeof(head));
        memset(dp,0,sizeof(dp));
        for(int t=1;t<=n;t++)
        {
            scanf("%lld",&a[t]);
        }
        int u,v;
        for(int t=1;t<=n-1;t++)
        {
            scanf("%d%d",&u,&v);
            Add(u,v);
            Add(v,u);
        }
        dfs(1,-1);
        dfs1(1,-1);
        printf("%lld %lld\n",ans*cc,cc);
    }
    return 0;
}