//二分答案
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
#include<hash_map>
const int maxn=2005;
typedef long long ll;
using namespace std;
using namespace __gnu_cxx;
int a[maxn];
int n;
hash_map<int,bool>mp;
bool check(int x)
{
    for(int t=1;t+x-1<=n;t++)
    {
         int flag=0;
        for(int j=1;j<t;j++)
        {
            if(mp[a[j]]==false)
            {
               mp[a[j]]=true;
            }
            else
            {
                flag=1;
                break;
            }
        }
        for(int j=t+x;j<=n;j++)
        {
            if(flag)
            {
                break;
            }
            if(mp[a[j]]==false)
            {
                mp[a[j]]=true;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        return true;
        for(int j=1;j<=n;j++)
        {
            mp[a[j]]=false;
        }
    }
    return false;
}
int main()
{
    cin>>n;
    int flag=0;
    for(int t=1;t<=n;t++)
    {
        scanf("%d",&a[t]);
        if(mp[a[t]]==0)
        {
            mp[a[t]]=1;
        }
        else
        {
            flag=1;
        }
    }
    if(!flag)
    {
        puts("0");
        return 0;
    }
    int l=0,r=n;
    int mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
   mid=(l+r)>>1;
   cout<<mid+1<<endl;
    return 0;
}
