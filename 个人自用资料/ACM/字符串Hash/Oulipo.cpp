//字符串Hash
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef unsigned long long  ll;
const int maxn=1e6+5;

char s1[maxn],s2[maxn];
ll pp[maxn];
ll H[maxn];
ll s,b=27,h=1<<31;


int main()
{
    pp[0]=1;
    for(int i=1;i<=1000000;i++)
        pp[i]=pp[i-1]*b;
    int T;
    cin>>T;
    int n,m;
    int ans;
    while(T--)
    {
        scanf("%s%s",s1+1,s2+1);
        n=strlen(s1+1);m=strlen(s2+1);
        H[0]=0;
        for(int i=1;i<=m;i++) H[i]=(H[i-1]*b+(ll)(s2[i]-'A'+1))%h;
        s=0;
        for(int i=1;i<=n;i++) s=(s*b+(ll)(s1[i]-'A'+1))%h;
        ans=0;
        for(int i=0;i<=m-n;i++)
            if(s==H[i+n]-H[i]*pp[n]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}