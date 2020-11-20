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

ll dp[12][2050];
ll tmp;
int h,w;
void dfs(int i,int status,int k)
{
    if(k>=w)
    {
        dp[i][status]+=tmp;
        return;
    }
    dfs(i,status,k+1);
    if(k<=w-2&&!(status&(1<<k))&&!(status&1<<(k+1)))
    {
        dfs(i,status|(1<<k)|(1<<(k+1)),k+2);
    }
}
int main()
{
    while(~scanf("%d%d",&h,&w))
    {
        if(h==0&&w==0)
        {
            break;
        }
        memset(dp,0,sizeof(dp));
        int ss=(1<<w)-1;
        tmp=1;
        dfs(1,0,0);
        for(int t=2;t<=h;t++)
        {
            for(int j=0;j<=ss;j++)
            {
                if(dp[t-1][j])
                {
                    tmp=dp[t-1][j];
                }
                else
                {
                    continue;
                }
                dfs(t,ss-j,0);
            }
        }
        printf("%lld\n",dp[h][ss]);
    }
    //system("pause");
    return 0;
}