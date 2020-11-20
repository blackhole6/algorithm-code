//链接：https://ac.nowcoder.com/acm/contest/4370/B
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int maxn=1e5+5;
struct node{
    int son[10];
}p[maxn];
int vis[100005];
int tot;
int num[100005];
int cnt;
void Insert(char *s){
    int len=strlen(s);
    int tmp=0;
    for(int t=0;t<len;t++){
        int now=s[t]-'0';
        if(p[tmp].son[now]==0)
           p[tmp].son[now]=++tot;
        tmp=p[tmp].son[now];
		vis[tmp]++;
    }
	num[cnt]=tmp;
	cnt++;
} 
char str[10005][25];
int main(){
    int T;
	cin>>T; 
	int cc=1;
	while(T--){
		tot=0;
		cnt=0;
		int n;
		scanf("%d",&n);
        for(int i=0;i<maxn;i++){
           for(int j=0;j<10;j++){
			   p[i].son[j]=0;
		   }
		}
		for(int i=0;i<100002;i++){
			vis[i]=0;
		}
		for(int i=0;i<n;i++)
		{
			 scanf("%s",str[i]);
			 Insert(str[i]);
		}
		int flag=0;
		for(int i=0;i<cnt;i++){ 
            if(vis[num[i]]>1){
				flag=1;
				break;
			}
		}
		if(flag){
			printf("Case #%d: No\n",cc++);
		}
		else{
			printf("Case #%d: Yes\n",cc++);
		}
	}
    return 0;
}