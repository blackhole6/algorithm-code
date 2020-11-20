//最小点覆盖
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>

const int maxn=505;
typedef long long ll;
using namespace std;

struct node
{
    int x,y;
}p[10005];
int n,K;
struct edge
{
    int u,v;
    int nxt;
}Edge[250005];
int cnt;
int head[maxn],vis[maxn],Girl[maxn];
void Add(int u,int v)
{
    Edge[cnt].u=u;
    Edge[cnt].v=v;
    Edge[cnt].nxt=head[u];
    head[u]=cnt++;
}
bool find(int x)
{
    for(int t=head[x];t!=-1;t=Edge[t].nxt)
    {
        int to=Edge[t].v;
        if(!vis[to])
        {
            vis[to]=1;
            if(Girl[to]==-1||find(Girl[to]))
            {
                Girl[to]=x;
                return true;
            }
        }
    }
    return false;
}
int match()
{
    int sum=0;
    for(int t=1;t<=n;t++)
    {
        memset(vis,0,sizeof(vis));
        if(find(t))sum++;
    }
    return sum;
}
int main()
{
    cin>>n>>K;
    cnt=0;
    memset(head,-1,sizeof(head));
    memset(Girl,-1,sizeof(Girl));
    for(int t=1;t<=K;t++)
    {
        scanf("%d%d",&p[t].x,&p[t].y);
        Add(p[t].x,p[t].y);
    }
    cout<<match()<<endl;
    system("pause");
    return 0;
}