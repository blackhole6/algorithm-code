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


const int maxn=1e5+5;
typedef long long ll;
using namespace std;
int a[15];
int dp[15][15][10];
int dfs(int pos,int mod,int pre,int limit)
{
   if(pos==-1)
   {
    return mod==0&&pre==2;
   }
   if(!limit&&dp[pos][mod][pre]!=-1) return dp[pos][mod][pre];
   int up=limit?a[pos]:9;
   int ans=0;
   for(int t=0;t<=up;t++)
   {
      int tmp=(mod*10+t)%13;
      if(pre==2||(pre==1&&t==3))
      {
         ans+=dfs(pos-1,tmp,2,limit&&t==a[pos]);
      }
      else if(t==1)
      {
         ans+=dfs(pos-1,tmp,1,limit&&t==a[pos]);
      }
      else 
      {
         ans+=dfs(pos-1,tmp,0,limit&&t==a[pos]);
      }
   }
   if(!limit) dp[pos][mod][pre]=ans;
   return ans;
}
int  solve(int x)
{
    int len=0;
    while(x)
    {
       a[len++]=(x%10);
       x/=10;
    }
    return dfs(len-1,x%13,0,1);
}

int main()
{
   int n;
   while(~scanf("%d",&n))
   {
      memset(dp,-1,sizeof(dp));
     printf("%d\n",solve(n));
   }
   system("pause");
   return 0;
}