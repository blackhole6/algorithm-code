//有两种操作
//往集合里面插入一系列数
//然后往找和要查询的值异或最大的
//输出这个数
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;
const int maxn=1e5+5;
typedef long long ll;
struct node{
   int nxt[2];
   ll val;
}p[maxn*32];
int tot;
void init(){
   for(int t=0;t<=maxn*32-1;t++){
      p[t].val=0;
      p[t].nxt[0]=p[t].nxt[1]=0;
   }
}
void Insert(ll x){
     int tmp=0;
     for(int t=32;t>=0;t--){
         int j=(x>>t)&1;
         if(p[tmp].nxt[j]==0){
            p[tmp].nxt[j]=++tot;
         }
         tmp=p[tmp].nxt[j];
     }
     p[tmp].val=x;
}
ll query(ll x){
   int tmp=0;
   for(int t=32;t>=0;t--){
         int j=(x>>t)&1;
         if(p[tmp].nxt[j^1]){
            tmp=p[tmp].nxt[j^1];
         }
         else{
            tmp=p[tmp].nxt[j];
         }
         
     }
     return p[tmp].val;
}
int main(){
    
    int T;
    cin>>T;
    int cnt=1;
    while(T--){
    int n,m;
    cin>>n>>m;
    tot=0;
    init();
    ll x;
    for(int t=0;t<n;t++){
       scanf("%lld",&x);
       Insert(x);
    }
    printf("Case #%d:\n",cnt++);
    while(m--){
       scanf("%lld",&x);
       printf("%lld\n",query(x));
    }
    }
    return 0;
}