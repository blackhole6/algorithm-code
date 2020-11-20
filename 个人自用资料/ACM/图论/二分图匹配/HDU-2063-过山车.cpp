//匈牙利算法
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<hash_map>
#include<vector>
#include<cmath>

const int maxn=505;
typedef long long ll;
using namespace std;

struct node
{
 int u,v;
 int nxt;
}Edge[maxn<<1];
int head[maxn];
int Girl[maxn];
int vis[maxn];
int cnt;
int k,n,m;
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
int  match()
{
    int sum=0;
    for(int t=1;t<=m;t++)
    {
       memset(vis,0,sizeof(vis));
       if(find(t))sum++;
    }
    return sum;
}
int main()
{
    while(cin>>k)
    {
    cnt=0;
    memset(head,-1,sizeof(head));
    memset(Girl,-1,sizeof(Girl));
    if(k==0)
    {
        break;
    }
    cin>>m>>n;
    int u,v;
    for(int t=1;t<=k;t++)
    {
        cin>>u>>v;
        Add(u,v);
    }
    cout<<match()<<endl;
    }
    system("pause");
    return 0;
}