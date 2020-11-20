//贪心+枚举起点，然后+k

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=4e5+5;
typedef long long ll;

ll a[maxn];
ll presum[maxn];
int main(){  
    ios::sync_with_stdio(false);
    cin.tie();
    int T;
	cin>>T;
	memset(a,inf,sizeof(a));
	while(T--){
		int n,p,k;
		cin>>n>>p>>k;
		for(int t=1;t<=n;t++){
			cin>>a[t];
		}
		sort(a+1,a+n+1);
		for(int t=1;t<=n;t++){
            presum[t]=presum[t-1]+a[t];
		}
		ll sans=0;
		for(int j=1;j<=k;j++){
	    ll sum=presum[j-1];
		ll ans=j-1;
		int flag=0;
		int tmp=n-k+1;
		for(int t=j;t+k-1<=n;t+=k){
			if(sum+a[t+k-1]<=p){
				flag=1;
				sum+=a[t+k-1];
				ans+=k;
			}
			else if(sum+a[t]<=p){
				   tmp=t;
				   flag=2;
			}
			if(flag==2){
				break;
			}
		}
		if(flag==2){
		for(int k1=tmp;k1<=n&&k1<=tmp+k-1;k1++){
		   //cout<<k1<<endl;
           if(sum+a[k1]<=p){
			   sum+=a[k1];
			   ans++;
		   }
		   else {
			   break;
		   }
		}
		}
		if(flag)
	    sans=max(sans,ans);
		}
		cout<<sans<<endl;
	}
	return 0;
}