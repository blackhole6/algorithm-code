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

const int maxn=55;
typedef long long ll;
using namespace std;
int a[maxn][maxn];
int vis[maxn][maxn];
vector<pair<int,int> >vec;
int cnt;
int n,m,num;
int i,j,tt;
int main()
{
#ifdef ONLINE_JUDGE
#else
      freopen("in.txt","r",stdin);
#endif
     while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        cnt=0;
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
                scanf("%d",&a[i][j]),cnt+=a[i][j];
        num=0;
        tt=0;
        for(i=2; i<=n; i++)
            for(j=2; j<=m; j++)
            {
                if(a[i][j]&&a[i-1][j]&&a[i][j-1]&&a[i-1][j-1])
                {
                    tt++;
                    if(!vis[i][j])
                        num++,vis[i][j]=1;
                    if(!vis[i-1][j])
                        num++,vis[i-1][j]=1;
                    if(!vis[i][j-1])
                        num++,vis[i][j-1]=1;
                    if(!vis[i-1][j-1])
                        num++,vis[i-1][j-1]=1;
                }
            }

        if(cnt!=num)
            printf("-1\n");
        else
        {
            printf("%d\n",tt);
            for( i=2; i<=n; i++)
                for( j=2; j<=m; j++)
                {
                    if(a[i][j]&&a[i-1][j]&&a[i][j-1]&&a[i-1][j-1])
                    {
                        printf("%d %d\n",i-1,j-1);
                    }
                }
        }
    }
      return 0;
}