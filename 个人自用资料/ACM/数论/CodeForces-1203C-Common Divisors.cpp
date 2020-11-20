//求一组数的公约数的个数
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


const int maxn=4e5+5;
typedef long long ll;
using namespace std;

ll a[maxn];
int prime[1000005];
bool vis[1000005];
int cnt;
void erla() {
	cnt =0;
	memset(vis,false,sizeof(vis));
	memset(prime,0,sizeof(prime));
	for(int t=2; t<=1000003; t++) {
		if(!vis[t]) {
			prime[cnt++]=t;
		}
		for(int j=0; j<cnt&&t*prime[j]<=1000003; j++) {
			vis[t*prime[j]]=true;
			if(t%prime[j]==0) {
				break;
			}
		}
	}
}

int main()
{
    int n;
    erla();
    while(~scanf("%d",&n))
    {
        for(int t=0;t<n;t++)
        {
            scanf("%lld",&a[t]);
        }
        ll ans1=a[0];
        for(int t=1;t<n;t++)
        {
         ans1=__gcd(ans1,a[t]);
        }
        ll ans=1;
        for(int t=0;t<cnt;t++)
        {
          int cc=0;
          while(ans1%prime[t]==0)
          {
            ans1/=prime[t];
            cc++;
          }
        ans*=(cc+1);
          if(ans1==1)
          {
              break;
          }
         
        }
        if(ans1!=1)
        ans*=2;
        printf("%lld\n",ans);
    }
    return 0;
}