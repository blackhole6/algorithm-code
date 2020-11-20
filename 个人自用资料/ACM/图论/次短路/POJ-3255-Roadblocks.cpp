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


const int maxn=1e5+5;
typedef long long ll;
using namespace std;

struct node
{
   int pos,w;
   node(int x,int y)
   {
       pos=x;
       w=y;
   }
   bool friend operator<(node x,node y )
   {
       return x.w>y.w;
   }
};
struct edge
{
   int u,v;
   ll cost;
   int nxt;
}Edge[maxn<<1];
int cnt;

ll dis[5005],dis2[5005];
int head[5005],vis[5005];
void Add(int u,int v,ll w)
{
   Edge[cnt].u=u;
   Edge[cnt].v=v;
   Edge[cnt].cost=w;
   Edge[cnt].nxt=head[u];
   head[u]=cnt++;
}
void Dijkstra(int u)
{
    dis[u]=0;
    priority_queue<node>q;
    q.push(node(u,0));
    while(!q.empty())
    {
       node now=q.top();
       q.pop();
       if(vis[now.pos])
       {
           continue;
       }
       vis[now.pos]=1;
       for(int t=head[now.pos];t!=-1;t=Edge[t].nxt)
       {
           if(dis[now.pos]+Edge[t].cost<dis[Edge[t].v])
           {
               dis[Edge[t].v]=dis[now.pos]+Edge[t].cost;
               q.push(node(Edge[t].v,dis[Edge[t].v]));
           }
       }
    }
    return ;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
    memset(dis,0x3f3f3f3f,sizeof(dis));
    cnt=0;
    int u,v;
    ll w;
    for(int t=0;t<m;t++)
    {
        scanf("%d%d%lld",&u,&v,&w);
        Add(u,v,w);
        Add(v,u,w);
    }
    Dijkstra(1);
    for(int t=1;t<=n;t++)
    {
        dis2[t]=dis[t];
    }
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    Dijkstra(n);
    int ans=0x3f3f3f3f;
    for(int t=0;t<cnt;t++)
    {
        if(dis[Edge[t].u]+dis2[Edge[t].v]+Edge[t].cost<ans&&(dis[Edge[t].u]+dis2[Edge[t].v]+Edge[t].cost)!=dis2[n])
        {
            ans=dis[Edge[t].u]+dis2[Edge[t].v]+Edge[t].cost;
        }
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}