#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<set>
#include<stack>
#include<map> 

const int maxn=3e5+5;
typedef long long ll;
using namespace std;

struct node
{
	int u,to,nxt;
}p[maxn<<1];
int tot,h[maxn],a[maxn],n,sum1[maxn],sum2[maxn];
void Add(int u,int v)
{
    p[tot].u=u;
    p[tot].to=v;
    p[tot].nxt=h[u];
    h[u]=tot++;
}
void dfs(int u,int pre)
{
	sum1[u]=sum2[u]=0;
	if(a[u]==1)sum1[u]++;
	if(a[u]==2)sum2[u]++;
	for(int i=h[u];i!=-1;i=p[i].nxt){
		int v=p[i].to;
		if(v==pre)continue;
		dfs(v,u);
		sum1[u]+=sum1[v];
		sum2[u]+=sum2[v];
	}
}
int main()
{
	int u,v;
	tot=0;
	memset(h,-1,sizeof h); 
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
    {
		cin>>u>>v;
		Add(u,v);
        Add(v,u);
	}
	dfs(1,0);
	int ans=0;
	for(int i=2;i<=n;i++)
	if(sum1[i]==sum1[1] && sum2[i]==0 || sum2[i]==sum2[1] && sum1[i]==0)
		ans++;
	printf("%d\n",ans);
	system("pause");
    return 0;
}