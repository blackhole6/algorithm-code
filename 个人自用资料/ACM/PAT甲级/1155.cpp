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

const int maxn=1e4+5;
typedef long long ll;
using namespace std;

int n;
int a[maxn];
int p[maxn];
int depths;
int cc1=0,cc2=0;
int cc=0;
void dfs(int m,int dep)
{
       p[dep]=a[m];
       if((dep==depths-1&&m*2>n)||dep==depths)
       {
            cc++;
            int maxx=0;
            int minn=0x3f3f3f3f;
            int s1=0;
            int s2=0;
           for(int t=1;t<=dep;t++)
           {
               if(p[t]>=maxx)
               {
                   s1++;
                   maxx=p[t];
               }
               if(p[t]<=minn)
               {
                   s2++;
                   minn=p[t];
               }
               if(t!=dep)
               printf("%d ",p[t]);
               else
               {
                 printf("%d\n",p[t]);
               }   
           }
           if(s1==dep)
           {
               cc1++;
           }
           if(s2==dep)
           {
               cc2++;
           }
       }
       if((m<<1|1)<=n)
       dfs(m<<1|1,dep+1);
       if((m<<1)<=n)
       dfs(m<<1,dep+1);
}
int main()
{  
    cin>>n;
    for(int t=1;t<=n;t++)
    {
        scanf("%d",&a[t]);
    }
   depths=log2(n)+1;
    dfs(1,1);
    if(cc1==cc&&cc2==0)
    {
        puts("Min Heap");
    }
    else if(cc2==cc&&cc1==0)
    {
        puts("Max Heap");
    }
    else
    {
        puts("Not Heap");
    }
    
    system("pause");
    return 0;
}