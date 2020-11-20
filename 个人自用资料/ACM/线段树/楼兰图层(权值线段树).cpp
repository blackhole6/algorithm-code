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

const int maxn=2e5+5;
typedef long long ll;
using namespace std;
struct node
{
   int l,r;
   int num;
}tree[maxn<<2];
vector<int>v;
int a[maxn];

void pushup(int m)
{
    tree[m].num=(tree[m<<1].num+tree[m<<1|1].num);
}

void build(int m,int l,int r)
{
    tree[m].l=l;
    tree[m].r=r;
    tree[m].num=0;
    if(l==r)
    {
       return ;
    }
    int mid=(tree[m].l+tree[m].r)>>1;
    build(m<<1,l,mid);
    build(m<<1|1,mid+1,r);
    
}
void update(int m,int pos,int val)
{
    if(tree[m].l==tree[m].r)
    {
        tree[m].num+=val;
        return;
    }
    int mid=(tree[m].l+tree[m].r)>>1;
    if(pos<=mid)
    {
        update(m<<1,pos,val);
    }
    else
    {
        update(m<<1|1,pos,val);
    }
    pushup(m);
}
int query(int m,int l,int r)
{
    if(tree[m].l==l&&tree[m].r==r)
    {
        return tree[m].num;
    }
    int mid=(tree[m].l+tree[m].r)>>1;
    if(r<=mid)
    {
        return query(m<<1,l,r);
    }
    else if(l>mid)
    {
        return query(m<<1|1,l,r);
    }
    else 
    {
        return query(m<<1,l,mid)+query(m<<1|1,mid+1,r);
    }
    
}
ll minl[maxn],minr[maxn],maxl[maxn],maxr[maxn];
int main()
{
    int n;
    cin>>n;
    for(int t=1;t<=n;t++)
    {
        scanf("%d",&a[t]);
    }
    build(1,0,n+1);
    for(int t=1;t<=n;t++)
    {
        minl[t]=query(1,0,a[t]-1);
        maxl[t]=query(1,a[t]+1,n+1);
        update(1,a[t],1);
    }
    build(1,0,n+1);
    for(int t=n;t>=1;t--)
    {
        minr[t]=query(1,0,a[t]-1);
        maxr[t]=query(1,a[t]+1,n+1);
        update(1,a[t],1);
    }
    ll ans1=0,ans2=0;
    for(int t=1;t<=n;t++)
    {
         ans1+=maxl[t]*maxr[t];
         ans2+=minl[t]*minr[t];
    }
    printf("%lld %lld\n",ans1,ans2);

    system("pause");
    return 0;
    
}