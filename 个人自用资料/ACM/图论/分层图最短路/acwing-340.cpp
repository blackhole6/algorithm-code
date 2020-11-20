//https://www.acwing.com/activity/content/problem/content/656/1/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<map>
#include<cmath>

const int N=1000000+10,M=1000000+10;
typedef long long ll;
using namespace std;


int n,p,k;
int tot=0;
priority_queue< pair<int ,int> > q;
struct edge
{
    int u,v;
    int  w;
    int nxt;
}Edge[M];
int head[N],dis[N];
bool v[N];

void add(int u,int v,int w)
{
    Edge[++tot].u=u;
    Edge[tot].v=v;
    Edge[tot].w=w;
    Edge[tot].nxt=head[u];
    head[u]=tot;
}
void dijkstra()
{
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[1]=0;
    q.push(make_pair(0,1));
    while(q.size())
    {
        int x=q.top().second;
        q.pop();
        if(v[x]) continue;
        v[x]=true;
        for(int i=head[x];i;i=Edge[i].nxt)
        {
            int y=Edge[i].v,z=max(Edge[i].w,dis[x]);
            if(dis[y]>z)
            {
                dis[y]=z;
                q.push(make_pair(-dis[y],y));
            }
        }
    }
}

int main()
{
    scanf("%d%d%d",&n,&p,&k);
    for(int i=1,x,y,z;i<=p;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
        for(int j=1,z1=0;j<=k;j++)
        {
            add(x+(j-1)*n,y+j*n,z1);
            add(y+(j-1)*n,x+j*n,z1);
            add(x+j*n,y+j*n,z);
            add(y+j*n,x+j*n,z);
        }
    }
    for(int i=1,z=0;i<=k;i++)
        add(i*n,(i+1)*n,z);
    dijkstra();
    if(dis[k+1]*n>=0x3f3f3f3f)
    {
        puts("-1");
    }
    else
    printf("%d",dis[(k+1)*n]);
    return 0;
}