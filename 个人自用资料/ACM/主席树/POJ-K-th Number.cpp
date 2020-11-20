//区间第K大
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;
const int maxn=2e5+5;
typedef long long ll;
struct node{
    int l,r,num;
}tree[maxn*32];
vector<int>vec;
int a[maxn];
int root[maxn];
int cnt=0;
int getid(int x){
    return lower_bound(vec.begin(),vec.end(),x)-vec.begin()+1;
}
void update(int l,int r,int pre,int &now,int p){
     tree[++cnt]=tree[pre];
     now=cnt;
     tree[now].num++;
     if(l==r)return ;
     int mid=(l+r)>>1;
     if(p<=mid){
         update(l,mid,tree[pre].l,tree[now].l,p);
     }
     else{
         update(mid+1,r,tree[pre].r,tree[now].r,p);
     }
}
int query(int l,int r,int L,int R,int k){
    if(l==r)return l;
    int mid=(l+r)>>1;
    int tmp=tree[tree[R].l].num-tree[tree[L].l].num;
    if(k<=tmp){
        return query(l,mid,tree[L].l,tree[R].l,k);
    }
    else{
        return query(mid+1,r,tree[L].r,tree[R].r,k-tmp);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int t=0;t<maxn*32;t++){
        tree[t].num=0;
        tree[t].l=0;
        tree[t].r=0;
    }
    root[0]=0;
    for(int t=1;t<=n;t++){
        root[t]=0;
        scanf("%d",&a[t]);
        vec.push_back(a[t]);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int t=1;t<=n;t++){
        //cout<<getid(a[t])<<endl;
        update(1,n,root[t-1],root[t],getid(a[t]));
    }
    int l,r,k;
    for(int t=0;t<m;t++){
        scanf("%d%d%d",&l,&r,&k);
        //cout<<query(1,n,root[l-1],root[r],k)<<endl;
        printf("%d\n",vec[query(1,n,root[l-1],root[r],k)-1]);

    }

}
