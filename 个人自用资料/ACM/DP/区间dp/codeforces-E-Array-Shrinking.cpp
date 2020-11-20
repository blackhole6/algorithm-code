//题目链接：https://codeforces.com/contest/1312/problem/E
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=505;
int a[maxn][maxn];//l-r值
int dp[maxn][maxn];//l-r的最小值
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i][i];
    	
    }
    for(int i=1;i<=n;i++){
    	for(int j=i;j<=n;j++){
    		dp[i][j]=(j-i)+1;
    	}
    }
    for(int len=1;len<=n;len++){
    	for(int l=1;l+len<=n;l++){
    		int r=l+len;
    		for(int k=l;k<=r;k++){
    			dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
    			if(dp[l][k]==1&&dp[k+1][r]==1&&a[l][k]==a[k+1][r]){
                  dp[l][r]=1;
                  a[l][r]=a[l][k]+1;
    			}
    		}
    	}
    }
    cout<<dp[1][n]<<endl;
	return 0;
}