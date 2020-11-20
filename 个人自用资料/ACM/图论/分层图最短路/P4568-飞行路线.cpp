//链接:https://www.luogu.org/problem/P4568
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N=1e5+1e4+5;
const int M=5e5+5e4+5;
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
}Edge[M<<2];
int dis[N],head[N],vis[N],cnt;
void Add(int x,int y,int w){
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
              if(dis[Edge[t].v]>dis[now.pos]+Edge[t].w){
                  dis[Edge[t].v]=Edge[t].w+dis[now.pos];
                  q.push(node(Edge[t].v,dis[Edge[t].v]));
              }
          }
     }
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int st, et;
    cin>>st>>et;
    int u,v,w;

    memset(dis,inf,sizeof(dis));
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    cnt=0;
    for(int t=1;t<=m;t++){
        scanf("%d%d%d",&u,&v,&w);
        for(int j=0;j<=k;j++){
            Add(u+j*n,v+j*n,w);
            Add(v+j*n,u+j*n,w);
            if(j!=k){
                Add(u+j*n,v+(j+1)*n,0);
                Add(v+j*n,u+(j+1)*n,0);
            }
        }
    }
    Dijkstra(st);
    int ans=inf;
    for(int t=0;t<=k;t++){
       ans=min(ans,dis[et+t*n]); 
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}