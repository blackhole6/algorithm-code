//线段树区间合并+二分
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
#define getmid(m) (tree[m].l+tree[m].r)>>1

const int maxn=5e4+5;
typedef long long ll;
using namespace std;

struct node
{
    int l,r;
    ll lazy;
    ll lmax,rmax;
    ll maxx;
}tree[maxn<<2];

struct node1
{
    int l,r;
    bool friend operator < (node1 x,node1 y)
    {
        return x.l<y.l;
    }
};
void pushup(int m)
{
    tree[m].lmax=tree[m<<1].lmax;
    tree[m].rmax=tree[m<<1|1].rmax;
    if(tree[m<<1].maxx==(tree[m<<1].r-tree[m<<1].l+1))
    {
        tree[m].lmax+=tree[m<<1|1].lmax;
    }
    if(tree[m<<1|1].maxx==(tree[m<<1|1].r-tree[m<<1|1].l+1))
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
   return ;
}

void build(int m,int l,int r)
{
    tree[m].l=l;
    tree[m].r=r;
    tree[m].lazy=-1;
    if(l==r)
    {
       tree[m].lmax=tree[m].rmax=tree[m].maxx=1;
       return ;
    }
    int mid=getmid(m);
    build(lson);
    build(rson);
    pushup(m);
    return ;
}
void update(int m,int l,int r,ll val)
{
    if(tree[m].l==l&&tree[m].r==r)
    {
     tree[m].lazy=val;
     tree[m].lmax=tree[m].rmax=tree[m].maxx=(tree[m].r-tree[m].l+1)*val;
     return ;
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
    return ;
}
int  query(int m,int len)
{
   if(tree[m].l==tree[m].r)
   {
       return tree[m].l;
   }
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
    int n,m;
    char op[10];
    while(~scanf("%d%d",&n,&m))
    {
      build(1,1,n);
      vector<node1>vec;
      vector<node1>::iterator it;
      for(int t=1;t<=m;t++)
      {
      scanf("%s",op);
      if(op[0]=='R')
      {
          vec.clear();
          update(1,1,n,1);
          printf("Reset Now\n");
      }
      else if(op[0]=='N')
      {
          int x;
          scanf("%d",&x);
          if(tree[1].maxx<x)
          printf("Reject New\n");
          else
          {
              int ans=query(1,x);
              printf("New at %d\n",ans);
              update(1,ans,ans+x-1,0);
              node1 tmp;
              tmp.l=ans;
              tmp.r=ans+x-1;
              it=upper_bound(vec.begin(),vec.end(),tmp);
              vec.insert(it,tmp);
          } 
      }
      else if(op[0]=='F')
      {
         int x;
         scanf("%d",&x);
         node1 tmp;
         tmp.l=x;
         it=upper_bound(vec.begin(),vec.end(),tmp);
         int mid=it-vec.begin()-1;
        if(mid!=-1&&vec[mid].l<=x&&vec[mid].r>=x)
        {
            printf("Free from %d to %d\n",vec[mid].l,vec[mid].r);
            update(1,vec[mid].l,vec[mid].r,1);
            vec.erase(vec.begin()+mid);
        }
        else
        {
            printf("Reject Free\n");
        }
      }
      else if(op[0]=='G')
      {
           int x;
           scanf("%d",&x);
           if(vec.size()<x)
           {
               printf("Reject Get\n");
           }
           else
           {
              printf("Get at %d\n",vec[x-1].l);
           }  
      }
      }
      printf("\n");
    }
    system("pause");
    return 0;
}