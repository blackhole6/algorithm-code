//伯特兰-切比雪夫定理
//链接：https://www.cometoj.com/contest/64/problem/B?problem_id=3516
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isprime(ll x){
    int xx=sqrt(x);
    for(int t=2;t<=xx;t++)
    {
        if(x%t==0) return false;
    }
    return true;
}
int main()
{
    ll n,k;
    while(cin>>n>>k)
    {
        if(isprime(k+1))
        {
            if((k+1)*2>n+1)puts("1");
            else puts("2");
        }
        else puts("2");
    }
    return 0;
}