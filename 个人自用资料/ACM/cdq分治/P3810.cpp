#include<bits/stdc++.h>  
#define lowbit(x) (x&-x)     
using namespace std;  
typedef long long ll;    
const int maxn=2e5+5;                           
struct node
{
    ll x,y,z;
    bool friend operator <(node x,node y)
    {
        if(x.x!=y.x)
        return x.x<y.x;
        else if(x.x==y.x&&x.y!=y.y){
             return x.y<y.y;
        }
        else {
             return x.z<y.z;
        }
      
    }
}q[maxn*8],a[maxn*8];
ll n,ans,num,sum[maxn*8];
void update(int x,int val)
{
    while(x<=n)
    {
        sum[x]+=val;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int res=0;
    while(x)
    {
        res+=sum[x];
        x-=lowbit(x);
    }
    return res;
}
void cdq(int l,int r)
{
    if(l==r)
        return;
    int m=(l+r)/2;
    for(int i=l;i<=r;i++)
    {
        if(a[i].z<=m)
            update(a[i].y,1);
        else
            ans+=query(a[i].y);
    }
    for(int i=l;i<=r;i++)
        if(a[i].z<=m)
            update(a[i].y,-1);
    int lq=l,rq=m+1;
    for(int i=l;i<=r;i++)
    {
        if(a[i].z<=m)
            q[lq++]=a[i];
        else
            q[rq++]=a[i];
    }
    for(int i=l;i<=r;i++)
        a[i]=q[i];
    cdq(l,m);cdq(m+1,r);
}
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
    sort(a+1,a+n+1);
    cdq(1,n);
    printf("%lld\n",n*(n-1)/2-ans);
    return 0;
}