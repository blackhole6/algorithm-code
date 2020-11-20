#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>


const int maxn=1e6+1e5;
typedef long long ll;
using namespace std;

struct hero
{
    char name[25];
    int ati,def,hp,exp;
}p[25];
int dp[maxn];//在i状态下能够保存的最大生命 1代表杀死的 0代表没杀死
int main()
{

    int LATI ,LDEF,LHP,LINATI,LINDEF,LINHP;
    int n;
    while(~scanf("%d%d%d%d%d%d",&LATI,&LDEF,&LHP,&LINATI,&LINDEF,&LINHP))
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int t=0;t<n;t++)
        {
            scanf("%s%d%d%d%d",p[t].name,&p[t].ati,&p[t].def,&p[t].hp,&p[t].exp);
        }
        int status=(1<<n)-1;
        dp[0]=LHP;
        for(int t=0;t<=status;t++)
        {   
            int level=1;
            int LEXP=0;
            if(dp[t]<=0)
            {
                     continue;
            }
             for(int j=0;j<n;j++)
             {
                 if(t&(1<<j))
                 {
                     LEXP+=p[j].exp;
                 }
                 if(LEXP>=level*100)
                 {
                   level++;//注意的坑点这个题的经验升完级是不需要清空的
                 }
             }
             int ati=LATI+((level-1)*LINATI);//第一级是不需要升的
             int def=LDEF+((level-1)*LINDEF);
             for(int j=0;j<n;j++)
             {
                 if(t&(1<<j))
                 {
                     continue;
                 }
                 int cc;
                 int Alost=max(1,ati-p[j].def);//A损失的生命
                 cc=p[j].hp/Alost;
                 if(p[j].hp%Alost!=0)
                 {
                        cc++;
                 }
                 int LLost=(cc-1)*max(1,p[j].ati-def);//吕布损失的生命
                 if(LLost>=dp[t])
                 {
                     continue;
                 }
                 int curhp=dp[t]-LLost;
                 if(LEXP+p[j].exp>=level*100)
                 {
                     curhp+=LINHP;
                 }
                 int st=t+(1<<j);
                 dp[st]=max(dp[st],curhp);
             }
        }
        if (dp[status] <= 0)
			printf("Poor LvBu,his period was gone.\n");
		else 
            printf("%d\n",dp[status]);
    }
    system("pause");
    return 0;
}