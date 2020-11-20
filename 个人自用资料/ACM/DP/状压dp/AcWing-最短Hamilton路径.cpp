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
#define Inf 0x3f3f3f3f

const int maxn=1e5+5;
typedef long long ll;
using namespace std;
int Map[25][25];
int n;
int dp[1100000][25];
int  main()
{

    scanf("%d",&n);
    for(int t=0;t<=1<<n;t++)
    {
        for(int j=0;j<n;j++)
        {
            dp[t][j]=Inf;
        }
    }
    dp[1][0]=0;
    for(int t=0;t<n;t++)
    {
       for(int j=0;j<n;j++)
       {
           scanf("%d",&Map[t][j]);
       }
    }
    for(int t=0;t<=1<<n;t++)
    {
        for(int j=0;j<n;j++)
        {
            if((t>>j)&1)
            {
                for(int k=0;k<n;k++)
                {
                    if((t^(1<<j)>>k)&1)
                    {
                       dp[t][j]=min(dp[t][j],dp[t^(1<<j)][k]+Map[k][j]);
                    }
                }
            }
        }
    }
    printf("%lld\n",dp[(1<<n)-1][n-1]);
    
    system("pause");
    return 0;
}