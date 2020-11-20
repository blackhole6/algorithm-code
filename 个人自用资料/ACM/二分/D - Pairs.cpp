//https://atcoder.jp/contests/abc155/tasks/abc155_d 
//有个长度为n的数组，则产生n*(n-1)/2,则排好序后的求第k个数
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=2e5+5;
typedef long long ll;
vector<ll>vec1,vec2,vec3;
ll n,k;
bool check(ll x){
	ll x1=vec1.size();
	ll x2=vec2.size();
	ll x3=vec3.size();
	ll pos=0;
     if(x==0){
		 pos+=(x1*x3);
		 pos+=(x2*x1+x3*x2);
		 pos+=(x2*(x2-1))/2;
		 return pos>=k;
	 }
	 else if(x>0){
		 pos+=(x1*x3);//负数的数量
		 pos+=(x2*x1+x3*x2);//0的数量
		 pos+=(x2*(x2-1))/2;//0的数量
		 for(int i=0;i<x1;i++){
			 ll tmp;
			 if(x%vec1[i]){
                 tmp=x/vec1[i];
			 }
			 else{
			     tmp=x/vec1[i];
			 }
             if(lower_bound(vec1.begin()+i+1,vec1.end(),tmp)==vec1.end()){
                 pos+=0;
			 }
			 else{
				 pos+=vec1.end()-lower_bound(vec1.begin()+i+1,vec1.end(),tmp);
			 }
		//	 pos+=x1-i-(lower_bound(vec1.begin()+i+1,vec1.end(),tmp)-(vec1.begin()+i));
		 }
		  for(int i=0;i<x3;i++){
			 ll tmp;
			 if(x%vec3[i]){
                 tmp=x/vec3[i];
			 }
			 else{
			     tmp=x/vec3[i];
			 }
			 if(upper_bound(vec3.begin()+i+1,vec3.end(),tmp)==vec3.end()){
                 pos+=vec3.end()-(vec3.begin()+i+1);
             }
             else{
                 pos+=upper_bound(vec3.begin()+i+1,vec3.end(),tmp)-1-vec3.begin()-i;
             }
			
		 }
		// cout<<"x:"<<x<<" "<<"pos:"<<pos<<endl;
		 return pos>=k;
	 }
	 else{
		 for(int i=x1-1;i>=0;i--){
			  ll tmp;
			 if(x%vec1[i]){
                 tmp=x/vec1[i]+1;
			 }
			 else{
			     tmp=x/vec1[i];
			 }
			if(lower_bound(vec3.begin(),vec3.end(),tmp)==vec3.end()){
                 pos+=0;
			 }
			 else{
				 pos+=vec3.end()-lower_bound(vec3.begin(),vec3.end(),tmp);
			 }
		 }
		 return pos>=k;
	 }
}
int main(){
	
	cin>>n>>k;
	ll x;
	for(int i=1;i<=n;i++){
        scanf("%lld",&x);
		if(x<0){
          vec1.push_back(x);
		}
		else if(x==0){
          vec2.push_back(x);
		} 
		else{
			vec3.push_back(x);
		}
	}
	sort(vec1.begin(),vec1.end());
	sort(vec2.begin(),vec2.end());
	sort(vec3.begin(),vec3.end());
	ll l=-1e18,r=1e18;
	ll mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else{
            l=mid+1;
		}
		
	}
    cout<<r+1<<endl;

	return 0;
}