#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
int a[25];
ll dp[25][25];
ll dfs(int pos,int pre,int limit,int zero)
{
    if(pos==-1) return 1;
    if(!limit&&!zero&&dp[pos][pre]!=-1){
       return dp[pos][pre];
    }
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int t=0;t<=up;t++){
        if(zero){
          if(t!=0)
          ans+=dfs(pos-1,t,limit&&a[pos]==t,0);
          else
          {
              ans+=dfs(pos-1,t,limit&&a[pos]==t,1);
          }
        }
        else{
           if(abs(pre-t)>=2){
            ans+=dfs(pos-1,t,limit&&a[pos]==t,0);
           }
        }
    }
    if(!limit&&!zero){
        dp[pos][pre]=ans;
    }
    return ans;
}
ll solve(ll x){
    int len=0;
    while(x){
      a[len++]=x%10;
      x/=10;
    }
    return dfs(len-1,0,1,1);
}
int main(){
    ll l,r;
    while(~scanf("%lld%lld",&l,&r)){
        memset(dp,-1,sizeof(dp));
        ll ans1=solve(r);
        ll ans2=solve(l-1);
        //cout<<ans1<<" "<<ans2<<endl;
        printf("%lld\n",ans1-ans2);
    }
    return 0;
}