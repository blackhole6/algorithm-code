#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>
const int maxn=1e5+5;
typedef long long ll;
using namespace std;
int a[maxn];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(k>=n/2)
    {
        puts("1");
        if(n%2==1)
        printf("%d\n",n/2+1);
        else
        {
             printf("%d\n",n/2);
        }
        
    }
    else
    {
        if(n%(2*k+1)==0)
        {
            printf("%d\n",n/(2*k+1));
            for(int t=k+1;t<=n;t+=2*k+1)
            {
                printf("%d ",t);
            }
        }
        else
        {
            int s=0;
            int tmp;
            for(int t=1;t<=n;t+=2*k+1)
            {
                s++;
            }
            printf("%d\n",s);
           
            for(int j=1;j<=k+1;j++)
            {
            int cnt=0;
            tmp=j;
            int kk=0;
            for(int t=j;t<=n;t+=2*k+1)
            {
              
                kk++;
                a[cnt++]=t;
                if(kk==s-1)
                {
                    tmp=t;
                    break;
                }
            }
       
           // cout<<tmp<<endl;
            if(tmp+2*k+1+k>=n)
            {
                
                for(int t=0;t<cnt;t++)
                {
                    printf("%d ",a[t]);
                }
                printf("%d ",tmp+2*k+1);
               // system("pause");
                return 0;
             }
            
            }
        }
    }
   //system("pause");
    return 0;
}