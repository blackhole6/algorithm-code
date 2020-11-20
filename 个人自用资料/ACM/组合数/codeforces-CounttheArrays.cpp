//Lucas用来求组合Cnm
//题意：求n个数，在m范围内选，然后找一个值为最大值形成凸性且左右仅有一个相等的方案书
//C（m,n-1）*(n-2)*(2^(n-3))
//https://codeforces.com/contest/1312/problem/D
#include<bits/stdc++.h>
//#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll quick_power_mod(ll a,ll b,ll m)//pow(a,b)%m
{
    a%=m;
	ll result = 1;
	while(b>0)
	{
		if(b&1)
		result=(result*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return result;
}
//计算组合数取模
ll comp(ll a,ll b,int p)//composite num C(a,b)%p
{
	if(a<b)return 0;
	if(a==b)return 1;
	if(b>a-b)b=a-b;
	ll ans=1,ca=1,cb=1;
	for(ll i=0;i<b;i++)
	{
		ca=(ca*(a-i))%p;
		cb=(cb*(b-i))%p;
	}
	ans=(ca*quick_power_mod(cb,p-2,p))%p;
	return ans;
}
ll lucas(ll n,ll m,ll p)
{
	ll ans=1;
	while(n&&m&&ans)
	{
		ans=(ans*comp(n%p,m%p,p))%p;//also can be recusive
		n/=p;
		m/=p;
	}
	return ans;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    if(n==2){
    	puts("0");
    	return 0;
    }
    ll temp1=lucas(m,n-1,mod);
    ll temp2=(temp1*(n-2))%mod;
    ll ans=temp2*quick_power_mod(2,n-3,mod);
    cout<<ans%mod<<endl;
		
	return 0;
}