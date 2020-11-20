//网络流最大流Dinic模板
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e5+5;
struct node{
	int to,w,nxt;
}Edge[M<<1];
int tot;
int n,m,s,t;
int head[N],dep[N];
void Add(int x,int y,int w){
	Edge[++tot].to=y;
	Edge[tot].w=w;
	Edge[tot].nxt=head[x];
	head[x]=tot;
	return ;
}
bool bfs(){
	memset(dep,0,sizeof(dep));
	queue<int>q;
	q.push(s);
	dep[s]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];i!=-1;i=Edge[i].nxt){
			int y=Edge[i].to;
			int w=Edge[i].w;
			if(w&&!dep[y]){
				dep[y]=dep[x]+1;
				q.push(y);
			}
		}
	}
    return dep[t];
}
int Dinic(int x,int flow){
	if(x==t)return flow;
	int sum=0;
	for(int i=head[x];i!=-1;i=Edge[i].nxt){
		int y=Edge[i].to;
		int w=Edge[i].w;
		if(w&&dep[y]==dep[x]+1){
			int tmp=Dinic(y,min(flow,w));
			flow-=tmp;sum+=tmp;
			Edge[i].w-=tmp;Edge[i^1].w+=tmp;
		}
	}
	if(!sum) return dep[x]=0;
	return sum;
}
int main(){
	while(~scanf("%d%d%d%d",&n,&m,&s,&t)){
		tot=1;
		memset(head,-1,sizeof(head));
		int xx,yy,ww;
		for(int i=1;i<=m;i++){
           scanf("%d%d%d",&xx,&yy,&ww);
		   Add(xx,yy,ww);
		   Add(yy,xx,0);
		}
		int ans=0;
		while(1){
			if(!bfs())break;
			ans+=Dinic(s,0x3f3f3f3f);
		}
		cout<<ans<<endl;
	}
	return 0;
}