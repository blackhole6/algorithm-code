//牛客多校4 J 分层图最短路
//https://ac.nowcoder.com/acm/contest/884/J
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=1010005;
const int M=4010005;
struct node{
    int pos;
    int w;
    node (int x,int y){
        pos=x;
        w=y;
    }
    bool friend operator < (node x,node y){
         return x.w>y.w;
    }
};
struct edge{
    int v;
    int w;
    int nxt;
}Edge[M];
int head[N],vis[N],dis[N];
int cnt;
void add(int x,int y,int w){
     Edge[cnt].v=y;
     Edge[cnt].w=w;
     Edge[cnt].nxt=head[x];
     head[x]=cnt++;
}
void Dijkstra(int s){
     priority_queue<node>q;
     dis[s]=0;
     q.push(node(s,0));
     while(!q.empty()){
          node now=q.top();
          q.pop();
          if(vis[now.pos])continue;
          vis[now.pos]=1;
          for(int t=head[now.pos];t!=-1;t=Edge[t].nxt){
              if(dis[now.pos]+Edge[t].w<dis[Edge[t].v]){
                  dis[Edge[t].v]=dis[now.pos]+Edge[t].w;
                  q.push(node(Edge[t].v,dis[Edge[t].v]));
              }
          }
     }
     
}
int main(){
    int n,m,S,T,k;
    cin>>n>>m>>S>>T>>k;
    int u,v,w;
    cnt=0;
    memset(dis,inf,sizeof(dis));
    memset(head,-1,sizeof(head));
    for(int t=0;t<m;t++){
        scanf("%d%d%d",&u,&v,&w);
        for(int j=0;j<=k;j++){
           add(u+j*n,v+j*n,w);
           add(v+j*n,u+j*n,w);
           if(j!=k){
               add(u+j*n,v+(j+1)*n,0);
               add(v+j*n,u+(j+1)*n,0);
           }
        }
    }
    Dijkstra(S);
    int ans=inf;
    for(int t=0;t<=k;t++){
        //cout<<dis[T+t*n]<<endl;
        ans=min(ans,dis[T+t*n]);
    }
    cout<<ans<<endl;
    
   // system("pause");
    return 0;
}