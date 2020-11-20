#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>


const int maxn=6e3+5;
typedef long long ll;
using namespace std;

int H[maxn];
vector<int>vec[maxn];
int vis[maxn],vis1[maxn];
int dp[maxn][2];
void dfs(int x)
{
    dp[x][0]=0;
    dp[x][1]=H[x];
    for(int t=0;t<vec[x].size();t++)
    {
        int nxt=vec[x][t];
        dfs(nxt);
        dp[x][0]+=max(dp[nxt][0],dp[nxt][1]);
        dp[x][1]+=dp[nxt][0];
    }
}
int main()
{
    int n;
    cin>>n;
    memset(vis,0,sizeof(vis));
    memset(vis1,0,sizeof(vis1));
    memset(dp,0,sizeof(dp));
    for(int t=1;t<=n;t++)scanf("%d",&H[t]);
    int L,K;
    for(int t=1;t<=n-1;t++){
        scanf("%d%d",&L,&K);
        vis[L]=1;
   //     vis1[K]=1;
        vec[K].push_back(L);
    }
    int x,y;
    scanf("%d%d",&x,&y);
    int ans;
    for(int t=1;t<=n;t++)
    {
        if(vis[t]==0)
        {
            dfs(t);
            ans=max(dp[t][0],dp[t][1]);  
        }
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}