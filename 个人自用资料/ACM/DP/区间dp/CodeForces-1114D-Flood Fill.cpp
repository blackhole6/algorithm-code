#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>
const int maxn=5e3+5;
typedef long long ll;
using namespace std;
vector<int>vec;
int dp[5005][5005];

int main()
{
    int n;
    cin>>n;
    int x;
    for(int t=1;t<=n;t++)
    {
        scanf("%d",&x);
        vec.push_back(x);
    }
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    int nn=vec.size();
    memset(dp,0x3f3f3f3f,sizeof(dp));
    for(int t=0;t<nn;t++)
    {
        dp[t][t]=0;
    }
    for(int t=nn-1;t>=0;t--)
    {
        for(int len=1;t+len<nn;len++)
        {
            if(vec[t]==vec[t+len])
            {
                if(len==1)
                {
                    dp[t][t+len]=0;
                }
                else
                {
                    dp[t][t+len]=dp[t+1][t+len-1]+1;
                }
            }
            else
            {
                dp[t][t+len]=min(dp[t][t+len-1],dp[t+1][t+len])+1;
            }
        }
    }
    cout<<dp[0][nn-1]<<endl;
    //system("pause");
    return 0;
}