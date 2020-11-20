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
#define inf 0x3f3f3f3f

const int maxn=2e5+5;
typedef long long ll;
using namespace std;
char str[maxn];
int a[maxn];
int main()
{
    scanf("%s",str+1);
    int len=strlen(str+1);
    int s=0;
    int cnt=0;
    int cc=0;
    for(int t=1;t<=len;t++)
    {
       s+=(str[t]-'0')%3;
       cnt++;
       if(cnt==3||s==3||(str[t]-'0')%3==0)
       {
           cc++;
           cnt=0;
           s=0;
       }
        
    }
    cout<<cc<<endl;
    system("pause");
    return 0;
}