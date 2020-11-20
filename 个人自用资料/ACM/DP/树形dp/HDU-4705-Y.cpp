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
ll n;
vector<int>vec[maxn];
ll dp[maxn];
int vis[maxn];
ll ans;
void dfs(int u,int pre)
{
   dp[u]=1;
   vis[u]=1;
   for(int t=0;t<vec[u].size();t++)
   {
	   int to=vec[u][t];
	   if(to==pre)
	   {
		   continue;
	   }
	   if(vis[to]==0)
	   {
		dfs(to,u);
	   }
	   dp[u]+=dp[to];
	   ans+=(n-dp[u])*dp[to];//v结点的个数和他上面节点的个数
   }
   return ;
}
int main()
{
    
	while(cin>>n)
	{ 
	int u,v;
	ans=0;
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	for(int t=1;t<=n;t++)
	{
		vec[t].clear();
	}
	for(int t=1;t<=n-1;t++)
	{
        scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
    dfs(1,-1);
	ans=(n*(n-1)*(n-2))/6-ans;//从n个点中选取3个点 - 三个在一条线上的
	printf("%lld\n",ans);
	}
    //system("pause");
	return 0;
}