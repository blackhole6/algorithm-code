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

const int maxn=1e5+5;
typedef long long ll;
using namespace std;
vector<int>vec[maxn];

int a[maxn];
int main()
{
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int t=0;t<m;t++)
    {
        scanf("%d%d",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int k;
    cin>>k;
    while(k--)
    {
    set<int>s;
    for(int t=0;t<n;t++)
    {
      scanf("%d",&a[t]);
      s.insert(a[t]);
    }
    int cnt=0;
    for(int t=0;t<n;t++)
    {
       for(int j=0;j<vec[t].size();j++)
       {
           if(a[t]!=a[vec[t][j]])
           {
            cnt++;
           }
       }
    }
    if(cnt==2*m)
    {
        printf("%d-coloring\n",s.size());
    }
    else
    {
        puts("No");
    }
    
   
    }
    system("pause");
    return 0;
}