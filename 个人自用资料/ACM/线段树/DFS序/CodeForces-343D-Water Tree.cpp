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
#define lson m<<1,l,mid
#define rson m<<1|1,mid+1,r
#define getmid(m) (tree[m].l+tree[m].r)>>1
#define ls  m<<1,pos,val
#define rs  m<<1|1,pos,val


const int maxn=5e5+5;
typedef long long ll;
using namespace std;
vector<int>vec[maxn];
int in[maxn],out[maxn];

struct  node
{
	int l,r;
	int val;
	int lazy;
	int flag;
}tree[maxn<<2];
int fa[maxn];
void pushup(int m)
{
	tree[m].val=tree[m<<1].val+tree[m<<1|1].val;
}
void pushdown(int m)
{
	if(tree[m].lazy!=-1)
	{
		tree[m<<1].lazy=tree[m<<1|1].lazy=tree[m].lazy;
		tree[m<<1].val=(tree[m<<1].r-tree[m<<1].l+1)*(tree[m].lazy);
		tree[m<<1|1].val=(tree[m<<1|1].r-tree[m<<1|1].l+1)*(tree[m].lazy);
		tree[m].lazy=-1;
	}
	return ;
}
void build(int m,int l,int r)
{
	tree[m].l=l;
	tree[m].r=r;
	tree[m].flag=0;
	tree[m].val=0;
	tree[m].lazy=-1;
	if(l==r)
	{
		return;
	}
	int mid=getmid(m);
	build(lson);
	build(rson);
}
void update(int m,int l,int r,int val)
{ 
   if(tree[m].l==l&&tree[m].r==r) 
   {
	   tree[m].val=(tree[m].r-tree[m].l+1)*val;
	   tree[m].lazy=val;
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
}
int query(int m,int l,int r)
{
	if(tree[m].l==l&&tree[m].r==r)
	{
		return tree[m].val;
	}
	pushdown(m);
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
	      return query(m<<1,l,mid)+query(m<<1|1,mid+1,r);
	}
}
int cc;
void dfs(int x,int pre)
{
	in[x]=cc++;
	for(int t=0;t<vec[x].size();t++)
	{
		int to=vec[x][t];
		if(to==pre)
		{
			continue;
		}
		fa[to]=x;
		dfs(to,x);
	}
	out[x]=cc;
}
int main()
{
    int n,q;
	while(~scanf("%d",&n))
	{
		for(int t=1;t<=n;t++)
		{
			vec[t].clear();
		}
		for(int t=1;t<=n;t++)
		{
			fa[t]=t;
		}
		for(int t=1;t<=n;t++)
		{
			in[t]=0;
			out[t]=0;
		}
		int u,v;
		for(int t=1;t<n;t++)
		{
           scanf("%d%d",&u,&v);
		   vec[u].push_back(v);
		   vec[v].push_back(u);
		}
		cc=1;
		dfs(1,-1);
		build(1,1,n);
		int op , vv;
		scanf("%d",&q);
		while(q--)
		{
          scanf("%d%d",&op,&vv);
		  if(op==1)
		  {
			 int ans=query(1,in[vv],out[vv]-1);
			 if(ans!=(out[vv]-in[vv])&&fa[vv]!=vv)
			 {
				 update(1,in[fa[vv]],in[fa[vv]],0);
			 }
             update(1,in[vv],out[vv]-1,1);
		  }
		  else if(op==2)
		  {
             update(1,in[vv],in[vv],0);
		  }
		  else
		  {
			  int ans=query(1,in[vv],out[vv]-1);
			  if(ans!=(out[vv]-in[vv]))
			  {
				  puts("0");
			  }
			  else
			  {
				  puts("1");
			  }
		  }
		}	
	}
	return 0;
}