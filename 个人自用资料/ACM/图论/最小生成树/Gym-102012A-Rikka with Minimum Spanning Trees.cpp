#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>

const int maxn=1e5+5;
typedef unsigned long long ll;
const ll mod=1e9+7;
using namespace std;
int n,m;
ll k1,k2;
struct node
{
    int u,v;
    ll w;

}e[maxn];
ll xorShift128Plus()
{
    ll k3=k1,k4=k2;
    k1=k4;
    k3^=k3<<23;
    k2=k3^k4^(k3>>17)^(k4>>26);
    return k2+k4;
}
void gen()
{
    scanf("%d%d%llu%llu",&n,&m,&k1,&k2);
    for(int i=1;i<=m;i++)
    {
        e[i].u=xorShift128Plus()%n+1;
        e[i].v=xorShift128Plus()%n+1;
        e[i].w=xorShift128Plus();
    }
}
int pre[maxn];
int find(int x)
{
    if(x==pre[x])
    {
        return x;
    }
    else
    {
        return pre[x]=find(pre[x]);
    }
}
bool Merge(int x,int y )
{
    int xx=find(x);
    int yy=find(y);
    if(xx!=yy)
    {
        pre[xx]=yy;
        return true;
    }
    else
    {
        return false;
    } 
}
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    gen();
    sort(e+1,e+m+1,cmp);
    ll sum=0;
    int cnt=0;
    int res=1;
    for(int t=1;t<=n;t++)
    {
        pre[t]=t;
    }
    for(int t=1;t<=m;t++)
    {
        if(cnt==n-1)
        {
            break;
        }
        if(Merge(e[t].u,e[t].v))
        {
         if(t+1<=m&&e[t].w==e[t+1].w&&e[t].u==e[t+1].u&&e[t].v==e[t+1].v)
         {
             res++;
         }
         cnt++;
         sum=(sum+e[t].w)%mod;
        }
    }

    if(cnt<n-1)
    {
        puts("0");
    }
    else
    {
        printf("%llu\n",(sum%mod*(res%mod)));
    }
    }
    system("pause");
    return 0;
}