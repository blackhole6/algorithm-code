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

int status[105];

char Map[105][15];
int cnt=0,stt[105];
int dp[105][105][105];
int sum[105];
bool check(int x)
{
    if(x&(x<<1))
    {
        return false;
    }
    if(x&(x<<2))
    {
        return false;
    }
    return true;
}
int getSum(int x)
{
    int num=0;
    while(x>0)
    {
        if(x&1)num++;
        x>>=1;
    }
    return num;
}
void init(int n)
{
   for(int t=0;t<(1<<n);t++)
   {
       if(check(t))
       {
           stt[cnt]=t;
           sum[cnt++]=getSum(t);
       }
   }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int t=0;t<n;t++)
    {
        scanf("%s",Map[t]);
        for(int j=0;j<m;j++)
        {
            if(Map[t][j]=='H')
            {
              status[t]|=(1<<j);
            }
        }
    }
    memset(dp,-1,sizeof(dp));
    init(m);
    for(int t=0;t<cnt;t++)
    {
        if(!(stt[t]&status[0]))
        {
            dp[0][0][t]=sum[t];
        }
    }
    for(int  k=1;k<n;k++)
    {
        for(int t=0;t<cnt;t++)
        {
            if(stt[t]&status[k])continue;
            for(int j=0;j<cnt;j++)
            {
                if(stt[t]&stt[j])continue;
                for(int kk=0;kk<cnt;kk++)
                {
                    if(stt[t]&stt[kk])continue;
                    if(dp[k-1][kk][j]==-1)continue;
                    dp[k][j][t]=max(dp[k][j][t],dp[k-1][kk][j]+sum[t]);
                }
            }
        }
    }
    int ans=0;
    for(int t=0;t<cnt;t++)
    {
        for(int j=0;j<cnt;j++)
        {
            ans=max(ans,dp[n-1][t][j]);
        }
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}