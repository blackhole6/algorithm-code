//链接：https://www.acwing.com/problem/content/344/
//SPFA SLF优化 利用双端对列
#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int N=25005,M=50005;
int T;
struct edge{
     int v;
     int w;
     int nxt;
}Edge[M<<2];
int head[N],vis[N],dis[N],num[N],cnt;
void add(int x,int y,int w){
     Edge[cnt].v=y;
     Edge[cnt].w=w;
     Edge[cnt].nxt=head[x];
     head[x]=cnt++;
}

bool SPFA(int s){
     dis[s]=0;
     vis[s]=1;
     num[s]++;
     deque<int>q;
     q.push_back(s);
     while(!q.empty()){
          int now=q.front();
          q.pop_front();
          vis[now]=0;
          for(int t=head[now];t!=-1;t=Edge[t].nxt){
              if(dis[now]+Edge[t].w<dis[Edge[t].v]){
                   dis[Edge[t].v]=dis[now]+Edge[t].w;
                   if(vis[Edge[t].v]==0){
                        vis[Edge[t].v]=1;
                        if(q.size()&&dis[Edge[t].v]<dis[q.front()]){
                             q.push_front(Edge[t].v);
                        }
                        else{
                             q.push_back(Edge[t].v);
                        }
                   }
              }
          }
     }
     return true;
}
int main(){
     int R,P,S;
     cin>>T>>R>>P>>S;
     int u,v,w;
     cnt=0;
     memset(dis,inf,sizeof(dis));
     memset(head,-1,sizeof(head));
     memset(vis,0,sizeof(vis));
     memset(num,0,sizeof(num));
     for(int t=0;t<R;t++){
         scanf("%d%d%d",&u,&v,&w);
         add(u,v,w);
         add(v,u,w);
     }
     for(int t=0;t<P;t++){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
     }
     SPFA(S);
     for(int t=1;t<=T;t++){
        if(dis[t]==inf){
             puts("NO PATH");
        }
        else{
             printf("%d\n",dis[t]);
        }
     }
     //system("pause");
     return 0;
}