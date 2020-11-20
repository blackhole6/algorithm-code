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
#define lson m<<1,l,mid
#define rson m<<1|1,mid+1,r
#define getmid(m) (tree[m].l+tree[m].r)>>1;
const int maxn=1e5+5;
typedef long long ll;
using namespace std;
pair<int,int>pp;
vector<int>vec[65];
vector<int>G[maxn];
ll a[maxn];
int vis[maxn];
int endd;
int minn=0x3f3f3f3f;
void  dfs(int sta,int dep)
{
    vis[sta]=1;
    if(dep>=minn)
    {
          vis[sta]=0;
          return;
    }
    for(int t=0;t<G[sta].size();t++)
    {  
      int u=G[sta][t];
      if(u==endd&&dep>1)
      {
          minn=min(minn,dep+1);
      }
      if(vis[u]==0)
      {
          dfs(u,dep+1);
      }
    }
    vis[sta]=0;  
}

int main()
{
    int n;
    cin>>n;
    for(int t=0;t<n;t++)
    {
        scanf("%lld",&a[t]);
    }
    for(int t=0;t<64;t++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]&((1ll<<t)))
            {
             vec[t].push_back(j);
            }
        }
    }
    for(int t=0;t<64;t++)
    {
        if(vec[t].size()>=3)
        {
            puts("3");
            return 0;
        }
    }
    for(int t=0;t<64;t++)
    {
        if(vec[t].size()==2)
        {
            int u=vec[t][0];
            int v=vec[t][1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
    for(int t=0;t<n;t++)
    {
        endd=t;
        dfs(t,0);
    }
    if(minn==0x3f3f3f3f)
    {
        puts("-1");
    }
    else
    {
    printf("%d\n",minn);
    }
    system("pause");
    return 0;
}