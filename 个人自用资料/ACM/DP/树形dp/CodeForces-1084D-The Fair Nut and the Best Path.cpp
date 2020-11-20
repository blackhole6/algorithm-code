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

const int maxn=3e5+5;
typedef long long ll;
using namespace std;
struct edge
{
    int u,v;
    ll w;
    int nxt;
}Edge[maxn<<1];
ll w[maxn];
vector<int>vec[maxn];
int vis[maxn];
ll dp[maxn][2];
int cnt=0;
int head[maxn];
void Add(int u,int v,ll w)
{
    Edge[cnt].u=u;
    Edge[cnt].v=v;
    Edge[cnt].w=w;
    Edge[cnt].nxt=head[u];
    head[u]=cnt++;
}
ll ans=0;
void dfs(int x,int pre)
{
    ll max1=0,max2=0;
    for(int t=head[x];t!=-1;t=Edge[t].nxt)
    {
        int nxt=Edge[t].v;
        if(nxt==pre){continue;}
        dfs(nxt,x);
        if(dp[nxt][0]-Edge[t].w>=max1)
        {
            max2=max1;
            max1=dp[nxt][0]-Edge[t].w;
        }
        else if(dp[nxt][0]-Edge[t].w>max2)
        {
            max2=dp[nxt][0]-Edge[t].w;
        }   
    }
    dp[x][1]=max1+max2+w[x];
    dp[x][0]=max1+w[x];
    ans=max(ans,max(dp[x][0],dp[x][1]));
}
int main()
{
    int n;
    cin>>n;
    memset(head,-1,sizeof(head));
    for(int t=1;t<=n;t++)scanf("%lld",&w[t]);
    int u,v;
    ll c;
    for(int t=1;t<=n-1;t++)
    {
       scanf("%d%d%lld",&u,&v,&c);
       Add(u,v,c);
       Add(v,u,c);
    }
    dfs(1,0);
    printf("%lld\n",ans);
    system("pause");
    return 0;
}