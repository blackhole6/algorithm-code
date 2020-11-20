//最大连续1
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
#define lson m<<1,l,mid
#define rson m<<1|1,mid+1,r
#define getmid(m) (tree[m].l+tree[m].r)>>1;
const int maxn=5e4+5;
typedef long long ll;
using namespace std;
struct node
{
    int l,r;
    ll lazy;
    ll lmax;
    ll rmax;
    ll maxx;
}tree[maxn<<2];

void pushup(int m)
{
    tree[m].lmax=tree[m<<1].lmax;
    tree[m].rmax=tree[m<<1|1].rmax;
    if(tree[m<<1].lmax==(tree[m<<1].r-tree[m<<1].l+1))
    {
        tree[m].lmax+=tree[m<<1|1].lmax;
    }
    if(tree[m<<1|1].rmax==(tree[m<<1|1].r-tree[m<<1|1].l+1))
    {
        tree[m].rmax+=tree[m<<1].rmax;
    }
    tree[m].maxx=max(max(tree[m<<1].maxx,tree[m<<1|1].maxx),tree[m<<1].rmax+tree[m<<1|1].lmax);
    return ;
}
void pushdown(int m)
{
   if(tree[m].lazy!=-1)
   {
       tree[m<<1].lazy=tree[m].lazy;
       tree[m<<1|1].lazy=tree[m].lazy;
       tree[m<<1].lmax=tree[m<<1].rmax=tree[m<<1].maxx=(tree[m<<1].r-tree[m<<1].l+1)*tree[m].lazy;
       tree[m<<1|1].lmax=tree[m<<1|1].rmax=tree[m<<1|1].maxx=(tree[m<<1|1].r-tree[m<<1|1].l+1)*tree[m].lazy;
       tree[m].lazy=-1;
   }
}
void build(int m,int l,int r)
{
    tree[m].l=l;
    tree[m].r=r;
    tree[m].lazy=-1;
    if(l==r)
    {
     tree[m].lmax=1;
     tree[m].rmax=1;
     tree[m].maxx=1;
     return ;
    }
    int mid=getmid(m);
    build(lson);
    build(rson);
    pushup(m);
}

void update(int m,ll l,ll r,ll val)
{
    if(tree[m].l==l&&tree[m].r==r)
    {
        tree[m].lazy=val;
        tree[m].maxx=tree[m].lmax=tree[m].rmax=(tree[m].r-tree[m].l+1)*val;
        return;
    }
    pushdown(m);
    int mid=getmid(m);
    if(r<=mid)
    {
        update(m<<1,l,r,val);
    }
    else if(l>mid)
    {
        update(m<<1|1,l,r,val);
    }
    else
    {
        update(lson,val);
        update(rson,val);
    }
    pushup(m);
}
int query(int m,int len)
{
    if(tree[m].l==tree[m].r)return tree[m].l;
    pushdown(m);
    if(tree[m<<1].maxx>=len)
    {
        return query(m<<1,len);
    }
    else if(tree[m<<1].rmax+tree[m<<1|1].lmax>=len)
    {
        return tree[m<<1].r-tree[m<<1].rmax+1;
    }
    else 
    {
        return query(m<<1|1,len);
    }
}
int main()
{
    int N,m;
    cin>>N>>m;
    build(1,1,N);
    int op,x,d;
    for(int t=1;t<=m;t++)
    {
         scanf("%d",&op);
         if(op==1)
         {
             scanf("%d",&d);
             int ans;
             if(tree[1].maxx<d)
             {
               puts("0");
               continue;
             }
             ans=query(1,d);
            // cout<<ans<<endl;
             printf("%d\n",ans);
             update(1,ans,ans+d-1,0);
         }
         else
         {
             scanf("%d%d",&x,&d);
             update(1,x,x+d-1,1);
         }
         
    }
    system("pause");
    return 0;
}