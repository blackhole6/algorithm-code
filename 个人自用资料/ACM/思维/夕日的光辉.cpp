//题目链接：https://cometoj.com/contest/73/problem/B?problem_id=4115
//分成三种情况去判断
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const int maxn=1e6+5;
char a[maxn],b[5]="pink";
int dp[maxn][5];
int vis[35];
int vis1[35];
int vis2[35];
int main(){
    int T;
    scanf("%d",&T);
    //cout<<T<<endl;
    while(T--){
        memset(vis,0,sizeof(vis));
        int lena;
        scanf("%d",&lena);
        scanf("%s",a);
        for(int t=0;t<lena;t++){
            vis[a[t]-'a']++;
        }
        for(int t=0;t<=lena;t++){
            for(int j=0;j<=4;j++){
                dp[t][j]=0;
            }
        }
        //int lena=strlen(a);
      //  int lenb=strlen(b);
        for(int i=1;i<=lena;i++)
        {
            for(int j=1;j<=4;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        if(dp[lena][4]!=4){
            puts("-1");
        }
        else{
            int ans=0;
            int minp;
            int maxk;
            for(int t=0;t<lena;t++){
                if(a[t]=='p'){
                    minp=t;
                    break;
                }
            }
            for(int t=lena-1;t>=0;t--){
                if(a[t]=='k'){
                    maxk=t;
                    break;
                }
            }
            memset(vis1,0,sizeof(vis1));
            memset(vis2,0,sizeof(vis2));
            for(int t=minp+1;t<maxk;t++){
                vis1[a[t]-'a']++;
                vis2[a[t]-'a']++;
            }
            int pos1,pos2;
            for(int t=minp+1;t<maxk;t++){
                if(a[t]=='i'){
                    pos1=t;
                    break;
                }
            }
            for(int t=maxk-1;t>minp;t--){
                if(a[t]=='n'){
                    pos2=t;
                    break;
                }
            }
            ans=max(ans,pos2-pos1-1);
            for(int t=minp+1;t<maxk;t++){
                vis1[a[t]-'a']--;
                if(a[t]=='i'&&vis1['n'-'a']>=1){
                    ans=max(ans,t-minp-1);
                }
            }
             for(int t=maxk-1;t>minp;t--){
                vis2[a[t]-'a']--;
                if(a[t]=='n'&&vis2['i'-'a']>=1){
                    ans=max(ans,maxk-t-1);
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}