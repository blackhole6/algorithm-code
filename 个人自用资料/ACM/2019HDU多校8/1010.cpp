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
#define eps 1e-6


const int maxn=1e5+5;
typedef long long ll;
using namespace std;
struct node
{
	char name[15];
	int num,tt;
}p[maxn];

bool cmp(node x,node y)
{
	if(x.num!=y.num)
	{
      return x.num>y.num;
	}
	else
	{
		return x.tt<y.tt;
	}
}
int main()
{
    int T;
	cin>>T;
	int n,d;
	while(T--)
	{
		scanf("%d%d",&n,&d);
	    for(int  t=0;t<n;t++)
		{
            scanf("%s%d%d",p[t].name,&p[t].num,&p[t].tt);
		}
	    sort(p,p+n,cmp);
		double s=n*(0.1)*d;
	    if((s-floor(s))>=0.5-eps&&s-floor(s)<=0.5+eps)
		{
			int tmp=ceil(s);
            printf("%s\n",p[tmp-1]);
		}
		else
		{
			puts("Quailty is very great");
		}
	}
    system("pause");
	return 0;
}