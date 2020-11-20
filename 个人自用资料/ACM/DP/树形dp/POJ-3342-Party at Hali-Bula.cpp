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

const int maxn=2e2+5;
typedef long long ll;
using namespace std;
map<string,int>mp;
vector<int>vec[maxn];
int dp[maxn][2];
void dfs(int u,int p)
{
  
    dp[u][1]=1;
    dp[u][0]=0;
    for(int t=0;t<vec[u].size();t++)
    {
        int v=vec[u][t];
        if(v==p) continue;
        dfs(v,u);
        dp[u][1]+=dp[v][0];
        dp[u][0]+=max(dp[v][0],dp[v][1]);
    }
    return ;
}

int main()
{
    int n;
    string boss;
    while(~scanf("%d",&n)&&n)
    {
      int cnt=0;
      for(int t=0;t<=n;t++)
      {
          vec[t].clear();
      }
      mp.clear();
      cin>>boss;
      mp[boss]=cnt++;
      string a,b;
      for(int t=0;t<n-1;t++)
      {
           cin>>a>>b;
           if(mp.find(a)==mp.end())
           {
               mp[a]=cnt++;
           }
           if(mp.find(b)==mp.end())
           {
               mp[b]=cnt++;
           }
           vec[mp[b]].push_back(mp[a]);
      }
      dfs(0,0);
      bool flag=true;
      for(int t=0;t<n;t++)
      {
            flag=true;
            if (dp[t][0] > dp[t][1])
            {
                for (int j = 0; j < vec[t].size(); j++)
                {
                    if (dp[vec[t][j]][0] == dp[vec[t][j]][1])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag)
                break;
      }
      int ans=max(dp[0][0],dp[0][1]);
      printf("%d", ans);
      if (dp[0][0]==dp[0][1]||!flag)
          printf(" No\n");
      else
          printf(" Yes\n");
    }
    system("pause");
    return 0;
}