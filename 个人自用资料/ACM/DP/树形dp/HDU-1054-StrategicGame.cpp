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

const int maxn=1e3+503;
typedef long long ll;
using namespace std;
int du[maxn],vis[maxn];
int dp[maxn][2];
vector<int>vec[maxn];
void dfs(int x)
{ 
   dp[x][0]=0;
   dp[x][1]=1;
   vis[x]=1;
   for(int t=0;t<vec[x].size();t++)
   {
       if(vis[vec[x][t]])
       {
           continue;
       }
       int nxt=vec[x][t];
       dfs(nxt);
       dp[x][1]+=min(dp[nxt][0],dp[nxt][1]);
       dp[x][0]+=dp[nxt][1];
   }
}
int main()
{
    int n;
    int pre,m;
    while(~scanf("%d",&n))
    {
        memset(vis,0,sizeof(vis));
        memset(du,0,sizeof(du));
        for(int t=0;t<n;t++)
        {
            vec[t].clear();
        }
        for(int j=0;j<n;j++)
        {
        scanf("%d:(%d)",&pre,&m);
        int x;
        for(int t=0;t<m;t++)
        {
            scanf("%d",&x);
            vec[pre].push_back(x);
            du[x]++;
        }
        }
        for(int t=0;t<n;t++)
        {
            if(!du[t])
            {
            dfs(t);
            int ans=min(dp[t][0],dp[t][1]);
            printf("%d\n",ans);
            break;
            }
        }
    }
    system("pause");
    return 0;
}