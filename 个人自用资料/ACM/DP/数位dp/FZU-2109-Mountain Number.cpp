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
int a[15];
ll dp[25][25][2];
ll dfs(int pos,int pre,int j,int lead,int limit)
{
     if(pos==-1) return 1;
     if(!limit&&dp[pos][pre][j]!=-1)
     {
         return dp[pos][pre][j];
     }
     int up=limit?a[pos]:9;
     ll ans=0;
     for(int t=0;t<=up;t++)
     {
         if(t==0&&lead==0)
         {
             ans+=dfs(pos-1,9,0,0,limit&&t==a[pos]);
         }
         else if(j&&t>=pre)
         {
             ans+=dfs(pos-1,t,!j,1,limit&&t==a[pos]);
         }
         else if(j==0&&t<=pre)
         {
              ans+=dfs(pos-1,t,!j,1,limit&&t==a[pos]);
         }
     }
     if(!limit)
     {
         dp[pos][pre][j]=ans;
     }
     return ans;
}
ll solve(ll x)
{ 
    int len=0;
    while(x)
    {
      a[len++]=x%10;
      x/=10;
    }
    return dfs(len-1,9,0,0,1);
}
int main()
{
    int T;
    cin>>T;
    memset(dp,-1,sizeof(dp));
    ll l,r;
    while(T--)
    {
      scanf("%lld%lld",&l,&r);
      printf("%lld\n",solve(r)-solve(l-1));
    }
    //system("pause");
    return 0;
}