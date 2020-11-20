#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>

const int maxn=205;
typedef long long ll;
using namespace std;
struct node
{
    int u,v;
    int nxt;
}Edge[40005];
int cnt;
int n,m;//奶牛数和摊位数
int head[maxn],Girl[maxn],vis[maxn];
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
        if(vis[to]==0)
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

    while(cin>>n>>m)
    {
        memset(head,-1,sizeof(head));
        memset(Girl,-1,sizeof(Girl));
        cnt=0;
        int s;
        for(int t=1;t<=n;t++)
        {
             scanf("%d",&s);
             int v;
             for(int j=0;j<s;j++)
             {
                 scanf("%d",&v);
                 Add(t,v);
             }
        }
        cout<<match()<<endl;
    }
    system("pause");
    return 0;
}