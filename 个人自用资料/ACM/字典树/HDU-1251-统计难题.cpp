#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int maxn=5e5+5;
const int N=26;
struct node{
	  int son[N];
	  int num;
}p[maxn];
int tot;
char str[maxn];
void  Insert(char  *s){
	int len=strlen(s);
	int tmp=0;
	int now;
	for(int t=0;t<len;t++){
		now=s[t]-'a';
		if(p[tmp].son[now]==0){
			p[tmp].son[now]=++tot;
		}
		tmp=p[tmp].son[now];
		p[tmp].num++;
	}
}
int Find(char *s){
	 int len=strlen(s);
	 int tmp=0;
	 int now;
	 for(int t=0;t<len;t++){
		 now=s[t]-'a';
		if(p[tmp].son[now]==0){
			return 0;
		}
		tmp=p[tmp].son[now];
	 }
	 return p[tmp].num;
}
int main(){
    tot=0;
    while(gets(str)){
       if(strcmp(str,"")==0){
		   break;
	   }
	   Insert(str);
	}
	while(scanf("%s",str)!=EOF){
		printf("%d\n",Find(str));
	}
	return 0;
}