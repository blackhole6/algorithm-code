//n个点m条边 求割边
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=100005;
struct Edge{
    int to,next;
    bool cut;
}edge[MAXN];
int head[MAXN],tot;
int low[MAXN],dfn[MAXN],stack[MAXN];
int Index,top;
bool Instack[MAXN];
bool cut[MAXN];
int add_block[MAXN];
int bridge;
int n,m;
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].cut=false;
    head[u]=tot++; 
}
void init()
{
    memset(head,-1,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(Instack,false,sizeof(Instack));
    memset(add_block,0,sizeof(add_block));
    memset(cut,false,sizeof(cut));
    tot=0;
    Index=top=0;
    bridge=0;
}
void Tarjan(int u,int pre)
{
    low[u]=dfn[u]=++Index;
    stack[top++]=u;
    Instack[u]=true;
    int son=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==pre) continue;
        if(!dfn[v])
        {
            son++;
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);     
            if(low[v]>dfn[u])
            {
                bridge++;
                edge[i].cut=true;
                edge[i^1].cut=true;
            }
           
            if(u!=pre&&low[v]>=dfn[u])
            {
                cut[u]=true;
                add_block[u]++;
            }
        }
        else if(low[u]>dfn[v])
        low[u]=dfn[v];
    }
    if(u==pre&&son>1) cut[u]=true;
    if(u==pre) add_block[u]=son-1;
    Instack[u]=false;
    top--;
}
void solve()
{
    for(int i=1;i<=n;i++)
    if(!dfn[i])
    Tarjan(i,i);
    //printf("%d critical links\n",bridge);割边数量
    vector< pair<int,int> >ans;
    for(int u=1;u<=n;u++)
        for(int i=head[u];i!=-1;i=edge[i].next)
        if(edge[i].cut && edge[i].to>u){
            ans.push_back(make_pair(u,edge[i].to));
        }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    printf("%d %d\n",ans[i].first,ans[i].second);
}
int main()
{
	int m;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        int u,v;
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d",&u,&v);
			addedge(u,v);
            addedge(v,u);
        }
        solve(); 
    }
    return 0;
} 