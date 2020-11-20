//https://vjudge.net/problem/CodeForces-777C
//题意:给定一个矩阵，然后让你找出从l行到r行至少有一列是非递减的则输出Yes，否则No
//暴力+记忆化的思想
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>vec[maxn];
int c[maxn];
int dp[maxn];
int main(){
    int n,m,k;
    cin>>n>>m;
    int x;
    for(int t=0;t<n;t++){
        for(int j=0;j<m;j++){
           scanf("%d",&x);
           vec[t].push_back(x);
        }
    }
    memset(dp,-1,sizeof(dp));
    for(int t=0;t<n;t++){
        int maxx=t;
        for(int j=0;j<m;j++){
           int tmp1=t;
           int cnt=t+1;
           if(dp[j]>=t) tmp1=dp[j];
           else {
           while(cnt<n&&vec[cnt][j]>=vec[cnt-1][j]){
            tmp1++;
            cnt++;
           }
           dp[j]=tmp1;
           }
           maxx=max(maxx,tmp1);
           
        }
        c[t]=maxx;
    }
    scanf("%d",&k);
    int l,r;
    while(k--){
         scanf("%d%d",&l,&r);
         if(r-1<=c[l-1])puts("Yes");
         else puts("No");
    }
   // system("pause");
    return 0;
}