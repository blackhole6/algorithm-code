//bush博弈的特点
//1.两人游戏
//2.轮流进行
//3.每次取1-m个
//谁先取完获胜
//链接：http://acm.hdu.edu.cn/showproblem.php?pid=1846
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
int main(){
    int T;
    cin>>T;
    int n,m;
    while(T--){
       scanf("%d%d",&n,&m);
       if(n%(m+1)){
           puts("first");
       }
       else{
           puts("second");
       }
    }
    return 0;
}