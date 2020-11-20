//链接：https://codeforces.com/problemset/problem/1310/A
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
typedef long long ll;
struct node{
	ll a;
	ll t;
	bool friend operator<(node x,node y){
		return x.t>y.t;
	}
}p[maxn];
unordered_map<ll,ll>fa;
ll find(int x){
	if(fa[x]==0)return x;
	else{
		return fa[x]=find(fa[x]);
	}
}
void Merge(int x,int y){
	int xx=find(x);
	int yy=find(y);
	if(yy==0){
       yy=xx+1;
	}
	if(xx!=yy){
       fa[xx]=yy;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){
    	cin>>p[i].a;
    	//fa[p[i].a]=p[i].a;
    }
    //fa[10]=10;
    for(int i=1;i<=n;i++){
    	cin>>p[i].t;
    }
    sort(p+1,p+n+1);
    ll ans=0;
    for(int i=1;i<=n;i++){
    	ll xx=find(p[i].a);
      //  cout<<xx<<endl;
    	//if(xx>p[i].a)
        ans+=(xx-p[i].a)*p[i].t;
        Merge(xx,xx+1);
    }
    cout<<ans<<endl;
	return 0;
}