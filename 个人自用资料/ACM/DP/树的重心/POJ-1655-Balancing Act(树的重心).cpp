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

const int maxn=2e5+5;
typedef long long ll;
using namespace std;

struct edge
{
  int u,v;
  int nxt;
}Edge[maxn<<2];
ll head[maxn];
ll dp[maxn];
ll a[maxn];
int cnt;
ll maxx;
int n;
void Add(int u,int v)
{
    Edge[cnt].u=u;
    Edge[cnt].v=v;
    Edge[cnt].nxt=head[u];
    head[u]=cnt++;
}

void dfs1(int u,int f)
{
 for(int t=head[u];t!=-1;t=Edge[t].nxt)
 {
     int to=Edge[t].v;
     if(to==f)continue;
     dfs1(to,u);
     a[u]+=a[to];
     dp[u]+=a[to]+dp[to];
 }
 return ;
}
void dfs2(int u,int f)
{
    if(u!=1)
    dp[u]=dp[f]+a[1]-2*a[u];
    for(int t=head[u];t!=-1;t=Edge[t].nxt)
    {
        int to=Edge[t].v;
        if(to==f)continue;
        dfs2(to,u);
    }
    maxx=max(maxx,dp[u]);
}
int main()
{

    memset(head, -1, sizeof(head));
    cnt = 0;
    memset(dp, 0, sizeof(dp));
    maxx = 0;
    int u, v;
    scanf("%d", &n);
    for(int t=1;t<=n;t++)
    {
        scanf("%lld",&a[t]);
    }
    for (int t = 2; t <= n; t++)
    {
        scanf("%d%d", &u, &v);
        Add(u, v);
        Add(v, u);
    }
    dfs1(1,0);
    dfs2( 1,0);
    printf("%lld\n", maxx);
    system("pause");
    return 0;
}