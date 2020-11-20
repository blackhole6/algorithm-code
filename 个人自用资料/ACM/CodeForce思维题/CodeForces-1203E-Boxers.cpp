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

const int maxn=150005;
typedef long long ll;
using namespace std;
int a[maxn];
int vis[maxn];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
     for(int t=1;t<=n;t++)
     {
        scanf("%d",&a[t]);
     }
     sort(a+1,a+n+1);
     int ans=0;
     a[n+1]=150002;
     for(int t=1;t<=n;t++)
     {
        if(a[t]-1>a[t-1])
        {
            ans++;
            a[t]--;
        }
        else if(a[t]!=a[t-1])
        {
            ans++;
        }
        else if(a[t+1]>a[t])
        {
            ans++;
            a[t]++;
        }
     }
     cout<<ans<<endl;
    }

}