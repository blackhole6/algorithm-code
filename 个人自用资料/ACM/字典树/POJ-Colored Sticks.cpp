//字典树+并查集
//欧拉路的性质
//1.具有连通性 
//2.有奇数度的个数为0或者2
//链接：http://poj.org/problem?id=2513
//代码：
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;
const int maxn=2000005;
struct node{
     int son[26];
	 int num;
}p[maxn];
int vis[maxn];
vector<int>vec;
int tot;
int pre[maxn];

void init(){
     for(int t=0;t<maxn;t++){
		 pre[t]=t;
	 }
}
int find(int x){
    if(x==pre[x])return x;
	else return pre[x]=find(pre[x]);
}
int  Insert(char *s){
	 int len=strlen(s);
	 int tmp=0;
	 int cc;
	 for(int t=0;t<len;t++){
		 cc=s[t]-'a';
		 if(p[tmp].son[cc]==0){
			 p[tmp].son[cc]=++tot;
		 }
		 tmp=p[tmp].son[cc];
	 }
	 if(vis[tmp]==0)
	 vec.push_back(tmp);
	 p[tmp].num++;
	 vis[tmp]=1;
	 return tmp;
}

char str1[15],str2[15];
int main(){
	tot=0;
	init();
     while(scanf("%s",str1)!=EOF){
		 scanf("%s",str2);
		 int tt1=Insert(str1);
		 int tt2=Insert(str2);
		 //cout<<tt1<<" "<<tt2<<endl;
		 int xx=find(tt1);
		 int yy=find(tt2);
		 if(xx!=yy){
			pre[xx]=yy;
		 }
	 }
	 int flag=0;
	 int ans=0;
	 for(int t=0;t<vec.size();t++){
		 if(find(vec[0])!=find(vec[t])){
			 //cout<<"sss"<<endl;
			 flag=1;
			 break;
		 }
		 if(p[vec[t]].num%2==1){
			// cout<<t<<endl;
			 ans++;
		 }
	 }
	 if(flag) puts("Impossible");
	 else{
	 if(ans==0||ans==2){
		 puts("Possible");
	 }
	 else{
		 puts("Impossible");
	 }
	 }
     return 0;
}
