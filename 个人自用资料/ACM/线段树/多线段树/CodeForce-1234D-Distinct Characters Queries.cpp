//建立26棵线段树进行操作,统计不同的数量区间不同字符的数量
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
typedef long long ll;
char str[maxn];
struct node{
    int l,r;
    int num;
}tree[28][maxn<<2];
void pushup(int i,int m){
     tree[i][m].num=(tree[i][m<<1].num+tree[i][m<<1|1].num);
     return ;
}
void build(int m,int l,int r,int i){
     tree[i][m].l=l;
     tree[i][m].r=r;
     tree[i][m].num=0;
     if(l==r){
        return ;
     }
     int mid=(l+r)>>1;
     build(m<<1,l,mid,i);
     build(m<<1|1,mid+1,r,i);
     pushup(i,m);
}
void update(int m,int pos,int val,int i){
     if(tree[i][m].l==tree[i][m].r&&tree[i][m].r==pos){
         tree[i][m].num=val;
         return ;
     }
     int mid=(tree[i][m].l+tree[i][m].r)>>1;
     if(pos<=mid){
         update(m<<1,pos,val,i);
     }
     else{
         update(m<<1|1,pos,val,i);
     }
     pushup(i,m);
}
int query(int m,int l,int r,int i){
    if(tree[i][m].l==l&&tree[i][m].r==r){
        return tree[i][m].num;
    }
    int mid=(tree[i][m].l+tree[i][m].r)>>1;
    if(r<=mid){
        return query(m<<1,l,r,i);
    }
    else if(l>mid){
        return query(m<<1|1,l,r,i);
    }
    else{
        return query(m<<1,l,mid,i)+query(m<<1|1,mid+1,r,i);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",str+1);
    int len=strlen(str+1);
    for(int t=1;t<=26;t++){
        build(1,1,len,t);
    }
    for(int t=1;t<=len;t++){
        update(1,t,1,str[t]-'a'+1);
    }
    int q;
    scanf("%d",&q);
    int op;
    char tmp[2];
    int pos,l,r;
    while(q--){
         scanf("%d",&op);
         if(op==1){
             scanf("%d%s",&pos,tmp);
             update(1,pos,0,str[pos]-'a'+1);
             update(1,pos,1,tmp[0]-'a'+1);
             str[pos]=tmp[0];
         }
         else{
             scanf("%d%d",&l,&r);
             int ans=0;
             for(int t=1;t<=26;t++){
               // cout<<tmp1<<" "<<query(1,l,r,t)<<endl;
                if(query(1,l,r,t)>0){
                   ans++;
                }
               
             }
             printf("%d\n",ans);
         }
    }
    return 0;
}