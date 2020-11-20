//n个数分成,k个区间,每个区间的权值是这个区间内不同数字的个数,求权值和最大
#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
const double esp = 1e-12;
const int ff = 0x3f3f3f3f;
map<int,int>::iterator it;
struct tree
{
	int l,r;
	int max_v;
	int val;
	int lazy;
}e[maxn*4];
int n,m;
int a[maxn],pre[maxn],last[maxn],dp[maxn];
 
void build(int i,int l,int r)
{
	e[i].l = l;
	e[i].r = r;
	e[i].max_v = e[i].lazy = 0;
	if(l == r)
	{
		e[i].val = e[i].max_v = a[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	e[i].max_v = max(e[i<<1].max_v,e[i<<1|1].max_v);
}
 
void push_down(int i)
{
	int v = e[i].lazy;
	e[i<<1].lazy+= v;
	e[i<<1|1].lazy+= v;
	e[i<<1].max_v+= v;
	e[i<<1|1].max_v+= v;
	e[i].lazy = 0;
}
void update(int i,int l,int r,int v)
{
	if(e[i].l> r||e[i].r< l)
		return ;
	if(e[i].l>= l&&e[i].r<= r)
	{
		e[i].lazy+= v;
		e[i].max_v+= v;
		return ;
	}
	push_down(i);
	update(i<<1,l,r,v);
	update(i<<1|1,l,r,v);
	e[i].max_v = max(e[i<<1].max_v,e[i<<1|1].max_v);
}
int query(int i,int l,int r)
{
	if(e[i].l> r||e[i].r< l)
		return 0;
	if(e[i].l>= l&&e[i].r<= r)
		return e[i].max_v;
	return max(query(i<<1,l,r),query(i<<1|1,l,r));
}
int main()
{
	cin>>n>>m;
	for(int i = 1;i<= n;i++)
		scanf("%d",&a[i]);
	for(int i = 1;i<= n;i++)
		pre[i] = last[a[i]]+1,last[a[i]] = i;
	for(int i = 1;i<= n;i++)
		dp[i] = dp[i-1]+(pre[i] == 1);
	for(int i = 2;i<= m;i++)
	{
		for(int j = 1;j<= n;j++)
			a[j] = dp[j-1];
		build(1,1,n);
		for(int j = 1;j<= n;j++)
		{
			update(1,pre[j],j,1);
			dp[j] = query(1,1,j);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}