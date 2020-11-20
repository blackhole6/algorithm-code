#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>


const int maxn=1e5+5;
typedef long long  ll;
using namespace std;
ll dp[19][19][2005];
int a[25];
ll dfs(int pos,int point,int L,int limit)
{
      if(pos==-1)return L==0;
      if(L<0)return 0;
      if(!limit&&dp[pos][point][L]!=-1)return dp[pos][point][L];
      int up=limit?a[pos]:9;
      ll ans=0;
      for(int t=0;t<=up;t++)
      {
          int tmp=L+(pos-point)*t;
          ans+=dfs(pos-1,point,tmp,limit&&t==a[pos]);
      }
      if(!limit)dp[pos][point][L]=ans;
      return ans;
}
ll solve(ll x)
{
   int len=0;
   ll ans=0;
   while(x)
   {
       a[len++]=x%10;
       x/=10;
   }
   for(int t=0;t<len;t++)
   {
       ans+=dfs(len-1,t,0,1);
   }
   return (ans-(len-1));
}
int main()
{
    int T;
    cin>>T;
    ll l,r;
    while(T--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",solve(r)-solve(l-1));
    }
    system("pause");
    return 0;
}