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

int a[55];
int dp[55][55][55];
int dfs(int pos,int num0,int num1,bool first,bool limit)
{
    if(pos==-1)
    {
       return num0>=num1;
    }
    if(!limit&&dp[pos][num0][num1]!=-1)
    {
        return dp[pos][num0][num1];
    }
    int up;
    if(limit)
    {
       up=a[pos];
    }
    else
    {
       up=1;
    }
    int ans=0;
    for(int t=0;t<=up;t++)
    {
        int temp=(first&&t==0);
        ans+=dfs(pos-1,temp?0:num0+(t==0),temp?0:num1+(t==1),temp,limit&&(t==up));
    }
    if(!limit)
    {
        dp[pos][num0][num1]=ans;
    }
    return ans;
}

int cal(int x)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x%2;
        x/=2;
    }
    return dfs(pos-1,0,0,true,true);
}

int main()
{

    int l,r;
    cin>>l>>r;
    memset(dp,-1,sizeof(dp));
    printf("%d\n",cal(r)-cal(l-1));
    system("pause");
    return 0;
}