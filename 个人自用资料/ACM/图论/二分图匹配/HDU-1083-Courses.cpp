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

const int maxn=305;
typedef long long ll;
using namespace std;

int vis[maxn],Girl[maxn];
int Map[305][305];

int p,n;
bool find(int x)
{
    for(int t=1;t<=p;t++)
    {
        int to=t;
        if(!vis[to]&&Map[x][t])
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
    int T;
    cin>>T;
    while(T--)
    {
      cin>>p>>n;
      memset(Girl,-1,sizeof(Girl));
      memset(Map,0,sizeof(Map));
      int cc;
      int v;
      for(int t=1;t<=p;t++)
      {
        scanf("%d",&cc);
        for(int j=1;j<=cc;j++)
        {
            scanf("%d",&v);
            Map[v][t]=1;
        }
      }
      if(match()==p)
      {
          puts("YES");
      }
      else
      {
          puts("NO");
      }
    }
    system("pause");
    return 0;
}

