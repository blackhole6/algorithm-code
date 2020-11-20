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
int a[20];
ll w[20];
ll dp[20][59050];
int change(int state,int pos){
    int data=0;
    if(state==0) data = 0;
    else data = (state%w[pos+1])/w[pos];
    if(data==0||data==1) state += w[pos];
    if(data==2) state -= w[pos];
    return state;
}
bool check(int state){
    int pos = 0;
    while(state!=0){
        int x;
        x = state%3;
        state /= 3;
        if(x==1&&pos%2==1)return 0;
        if(x==2&&pos%2==0)return 0;
        pos ++;
    }
    return 1;
}
ll dfs(int pos,int state,bool zero,bool limit){
    if(pos==0){
        if(check(state)) return 1;
        return 0;
    }
    if(!limit&&dp[pos][state]!=-1&&!zero) return dp[pos][state];
    int up = limit?a[pos]:9;
    ll ans = 0;
    for(int t = 0;t <= up;t ++){
        if(zero&&t==0) {
            ans += dfs(pos-1,state,zero&&t==0,limit&&t==up);
            continue;
        }
        int next = change(state,t);
        ans += dfs(pos-1,next,zero&&t==0,limit&&t==up);
    }
    if(!limit&&!zero)  dp[pos][state]= ans;
    return ans;
}
ll solve(ll n){
    int len = 0;
    while(n!=0){
        a[++len] = n%10;
        n /= 10;
    }
    return dfs(len,0,1,1);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    w[0] = 1;
    for(int t = 1;t <= 10;t ++)
        w[t] = w[t-1]*3;
    ll l,r;
    int T;
    cin>>T;
    while(T--)
	{
        cin>>l>>r;
        cout<<solve(r)-solve(l-1)<<endl;
    }
	system("pause");
    return 0;
}