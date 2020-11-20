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
const ll mod=1e9+7;
using namespace std;


struct node
{
  ll cnt;
  ll sum;
  ll squaresum;
}dp[25][10][10];

ll a[25];
ll num[25];
node dfs(int pos,int pre1,int pre2,int limit)
{
   if(pos==-1)
   {
     node tt;
     tt.cnt=(pre1!=0&&pre2!=0);
     tt.sum=tt.squaresum=0;
     return tt;
   }
   if(!limit&&dp[pos][pre1][pre2].cnt!=-1)
   {
     return dp[pos][pre1][pre2];
   }
   int up=limit?num[pos]:9;
   node ans;
   node tt;
   ans.cnt=ans.squaresum=ans.sum=0;
   for(int t=0;t<=up;t++)
   {
     if(t==7)
     {
       continue;
     }
     tt=dfs(pos-1,(pre1+t)%7,(pre2*10+t)%7,limit&&t==num[pos]);
     ans.cnt=(ans.cnt+tt.cnt)%mod;
     ans.sum=(ans.sum+(tt.sum+(((a[pos]*t)%mod)*tt.cnt)%mod))%mod;
     ans.squaresum=(ans.squaresum+(tt.squaresum + ((2*a[pos]*t)%mod)*tt.sum)%mod)%mod; 
     ans.squaresum=(ans.squaresum+ (tt.cnt*a[pos])%mod*a[pos]%mod*t*t%mod)%mod; 
   }
   if(!limit)
   {
     dp[pos][pre1][pre2]=ans;
   }
   return ans;
   
}
ll solve(ll x)
{
   int cnt=0;
   while(x)
   {
     num[cnt++]=x%10;
     x/=10;
   }
   return dfs(cnt-1,0,0,1).squaresum;
}

int main()
{
       int T;
       cin>>T;
       a[0]=1;
       for(int t=1;t<25;t++)
       {
         a[t]=(a[t-1]*10)%mod;
       }
       memset(dp,-1,sizeof(dp));
       while(T--)
       {
         ll l,r;
         scanf("%lld%lld",&l,&r);
         ll ans=solve(r)-solve(l-1);
         ans=(ans%mod+mod)%mod;
         printf("%lld\n",ans);
       }
      system("pause");
       return 0;
}