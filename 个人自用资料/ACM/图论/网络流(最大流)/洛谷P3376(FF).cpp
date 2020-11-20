//网络流最大流FF算法模板
#include<bits/stdc++.h>
const int maxn=1e4+5;
typedef long long ll;
using namespace std;
struct node
{
	int to,nxt,w;
}Edge[200005];
int head[maxn],cnt=2,vis[maxn];
int n,m,st,se;
void Add(int x,int y,int w)
{
	Edge[cnt].to=y;
	Edge[cnt].w=w;
	Edge[cnt].nxt=head[x];
	head[x]=cnt++;
}
int dfs(int u,int flow)
{
	vis[u]=1;
	if(u==se)
	{
		return flow;
	}
	for(int t=head[u];t!=-1;t=Edge[t].nxt)
	{
		int to=Edge[t].to;
		int w=Edge[t].w;
		if(vis[to]==0&&w>0)
		{
            int tmp=dfs(to,min(w,flow));
			if(tmp>0)
			{
				Edge[t].w-=tmp;
				Edge[t^1].w+=tmp;
				return tmp;
			}
			
		}
	}
	return 0;
}
int main(){

	scanf("%d%d%d%d",&n,&m,&st,&se);
	int x,y,w;
	memset(head,-1,sizeof(head));
	for(int t=1;t<=m;t++)
	{
		scanf("%d%d%d",&x,&y,&w);
		Add(x,y,w);
		Add(y,x,0);
	}
	int ans=0;
	while(1)
	{
	memset(vis,0,sizeof(vis));
	int te=dfs(st,0x3f3f3f3f);
	if(te==0)
	{
		break;
	}
	ans+=te;
	}
	printf("%d\n",ans);
    system("pause");
	return 0;
}