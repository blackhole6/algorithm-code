#include<cstdio>
#include<iostream>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>
#define mod 100000000

const int maxn=1e5+5;
typedef long long ll;
using namespace std;

int Map[15][15];
int dp[15][4100];
int m,n;
bool check(int i,int j)//判断每一行是否合法
{
   int len=0;
   int a[15];
   int k=j;
   //暴力判断
   while(len<n)
   {
       a[len++]=(k%2);
       k/=2;
   }
   for(int t=len-1;t>=0;t--)
   {
       if(a[t]==1)
       {
           if(Map[i][len-1-t]==0)
           {
               return 0;
           }
       }
   }
   if(j&(j<<1))return 0;
   return 1;
}
bool check1(int i,int j,int k)//判断同列不相邻
{
    //j是当前i行的各种状态
    //k是第i-1行的各种状态情况
    if(dp[i-1][k]==0)
    {
        return 0;
    }
    else{
		int t=0;
        //位运算判断更快
		while(t<n){
			if( (j & (1<<t)) && (k & (1<<t)) )
            {
				return 0;
			}
			t++;
		}
	}
	return 1;
}
int main()
{
    cin>>m>>n;
    int status=(1<<n)-1;
    for(int t=0;t<m;t++)
    {
        for(int j=0;j<=status;j++)
        {
            dp[t][j]=0;
        }
    }
    for(int t=0;t<m;t++)
    {
        for(int j=0;j<n;j++)
        scanf("%d",&Map[t][j]);
    }
    
    for(int j=0;j<=status;j++)
    {
      if(check(0,j))
      {
          dp[0][j]=1;
      }
    }
    for(int i=1;i<m;i++){
		for(int j=0;j<=status;j++){
			for(int k=0;k<=status;k++){
				if( check(i,j)==1  && check1(i,j,k)==1){
					dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
				}
			} 
		}
	}	
    int ans=0;//注意这个初始化
	for(int j=0;j<=status;j++){
		ans=(ans+dp[m-1][j])%mod;
	}
	printf("%d\n",ans); 
    system("pause");

    return 0;
}