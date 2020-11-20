//给定一个01串 问有多少个子串满足子串的值等于区间长度
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
char str[maxn];
int pre[maxn];
int main(){
    int T;
    std::ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>T;
    while(T--){
        cin>>str;
        int len=strlen(str);
        memset(pre,0,sizeof(pre));
        int ans=0;
        int k=-1;
        for(int t=0;t<len;t++){
            if(str[t]=='1'){
                ans++;
                pre[t]=k;
                k=t;
            }
        }
        for(int t=0;t<len;t++){
            int sum=1;
            if(str[t]=='1'){
                for(int j=t+1;j<t+20&&j<len;j++){
                sum=sum*2+str[j]-'0';
                if((j-t+(t-pre[t]))>=sum){
                    ans++;
                }
                }
            }
        }
        cout<<ans<<endl;   
    }
    return 0;
}