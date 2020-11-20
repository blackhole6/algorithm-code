//找一个区间里比他小的这个数的最右边位置
//有点搜索的意思
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
int ans[maxn];
struct node{
    int l,r;
    int num;
}tree[maxn<<2];
int a[maxn];
void pushup(int m){
     tree[m].num=min(tree[m<<1].num,tree[m<<1|1].num);
}
void build (int m,int l,int r){
     tree[m].l=l;
     tree[m].r=r;
     if(l==r){
         scanf("%d",&tree[m].num);
         a[l]=tree[m].num;
         return ;
     }
     int mid=(l+r)>>1;
     build(m<<1,l,mid);
     build(m<<1|1,mid+1,r);
     pushup(m);
}
void query(int m,int l,int r,int i){
    //cout<<tree[m].l<<" "<<tree[m].r<<endl;

    if(tree[m].l==tree[m].r ){
        if(tree[m].l<=i){
            ans[i]=-1;
        }
        else
        ans[i]=(tree[m].l-i-1);
        return ;
    }
    int mid=(tree[m].l+tree[m].r)>>1;
    if(a[i]>tree[m<<1|1].num){
        query(m<<1|1,mid+1,r,i);
    }
    else{
        query(m<<1,l,mid,i);
    }
}
int main(){
    int n;
    cin>>n;
    build(1,1,n);
    for(int t=1;t<=n;t++){
        if(tree[1].num==a[t]){
            ans[t]=-1;
        }
        else{
           query(1,t,n,t);
        }

    }
    for(int t=1;t<=n;t++){
        printf("%d ",ans[t]);
    }
    return 0;
}