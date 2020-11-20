//最大连续字段和
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<cmath>
#define lson m<<1,l,mid
#define rson m<<1|1,mid+1,r
#define getmid(m) (tree[m].l+tree[m].r)>>1
const int maxn=5e4+5;
typedef long long ll;
using namespace std;

struct node
{
    int l,r;
    ll sum,lmax,rmax,maxx;
}tree[maxn<<2];
void pushup(int m)
{
    tree[m].sum=(tree[m<<1].sum+tree[m<<1|1].sum);
    tree[m].lmax=max(tree[m<<1].lmax,tree[m<<1].sum+tree[m<<1|1].lmax);
    tree[m].rmax=max(tree[m<<1|1].rmax,tree[m<<1|1].sum+tree[m<<1].rmax);
    tree[m].maxx=max(max(tree[m<<1].maxx,tree[m<<1|1].maxx),tree[m<<1].rmax+tree[m<<1|1].lmax);
    return ;
}
void build(int m,int l,int r)
{
    tree[m].l=l;
    tree[m].r=r;
    if(l==r)
    {
        scanf("%lld",&tree[m].sum);
        tree[m].lmax=tree[m].rmax=tree[m].maxx=tree[m].sum;
        return ;
    }
    int mid=getmid(m);
    build(lson);
    build(rson);
    pushup(m);
}
void update(int m,int pos,ll val)
{
    if(tree[m].l==tree[m].r&&tree[m].l==pos)
    {
        tree[m].sum=val;
        tree[m].lmax=tree[m].rmax=tree[m].maxx=val;
        return ;
    }
    int mid=getmid(m);
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
node query(int m,int l,int r)
{
    if(tree[m].l==l&&tree[m].r==r)
    {
       return tree[m];
    }
    int mid=getmid(m);
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
        node a=query(m<<1,l,mid);
        node b=query(m<<1|1,mid+1,r);
        node c;
        c.lmax=max(a.lmax,a.sum+b.lmax);
        c.rmax=max(b.rmax,b.sum+a.rmax);
        c.maxx=max(max(a.maxx,b.maxx),a.rmax+b.lmax);
        return c;
    }
    
}
int main()
{
    int N;
    cin>>N;
    build(1,1,N);
    int m;
    cin>>m;
    int op;
    int l,r,pos;
    ll val;
    while(m--)
    {
        scanf("%d",&op);
        if(op==0)
        {
          scanf("%d%lld",&pos,&val);
          update(1,pos,val);
        }
        else
        {
            scanf("%d%d",&l,&r);
            node ans=query(1,l,r);
            printf("%lld\n",ans.maxx);
        }
        
    }
    system("pause");
    return 0;
}