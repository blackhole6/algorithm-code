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

const int maxn=1e4+5;
typedef long long ll;
using namespace std;

struct edge
{
  int u,v,w;
  int nxt;
}Edge[maxn<<2];
int head[maxn];
int dp[maxn][2];//0代表最大 1代表次大
int cnt;
int maxid[maxn];
int smaxid[maxn];
void Add(int u,int v,int w)
{
    Edge[cnt].u=u;
    Edge[cnt].v=v;
    Edge[cnt].w=w;
    Edge[cnt].nxt=head[u];
    head[u]=cnt++;
}

void dfs1(int u,int f)
{
 dp[u][0]=dp[u][1]=0;
 for(int t=head[u];t!=-1;t=Edge[t].nxt)
 {
     int to=Edge[t].v;
     if(to==f)continue;
     dfs1(to,u);
     if(dp[u][1]<dp[to][0]+Edge[t].w)
     {
         dp[u][1]=dp[to][0]+Edge[t].w;
         smaxid[u]=to;
         if(dp[u][1]>dp[u][0])
         {
             swap(dp[u][1],dp[u][0]);
             swap(smaxid[u],maxid[u]);
         }
     } 
 }
 return ;
}
void dfs2(int u,int pre)
{

    for(int t=head[u];t!=-1;t=Edge[t].nxt)
    {
         int to=Edge[t].v;
        if(to==pre)continue;
        if(to==maxid[u])
        {
            if(Edge[t].w+dp[u][1]>dp[to][1])
            {
               dp[to][1]=Edge[t].w+dp[u][1];
               smaxid[to]=u;
               if(dp[to][1]>dp[to][0])
               {
                   swap(dp[to][1],dp[to][0]);
                   swap(smaxid[to],maxid[to]);
               }
               
            }
        }
        else
        {
            if(Edge[t].w+dp[u][0]>dp[to][1])
            {
               dp[to][1]=Edge[t].w+dp[u][0];
               smaxid[to]=u;
               if(dp[to][1]>dp[to][0])
               {
                   swap(dp[to][1],dp[to][0]);
                   swap(smaxid[to],maxid[to]);
               }
               
            }
        }
         dfs2(to,u);
    }
    return ;
}
int main()
{
    int n;
    int v,w;
    while(~scanf("%d",&n))
    {
        memset(head,-1,sizeof(head));
        cnt=0;
        for(int t=2;t<=n;t++)
        {
           scanf("%d%d",&v,&w);
           Add(v,t,w);
           Add(t,v,w);
        }
        dfs1(1,-1);
        dfs2(1,-1);
        for(int t=1;t<=n;t++)
        {
            printf("%d\n",dp[t][0]);
        }
        
    }
    return 0;
}