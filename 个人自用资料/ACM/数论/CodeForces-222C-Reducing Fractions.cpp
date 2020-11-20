//对素数进行分解，然后统计分子分母的个数然后，对可进行约分的进行约分
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e7+5;
const int M=1e5+5;
int a[M],b[M],prime[N];
int cnt1[N],cnt2[N];
void get_prime(){
	 for(int t=2;t<N;t++){
	 	if(prime[t]==0){
	 		  prime[t]=t;
	 		  for(int j=2*t;j<N;j+=t){
	 		  	if(prime[j]==0){
	 		  		prime[j]=t;
	 		  	}
	 		  }
	 	}
	 }
}
int main(){
	int n,m;
	cin>>n>>m;
	int x;
	get_prime();
	for(int t=1;t<=n;t++){
		scanf("%d",&a[t]);
        x=a[t];
	    while(x!=1){
	    	cnt1[prime[x]]++;
	    	x/=prime[x];
	    }
	}
	for(int t=1;t<=m;t++){
		scanf("%d",&b[t]);
        x=b[t];
	    while(x!=1){
	    	cnt2[prime[x]]++;
	    	x/=prime[x];
	    }
	}
	printf("%d %d\n",n,m);
    //分子约分分母
    for(int t=1;t<=n;t++){
        int cnt=1;
        int xx=a[t];
        while(xx!=1){
            //cout<<"*"<<xx<<" "<<prime[xx]<<endl;
            if(cnt2[prime[xx]]){
                  cnt2[prime[xx]]--;
            }
            else{
                cnt*=prime[xx];
            }
            xx/=prime[xx];
        }
        printf("%d ",cnt);
    }
    puts("");
    //分母约分分子
    for(int t=1;t<=m;t++){
        int cnt=1;
        int xx=b[t];
        while(xx!=1){
            if(cnt1[prime[xx]]){
                  cnt1[prime[xx]]--;
            }
            else{
                cnt*=prime[xx];
            }
            xx/=prime[xx];
        }
        printf("%d ",cnt);
    }

	return 0;
}