//广度优先搜索
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
char Map[1005][1005];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int vis[1005][1005];
int n,m;
int sx,sy,ex,ey;
bool check(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m){
        return true;
    }
    else{
        return false;
    }
}

struct node{
    int x,y;
    int cnt;
};
struct node1{
    int x,y;
    int x1,y1;
}p[15];
int k;
int BFS(int x,int y){
    node start;
    start.x=x;
    start.y=y;
    start.cnt=0;
    queue<node>q;
    q.push(start);
    int minn=0x3f3f3f3f;
    memset(vis,0x3f3f3f3f,sizeof(vis));
    vis[x][y]=0;
    while(!q.empty()) {
        node now=q.front();
        q.pop();
        node nxt;
        for(int j=0;j<k;j++){
            if(p[j].x==now.x&&p[j].y==now.y){
                nxt.x=p[j].x1;
                nxt.y=p[j].y1;
                nxt.cnt=now.cnt;
                if(nxt.cnt<vis[nxt.x][nxt.y]){
                    vis[nxt.x][nxt.y]=nxt.cnt;
                    q.push(nxt);
                }
            }
            if(p[j].x1==now.x&&p[j].y1==now.y){
                nxt.x=p[j].x;
                nxt.y=p[j].y;
                nxt.cnt=now.cnt;
                if(nxt.cnt<vis[nxt.x][nxt.y]){
                    vis[nxt.x][nxt.y]=nxt.cnt;
                    q.push(nxt);
                }
            }
        }
        for(int t=0;t<4;t++){
            node nxt;
            nxt.x=now.x+dir[t][0];
            nxt.y=now.y+dir[t][1];
            nxt.cnt=now.cnt+1;
            if(check(nxt.x,nxt.y)&&nxt.cnt<vis[nxt.x][nxt.y]&&(Map[nxt.x][nxt.y]=='*'||Map[nxt.x][nxt.y]=='T')){
                vis[nxt.x][nxt.y]=nxt.cnt;
                q.push(nxt);
            }
        }
    }
    if(vis[ex][ey]==0x3f3f3f3f)
        return -1;
    else{
        return vis[ex][ey]+(vis[ex][ey]-1)/8;
    }

}
int main(){
    cin>>n>>m;
    scanf("%d%d",&n,&m);
    for(int t=0;t<n;t++){
        scanf("%s",Map[t]);
        for(int j=0;j<m;j++){
            if(Map[t][j]=='S'){
                sx=t;
                sy=j;
            }
            if(Map[t][j]=='T'){
                ex=t;
                ey=j;
            }
        }
    }
    cin>>k;
    for(int t=0;t<k;t++){
        scanf("%d%d%d%d",&p[t].x,&p[t].y,&p[t].x1,&p[t].y1);
        p[t].x--;
        p[t].x1--;
        p[t].y--;
        p[t].y1--;
    }
    cout<<BFS(sx,sy);
    return 0;
}