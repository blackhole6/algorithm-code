//区间不同数个数
#include<bits/stdc++.h>
using namespace std;
const int maxn=30005; 
struct node{
	int l,r;
	int num;
}tree[maxn*32];
int a[maxn];
int root[maxn];
int pos[1000005];
int cnt=0;
void update(int l,int r,int pre,int &now,int p,int add){
	 tree[++cnt]=tree[pre];
	 now=cnt;
	 tree[now].num+=add;
	 //cout<<l<<" "<<r<<" "<<tree[now].num<<endl; 
	 if(l==r)return;
	 int mid=(l+r)>>1;
	 if(p<=mid){
	 	update(l,mid,tree[pre].l,tree[now].l,p,add);
	 }
	 else{
	 	update(mid+1,r,tree[pre].r,tree[now].r,p,add);
	 }
} 
int query(int l,int r,int m,int L,int R){
    if(l==L&&r==R){
    	return tree[m].num;
	}
	int mid=(l+r)>>1;
	if(R<=mid){
		return query(l,mid,tree[m].l,L,R);
	}
	else if(L>mid){
		return query(mid+1,r,tree[m].r,L,R);
	}
	else{
		return query(l,mid,tree[m].l,L,mid)+query(mid+1,r,tree[m].r,mid+1,R);
	}
}
int main(){
	int n;
	cin>>n;
	for(int t=1;t<=n;t++){
		scanf("%d",&a[t]);
	}
	for(int t=1;t<=n;t++){
		if(pos[a[t]]==0)
	    update(1,n,root[t-1],root[t],t,1);
	    else{
	    
	    	update(1,n,root[t-1],root[t],t,1);
	    	int tmp=root[t];
	    	update(1,n,tmp,root[t],pos[a[t]],-1);
		}
		pos[a[t]]=t;
	}
	int m;
	cin>>m;
	int l,r;
	for(int t=0;t<m;t++){
		scanf("%d%d",&l,&r);
		printf("%d\n",query(1,n,root[r],l,r));
		
	}
	return 0;
}
