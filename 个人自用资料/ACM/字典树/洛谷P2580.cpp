//字典树基本题目练习Insert和Find函数
//链接：https://www.luogu.org/problem/P2580
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int maxn=1e6+5;
struct node{
    int son[26];
    int num;
}p[maxn];
int tot;
void Insert(char *s){
    int len=strlen(s);
    int tmp=0;
    for(int t=0;t<len;t++){
        int now=s[t]-'a';
        if(p[tmp].son[now]==0)
           p[tmp].son[now]=++tot;
        tmp=p[tmp].son[now];
    }
}
bool Find(char *s){
    int len=strlen(s);
    int tmp=0;
    for(int  t=0;t<len;t++){
        int now=s[t]-'a';
        if(p[tmp].son[now]==0){
            return false;
        }
        tmp=p[tmp].son[now];
    }
    return true;
}
char str[55];
int main(){
    tot=0;
    int n,m;
    cin>>n;
    for(int t=0;t<n;t++){
        scanf("%s",str);
        Insert(str);
    }
    cin>>m;
    map<string,bool>mp;
    for(int t=0;t<m;t++){
        scanf("%s",str);
        if(Find(str)){
            if(mp[str]==0){
                puts("OK");
            }
            else{
                puts("REPEAT");
            }
        }
        else{
            puts("WRONG");
        }
        mp[str]=1;
    }
    return 0;
}